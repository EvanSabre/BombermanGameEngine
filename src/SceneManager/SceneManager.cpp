/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** SceneManager
*/

#include "SceneManager.hpp"

const std::unordered_map<std::string, std::function<std::shared_ptr<Interfaces::IScene>(void)>>Interfaces::SceneManager::_scene{
        {"menu",
            []() {
                return std::make_shared<Interfaces::MENU>();
            }},
        {"game",
            []() {
                return std::make_shared<Interfaces::GAME>();
            }},
		{"settings",
            []() {
                return std::make_shared<Interfaces::SETTINGS>();
            }},
		{"pause",
            []() {
                return std::make_shared<Interfaces::PAUSE>();
            }},
		{"load",
            []() {
                return std::make_shared<Interfaces::LOAD>();
            }},
    };


Interfaces::SceneManager::SceneManager()
{
}

Interfaces::SceneManager::~SceneManager()
{
}

std::shared_ptr<Interfaces::IScene> Interfaces::SceneManager::loadScene(const std::string &type)
{
    return _scene.at(type)();
}
