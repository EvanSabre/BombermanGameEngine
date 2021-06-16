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

MainMenuScene::MainMenuScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, const std::shared_ptr<gameEngine::scenes::SceneInfo> &info)
: AScene(windowManager, info)
{
}

MainMenuScene::~MainMenuScene()
{
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

    gameEngine::encapsulation::BText strText("PLAY", Vector<float>(middle2._x + 110, middle2._y + 10), WHITE, 30);
    gameEngine::encapsulation::BFont fontPlay;
    fontPlay.loadFromFile("./assets/Fonts/Pacifico-Regular.ttf");
    strText.setFont(fontPlay);
    std::shared_ptr<gameEngine::encapsulation::Button> button =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(300, 50), middle2, strText, DARKGRAY);

    middle2._y += middle2._y / 2;
    gameEngine::encapsulation::BText settingText("SETTINGS", Vector<float>(middle2._x + 70, middle2._y + 10), WHITE, 30);
    gameEngine::encapsulation::BFont fontSetting;
    fontSetting.loadFromFile("./assets/Fonts/Pacifico-Regular.ttf");
    settingText.setFont(fontSetting);
    std::shared_ptr<gameEngine::encapsulation::Button> buttonSettings =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(300, 50), middle2, settingText, DARKGRAY);

    middle2._y += middle2._y / 2;
    gameEngine::encapsulation::BText quitText("QUIT", Vector<float>(middle2._x + 115, middle2._y + 10), WHITE, 30);
    gameEngine::encapsulation::BFont fontQuit;
    fontQuit.loadFromFile("./assets/Fonts/Pacifico-Regular.ttf");
    quitText.setFont(fontQuit);
    std::shared_ptr<gameEngine::encapsulation::Button> buttonQuit =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(300, 50), middle2, quitText, DARKGRAY);

    _buttonManager.pushButton(button);
    _buttonManager.pushButton(buttonSettings);
    _buttonManager.pushButton(buttonQuit);
}

std::string MainMenuScene::update()
{
    _buttonManager.updateButtons();
    if (_buttonManager.isButtonClicked("PLAY")) {
        std::cout << "Clicked play button\n";
        return "play";
    }
    return "";
}

void MainMenuScene::draw()
{
    _background.draw();
    _buttonManager.drawButtons();
    _title->draw();
}
