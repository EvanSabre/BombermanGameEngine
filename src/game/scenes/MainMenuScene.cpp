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
    gameEngine::encapsulation::BTexture2D text("./assets/button_test.png");
    gameEngine::encapsulation::BRectangle rect(Vector<float>(100, 100), Vector<float>(100, 100));
    _buttonManager.createButton(text, rect, BText("Hello"));
}

void MainMenuScene::update()
{
    while(!WindowShouldClose()) {
        _buttonManager.drawButtons();
    }
}

extern "C" {
    gameEngine::interfaces::IScene *entryPoint() {
        return new MainMenuScene();
    };
}
