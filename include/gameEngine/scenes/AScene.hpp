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

namespace gameEngine {
    class AScene : public gameEngine::interfaces::IScene {
        public:
            AScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager);
            ~AScene();

            std::shared_ptr<gameEngine::managers::WindowManager> getWindowManager() const;
            std::vector<std::shared_ptr<gameEngine::encapsulation::BTexture2D>> getTextures() const;

            void pushTexture(const std::shared_ptr<gameEngine::encapsulation::BTexture2D> &text);
            void drawTextures();
        protected:
            std::shared_ptr<gameEngine::managers::WindowManager> _windowManager;
            std::vector<std::shared_ptr<gameEngine::encapsulation::BTexture2D>> _textures;
        private:
    };
}

#endif /* !ASCENE_HPP_ */
