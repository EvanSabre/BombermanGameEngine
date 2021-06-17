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
    for (std::size_t i = 0; i != _bombs.size(); i++) {
        if (_bombs[i]->isDone()) {
            explode(*_bombs[i]);
            updateExplosionAnimation();
            _bombs.erase(_bombs.begin() + i);
        }
    }
}

void ExplosionManager::updateExplosionAnimation()
{
}

void ExplosionManager::explode(const game::objects::AExplosif &bomb)
{
    std::unordered_map<std::string, bool> direction = {
        {"UP", true}, {"LEFT", true}, {"DOWN", true}, {"RIGHT", true}};

    for (std::size_t range = 1; range <= bomb.getRange(); range++) {
        Vector3T<float> pos(bomb.getTransform().getPosition());

        if (direction["UP"]) {
            game::objects::Tile ex(bomb);

            ex.setTransform().setPosition({
                ex.getTransform().getPosition()._x,
                ex.getTransform().getPosition()._y,
                ex.getTransform().getPosition()._z + (float)range,
            });
            for (auto &tile : _tiles) {
                if (tile->getTransform().getPosition()._x == ex.getTransform().getPosition()._x &&
                    tile->getTransform().getPosition()._z == ex.getTransform().getPosition()._z + (float)range) {
                    // check tile type -> brick = explode
                    direction["UP"] = false;
                } else {
                    // animation explosion
                }
            }
            for (auto &player : _players) {
                if (player->getTransform().getPosition()._x == ex.getTransform().getPosition()._x &&
                    player->getTransform().getPosition()._z == ex.getTransform().getPosition()._z + (float)range) {
                    // check tile type -> brick = explode
                    direction["UP"] = false;
                } else {
                    // animation explosion
                }
            }
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
}

void ExplosionManager::pushBomb(const std::shared_ptr<game::objects::AExplosif> &bomb)
{
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
