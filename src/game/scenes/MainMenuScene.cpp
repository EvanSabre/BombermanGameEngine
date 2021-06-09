/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** MainMenuScene
*/

#include "MainMenuScene.hpp"
#include "Vector.hpp"

using namespace game::scenes;

#define BACKGROUND "./resources/backgrounds/cyberpunk_street_background.png"
#define MIDGROUND "./resources/backgrounds/cyberpunk_street_midground.png"
#define FOREGROUND "./resources/backgrounds/cyberpunk_street_foreground.png"
#define PLAY_BUTTON "./resources/UI-Elements/PlayButton.png"

MainMenuScene::MainMenuScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, const gameEngine::scenes::SceneInfo &info)
: AScene(windowManager, info)
{
}

MainMenuScene::~MainMenuScene()
{
}

void MainMenuScene::start()
{
    Vector<float> size(_windowManager->getWindowSize()._x/2,  _windowManager->getWindowSize()._y/2);
    Vector<float> middle(_windowManager->getWindowSize()._x/3 - size._x / 2, _windowManager->getWindowSize()._y/3 - size._y / 2);

    gameEngine::encapsulation::BRectangle rect(size, middle);
    gameEngine::encapsulation::BTexture2D text;

    text.loadFromImgRelRect(PLAY_BUTTON, rect);

    std::shared_ptr<gameEngine::encapsulation::Button> button =
    std::make_shared<gameEngine::encapsulation::Button>(text, rect, gameEngine::encapsulation::BText(""));

    _parallax.initParallax(BACKGROUND, MIDGROUND, FOREGROUND);
    _buttonManager.pushButton(button);
}

std::string MainMenuScene::update()
{
    _parallax.calculateParallax(0.1f, 0.5f, 1.0f);
    _buttonManager.updateButtons();
    if (_buttonManager.isButtonClicked("PLAY")) {
        std::cout << "Clicked play button\n";
        return "play";
    }
    _windowManager->BeginDraw();
    _parallax.drawParallax();
    _buttonManager.drawButtons();
    _windowManager->EndDraw();
    return "";
}
