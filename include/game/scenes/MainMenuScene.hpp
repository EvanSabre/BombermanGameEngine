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
#include "CheckBox.hpp"

namespace game {
    namespace scenes {
        class MainMenuScene : public gameEngine::AScene {
            public:
                MainMenuScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, const std::shared_ptr<gameEngine::scenes::SceneInfo> &info);
                ~MainMenuScene();

                void start() override;
                std::string update() override;
                void draw() override;
                //Unique to this scene
            protected:
                gameEngine::scenes::Parallax _parallax;
                std::shared_ptr<gameEngine::encapsulation::BText> _title = nullptr;
                gameEngine::encapsulation::BTexture2D _background;
            private:

        };
    }
}
#endif /* !MAINMENUSCENE_HPP_ */
