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
#include "AudioManager.hpp"
#include "Map.hpp"
#include "BCamera.hpp"
#include "Player.hpp"
#include "BModel.hpp"
#include "BTexture2D.hpp"
#include "CheckBox.hpp"

namespace game {
    namespace scenes {
        class PlayGameScene : public gameEngine::AScene {
            public:
                PlayGameScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, const std::shared_ptr<gameEngine::scenes::SceneInfo> &info);
                ~PlayGameScene();

                void start() override;
                std::string update() override;
                void draw() override;
            protected:
            private:
                Map _map{15};
                gameEngine::encapsulation::BCamera _cam;
                gameEngine::managers::AudioManager _audio;
                std::vector<std::shared_ptr<game::objects::Character>> _players;

            private:
                void setupCamera() noexcept;
        };
    }
}

#endif /* !PLAYSCENE_HPP_ */
