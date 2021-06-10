/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** SceneManager
*/

#include "SceneManager.hpp"
#include "MainMenuScene.hpp"
#include "PlayGameScene.hpp"

using namespace game::managers;

const std::unordered_map<std::string, std::function<std::shared_ptr<gameEngine::interfaces::IScene>(std::shared_ptr<gameEngine::managers::WindowManager> window, gameEngine::scenes::SceneInfo)>>SceneManager::_scene{
        {"menu",
            [](std::shared_ptr<gameEngine::managers::WindowManager> window, gameEngine::scenes::SceneInfo info) {
                return std::make_shared<game::scenes::MainMenuScene>(window, info);
            }},
        {"play",
            [](std::shared_ptr<gameEngine::managers::WindowManager> window, gameEngine::scenes::SceneInfo info) {
                return std::make_shared<game::scenes::PlayGameScene>(window, info);
            }}
    };


SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

std::shared_ptr<gameEngine::interfaces::IScene> SceneManager::loadScene(const std::string &type, std::shared_ptr<gameEngine::managers::WindowManager> window, gameEngine::scenes::SceneInfo info)
{
    return _scene.at(type)(window, info);
}
