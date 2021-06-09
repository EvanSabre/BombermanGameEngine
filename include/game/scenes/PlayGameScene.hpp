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
        };
    }
}

#endif /* !PLAYSCENE_HPP_ */
