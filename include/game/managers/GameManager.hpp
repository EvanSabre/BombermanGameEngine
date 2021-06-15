/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** GAMEMANAGER
*/

#ifndef GAMEMANAGER_HPP_
#define GAMEMANAGER_HPP_

//#include "game/managers/UserManager.hpp"
#include "IScene.hpp"
#include "WindowManager.hpp"

namespace game {
    namespace managers {
        class GameManager {
            public:
                GameManager(std::shared_ptr<gameEngine::managers::WindowManager> win, const std::string &str = "");
                ~GameManager();

                void setCurrentScene(const std::string &str);
                std::string getCurrentScene() const noexcept;

                void loadNewScene(const std::string &sceneName);
            protected:
                std::string _currentScene;
                std::shared_ptr<gameEngine::managers::WindowManager> _windowManager;
                std::shared_ptr<gameEngine::interfaces::IScene> _currentScene;

                //std::unique_ptr<game::managers::UserManager> _userManager;
                //PlayerInfo {Inputs, Names, Map Seed choosen}
                //AudioLevels
            private:
        };
    }
}

#endif /* !GAMEMANAGER_HPP_ */
