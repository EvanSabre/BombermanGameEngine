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
#include "AudioManager.hpp"
#include "BText.hpp"
#include "BColor.hpp"

namespace game {
    namespace scenes {
        class SplashScreenScene : public gameEngine::AScene {
            enum STATE {
                IDLE,
                JUMP,
                ATTACK,
                DONE,
                SKIP
            };
            public:
                SplashScreenScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, std::shared_ptr<game::managers::GameManager> &info);
                ~SplashScreenScene();

                void start() override;
                void update() override;
                void draw() override;
                void updateAnim(size_t &frame, size_t max, int multipler, gameEngine::encapsulation::BRectangle &rect);
                void animIdle();
                void animJump();
                void animAttack();
                std::string done();

            protected:
                gameEngine::encapsulation::BRectangle _attackRect;
                gameEngine::encapsulation::BRectangle _jumpRect;
                gameEngine::encapsulation::BRectangle _idleRect;
                gameEngine::encapsulation::BTexture2D _jumpText;
                gameEngine::encapsulation::BTexture2D _attackText;
                gameEngine::encapsulation::BTexture2D _idleText;
                gameEngine::encapsulation::BTexture2D _logo;
                gameEngine::component::Clock _clock;
                enum STATE _state;
                size_t _attackFrame;
                size_t _jumpFrame;
                size_t _idleFrame;
                size_t _currentFrame;
                size_t _nbReset;
                std::shared_ptr<gameEngine::managers::AudioManager> _audio = nullptr;
                gameEngine::encapsulation::BText _skipText{std::string("Press SPACE to skip"),
                    Vector<float>(10, 35),
                    gameEngine::encapsulation::BColor(WHITE),
                    20};
            private:

        };

    }
}

#endif /* !SPLASHSCREENSCENE_HPP_ */
