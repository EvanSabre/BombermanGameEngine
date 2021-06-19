/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** SettingsScene
*/

#include "SettingsScene.hpp"

using namespace game::scenes;

static const std::array<gameEngine::key_e, 5> gamePadKeys = {
    gameEngine::GAMEPAD_BUTTON_LEFT_FACE_UP,
    gameEngine::GAMEPAD_BUTTON_LEFT_FACE_DOWN,
    gameEngine::GAMEPAD_BUTTON_LEFT_FACE_RIGHT,
    gameEngine::GAMEPAD_BUTTON_LEFT_FACE_LEFT,
    gameEngine::GAMEPAD_BUTTON_RIGHT_FACE_LEFT
};

SettingsScene::SettingsScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, std::shared_ptr<game::managers::GameManager> &info)
: AScene(windowManager, info)
{
    _audio = std::make_shared<gameEngine::managers::AudioManager>();
    _audio->loadMusicStreamFromFile("./assets/All/Music/Settings.mp3");
    _audio->loadSoundFromFile("./assets/All/Sound/Button.wav", "button");
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
    _title = std::make_shared<gameEngine::encapsulation::BSdf>("SETTINGS", 100, WHITE, Vector3T<float>(middle._x - 280, 60, 0));

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
    gameEngine::encapsulation::BText quitText("Back to Menu", Vector<float>(40, 1010), WHITE, 30);
    quitText.setFont(_font);
    std::shared_ptr<gameEngine::encapsulation::Button> buttonQuit =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(250, 50), Vector<float>(20, 1000), quitText, DARKGRAY, WHITE, PLAY_BUTTON);
    // buttonQuit->setCallback([](std::shared_ptr<game::managers::GameManager> info) { info->setCurrentScene("menu"); }, _info);

    //keybindings
    _keybindings = std::make_shared<gameEngine::encapsulation::BText>("Key Bindings", Vector<float>(middle._x + 400, middle._y - 300), WHITE, 60);

    _left = std::make_shared<gameEngine::encapsulation::BText>("Move Left", Vector<float>(middle._x + 300, middle._y - 150), WHITE, 30);
    gameEngine::encapsulation::BText inputLeftText("a", Vector<float>(middle._x + 800, middle._y - 170), WHITE, 20);
    inputLeftText.setFont(_font);
    std::shared_ptr<gameEngine::object::InputButton> buttonLeft =
    std::make_shared<gameEngine::object::InputButton>(Vector<float>(100, 50), Vector<float>(middle._x + 800, middle._y - 150), 1, inputLeftText, DARKGRAY, true);

    _right = std::make_shared<gameEngine::encapsulation::BText>("Move Right", Vector<float>(middle._x + 300, middle._y - 50), WHITE, 30);
    gameEngine::encapsulation::BText inputRightText("d", Vector<float>(middle._x + 800, middle._y - 60), WHITE, 20);
    inputRightText.setFont(_font);
    std::shared_ptr<gameEngine::object::InputButton> buttonRight =
    std::make_shared<gameEngine::object::InputButton>(Vector<float>(100, 50), Vector<float>(middle._x + 800, middle._y - 50), 1, inputRightText, DARKGRAY, true);

    _up = std::make_shared<gameEngine::encapsulation::BText>("Move Up", Vector<float>(middle._x + 300, middle._y + 50), WHITE, 30);
    gameEngine::encapsulation::BText inputUpText("w", Vector<float>(middle._x + 800, middle._y + 70), WHITE, 20);
    inputUpText.setFont(_font);
    std::shared_ptr<gameEngine::object::InputButton> buttonUp =
    std::make_shared<gameEngine::object::InputButton>(Vector<float>(100, 50), Vector<float>(middle._x + 800, middle._y + 50), 1, inputUpText, DARKGRAY, true);

    _down = std::make_shared<gameEngine::encapsulation::BText>("Move Down", Vector<float>(middle._x + 300, middle._y + 150), WHITE, 30);
    gameEngine::encapsulation::BText inputDownText("s", Vector<float>(middle._x + 800, middle._y + 170), WHITE, 20);
    inputDownText.setFont(_font);
    std::shared_ptr<gameEngine::object::InputButton> buttonDown =
    std::make_shared<gameEngine::object::InputButton>(Vector<float>(100, 50), Vector<float>(middle._x + 800, middle._y + 150), 1, inputDownText, DARKGRAY, true);

    _drop = std::make_shared<gameEngine::encapsulation::BText>("Drop", Vector<float>(middle._x + 300, middle._y + 250), WHITE, 30);
    gameEngine::encapsulation::BText inputDropText("l", Vector<float>(middle._x + 800, middle._y + 270), WHITE, 20);
    inputDropText.setFont(_font);
    std::shared_ptr<gameEngine::object::InputButton> buttonDrop =
    std::make_shared<gameEngine::object::InputButton>(Vector<float>(100, 50), Vector<float>(middle._x + 800, middle._y + 250), 1, inputDropText, DARKGRAY, true);

    //save keybindings
    _saveButtonText = gameEngine::encapsulation::BText("Save", Vector<float>(1730, 1010), BLACK, 30);
    _saveButtonText.setFont(_font);
    std::shared_ptr<gameEngine::encapsulation::Button> buttonSave =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(150, 50), Vector<float>(1700, 1000), _saveButtonText, DARKGRAY, WHITE, PLAY_BUTTON);

    _buttonManager.pushButton(buttonQuit);
    _inputManager.pushButton(buttonUp);
    _inputManager.pushButton(buttonDown);
    _inputManager.pushButton(buttonRight);
    _inputManager.pushButton(buttonLeft);
    _inputManager.pushButton(buttonDrop);

    _buttonManager.pushButton(buttonSave);
    //_buttonManager.setEnabledButton("Save", false);
    // _keybindings->setFont(_font);
    // _left->setFont(_font);
    // _right->setFont(_font);
    // _up->setFont(_font);
    // _down->setFont(_font);
    // _pick->setFont(_font);
    // _drop->setFont(_font);
}

void toUpper(std::string &str)
{
    std::for_each(str.begin(), str.end(), [](char &c) {
        c = ::toupper(c);
    });
}

void SettingsScene::setKeyMap()
{
    std::pair<gameEngine::key_e, gameEngine::key_e> pair;
    std::pair<game::Event, std::pair<gameEngine::key_e, gameEngine::key_e>> fullPair;
    int i = 1;
    std::string tmp;

    for (auto it : _inputManager.getCurrentButtons()) {
        fullPair.first = (game::Event)i;
        tmp = it->getContent().getStr();
        toUpper(tmp);
        pair.first = (gameEngine::key_e)(tmp.c_str()[0]);
        pair.second = gamePadKeys.at(i - 1);
        fullPair.second = pair;
        _keyMap.insert(fullPair);
        i++;
    }
}

void SettingsScene::update()
{
    bool canSave = true;

    _buttonManager.updateButtons();
    _inputManager.updateButtons();
    for (auto it : _inputManager.getCurrentButtons()) {
        if (it->getContent().getStr().empty()) {
            canSave = false;
            it->setColor(RED);
        } else
            it->setColor(DARKGRAY);
    }
    if (canSave)
        _buttonManager.setEnabledButton("Save", true);
    else
        _buttonManager.setEnabledButton("Save", false);
    if (_buttonManager.isButtonClicked("Save")) {
        setKeyMap();
        _audio->playSound("button");
        _info->_inputManager->setKeymap(_keyMap);
    }
    _soundSelector->update();
    _musicSelector->update();
    _info->setMusicVolume(std::atof(_musicSelector->getCurrentContent()->getContent().c_str()));
    _info->setSoundVolume(std::atof(_soundSelector->getCurrentContent()->getContent().c_str()));
    _audio->setMusicVolume(_info->getMusicVolume() / 100);
    _audio->setSoundVolume(_info->getSoundVolume() / 100);
    if (_buttonManager.isButtonClicked("Back to Menu")) {
        _audio->playSound("button");
        sleep(1);
        _info->setCurrentScene("menu");
    }
    _audio->updateMusicStream();
}

void SettingsScene::draw()
{
    _background.draw();
    _title->draw();
    _keybindings->draw();
    _left->draw();
    _right->draw();
    _up->draw();
    _down->draw();
    _drop->draw();
    _inputManager.drawButtons();
    _buttonManager.drawButtons();
    _soundSelector->draw();
    _musicSelector->draw();
}
