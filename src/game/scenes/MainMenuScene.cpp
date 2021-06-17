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
#define PLAY_BUTTON "./assets/Backgrounds/button_background1.png"

MainMenuScene::MainMenuScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, std::shared_ptr<game::managers::GameManager> &info)
: AScene(windowManager, info)
{
    _audio.loadMusicStreamFromFile("./assets/All/Music/Menu.mp3");
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

    _audio.setMusicVolume(1.0); //1.0 is max level
    _audio.playMusic();

    _background.loadFromFile("./assets/Backgrounds/SupernovaBG.png");
    _title = std::make_shared<gameEngine::encapsulation::BSdf>("BomberVerse", 120, RED, Vector3T<float>(middle1._x + 120, 60, 0));

    gameEngine::encapsulation::BText strText("PLAY", Vector<float>(middle2._x + 110, middle2._y + 10), WHITE, 30);
    gameEngine::encapsulation::BFont fontPlay;
    fontPlay.loadFromFile("./assets/Fonts/Pacifico-Regular.ttf");
    strText.setFont(fontPlay);
    std::shared_ptr<gameEngine::encapsulation::Button> button =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(310, 70), middle2, strText, DARKGRAY, RED, PLAY_BUTTON);

    button->setCallback([](std::shared_ptr<game::managers::GameManager> info) { info->setCurrentScene("choosePlayers"); }, _info);

    middle2._y += middle2._y / 2;
    gameEngine::encapsulation::BText settingText("SETTINGS", Vector<float>(middle2._x + 70, middle2._y + 10), WHITE, 30);
    gameEngine::encapsulation::BFont fontSetting;
    fontSetting.loadFromFile("./assets/Fonts/Pacifico-Regular.ttf");
    settingText.setFont(fontSetting);
    std::shared_ptr<gameEngine::encapsulation::Button> buttonSettings =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(300, 50), middle2, settingText, DARKGRAY);
    buttonSettings->setCallback([](std::shared_ptr<game::managers::GameManager> info) { info->setCurrentScene("settings"); }, _info);

    middle2._y += middle2._y / 2;
    gameEngine::encapsulation::BText quitText("QUIT", Vector<float>(middle2._x + 115, middle2._y + 10), WHITE, 30);
    gameEngine::encapsulation::BFont fontQuit;
    fontQuit.loadFromFile("./assets/Fonts/Pacifico-Regular.ttf");
    quitText.setFont(fontQuit);
    std::shared_ptr<gameEngine::encapsulation::Button> buttonQuit =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(300, 50), middle2, quitText, DARKGRAY);

    buttonQuit->setCallback([](std::shared_ptr<game::managers::GameManager> info) { info->setQuit(true); }, _info);
    _buttonManager.pushButton(button);
    _buttonManager.pushButton(buttonSettings);
    _buttonManager.pushButton(buttonQuit);
}

void MainMenuScene::update()
{
    if (!_windowManager->isRunning())
        _info->setQuit(true);
    _buttonManager.updateButtons();
    _audio.updateMusicStream();
}

#include "Character.hpp"

void MainMenuScene::draw()
{
   // game::objects::Character charac{"oui", "hello", "path", "model", "animation", "idle"};
    _gui.draw(2, Gui::BOTTOM_LEFT);
    // _background.draw();
    // _buttonManager.drawButtons();
    //_title->draw();
}
