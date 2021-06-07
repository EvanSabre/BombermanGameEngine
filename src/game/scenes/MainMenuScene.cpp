/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** MainMenuScene
*/

#include "MainMenuScene.hpp"
#include "Vector.hpp"

using namespace game::scenes;

MainMenuScene::MainMenuScene()
{
}

MainMenuScene::~MainMenuScene()
{
    //_windowManager.deleteWindow();
}

void MainMenuScene::start()
{
    _windowManager.createWindow("MainMenu", {800, 450});
    std::shared_ptr<gameEngine::encapsulation::Button> button = std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(100, 100), Vector<float>(100, 100), BText("HELP", Vector<int>(50, 50)), BLACK, "./assets/button_test.png");
    _buttonManager.pushButton(button);
}

void MainMenuScene::update()
{

    while(_windowManager.isRunning()) {
        _windowManager.BeginDraw();
        _buttonManager.drawButtons();
        _windowManager.setBackgroundColor(BColor(245, 245, 245, 255));
        _windowManager.EndDraw();
    }
}

extern "C" {
    gameEngine::interfaces::IScene *entryPoint() {
        return new MainMenuScene();
    };
}
