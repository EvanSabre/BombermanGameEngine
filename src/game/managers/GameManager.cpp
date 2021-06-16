/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** GameManager
*/

#include "GameManager.hpp"

game::managers::GameManager::GameManager(const std::string &str) : _currentScene(str), _change(false)
{
}

game::managers::GameManager::~GameManager()
{
}

std::string game::managers::GameManager::getCurrentScene() const noexcept
{
    return _currentScene;
}

bool game::managers::GameManager::haveToChange()
{
    if (_change) {
        _change = false;
        return true;
    }
    return false;
}

void game::managers::GameManager::setCurrentScene(const std::string &str)
{
    _currentScene = str;
    _change = true;
}
