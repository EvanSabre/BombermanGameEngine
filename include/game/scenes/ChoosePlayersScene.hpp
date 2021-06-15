/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** ChoosePlayerScene
*/

#ifndef CHOOSEPLAYERSCENE_HPP_
#define CHOOSEPLAYERSCENE_HPP_

#include "AScene.hpp"
#include "Button.hpp"
#include "InputButton.hpp"
#include "Selector.hpp"

#define RECTANGLE gameEngine::encapsulation::BRectangle
#define SELECTOR gameEngine::component::Selector
#define WINDOW_X _windowManager->getWindowSize()._x
#define WINDOW_Y _windowManager->getWindowSize()._y

namespace game
{
    namespace scenes
    {
        class ChoosePlayersScene : public gameEngine::AScene
        {
            public:
                ChoosePlayersScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, const std::shared_ptr<gameEngine::scenes::SceneInfo> &info);
                ~ChoosePlayersScene();
                void start() override;
                std::string update() override;
                void draw() override;
            private:
                std::shared_ptr<RECTANGLE> _Mainrect;
                std::shared_ptr<SELECTOR> _playerSelector;
                std::shared_ptr<SELECTOR> _botSelector;
        };
    };
};
#endif /* !CHOOSEPLAYERSCENE_HPP_ */
