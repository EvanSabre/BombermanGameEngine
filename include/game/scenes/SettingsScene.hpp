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
#include "Selector.hpp"
#include "InputButton.hpp"
#include <algorithm>

namespace game {
    namespace scenes {
        class SettingsScene : public gameEngine::AScene {
            public:
                SettingsScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, std::shared_ptr<game::managers::GameManager> &info);
                ~SettingsScene();

                void switchScene(std::shared_ptr<game::managers::GameManager> info);
                void setKeyMap();
                void start() override;
                void update() override;
                void draw() override;

            protected:
                std::shared_ptr <gameEngine::managers::AudioManager> _audio = nullptr;
                gameEngine::encapsulation::BFont _font;
                std::shared_ptr<gameEngine::encapsulation::BSdf> _title = nullptr;
                std::shared_ptr<gameEngine::encapsulation::BText> _keybindings = nullptr;
                std::shared_ptr<gameEngine::encapsulation::BText> _left = nullptr;
                std::shared_ptr<gameEngine::encapsulation::BText> _right = nullptr;
                std::shared_ptr<gameEngine::encapsulation::BText> _up = nullptr;
                std::shared_ptr<gameEngine::encapsulation::BText> _down = nullptr;
                std::shared_ptr<gameEngine::encapsulation::BText> _drop = nullptr;
                gameEngine::encapsulation::BText _saveButtonText;
                gameEngine::encapsulation::BTexture2D _background;
                std::unique_ptr<gameEngine::component::Selector> _soundSelector = nullptr;
                std::unique_ptr<gameEngine::component::Selector> _musicSelector = nullptr;
                std::unique_ptr<gameEngine::component::Selector> _aiSelector = nullptr;
                std::unordered_map<game::Event, std::pair<gameEngine::key_e, gameEngine::key_e>> _keyMap;
                gameEngine::managers::ButtonManager _inputManager;
            private:
        };
    }
}

#endif /* !SETTINGSSCENE_HPP_ */
