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
#include "CheckBox.hpp"
#include "BSdf.hpp"

namespace game {
    namespace scenes {
        class MainMenuScene : public gameEngine::AScene {
            public:
                MainMenuScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, std::shared_ptr<game::managers::GameManager> &info);
                ~MainMenuScene();

                void switchScene(std::shared_ptr<game::managers::GameManager> info);
                void start() override;
                void update() override;
                void draw() override;
                //Unique to this scene
            protected:
                gameEngine::scenes::Parallax _parallax;
                std::shared_ptr<gameEngine::managers::AudioManager> _audio = nullptr;
                std::shared_ptr<gameEngine::encapsulation::BSdf> _title = nullptr;
                std::shared_ptr<gameEngine::encapsulation::BText> _settings = nullptr;
                gameEngine::encapsulation::BTexture2D _background;
            private:
        };
    }
}
#endif /* !MAINMENUSCENE_HPP_ */
