/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** EmptyScene
*/

#include "EmptyScene.hpp"

using namespace game::scenes;

EmptyScene::EmptyScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, const std::shared_ptr<game::managers::GameManager> &info)
: AScene(windowManager, info), _text("HELLO BITE", 10), _map(_info->getUniverse(), 15)
{
}
EmptyScene::~EmptyScene()
{
}

void EmptyScene::start()
{
    Vector<float> size(WINDOW_X / 2, WINDOW_Y / 1.5);
    Vector<float> pos(WINDOW_X / 4, WINDOW_Y / 7);

}

void EmptyScene::update()
{
    if (!_windowManager->isRunning()) {
        _info->setQuit(true);
    }
}

void EmptyScene::draw()
{
}
