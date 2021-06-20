/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** TutorialScene
*/

#ifndef TUTORIALSCENE_HPP_
#define TUTORIALSCENE_HPP_

#include "AScene.hpp"
#include "Parallax.hpp"
#include "Errors.hpp"
#include "AudioManager.hpp"
#include "CheckBox.hpp"
#include "BSdf.hpp"

namespace game {
    namespace scenes {
        class TutorialScene : public gameEngine::AScene {
            public:
                TutorialScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, std::shared_ptr<game::managers::GameManager> &info);
                ~TutorialScene();

                void start() override;
                void update() override;
                void draw() override;
            protected:
                std::shared_ptr<gameEngine::managers::AudioManager> _audio = nullptr;
                gameEngine::encapsulation::BFont _font;
                gameEngine::encapsulation::BTexture2D _background;
                std::shared_ptr<gameEngine::encapsulation::BSdf> _title = nullptr;
                std::shared_ptr<gameEngine::encapsulation::BText> _text = nullptr;
                std::string _tutorialText;

            private:
        };
    }
}

#endif /* !TUTORIALSCENE_HPP_ */
