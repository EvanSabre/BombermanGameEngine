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
    this->setupCamera();
}

PlayGameScene::~PlayGameScene()
{
}

void PlayGameScene::start()
{
    gameEngine::encapsulation::BColor bgColor = {0, 170, 170, 255};
    std::shared_ptr<gameEngine::encapsulation::Button> button =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(50, 50), Vector<float>(10, 10), gameEngine::encapsulation::BText("PAUSE"), BLUE);

    _buttonManager.pushButton(button);

    this->_windowManager.get()->setBackgroundColor(bgColor);
}

void PlayGameScene::setupCamera() noexcept
{
    _cam.setPosition({7, 20, -7});
    _cam.setTarget({7, 0, 7});
    _cam.setUp({0, 1, 0});
    _cam.setFovy(55);
    _cam.setProjection(CAMERA_PERSPECTIVE);
}

std::string PlayGameScene::update()
{
    _buttonManager.updateButtons();
    if (_buttonManager.isButtonClicked("PAUSE")) {
        std::cout << "Clicked pause button" << std::endl;
        //return "play";
    }
    return "";
}

void PlayGameScene::draw()
{
    _buttonManager.drawButtons();
    this->_windowManager.get()->set3DMode(_cam);
    _map.draw();
    _cam.endMode();
}
