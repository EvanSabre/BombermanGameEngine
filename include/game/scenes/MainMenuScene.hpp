/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** MainMenuScene
*/

#ifndef MAINMENUSCENE_HPP_
#define MAINMENUSCENE_HPP_

#include "AScene.hpp"
#include "Parallax.hpp"
#include "Errors.hpp"
#include "AudioManager.hpp"

namespace game {
    namespace scenes {
        class MainMenuScene : public gameEngine::AScene {
            public:
                MainMenuScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, const gameEngine::scenes::SceneInfo &info);
                ~MainMenuScene();

                void start() override;
                std::string update() override;
                void draw() override;
                //Unique to this scene
            protected:
                gameEngine::scenes::Parallax _parallax;
                gameEngine::managers::AudioManager _audio;
            private:

        };
    }
}
#endif /* !MAINMENUSCENE_HPP_ */
