/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** PlayScene
*/

#include "PlayGameScene.hpp"

using namespace game::scenes;

PlayGameScene::PlayGameScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, const std::shared_ptr<game::managers::GameManager> &info)
: AScene(windowManager, info)
{
    std::shared_ptr<game::objects::Player> player = std::make_shared<game::objects::Player>("991", "Josh", "./resources/models/kaya/kayaTexture.png", "./resources/models/kaya/kaya.iqm");
    player->setTransform().setScale({0.01, 0.01, 0.01});
    player->setTransform().setPosition({1, 1, 1});
    player->setTransform().setRotation({0, 90, 0});
    _players.push_back(player);
    this->setupCamera();
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
    _cam.setPosition({-7, 20, 7});
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
    for (auto it : _players) {
        it->update();
    }
    return "";
}

void PlayGameScene::draw()
{
    _buttonManager.drawButtons();
    this->_windowManager->set3DMode(_cam);
    _map.draw();
    for (auto it : _players) {
        it->draw();
    }
    _cam.endMode();
}
