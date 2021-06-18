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
    _audio = std::make_shared<gameEngine::managers::AudioManager>();
    _audio->loadMusicStreamFromFile("./assets/All/Music/Settings.mp3");
    _audio->loadSoundFromFile("./assets/All/Sound/Bombdrop.wav");
    _audio->setMusicVolume(_info->getMusicVolume() / 100);
    _audio->setSoundVolume(_info->getSoundVolume() / 100);

    _background.loadFromFile("./assets/Backgrounds/settings_background.png");

    _font.loadFromFile("./assets/Fonts/Pacifico-Regular.ttf");
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
    Vector<float> middle(_windowManager->getWindowSize()._x / 2, _windowManager->getWindowSize()._y / 2);

    _audio->playMusic();
    //title
    _title = std::make_shared<gameEngine::encapsulation::BSdf>("SETTINGS", 120, WHITE, Vector3T<float>(middle._x - 200, 60, 0));

    //sound selector
    int currentSound = (int)_info->getSoundVolume();
    std::vector<std::shared_ptr<gameEngine::encapsulation::ADrawable>> soundCt =
        {
            std::make_shared<TEXT>(std::to_string(currentSound).c_str(), size, BLACK, 40),
            std::make_shared<TEXT>("0", size, BLACK, 40),
            std::make_shared<TEXT>("10", size, BLACK, 40),
            std::make_shared<TEXT>("20", size, BLACK, 40),
            std::make_shared<TEXT>("30", size, BLACK, 40),
            std::make_shared<TEXT>("40", size, BLACK, 40),
            std::make_shared<TEXT>("50", size, BLACK, 40),
            std::make_shared<TEXT>("60", size, BLACK, 40),
            std::make_shared<TEXT>("70", size, BLACK, 40),
            std::make_shared<TEXT>("80", size, BLACK, 40),
            std::make_shared<TEXT>("90", size, BLACK, 40),
            std::make_shared<TEXT>("100", size, BLACK, 40),
        };
    _soundSelector = std::make_unique<gameEngine::component::Selector>("Sound Volume", soundCt, Vector<float>(100,  middle._y - 200), Vector<float>(600, 150), 30, WHITE);

    //music selector
    int currentMusic = (int)_info->getMusicVolume();
    std::vector<std::shared_ptr<gameEngine::encapsulation::ADrawable>> musicCt =
        {
            std::make_shared<TEXT>(std::to_string(currentMusic).c_str(), size, BLACK, 40),
            std::make_shared<TEXT>("0", size, BLACK, 40),
            std::make_shared<TEXT>("10", size, BLACK, 40),
            std::make_shared<TEXT>("20", size, BLACK, 40),
            std::make_shared<TEXT>("30", size, BLACK, 40),
            std::make_shared<TEXT>("40", size, BLACK, 40),
            std::make_shared<TEXT>("50", size, BLACK, 40),
            std::make_shared<TEXT>("60", size, BLACK, 40),
            std::make_shared<TEXT>("70", size, BLACK, 40),
            std::make_shared<TEXT>("80", size, BLACK, 40),
            std::make_shared<TEXT>("90", size, BLACK, 40),
            std::make_shared<TEXT>("100", size, BLACK, 40),
        };
    _musicSelector = std::make_unique<gameEngine::component::Selector>("Music Volume", musicCt, Vector<float>(100,  middle._y + 50), Vector<float>(600, 150), 30, WHITE);

    //back to menu
    gameEngine::encapsulation::BText quitText("Back to Menu", Vector<float>(60, 1010), WHITE, 30);
    quitText.setFont(_font);
    std::shared_ptr<gameEngine::encapsulation::Button> buttonQuit =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(310, 50), Vector<float>(20, 1000), quitText, DARKGRAY);
    buttonQuit->setCallback([](std::shared_ptr<game::managers::GameManager> info) { info->setCurrentScene("menu"); }, _info);

    //keybindings
    _keybindings = std::make_shared<gameEngine::encapsulation::BText>("Key Bindings", Vector<float>(middle._x + 400, middle._y - 300), WHITE, 60);

    _left = std::make_shared<gameEngine::encapsulation::BText>("Move Left", Vector<float>(middle._x + 300, middle._y - 150), WHITE, 30);
    gameEngine::encapsulation::BText inputLeftText("A", Vector<float>(middle._x + 850, middle._y - 150), WHITE, 80);
    inputLeftText.setFont(_font);
    std::shared_ptr<gameEngine::object::InputButton> buttonLeft =
    std::make_shared<gameEngine::object::InputButton>(Vector<float>(100, 50), Vector<float>(middle._x + 800, middle._y - 150), 1, inputLeftText, DARKGRAY);

    _right = std::make_shared<gameEngine::encapsulation::BText>("Move Right", Vector<float>(middle._x + 300, middle._y - 50), WHITE, 30);
    gameEngine::encapsulation::BText inputRightText("D", Vector<float>(middle._x + 850, middle._y - 50), WHITE, 80);
    inputRightText.setFont(_font);
    std::shared_ptr<gameEngine::object::InputButton> buttonRight =
    std::make_shared<gameEngine::object::InputButton>(Vector<float>(100, 50), Vector<float>(middle._x + 800, middle._y - 50), 1, inputRightText, DARKGRAY);

    _up = std::make_shared<gameEngine::encapsulation::BText>("Move Up", Vector<float>(middle._x + 300, middle._y + 50), WHITE, 30);
    gameEngine::encapsulation::BText inputUpText("W", Vector<float>(middle._x + 850, middle._y + 50), WHITE, 80);
    inputUpText.setFont(_font);
    std::shared_ptr<gameEngine::object::InputButton> buttonUp =
    std::make_shared<gameEngine::object::InputButton>(Vector<float>(100, 50), Vector<float>(middle._x + 800, middle._y + 50), 1, inputUpText, DARKGRAY);

    _down = std::make_shared<gameEngine::encapsulation::BText>("Move Down", Vector<float>(middle._x + 300, middle._y + 150), WHITE, 30);
    gameEngine::encapsulation::BText inputDownText("S", Vector<float>(middle._x + 850, middle._y + 150), WHITE, 80);
    inputDownText.setFont(_font);
    std::shared_ptr<gameEngine::object::InputButton> buttonDown =
    std::make_shared<gameEngine::object::InputButton>(Vector<float>(100, 50), Vector<float>(middle._x + 800, middle._y + 150), 1, inputDownText, DARKGRAY);

    _pick = std::make_shared<gameEngine::encapsulation::BText>("Pick", Vector<float>(middle._x + 300, middle._y + 250), WHITE, 30);
    gameEngine::encapsulation::BText inputPickText("K", Vector<float>(middle._x + 850, middle._y + 250), WHITE, 80);
    inputPickText.setFont(_font);
    std::shared_ptr<gameEngine::object::InputButton> buttonPick =
    std::make_shared<gameEngine::object::InputButton>(Vector<float>(100, 50), Vector<float>(middle._x + 800, middle._y + 250), 1, inputPickText, DARKGRAY);

    _drop = std::make_shared<gameEngine::encapsulation::BText>("Drop", Vector<float>(middle._x + 300, middle._y + 350), WHITE, 30);
    gameEngine::encapsulation::BText inputDropText("L", Vector<float>(middle._x + 850, middle._y + 350), WHITE, 80);
    inputDropText.setFont(_font);
    std::shared_ptr<gameEngine::object::InputButton> buttonDrop =
    std::make_shared<gameEngine::object::InputButton>(Vector<float>(100, 50), Vector<float>(middle._x + 800, middle._y + 350), 1, inputDropText, DARKGRAY);

    //save keybindings
    _saveButtonText = gameEngine::encapsulation::BText("Save", Vector<float>(1730, 1010), BLACK, 30);
    _saveButtonText.setFont(_font);
    std::shared_ptr<gameEngine::encapsulation::Button> buttonSave =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(150, 50), Vector<float>(1700, 1000), _saveButtonText, DARKGRAY);
    // buttonQuit->setCallback([](std::shared_ptr<game::managers::GameManager> info) { info->setCurrentScene("menu"); }, _info);

    _buttonManager.pushButton(buttonQuit);
    _buttonManager.pushButton(buttonLeft);
    _buttonManager.pushButton(buttonRight);
    _buttonManager.pushButton(buttonUp);
    _buttonManager.pushButton(buttonDown);
    _buttonManager.pushButton(buttonPick);
    _buttonManager.pushButton(buttonDrop);
    _buttonManager.pushButton(buttonSave);
    // _keybindings->setFont(_font);
    // _left->setFont(_font);
    // _right->setFont(_font);
    // _up->setFont(_font);
    // _down->setFont(_font);
    // _pick->setFont(_font);
    // _drop->setFont(_font);
}

void SettingsScene::update()
{
    _buttonManager.updateButtons();

    _soundSelector->update();
    _musicSelector->update();
    _info->setMusicVolume(std::atof(_musicSelector->getCurrentContent()->getContent().c_str()));
    _info->setSoundVolume(std::atof(_soundSelector->getCurrentContent()->getContent().c_str()));
    _audio->setMusicVolume(_info->getMusicVolume() / 100);
    _audio->setSoundVolume(_info->getSoundVolume() / 100);
    _audio->updateMusicStream();
    // if (_buttonManager.isButtonClicked("Back to Menu")) {
    //     std::cout << "BBBBBUUUUUUUUUUUUUUUUUUUUUUUUU" << std::endl;
    //     _audio->playSound();
    //     _audio->playSound();
    //     _audio->playSound();
    //     _audio->playSound();
    //     _audio->playSound();
    //     _audio->playSound();
    //     _audio->playSound();
    //     _audio->playSound();
    //     _audio->playSound();
    //     _audio->playSound();
    // }
}

void SettingsScene::draw()
{
    _background.draw();
    _buttonManager.drawButtons();
    _title->draw();
    _keybindings->draw();
    _left->draw();
    _right->draw();
    _up->draw();
    _down->draw();
    _pick->draw();
    _drop->draw();
    _soundSelector->draw();
    _musicSelector->draw();
}
