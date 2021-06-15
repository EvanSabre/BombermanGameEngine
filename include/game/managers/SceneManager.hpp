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
#include "GameManager.hpp"
#include "Errors.hpp"

namespace game {
    namespace managers {
        class SceneManager {
            public:
                SceneManager();
                ~SceneManager();
                static std::shared_ptr<gameEngine::interfaces::IScene> loadScene(const std::string &type, std::shared_ptr<gameEngine::managers::WindowManager> window, std::shared_ptr<game::managers::GameManager> info);

            private:
                static const std::unordered_map<std::string, std::function<std::shared_ptr<gameEngine::interfaces::IScene>(std::shared_ptr<gameEngine::managers::WindowManager> window, std::shared_ptr<game::managers::GameManager> info)>>_scene;
        };
    }
}
#endif /* !SCENEMANAGER_HPP_ */
