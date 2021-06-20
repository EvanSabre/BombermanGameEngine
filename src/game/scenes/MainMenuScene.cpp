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

MainMenuScene::MainMenuScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, std::shared_ptr<game::managers::GameManager> &info)
: AScene(windowManager, info)
{
    _audio = std::make_shared<gameEngine::managers::AudioManager>();
    _audio->loadMusicStreamFromFile("./assets/All/Music/Menu.mp3");
    _audio->loadSoundFromFile("./assets/All/Sound/Button.wav", "button");
    _audio->setMusicVolume(_info->getMusicVolume() / 100);
    _audio->setSoundVolume(_info->getSoundVolume() / 100);
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

    _audio->playMusic();

    _background.loadFromFile("./assets/Backgrounds/menu_background.png");
    _title = std::make_shared<gameEngine::encapsulation::BSdf>("BomberVerse", 120, DARKBLUE, Vector3T<float>(middle1._x + 40, 60, 0));

    middle2._x += 80;
    gameEngine::encapsulation::BText strText("PLAY", Vector<float>(middle2._x + 60, middle2._y + 15), WHITE, 40);
    std::shared_ptr<gameEngine::encapsulation::Button> button =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(250, 70), Vector<float>(middle2._x, middle2._y), strText, DARKGRAY, WHITE, PLAY_BUTTON);

    gameEngine::encapsulation::BText loadText("LOAD", Vector<float>(middle2._x + 60, middle2._y + 115), WHITE, 40);
    std::shared_ptr<gameEngine::encapsulation::Button> buttonLoads =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(250, 70), Vector<float>(middle2._x, middle2._y + 100), loadText, DARKGRAY, WHITE, PLAY_BUTTON);
    middle2._y += 100;
    gameEngine::encapsulation::BText settingText("SETTINGS", Vector<float>(middle2._x + 15, middle2._y + 115), WHITE, 40);
    std::shared_ptr<gameEngine::encapsulation::Button> buttonSettings =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(250, 70), Vector<float>(middle2._x, middle2._y + 100), settingText, DARKGRAY, WHITE, PLAY_BUTTON);

    gameEngine::encapsulation::BText creditText("CREDITS", Vector<float>(middle2._x + 35, middle2._y + 215), WHITE, 40);
    std::shared_ptr<gameEngine::encapsulation::Button> buttonCredits =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(250, 70), Vector<float>(middle2._x, middle2._y + 200), creditText, DARKGRAY, WHITE, PLAY_BUTTON);

    gameEngine::encapsulation::BText quitText("QUIT", Vector<float>(middle2._x + 80, middle2._y + 515), WHITE, 40);
    std::shared_ptr<gameEngine::encapsulation::Button> buttonQuit =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(250, 70), Vector<float>(middle2._x, middle2._y + 500), quitText, DARKGRAY, WHITE, PLAY_BUTTON);

    buttonQuit->setCallback([](std::shared_ptr<game::managers::GameManager> info) { info->setQuit(true); }, _info);
    _buttonManager.pushButton(button);
    _buttonManager.pushButton(buttonLoads);
    _buttonManager.pushButton(buttonSettings);
    _buttonManager.pushButton(buttonCredits);
    _buttonManager.pushButton(buttonQuit);
}

void MainMenuScene::update()
{
    if (!_windowManager->isRunning())
        _info->setQuit(true);
    _buttonManager.updateButtons();
    if (_buttonManager.isButtonClicked("PLAY")) {
        _audio->stopMusic();
        _audio->playSound("button");
        //sleep(1);
        _info->setCurrentScene("choosePlayers");
    }
    if (_buttonManager.isButtonClicked("SETTINGS")) {
        _audio->stopMusic();
        _audio->playSound("button");
        //sleep(1);
        _info->setCurrentScene("settings");
    }
    if (_buttonManager.isButtonClicked("CREDITS")) {
        _audio->stopMusic();
        _audio->playSound("button");
        //sleep(1);
        _info->setCurrentScene("credits");
    }
    _audio->updateMusicStream();
}


void MainMenuScene::draw()
{
    _background.draw();
    _buttonManager.drawButtons();
    _title->draw();
}
