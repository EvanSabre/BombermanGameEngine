/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** AScene
*/

#ifndef ASCENE_HPP_
#define ASCENE_HPP_

#include "IScene.hpp"
#include "WindowManager.hpp"
#include "BTexture2D.hpp"
#include "GameManager.hpp"
#include "ButtonManager.hpp"

#define PLAY_BUTTON "./assets/Backgrounds/button_background1.png"
#define WINDOW_X _windowManager->getWindowSize()._x
#define WINDOW_Y _windowManager->getWindowSize()._y

namespace gameEngine {
    class AScene : public gameEngine::interfaces::IScene {
        public:
            AScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, const std::shared_ptr<game::managers::GameManager> &info);
            ~AScene();

            std::shared_ptr<gameEngine::managers::WindowManager> getWindowManager() const;
            std::vector<std::shared_ptr<gameEngine::encapsulation::BTexture2D>> getTextures() const;

            void pushTexture(const std::shared_ptr<gameEngine::encapsulation::BTexture2D> &text);
            void drawTextures();
        protected:
            std::shared_ptr<gameEngine::managers::WindowManager> _windowManager;
            std::shared_ptr<game::managers::GameManager> _info;
            std::vector<std::shared_ptr<gameEngine::encapsulation::BTexture2D>> _textures;
            gameEngine::managers::ButtonManager _buttonManager;
            // gameEngine::managers::CheckBoxManager _checkboxManager;

        private:
    };
}

#endif /* !ASCENE_HPP_ */
