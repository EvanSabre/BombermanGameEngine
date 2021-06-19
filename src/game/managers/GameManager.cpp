/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** GameManager
*/

#include "GameManager.hpp"
#include "SettingConf.hpp"

game::managers::GameManager::GameManager(const std::string &str) : _currentScene(str), _change(false), _musicVolume(100), _soundVolume(100)
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

std::string game::managers::GameManager::getUniverse() const noexcept
{
    return _universe;
}

void game::managers::GameManager::setUniverse(const std::string &uni)
{
    _universe = uni;
}

std::vector<std::shared_ptr<game::User>> game::managers::GameManager::getPlayers() const noexcept
{
    return _players;
}

bool game::managers::GameManager::getIsSave() const noexcept
{
    return _isSave;
}

std::string game::managers::GameManager::getSavePath() const noexcept
{
    return _savePath;
}

void game::managers::GameManager::pushPlayer(std::shared_ptr<game::User> &player)
{
    _players.push_back(player);
}

void game::managers::GameManager::setQuit(bool q)
{
    _quit = q;
}

void game::managers::GameManager::setCurrentScene(const std::string &str)
{
    std::cout << "SETTING CURRENT SCENE " << str << " changing from " << _currentScene << std::endl;
    _currentScene = str;
    _change = true;
}

bool game::managers::GameManager::haveToQuit()
{
    if (_quit)
        return true;
    return false;
}

void game::managers::GameManager::setSave(bool save)
{
    _isSave = save;
}

void game::managers::GameManager::setSavePath(const std::string &path)
{
    _savePath = path;
}

void game::managers::GameManager::setMusicVolume(float volume)
{
    _musicVolume = volume;
}

float game::managers::GameManager::getMusicVolume() const
{
    return _musicVolume;
}

void game::managers::GameManager::setSoundVolume(float volume)
{
    _soundVolume = volume;
}

float game::managers::GameManager::getSoundVolume() const
{
    return _soundVolume;
}
