/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** EmptyScene
*/

#include "EmptyScene.hpp"

using namespace game::scenes;

EmptyScene::EmptyScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, const std::shared_ptr<game::managers::GameManager> &info)
: AScene(windowManager, info)
{
}

EmptyScene::~EmptyScene()
{
}

void EmptyScene::start()
{
    _timer.getCurrentTime().setTextPosition(Vector<float>(100, 100));
    _timer.getCurrentTime().setTextSize(100);
}

void EmptyScene::update()
{
    if (!_windowManager->isRunning()) {
        _timer.setIsDone(true);
        _timer.wait();
        _info->setQuit(true);
    }
}

void EmptyScene::draw()
{
    _timer.getCurrentTime().draw();
}
