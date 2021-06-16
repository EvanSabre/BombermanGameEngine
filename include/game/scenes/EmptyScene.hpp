/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** EmptyScene
*/

#ifndef EMPTYSCENE_HPP_
#define EMPTYSCENE_HPP_

#include "AScene.hpp"
#include "Timer.hpp"
#include "BSdf.hpp"

namespace game {
    namespace scenes {
        class EmptyScene : public gameEngine::AScene {
            public:
                EmptyScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, const std::shared_ptr<game::managers::GameManager> &info);
                ~EmptyScene();

                void start() override;
                void update() override;
                void draw() override;
            protected:
                gameEngine::encapsulation::BSdf _text;
                gameEngine::component::Timer _timer;
            private:
        };
    }
}

#endif /* !EMPTYSCENE_HPP_ */
