/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** SceneManager
*/

#include "SceneManager.hpp"
#include "MainMenuScene.hpp"
#include "PlayGameScene.hpp"
#include "SplashScreenScene.hpp"
#include "ChoosePlayersScene.hpp"

#include "EmptyScene.hpp"
using namespace game::managers;

const std::unordered_map<std::string, std::function<std::shared_ptr<gameEngine::interfaces::IScene>(std::shared_ptr<gameEngine::managers::WindowManager> window, std::shared_ptr<game::managers::GameManager> &info)>>SceneManager::_scene{
        {"menu",
            [](std::shared_ptr<gameEngine::managers::WindowManager> window, std::shared_ptr<game::managers::GameManager> &info) {
                return std::make_shared<game::scenes::MainMenuScene>(window, info);
            }},
        {"play",
            [](std::shared_ptr<gameEngine::managers::WindowManager> window, std::shared_ptr<game::managers::GameManager> &info) {
                return std::make_shared<game::scenes::PlayGameScene>(window, info);
            }},
        {"splash",
            [](std::shared_ptr<gameEngine::managers::WindowManager> window, std::shared_ptr<game::managers::GameManager> &info) {
                return std::make_shared<game::scenes::SplashScreenScene>(window, info);
            }},
        {"choosePlayers",
            [](std::shared_ptr<gameEngine::managers::WindowManager> window, std::shared_ptr<game::managers::GameManager> info) {
                return std::make_shared<game::scenes::ChoosePlayersScene>(window, info);
        {"empty",
            [](std::shared_ptr<gameEngine::managers::WindowManager> window, std::shared_ptr<game::managers::GameManager> &info) {
                return std::make_shared<game::scenes::EmptyScene>(window, info);
            }}

    };


SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

std::shared_ptr<gameEngine::interfaces::IScene> SceneManager::loadScene(const std::string &type, std::shared_ptr<gameEngine::managers::WindowManager> window, std::shared_ptr<game::managers::GameManager> &info)
{
    try {
        return _scene.at(type)(window, info);
    } catch(std::exception &e) {
        std::cerr << "Scene with name not found" << std::endl;
        throw NoSceneException();
    }
}
