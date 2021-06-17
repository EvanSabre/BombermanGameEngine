/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** SettingsScene
*/

#include "SettingsScene.hpp"

using namespace game::scenes;

#define VOLUME_BUTTON "./assets/Backgrounds/button_background1.png"

SettingsScene::SettingsScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, std::shared_ptr<game::managers::GameManager> &info)
: AScene(windowManager, info)
{
    _audio.loadMusicStreamFromFile("./assets/All/Music/Menu.mp3");
    _audio.loadSoundFromFile("./assets/All/Music/Button.wav");
}

SettingsScene::~SettingsScene()
{
}

void SettingsScene::switchScene(std::shared_ptr<game::managers::GameManager> info)
{
    info->setCurrentScene("menu");
}

void SettingsScene::start()
{
    Vector<float> size(300, 200);
    Vector<float> middle1(_windowManager->getWindowSize()._x / 3 - size._x / 2, _windowManager->getWindowSize()._y / 3 - size._y / 2);
    Vector<float> middle2(_windowManager->getWindowSize()._x / 3 - size._x / 2 + size._x, _windowManager->getWindowSize()._y / 3 - size._y / 2);

    _audio.setMusicVolume(1.0); //1.0 is max level
    _audio.playMusic();

    _background.loadFromFile("./assets/Backgrounds/SupernovaBG.png");
    _title = std::make_shared<gameEngine::encapsulation::BSdf>("SETTINGS", 120, WHITE, Vector3T<float>(middle1._x + 200, 60, 0));

    gameEngine::encapsulation::BText musicText("Music Volume", Vector<float>(middle2._x + 20, middle2._y + 10), WHITE, 30);
    gameEngine::encapsulation::BFont fontMusic;
    fontMusic.loadFromFile("./assets/Fonts/Pacifico-Regular.ttf");
    musicText.setFont(fontMusic);
    std::shared_ptr<gameEngine::encapsulation::Button> buttonMusic =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(300, 50), middle2, musicText, DARKGRAY, RED);


    middle2._y += middle2._y / 2;
    gameEngine::encapsulation::BText soundText("Sound Volume", Vector<float>(middle2._x + 20, middle2._y + 10), WHITE, 30);
    gameEngine::encapsulation::BFont fontSound;
    fontSound.loadFromFile("./assets/Fonts/Pacifico-Regular.ttf");
    soundText.setFont(fontSound);
    std::shared_ptr<gameEngine::encapsulation::Button> buttonSound =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(300, 50), middle2, soundText, DARKGRAY);

    middle2._y += middle2._y / 2;
    gameEngine::encapsulation::BText KeyText("Key Bindings", Vector<float>(middle2._x + 20, middle2._y + 10), WHITE, 30);
    gameEngine::encapsulation::BFont fontKey;
    fontKey.loadFromFile("./assets/Fonts/Pacifico-Regular.ttf");
    KeyText.setFont(fontKey);
    std::shared_ptr<gameEngine::encapsulation::Button> buttonKeys =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(300, 50), middle2, KeyText, DARKGRAY);

    middle2._y += middle2._y / 2;
    gameEngine::encapsulation::BText quitText("Back to Menu", Vector<float>(middle2._x + 20, middle2._y + 10), WHITE, 30);
    gameEngine::encapsulation::BFont fontQuit;
    fontQuit.loadFromFile("./assets/Fonts/Pacifico-Regular.ttf");
    quitText.setFont(fontQuit);
    std::shared_ptr<gameEngine::encapsulation::Button> buttonQuit =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(300, 50), middle2, quitText, DARKGRAY);

    buttonQuit->setCallback([](std::shared_ptr<game::managers::GameManager> info) { info->setCurrentScene("menu"); }, _info);
    _buttonManager.pushButton(buttonMusic);
    _buttonManager.pushButton(buttonSound);
    _buttonManager.pushButton(buttonKeys);
    _buttonManager.pushButton(buttonQuit);
}

void SettingsScene::update()
{
    _buttonManager.updateButtons();
    _audio.updateMusicStream();
}

void SettingsScene::draw()
{
    _background.draw();
    _buttonManager.drawButtons();
    _title->draw();
}
