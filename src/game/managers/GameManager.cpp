/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** GameManager
*/

#include "GameManager.hpp"
#include "SettingConf.hpp"

game::managers::GameManager::GameManager(const std::string &str) : _currentScene(str), _change(false)
{
    _settings = game::systems::SettingConf::getDefaultSettings();
    _userManager = std::make_shared<UserManager>("./Users/");
    _inputManager = std::make_shared<gameEngine::managers::InputManager<Event>>(_userManager->getUserInputs(), _settings._keyMap);
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

void game::managers::GameManager::setQuit(bool q)
{
    _quit = q;
}

void game::managers::GameManager::setCurrentScene(const std::string &str)
{
    _currentScene = str;
    _change = true;
}

bool game::managers::GameManager::haveToQuit()
{
    if (_quit)
        return true;
    return false;
}
