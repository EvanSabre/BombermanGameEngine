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
                GameManager(const std::string &str = "");
                ~GameManager();

                void setCurrentScene(const std::string &str);
                std::string getCurrentScene() const noexcept;

            protected:
                std::string _currentScene;
                //std::unique_ptr<game::managers::UserManager> _userManager;
                //PlayerInfo {Inputs, Names, Map Seed choosen}
                //AudioLevels
            private:
        };
    }
}

#endif /* !GAMEMANAGER_HPP_ */
