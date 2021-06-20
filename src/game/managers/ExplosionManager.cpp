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
    : _texture(EXPLOSIONTEXT)
{
    _explosionH = std::make_shared<gameEngine::encapsulation::BModel>(EXPLOSIONPATH);
    _explosionV = std::make_shared<gameEngine::encapsulation::BModel>(EXPLOSIONPATH);
    _explosionH->setTexture(0, MATERIAL_MAP_DIFFUSE, _texture);
    _explosionV->setTexture(0, MATERIAL_MAP_DIFFUSE, _texture);
    _players = players;
    _tiles = tiles;
    _audio = std::make_shared<gameEngine::managers::AudioManager>();
    _audio->loadSoundFromFile("./assets/All/Sound/BombExplode.mp3", "boom");
    _audio->loadSoundFromFile("./assets/All/Sound/CharacterDamage.wav", "damage");
    _audio->loadSoundFromFile("./assets/All/Sound/CharacterDeath.wav", "death");
    _audio->loadSoundFromFile("./assets/All/Sound/CollectibleDrop.wav", "itemDrop");
    std::shared_ptr<gameEngine::encapsulation::BTexture2D> tileTex = std::make_shared<gameEngine::encapsulation::BTexture2D>("assets/All/Textures/Tile.png");
    std::shared_ptr<gameEngine::encapsulation::BTexture2D> speedTex = std::make_shared<gameEngine::encapsulation::BTexture2D>("assets/All/Textures/SpeedUp.png");
    std::shared_ptr<gameEngine::encapsulation::BModel> healthModel = std::make_shared<gameEngine::encapsulation::BModel>("assets/All/Models/HealthUp.obj", Vector3T<float>(0, 0, 0), WHITE, Vector3T<float>(0.5, 0.5, 0.5));
    std::shared_ptr<gameEngine::encapsulation::BModel> oneModel = std::make_shared<gameEngine::encapsulation::BModel>("assets/All/Models/OneUp.obj", Vector3T<float>(0, 0, 0), WHITE, Vector3T<float>(0.5, 0.5, 0.5));
    std::shared_ptr<gameEngine::encapsulation::BModel> speedModel = std::make_shared<gameEngine::encapsulation::BModel>("assets/All/Models/SpeedUp.obj", Vector3T<float>(0, 0, 0), WHITE, Vector3T<float>(0.5, 0.5, 0.5));
    std::shared_ptr<gameEngine::encapsulation::BModel> bombModel = std::make_shared<gameEngine::encapsulation::BModel>("assets/All/Models/BombUp.obj", Vector3T<float>(0, 0, 0), WHITE, Vector3T<float>(0.5, 0.5, 0.5));
    std::shared_ptr<gameEngine::encapsulation::BModel> passModel = std::make_shared<gameEngine::encapsulation::BModel>("assets/All/Models/BombPass.obj", Vector3T<float>(0, 0, 0), WHITE, Vector3T<float>(0.5, 0.5, 0.5));
    _powerUps[game::ONEUP] = std::make_shared<game::objects::PowerUpTile>(oneModel, tileTex, game::ONEUP);
    _powerUps[game::BOMBUP] = std::make_shared<game::objects::PowerUpTile>(bombModel, tileTex, game::BOMBUP);
    _powerUps[game::HEALTHUP] = std::make_shared<game::objects::PowerUpTile>(healthModel, tileTex, game::HEALTHUP);
    _powerUps[game::FIREUP] = std::make_shared<game::objects::PowerUpTile>(passModel, tileTex, game::FIREUP);
    _powerUps[game::BOMBPASS] = std::make_shared<game::objects::PowerUpTile>(passModel, tileTex, game::ONEUP);
    _powerUps[game::SPEEDUP] = std::make_shared<game::objects::PowerUpTile>(speedModel, speedTex, game::SPEEDUP);
}

ExplosionManager::~ExplosionManager()
{
}

// Member functions
void ExplosionManager::update()
{
    std::vector<std::size_t> eraser;

    for (std::size_t i = 0; i != _bombs.size(); i++) {
        if (_bombs.at(i)->isDone()) {
            for (auto &player : _players)
                if (_bombs.at(i)->getPlayerId() == player->getId())
                    player->reload();
            explode(*_bombs[i]);
            eraser.push_back(i);
        }
    }
    for (auto it : eraser)
        _bombs.erase(_bombs.begin() + it);
}

void ExplosionManager::draw()
{
    for (auto explo = _explosion.begin(); explo != _explosion.end();) {
        explo->first.first->draw();
        explo->first.second->draw();
        if (explo->second->getElapsedTime(true) > 200)
            _explosion.erase(explo);
        else
            explo++;
    }
}

int ExplosionManager::checkTilesExplosion(const game::objects::AExplosif &bomb, const Vector3T<float> &pos, bool first)
{
    std::unordered_map<std::size_t, game::Tag_e> map({{0, BOMBUP}, {1, FIREUP}, {2, SPEEDUP}, {3, ONEUP}, {4, HEALTHUP}, {5, BOMBPASS}});

    _audio->playSound("boom");
    for (auto tile = _tiles.begin(); tile != _tiles.end(); tile++) {
        if ((*tile)->getTransform().getPosition()._x == pos._x &&
            (*tile)->getTransform().getPosition()._y >= 0 &&
            (*tile)->getTransform().getPosition()._z == pos._z) {
            if ((*tile)->getTag() == BRICK) {
                if (!(std::rand() % 4)) {
                // if (!(std::rand() % 1)) {
                    std::size_t nb = std::rand() % 5;
                    // std::size_t nb = 0;
                    _audio->playSound("itemDrop");
                    _powerUps[map[nb]]->setTransform().setPosition((*tile)->getTransform().getPosition());
                    _powerUps[map[nb]]->setTransform().setScale({5, 5, 5});
                    _tiles.push_back(std::make_shared<game::objects::PowerUpTile>(*_powerUps[map[nb]]));
                }
                _tiles.erase(tile);
                return 2;
            } else if ((*tile)->getTag() == BOMBUP || (*tile)->getTag() == FIREUP ||
                       (*tile)->getTag() == SPEEDUP || (*tile)->getTag() == ONEUP ||
                       (*tile)->getTag() == HEALTHUP || (*tile)->getTag() == BOMBPASS) {
                _tiles.erase(tile);
                return 2;
            }
            return 0;
        }
    }
    if (!first)
        for (auto &bomb : _bombs) {
            if (bomb->getTransform().getPosition()._x == pos._x &&
                bomb->getTransform().getPosition()._y == pos._y &&
                bomb->getTransform().getPosition()._z == pos._z) {
                bomb->explode();
            }
        }
    for (auto player = _players.begin(); player != _players.end(); player++) {
        if ((int)(((*player)->getTransform().getPosition()._x + 3) / TILESIZE) == (int)(pos._x / TILESIZE) &&
            (*player)->getTransform().getPosition()._y == pos._y &&
            (int)(((*player)->getTransform().getPosition()._z + 3) / TILESIZE) == (int)(pos._z / TILESIZE)) {
            (*player)->looseLife();
            (*player)->subScore(50);
            addKillerScore(bomb, (*player)->getId());
            if (!(*player)->isAlive()) {
                _audio->playSound("death");
                _players.erase(player);
            } else
                _audio->playSound("damage");
            return 2;
        }
    }
    return 1;
}

void ExplosionManager::explode(const game::objects::AExplosif &bomb)
{
    std::unordered_map<std::string, bool> direction = {
        {"UP", true}, {"LEFT", true}, {"DOWN", true}, {"RIGHT", true}};
    std::unordered_map<std::string, float> power = {
        {"UP", 0}, {"LEFT", 0}, {"DOWN", 0}, {"RIGHT", 0}};
    Vector3T<float> pos(bomb.getTransform().getPosition());
    Vector3T<float> posTemp(bomb.getTransform().getPosition());

    checkTilesExplosion(bomb, posTemp, true);
    for (std::size_t range = 1; range <= bomb.getRange(); range++) {
        if (direction["RIGHT"]) {
            posTemp = {pos._x, pos._y, pos._z + (float)range * TILESIZE};
            if ((direction["RIGHT"] = checkTilesExplosion(bomb, posTemp, false)))
                power["RIGHT"]++;
        }
        if (direction["LEFT"]) {
            posTemp = {pos._x, pos._y, pos._z - (float)range * TILESIZE};
            if ((direction["LEFT"] = checkTilesExplosion(bomb, posTemp, false)))
                power["LEFT"]++;
        }
        if (direction["UP"]) {
            posTemp = {pos._x + (float)range * TILESIZE, pos._y, pos._z};
            if ((direction["UP"] = checkTilesExplosion(bomb, posTemp, false)))
                power["UP"]++;
        }
        if (direction["DOWN"]) {
            posTemp = {pos._x - (float)range * TILESIZE, pos._y, pos._z};
            if ((direction["DOWN"] = checkTilesExplosion(bomb, posTemp, false)))
                power["DOWN"]++;
        }
    }
    _explosionV->setTransform().setPosition({pos._x, pos._y, pos._z -
        (power["LEFT"] * TILESIZE) / 2 + (power["RIGHT"] * TILESIZE) / 2});
    _explosionV->setTransform().setScale({0.8, 1, power["LEFT"] + power["RIGHT"] + 1});
    _explosionH->setTransform().setPosition({pos._x -
        (power["DOWN"] * TILESIZE) / 2 + (power["UP"] * TILESIZE) / 2,
        pos._y, pos._z});
    _explosionH->setTransform().setScale({power["DOWN"] + power["UP"] + 1, 1, 0.8});
    _explosion.push_back({{_explosionH, _explosionV},
        std::make_unique<gameEngine::component::Clock>()});
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
    _bombs.push_back(bomb);
}

// Getters
std::vector<std::shared_ptr<game::objects::AExplosif>> &ExplosionManager::getBombs()
{
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

void ExplosionManager::addKillerScore(const game::objects::AExplosif &bomb, const std::string &victimeId) noexcept
{
    if (victimeId == bomb.getPlayerId())
        return;
    for (auto player : _players) {
        if (player->getId() == bomb.getPlayerId()) {
            player->addScore(50);
            return;
        }
    }
}
