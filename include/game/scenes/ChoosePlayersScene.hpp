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
#include "ButtonManager.hpp"

#define RECTANGLE gameEngine::encapsulation::BRectangle
#define IMAGE gameEngine::encapsulation::BTexture2D
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
                ChoosePlayersScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, std::shared_ptr<game::managers::GameManager> &info);
                ~ChoosePlayersScene();
                void start() override;
                void update() override;
                void draw() override;
            private:
                std::unique_ptr<IMAGE> _background = nullptr;
                std::unique_ptr<SELECTOR> _playerSelector = nullptr;
                std::unique_ptr<SELECTOR> _botSelector = nullptr;
                TEXT _PlayersIndication;
                gameEngine::managers::ButtonManager _buttonManager;
        };
    };
};
#endif /* !CHOOSEPLAYERSCENE_HPP_ */
