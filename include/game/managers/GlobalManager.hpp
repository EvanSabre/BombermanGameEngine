/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** GlobalManager
*/

#ifndef GLOBALMANAGER_HPP_
#define GLOBALMANAGER_HPP_

#include "GameManager.hpp"
#include "Errors.hpp"
#include <memory>

namespace game {
    namespace managers {
        class GlobalManager {
            public:
                GlobalManager();
                ~GlobalManager();

                void run();
                void loadNewScene(const std::string &sceneName);
            protected:
                std::shared_ptr<gameEngine::managers::WindowManager> _windowManager;
                std::shared_ptr<gameEngine::interfaces::IScene> _currentScene;
                std::shared_ptr<game::managers::GameManager> _gameManager;
            private:
        };
    }
}

#endif /* !GLOBALMANAGER_HPP_ */
