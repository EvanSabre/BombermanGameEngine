/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** MainMenuScene
*/

#include "MainMenuScene.hpp"
#include "Vector.hpp"

using namespace game::scenes;

#define WIN_HEIGHT 450
#define WIN_WIDTH 800

MainMenuScene::MainMenuScene()
{
}

MainMenuScene::~MainMenuScene()
{
    //_windowManager.deleteWindow();
}

void MainMenuScene::start()
{
    _windowManager.createWindow("MainMenu", {WIN_WIDTH, WIN_HEIGHT});
    gameEngine::encapsulation::BTexture2D text("./assets/button_test.png");
    Vector<float> rect_pos(WIN_WIDTH/2 - text.getSize()._x / 2, WIN_HEIGHT/2 - text.getSize()._y/2);
    gameEngine::encapsulation::BRectangle rect(Vector<float>(text.getSize()._x, text.getSize()._y), rect_pos, gameEngine::encapsulation::BColor(245, 245, 245, 255));
    std::shared_ptr<gameEngine::encapsulation::Button> button = std::make_shared<gameEngine::encapsulation::Button>(text, rect, gameEngine::encapsulation::BText("HELP", {rect_pos._x, rect_pos._y}, BLACK, 40));
    //std::shared_ptr<gameEngine::encapsulation::Button> button1 = std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(650, 400), Vector<float>(100, 100), BText("HELP", Vector<int>(50, 50)), BLACK, "./assets/button_test.png");
    _buttonManager.pushButton(button);
    //_buttonManager.pushButton(button1);
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
