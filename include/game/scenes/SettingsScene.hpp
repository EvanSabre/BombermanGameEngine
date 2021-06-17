/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** SettingsScene
*/

#ifndef SETTINGSSCENE_HPP_
#define SETTINGSSCENE_HPP_

#include "AScene.hpp"
#include "Parallax.hpp"
#include "Errors.hpp"
#include "AudioManager.hpp"
#include "CheckBox.hpp"
#include "BSdf.hpp"

namespace game {
    namespace scenes {
        class SettingsScene : public gameEngine::AScene {
            public:
                SettingsScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, std::shared_ptr<game::managers::GameManager> &info);
                ~SettingsScene();

                void switchScene(std::shared_ptr<game::managers::GameManager> info);

                void start() override;
                void update() override;
                void draw() override;

            protected:
                gameEngine::managers::AudioManager _audio;
                std::shared_ptr<gameEngine::encapsulation::BSdf> _title = nullptr;
                std::shared_ptr<gameEngine::encapsulation::BText> _settings = nullptr;
                gameEngine::encapsulation::BTexture2D _background;
            private:
        };
    }
}

#endif /* !SETTINGSSCENE_HPP_ */
