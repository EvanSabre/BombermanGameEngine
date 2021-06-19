/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** ExplosionManager
*/

#include "ExplosionManager.hpp"

using namespace game::managers;

ExplosionManager::ExplosionManager(
    const std::vector<std::shared_ptr<game::objects::Character>> players,
    const std::vector<std::shared_ptr<game::objects::Tile>> tiles)
{
    _model = std::make_shared<gameEngine::encapsulation::BModel>(MODELEXPLOSION);
    _texture = std::make_shared<gameEngine::encapsulation::BTexture2D>(TEXTUREEXPLOSION);
    _anim = std::make_shared<gameEngine::encapsulation::BModelAnimation>(ANIMEXPLOSION);
    _animRef = std::make_shared<gameEngine::Animation>(*_model, *_texture, *_anim);
    _players = players;
    _tiles = tiles;
    _audio = std::make_shared<gameEngine::managers::AudioManager>();
    _audio->loadSoundFromFile("./assets/All/Sound/BombExplode.mp3", "boom");
    _audio->loadSoundFromFile("./assets/All/Sound/CharacterDamage.wav", "damage");
    _audio->loadSoundFromFile("./assets/All/Sound/CharacterDeath.wav", "death");
    _audio->loadSoundFromFile("./assets/All/Sound/CollectibleDrop.wav", "itemDrop");
}

ExplosionManager::~ExplosionManager()
{
}

// Member functions
void ExplosionManager::update()
{
    std::vector<std::size_t> eraser;

    updateExplosionAnimation();
    for (std::size_t i = 0; i != _bombs.size(); i++) {
        if (_bombs.at(i)->isDone()) {
            // std::cout << "done id = " << i << std::endl;
            // std::cout << "--start explode--" << std::endl;
            explode(*_bombs[i]);
            // std::cout << "--end explode--" << std::endl;
            eraser.push_back(i);
            // _bombs.erase(_bombs.begin() + i);
            // delete _bombs.at(i).get();
        }
    }
    for (auto it : eraser) {
        // std::cout << "  nb = " << it << std::endl;
        _bombs.erase(_bombs.begin() + it);
    }
}

void ExplosionManager::draw()
{
    for (auto &anim : _anims) {
        anim->refresh();
    }
}

void ExplosionManager::updateExplosionAnimation()
{
    for (auto &anim : _anims) {
        anim->updateModelAnimation();
    }
}

bool ExplosionManager::checkTilesExplosion(const Vector3T<float> &pos)
{
    // bruit explosion
    _audio->playSound("boom");
    for (auto tile = _tiles.begin(); tile != _tiles.end(); tile++) {
        if ((*tile)->getTransform().getPosition()._x == pos._x &&
            (*tile)->getTransform().getPosition()._y == pos._y &&
            (*tile)->getTransform().getPosition()._z == pos._z) {
            // check tile type -> brick = explode
            if ((*tile)->getTag() == BRICK)
                _tiles.erase(tile);
            // std::cout << "* TILE DESTROYED *" << std::endl;
            return false;
        }
    }
    for (auto player = _players.begin(); player != _players.end(); player++) {
        if ((*player)->getTransform().getPosition()._x / TILESIZE == pos._x / TILESIZE &&
            (*player)->getTransform().getPosition()._y == pos._y &&
            (*player)->getTransform().getPosition()._z / TILESIZE == (pos._z) / TILESIZE) {
            // (*player) dies
            // std::cout << "* PLAYER DESTROYED *" << std::endl;
            _audio->playSound("damage");
            (*player)->looseLife();
            if (!(*player)->isAlive())
                _players.erase(player);
            return false;
        }
    }
    return true;
}

void ExplosionManager::explode(const game::objects::AExplosif &bomb)
{
    std::unordered_map<std::string, bool> direction = {
        {"UP", true}, {"LEFT", true}, {"DOWN", true}, {"RIGHT", true}};

    for (std::size_t range = 1; range <= bomb.getRange(); range++) {
        Vector3T<float> pos(bomb.getTransform().getPosition());

        // std::cout << "range = " << range << std::endl;
        if (direction["UP"]) {
            // std::cout << "UP" << std::endl;
            _animRef->setPos({pos._x, pos._y, pos._z + (float)range * TILESIZE});
            direction["UP"] = checkTilesExplosion(_animRef->getPos());
            // std::cout << "!! EXPLOOOOSSIOOOONNNN !!" << std::endl;
            // _anims.push_back(std::make_unique<gameEngine::Animation>(*_animRef));
            // Animation Explosion with ex
        }
        if (direction["DOWN"]) {
            // std::cout << "DOWN" << std::endl;
            _animRef->setPos({pos._x, pos._y, pos._z - (float)range * TILESIZE});
            direction["DOWN"] = checkTilesExplosion(_animRef->getPos());
            // std::cout << "!! EXPLOOOOSSIOOOONNNN !!" << std::endl;
            // _anims.push_back(std::make_unique<gameEngine::Animation>(*_animRef));
            // Animation Explosion with ex
        }
        if (direction["LEFT"]) {
            // std::cout << "LEFT" << std::endl;
            _animRef->setPos({pos._x + (float)range * TILESIZE, pos._y, pos._z});
            direction["LEFT"] = checkTilesExplosion(_animRef->getPos());
            // std::cout << "!! EXPLOOOOSSIOOOONNNN !!" << std::endl;
            // _anims.push_back(std::make_unique<gameEngine::Animation>(*_animRef));
            // Animation Explosion with ex
        }
        if (direction["RIGHT"]) {
            // std::cout << "RIGHT" << std::endl;
            _animRef->setPos({pos._x - (float)range * TILESIZE, pos._y, pos._z});
            direction["RIGHT"] = checkTilesExplosion(_animRef->getPos());
            // std::cout << "!! EXPLOOOOSSIOOOONNNN !!" << std::endl;
            // _anims.push_back(std::make_unique<gameEngine::Animation>(*_animRef));
            // Animation Explosion with ex
        }
    }
}

// Setters
void ExplosionManager::setObjects(
    const std::vector<std::shared_ptr<game::objects::Character>> players,
    const std::vector<std::shared_ptr<game::objects::Tile>> tiles)
{
    _players = players;
    _tiles = tiles;
    for (auto it = _tiles.begin(); it != _tiles.end();) {
        if ((*it)->getTag() == BOMB)
            _tiles.erase(it);
        else
            it++;
    }
}

void ExplosionManager::pushBomb(const std::shared_ptr<game::objects::AExplosif> &bomb)
{
    if (bomb == nullptr)
        return;
    // std::cout << bomb->getTransform() << std::endl;
    _bombs.push_back(bomb);
}

// Getters
std::vector<std::shared_ptr<game::objects::AExplosif>> &ExplosionManager::getBombs()
{
    // if (!_bombs.empty())
    //     std::cout << _bombs.front()->getTransform() << std::endl;

    return _bombs;
}

std::vector<std::shared_ptr<game::objects::Tile>> &ExplosionManager::getTiles()
{
    return _tiles;
}

std::vector<std::shared_ptr<game::objects::Character>> &ExplosionManager::getPlayers()
{
    return _players;
}
