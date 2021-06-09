/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** PlayScene
*/

#include "PlayGameScene.hpp"

using namespace game::scenes;

PlayGameScene::PlayGameScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, const gameEngine::scenes::SceneInfo &info)
: AScene(windowManager, info)
{
}

PlayGameScene::~PlayGameScene()
{
}

void PlayGameScene::start()
{
    std::shared_ptr<gameEngine::encapsulation::Button> button =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(_windowManager->getWindowSize()._x/3, _windowManager->getWindowSize()._y/3), Vector<float>(_windowManager->getWindowSize()._x / 2, _windowManager->getWindowSize()._y / 2), gameEngine::encapsulation::BText("In GAME"), WHITE);

    _buttonManager.pushButton(button);
}

std::string PlayGameScene::update()
{
    return "";
}

void PlayGameScene::draw()
{
    _buttonManager.drawButtons();
}
