/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** ExplosionManager
*/

#include "ExplosionManager.hpp"
#include "PowerUpTile.hpp"

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
    std::shared_ptr<gameEngine::encapsulation::BModel> healthModel = std::make_shared<gameEngine::encapsulation::BModel>("assets/All/Models/HealthUp.obj", Vector3T<float>(0, 0, 0), WHITE, Vector3T<float>(0.5, 0.5, 0.5));
    std::shared_ptr<gameEngine::encapsulation::BTexture2D> healthTex = std::make_shared<gameEngine::encapsulation::BTexture2D>("assets/All/Textures/Tile.png");
    _powerUps[game::ONEUP] = std::make_shared<game::objects::PowerUpTile>(healthModel, healthTex, game::ONEUP);
    _powerUps[game::BOMBUP] = std::make_shared<game::objects::PowerUpTile>(healthModel, healthTex, game::BOMBUP);
    _powerUps[game::HEALTHUP] = std::make_shared<game::objects::PowerUpTile>(healthModel, healthTex, game::HEALTHUP);
    _powerUps[game::FIREUP] = std::make_shared<game::objects::PowerUpTile>(healthModel, healthTex, game::FIREUP);
    _powerUps[game::BOMBPASS] = std::make_shared<game::objects::PowerUpTile>(healthModel, healthTex, game::ONEUP);
    _powerUps[game::SPEEDUP] = std::make_shared<game::objects::PowerUpTile>(healthModel, healthTex, game::SPEEDUP);
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
    std::unordered_map<std::size_t, game::Tag_e> map({{0, BOMBUP}, {1, FIREUP}, {2, SPEEDUP}, {3, ONEUP}, {4, HEALTHUP}, {5, BOMBPASS}});

    _audio->playSound("boom");
    for (auto tile = _tiles.begin(); tile != _tiles.end(); tile++) {
        if ((*tile)->getTransform().getPosition()._x == pos._x &&
            (*tile)->getTransform().getPosition()._y == pos._y &&
            (*tile)->getTransform().getPosition()._z == pos._z) {
            // check tile type -> brick = explode
            if ((*tile)->getTag() == BRICK) {
                if (!(std::rand() % 6)) {
                    std::size_t nb = std::rand() % 5;
                    _powerUps[map[nb]]->setTransform().setPosition((*tile)->getTransform().getPosition());
                    _powerUps[map[nb]]->setTransform().setScale({5, 5, 5});
                    _tiles.push_back(std::make_shared<game::objects::PowerUpTile>(*_powerUps[map[nb]]));
                }
                _tiles.erase(tile);
            }
            // std::cout << "* TILE DESTROYED *" << std::endl;
            return false;
        }
    }
            // player dies
    for (auto player = _players.begin(); player != _players.end(); player++) {
        if ((int)(((*player)->getTransform().getPosition()._x + 3) / TILESIZE) == (int)(pos._x / TILESIZE) &&
            (*player)->getTransform().getPosition()._y == pos._y &&
            (int)(((*player)->getTransform().getPosition()._z + 3) / TILESIZE) == (int)(pos._z / TILESIZE)) {
            // player dies
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
    Vector3T<float> pos(bomb.getTransform().getPosition());

    _animRef->setPos({pos._x, pos._y, pos._z});
    direction["UP"] = checkTilesExplosion(_animRef->getPos());
    for (std::size_t range = 1; range <= bomb.getRange(); range++) {

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
