/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** AScene
*/

#include "AScene.hpp"

using namespace gameEngine;

AScene::AScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, const std::shared_ptr<game::managers::GameManager> &info)
{
    _windowManager = windowManager;
}

AScene::~AScene()
{
}

std::shared_ptr<gameEngine::managers::WindowManager> AScene::getWindowManager() const
{
    return _windowManager;
}

std::vector<std::shared_ptr<encapsulation::BTexture2D>> AScene::getTextures() const
{
    return _textures;
}

void AScene::pushTexture(const std::shared_ptr<encapsulation::BTexture2D> &text)
{
    _textures.push_back(text);
}

void AScene::drawTextures()
{
    for (auto it : _textures) {
        it->draw();
    }
}
