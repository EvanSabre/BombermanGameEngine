/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** PlayScene
*/

#ifndef PLAYGAMESCENE_HPP_
#define PLAYGAMESCENE_HPP_

#include "AScene.hpp"
#include "ButtonManager.hpp"
#include "Map.hpp"
#include "BCamera.hpp"
#include "Player.hpp"
#include "BModel.hpp"
#include "BTexture2D.hpp"

namespace game {
    namespace scenes {
        class PlayGameScene : public gameEngine::AScene {
            public:
                PlayGameScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, const gameEngine::scenes::SceneInfo &info);
                ~PlayGameScene();

                void start() override;
                std::string update() override;
                void draw() override;
            protected:
            private:
                Map _map{15, 637520213};
                gameEngine::encapsulation::BTexture2D _playerTexture{""};
                gameEngine::encapsulation::BModel _playerModel{""};
                game::objects::Player _player{"p1", "test_name"};
                gameEngine::encapsulation::BCamera _cam;

            private:
                void setupCamera() noexcept;
        };
    }
}

#endif /* !PLAYSCENE_HPP_ */
