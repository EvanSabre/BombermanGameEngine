/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** ExplosionManager
*/

#include "ExplosionManager.hpp"

using namespace game::manager;

ExplosionManager::ExplosionManager(
    const std::vector<std::shared_ptr<game::objects::Character>> players,
    const std::vector<std::shared_ptr<game::objects::Tile>> tiles)
{
}

ExplosionManager::~ExplosionManager()
{
}

// Member functions
void ExplosionManager::draw()
{

}

void ExplosionManager::update()
{
    std::vector<std::size_t> eraser;

    for (std::size_t i = 0; i != _bombs.size(); i++) {
        if (_bombs.at(i)->isDone()) {
            std::cout << "done id = " << i << std::endl;
            std::cout << "--start explode--" << std::endl;
            explode(*_bombs[i]);
            std::cout << "--end explode--" << std::endl;
            updateExplosionAnimation();
            eraser.push_back(i);
            // _bombs.erase(_bombs.begin() + i);
            // delete _bombs.at(i).get();
        }
    }
    for (auto it : eraser) {
        std::cout << "  nb = " << it << std::endl;
        _bombs.erase(_bombs.begin() + it);
    }
}

void ExplosionManager::updateExplosionAnimation()
{
}

bool ExplosionManager::checkTilesExplosion(const game::objects::Tile &ex)
{
    for (auto tile = _tiles.begin(); tile != _tiles.end(); tile++) {
        if ((*tile)->getTransform().getPosition()._x == ex.getTransform().getPosition()._x &&
            (*tile)->getTransform().getPosition()._y == ex.getTransform().getPosition()._y &&
            (*tile)->getTransform().getPosition()._z == ex.getTransform().getPosition()._z) {
            // check tile type -> brick = explode
            if ((*tile)->getTag() == BRICK)
                _tiles.erase(tile);
            std::cout << "* TILE DESTROYED *" << std::endl;
            return false;
        }
    }
    for (auto &player : _players) {
        if (player->getTransform().getPosition()._x / TILESIZE == ex.getTransform().getPosition()._x / TILESIZE &&
            player->getTransform().getPosition()._y == ex.getTransform().getPosition()._y &&
            player->getTransform().getPosition()._z / TILESIZE == (ex.getTransform().getPosition()._z) / TILESIZE) {
            // player dies
            std::cout << "* PLAYER DESTROYED *" << std::endl;
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
        game::objects::Tile ex(bomb);

        std::cout << "range = " << range << std::endl;
        if (direction["UP"]) {
            std::cout << "UP" << std::endl;
            ex.setTransform().setPosition({pos._x, pos._y, pos._z + (float)range * TILESIZE});
            direction["UP"] = checkTilesExplosion(ex);
            std::cout << "!! EXPLOOOOSSIOOOONNNN !!" << std::endl;
            // Animation Explosion with ex
        }
        if (direction["DOWN"]) {
            std::cout << "DOWN" << std::endl;
            ex.setTransform().setPosition({pos._x, pos._y, pos._z - (float)range * TILESIZE});
            direction["DOWN"] = checkTilesExplosion(ex);
            std::cout << "!! EXPLOOOOSSIOOOONNNN !!" << std::endl;
            // Animation Explosion with ex
        }
        if (direction["LEFT"]) {
            std::cout << "LEFT" << std::endl;
            ex.setTransform().setPosition({pos._x + (float)range * TILESIZE, pos._y, pos._z});
            direction["LEFT"] = checkTilesExplosion(ex);
            std::cout << "!! EXPLOOOOSSIOOOONNNN !!" << std::endl;
            // Animation Explosion with ex
        }
        if (direction["RIGHT"]) {
            std::cout << "RIGHT" << std::endl;
            ex.setTransform().setPosition({pos._x - (float)range * TILESIZE, pos._y, pos._z});
            direction["RIGHT"] = checkTilesExplosion(ex);
            std::cout << "!! EXPLOOOOSSIOOOONNNN !!" << std::endl;
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
