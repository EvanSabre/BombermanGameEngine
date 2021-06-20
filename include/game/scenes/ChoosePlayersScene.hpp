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
#include "AudioManager.hpp"
#include "TSelector.hpp"
#include "BModel.hpp"

#define RECTANGLE gameEngine::encapsulation::BRectangle
#define IMAGE gameEngine::encapsulation::BTexture2D
#define SELECTOR gameEngine::component::Selector
#define TSELECTOR gameEngine::component::TSelector

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

            protected:
                std::shared_ptr<gameEngine::managers::AudioManager> _audio = nullptr;

            private:
                IMAGE _background;
                std::unique_ptr<SELECTOR> _playerSelector = nullptr;
                std::unique_ptr<SELECTOR> _botSelector = nullptr;
                std::unique_ptr<TSELECTOR<gameEngine::encapsulation::BModel>> _universeSelector = nullptr;
                TEXT _PlayersIndication;
                std::string _universe;
                std::array<std::shared_ptr<gameEngine::encapsulation::BTexture2D>, 3> _textures;
        };
    };
};
#endif /* !CHOOSEPLAYERSCENE_HPP_ */
