/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** MainMenuScene
*/

#include "MainMenuScene.hpp"
#include "InputButton.hpp"
#include "Vector.hpp"

using namespace game::scenes;

#define BACKGROUND "./resources/backgrounds/cyberpunk_street_background.png"
#define MIDGROUND "./resources/backgrounds/cyberpunk_street_midground.png"
#define FOREGROUND "./resources/backgrounds/cyberpunk_street_foreground.png"
#define PLAY_BUTTON "./resources/UI-Elements/PlayButton.png"

MainMenuScene::MainMenuScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, const std::shared_ptr<game::managers::GameManager> &info)
: AScene(windowManager, info)
{
}

MainMenuScene::~MainMenuScene()
{
}

void MainMenuScene::switchScene(std::shared_ptr<game::managers::GameManager> info)
{
    info->setCurrentScene("play");
}

void MainMenuScene::start()
{
    Vector<float> size(300, 200);
    Vector<float> middle1(_windowManager->getWindowSize()._x/3 - size._x / 2, _windowManager->getWindowSize()._y/3 - size._y / 2);
    Vector<float> middle2(_windowManager->getWindowSize()._x/3 - size._x / 2 + size._x, _windowManager->getWindowSize()._y/3 - size._y / 2);

    _background.loadFromFile("./assets/Backgrounds/SupernovaBG.png");
    _title = std::make_shared<gameEngine::encapsulation::BText>("BomberVerse", Vector<float>(middle1._x - 60, 60), WHITE, 120);
    gameEngine::encapsulation::BFont font;
    font.loadFromFile("./assets/Fonts/TarrgetLaserRegular-4OE9.otf");
    _title->setFont(font);
    _title->setSpacing(0);
    gameEngine::encapsulation::BText strText("PLAY", Vector<float>(middle2._x, middle2._y), WHITE, 30);
    std::shared_ptr<gameEngine::encapsulation::Button> button =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(300, 50), middle2, strText, LIGHTGRAY);

    button->setCallback([](std::shared_ptr<game::managers::GameManager> info) { info->setCurrentScene("play"); }, _info);

    middle2._y += middle2._y / 2;
    gameEngine::encapsulation::BText settingText("SETTINGS", Vector<float>(middle2._x, middle2._y), WHITE, 30);
    std::shared_ptr<gameEngine::encapsulation::Button> buttonSettings =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(300, 50), middle2, settingText, LIGHTGRAY);

    middle2._y += middle2._y / 2;
    gameEngine::encapsulation::BText quitText("QUIT", Vector<float>(middle2._x, middle2._y), WHITE, 30);
    std::shared_ptr<gameEngine::encapsulation::Button> buttonQuit =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(300, 50), middle2, quitText, LIGHTGRAY);

    buttonQuit->setCallback([](std::shared_ptr<game::managers::GameManager> info) { info->setQuit(true); }, _info);
    _buttonManager.pushButton(button);
    _buttonManager.pushButton(buttonSettings);
    _buttonManager.pushButton(buttonQuit);
}

void MainMenuScene::update()
{
    _buttonManager.updateButtons();
}

void MainMenuScene::draw()
{
    _background.draw();
    _buttonManager.drawButtons();
    _title->draw();
}
