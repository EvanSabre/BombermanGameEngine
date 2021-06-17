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
#include "Timer.hpp"
#include "ExplosionManager.hpp"
#include "Bot.hpp"

#define UNIVERSE std::vector<std::string>({"Vikings", "Pirates", "Samurai"})

namespace game {
    namespace scenes {
        class PlayGameScene : public gameEngine::AScene {
            public:
                PlayGameScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, std::shared_ptr<game::managers::GameManager> &info);
                ~PlayGameScene();

                void collisionChecker(std::shared_ptr<game::objects::Character> &, const Vector3T<float> &);
                void start() override;
                void update() override;
                void draw() override;
                void updateExplosionManager();
            protected:
            private:
                std::string _universe;
                Map _map;
                gameEngine::encapsulation::BCamera _cam;
                gameEngine::managers::AudioManager _audio;
                std::vector<std::shared_ptr<game::objects::Character>> _players;
                std::vector<std::shared_ptr<game::objects::Tile>> _tiles;
                gameEngine::component::Timer _timer;
                std::shared_ptr<game::manager::ExplosionManager> _explosion;
            private:
                void setupCamera() noexcept;
        };
    }
}

#endif /* !PLAYSCENE_HPP_ */
