/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** EmptyScene
*/

#include "EmptyScene.hpp"

using namespace game::scenes;

EmptyScene::EmptyScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, const std::shared_ptr<game::managers::GameManager> &info)
: AScene(windowManager, info), _text("HELLO BITE", 10)
{
}

EmptyScene::~EmptyScene()
{
}

void EmptyScene::start()
{
}

void EmptyScene::update()
{
    if (!_windowManager->isRunning()) {
        _info->setQuit(true);
    }
}

void EmptyScene::draw()
{
    _text.draw();
}
