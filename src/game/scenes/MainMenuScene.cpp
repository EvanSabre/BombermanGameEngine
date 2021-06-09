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
    std::shared_ptr<gameEngine::encapsulation::Button> button =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(_windowManager->getWindowSize()._x/3, _windowManager->getWindowSize()._y/3), Vector<float>(_windowManager->getWindowSize()._x / 2, _windowManager->getWindowSize()._y / 2), gameEngine::encapsulation::BText("PLAY"));

    _parallax.initParallax(BACKGROUND, MIDGROUND, FOREGROUND);
    _buttonManager.pushButton(button);

    // gameEngine::encapsulation::BTexture2D text("./assets/button_test.png", gameEngine::encapsulation::BText("HELP", {0, 0}, BLACK, 40));
    // Vector<float> rect_pos(WIN_WIDTH/2 - text.getSize()._x / 2, WIN_HEIGHT/2 - text.getSize()._y/2);
    // gameEngine::encapsulation::BRectangle rect(Vector<float>(text.getSize()._x, text.getSize()._y), rect_pos, gameEngine::encapsulation::BColor(245, 245, 245, 255));
    // std::shared_ptr<gameEngine::encapsulation::Button> button = std::make_shared<gameEngine::encapsulation::Button>(text, rect, gameEngine::encapsulation::BText("HELP", {rect_pos._x, rect_pos._y}, BLACK, 40));
    // //std::shared_ptr<gameEngine::encapsulation::Button> button1 = std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(650, 400), Vector<float>(100, 100), BText("HELP", Vector<int>(50, 50)), BLACK, "./assets/button_test.png");
    // //_buttonManager.pushButton(button1);
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
