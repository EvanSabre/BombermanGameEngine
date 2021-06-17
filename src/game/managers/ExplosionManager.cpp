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
    for (int x = 1; x <= bomb.getRange(); x++) {
        // check player and tiles
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
