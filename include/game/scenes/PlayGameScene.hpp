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
#include "CheckBox.hpp"

namespace game {
    namespace scenes {
        class PlayGameScene : public gameEngine::AScene {
            public:
                PlayGameScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, const std::shared_ptr<gameEngine::scenes::SceneInfo> &info);
                ~PlayGameScene();

                void collisionChecker(std::shared_ptr<game::objects::Character> &, const Vector3T<float> &);
                void start() override;
                std::string update() override;
                void draw() override;
            protected:
            private:
                Map _map;
                gameEngine::encapsulation::BCamera _cam;
                std::vector<std::shared_ptr<game::objects::Character>> _players;
                std::vector<Tile> _tiles;

            private:
                void setupCamera() noexcept;
        };
    }
}

#endif /* !PLAYSCENE_HPP_ */
