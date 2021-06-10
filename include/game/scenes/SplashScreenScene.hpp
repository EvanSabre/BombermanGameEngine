/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** SplashScreenScene
*/

#ifndef SPLASHSCREENSCENE_HPP_
#define SPLASHSCREENSCENE_HPP_

#include "AScene.hpp"
#include "Clock.hpp"

namespace game {
    namespace scenes {
        class SplashScreenScene : public gameEngine::AScene {
            enum STATE {
                IDLE,
                JUMP,
                ATTACK
            };
            public:
                SplashScreenScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, const gameEngine::scenes::SceneInfo &info);
                ~SplashScreenScene();

                void start() override;
                std::string update() override;
                void draw() override;
                void updateAnim(size_t &frame, size_t max, int multipler, gameEngine::encapsulation::BRectangle &rect);
                void animIdle();
                void animJump();
                void animAttack();

            protected:
                gameEngine::encapsulation::BRectangle _attackRect;
                gameEngine::encapsulation::BRectangle _jumpRect;
                gameEngine::encapsulation::BRectangle _idleRect;
                gameEngine::encapsulation::BTexture2D _jumpText;
                gameEngine::encapsulation::BTexture2D _attackText;
                gameEngine::encapsulation::BTexture2D _idleText;
                gameEngine::component::Clock _clock;
                enum STATE _state;
                size_t _attackFrame;
                size_t _jumpFrame;
                size_t _idleFrame;
                size_t _currentFrame;
                size_t _nbReset;
                bool _reset;
            private:

        };

    }
}

#endif /* !SPLASHSCREENSCENE_HPP_ */
