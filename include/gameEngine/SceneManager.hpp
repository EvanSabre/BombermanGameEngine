/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** SceneManager
*/

#ifndef SCENEMANAGER_HPP_
#define SCENEMANAGER_HPP_

#include <string>
#include <memory>
#include <list>
#include <unordered_map>
#include <functional>
#include <iostream>
#include "IScene.hpp"

namespace gameEngine {
    class SceneManager {
    public:
        SceneManager();
        ~SceneManager();
        static std::shared_ptr<Interfaces::IScene> loadScene(const std::string &type);

    private:
        static const std::unordered_map<std::string, std::function<std::shared_ptr<Interfaces::IScene>(void)>>_scene;
    };
}
#endif /* !SCENEMANAGER_HPP_ */
