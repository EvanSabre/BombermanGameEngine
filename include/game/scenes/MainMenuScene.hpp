/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** MainMenuScene
*/

#ifndef MAINMENUSCENE_HPP_
#define MAINMENUSCENE_HPP_

#include "AScene.hpp"
#include "ButtonManager.hpp"
#include "Parallax.hpp"
#include "SceneInfo.hpp"

namespace game {
    namespace scenes {
        class MainMenuScene : public gameEngine::AScene {
            public:
                MainMenuScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, const gameEngine::scenes::SceneInfo &info);
                ~MainMenuScene();

                void start() override;
                void update() override;

                //Unique to this scene
            protected:
                gameEngine::managers::ButtonManager _buttonManager;
                gameEngine::scenes::Parallax _parallax;
            private:

        };
    }
}
#endif /* !MAINMENUSCENE_HPP_ */
