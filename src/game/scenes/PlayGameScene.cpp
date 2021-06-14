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
    _playerTexture.loadFromFile("./resources/models/kaya/kayaTexture.png");
    _playerModel.load("./resources/models/kaya/kaya.iqm");
    _playerModel.setTexture(0, MATERIAL_MAP_DIFFUSE, _playerTexture);
    _playerModel.setTransform().setScale({0.02, 0.02, 0.02});
    _player.setTransform().setPosition({0, 3, 0});
    this->setupCamera();
    this->_player.setModel(&_playerModel);
}

PlayGameScene::~PlayGameScene()
{
}

void PlayGameScene::start()
{
    std::shared_ptr<gameEngine::encapsulation::Button> button =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(50, 50), Vector<float>(10, 10), gameEngine::encapsulation::BText("PAUSE"), BLUE);

    _buttonManager.pushButton(button);
    _windowManager->setBackgroundColor({0, 170, 170, 255});
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
    _player.handleKeyEvent();
    return "";
}

void PlayGameScene::draw()
{
    _buttonManager.drawButtons();
    this->_windowManager->set3DMode(_cam);
    _map.draw();
    _player.draw();
    _cam.endMode();
}
