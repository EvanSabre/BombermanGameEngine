/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** ChooseProfileScene
*/

#ifndef CHOOSEPROFILESCENE_HPP_
#define CHOOSEPROFILESCENE_HPP_

#include "AScene.hpp"
#include "Button.hpp"
#include "InputButton.hpp"
#include "Selector.hpp"
#include "ButtonManager.hpp"

#define RECTANGLE gameEngine::encapsulation::BRectangle
#define IMAGE gameEngine::encapsulation::BTexture2D
#define SELECTOR gameEngine::component::Selector
#define INPUT_BUTTON gameEngine::object::InputButton
#define WINDOW_X _windowManager->getWindowSize()._x
#define WINDOW_Y _windowManager->getWindowSize()._y

namespace game
{
    namespace scenes
    {
        class ChooseProfileScene : public gameEngine::AScene
        {
            public:
                ChooseProfileScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, std::shared_ptr<game::managers::GameManager> &info);
                ~ChooseProfileScene();
                void start() override;
                void update() override;
                void draw() override;
            private:
                std::unique_ptr<IMAGE> _background = nullptr;
                std::unique_ptr<SELECTOR> _profileSelector = nullptr;
                std::unique_ptr<RECTANGLE> _profileKeypad = nullptr;
                std::unique_ptr<RECTANGLE> _zoneStat = nullptr;
                TEXT _ProfilesIndicationGame;
                TEXT _ProfilesIndicationPlayed;
                TEXT _ProfilesIndicationKilled;
                gameEngine::managers::ButtonManager _buttonManager;
        };
    };
};

#endif /* !CHOOSEPROFILESCENE_HPP_ */
