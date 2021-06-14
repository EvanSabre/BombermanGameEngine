/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** GlobalManager
*/

#ifndef GLOBALMANAGER_HPP_
#define GLOBALMANAGER_HPP_

#include "SceneManager.hpp"
#include "Errors.hpp"

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
                std::shared_ptr<gameEngine::scenes::SceneInfo> _sceneInfo;
            private:
        };
    }
}

#endif /* !GLOBALMANAGER_HPP_ */
