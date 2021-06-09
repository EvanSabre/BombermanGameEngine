/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** MainMenuScene
*/

#ifndef MAINMENUSCENE_HPP_
#define MAINMENUSCENE_HPP_

#include "IScene.hpp"
#include "WindowManager.hpp"
#include "ButtonManager.hpp"

namespace game {
    namespace scenes {
        class MainMenuScene : public gameEngine::interfaces::IScene {
            public:
                MainMenuScene();
                ~MainMenuScene();

                void start() override;
                void update() override;
            protected:
                gameEngine::Managers::WindowManager _windowManager;
                gameEngine::Managers::ButtonManager _buttonManager;
            private:

        };
    }
}
#endif /* !MAINMENUSCENE_HPP_ */
