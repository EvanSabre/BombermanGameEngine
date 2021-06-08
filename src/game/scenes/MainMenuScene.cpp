/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** MainMenuScene
*/

#include "MainMenuScene.hpp"
#include "Vector.hpp"

using namespace game::scenes;

#define WIN_HEIGHT 450
#define WIN_WIDTH 800
#define BACKGROUND "/home/pbachelin/Epitech/epitech_YEAR2/YEP-400/Indie_ressources/cyberpunk_street_background.png"
#define MIDGROUND "/home/pbachelin/Epitech/epitech_YEAR2/YEP-400/Indie_ressources/cyberpunk_street_midground.png"
#define FOREGROUND "/home/pbachelin/Epitech/epitech_YEAR2/YEP-400/Indie_ressources/cyberpunk_street_foreground.png"


MainMenuScene::MainMenuScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, const gameEngine::scenes::SceneInfo &info)
: AScene(windowManager)
{
}

MainMenuScene::~MainMenuScene()
{
}

void MainMenuScene::start()
{
    _parallax.initParallax(BACKGROUND, MIDGROUND, FOREGROUND);

    // gameEngine::encapsulation::BTexture2D text("./assets/button_test.png", gameEngine::encapsulation::BText("HELP", {0, 0}, BLACK, 40));
    // Vector<float> rect_pos(WIN_WIDTH/2 - text.getSize()._x / 2, WIN_HEIGHT/2 - text.getSize()._y/2);
    // gameEngine::encapsulation::BRectangle rect(Vector<float>(text.getSize()._x, text.getSize()._y), rect_pos, gameEngine::encapsulation::BColor(245, 245, 245, 255));
    // std::shared_ptr<gameEngine::encapsulation::Button> button = std::make_shared<gameEngine::encapsulation::Button>(text, rect, gameEngine::encapsulation::BText("HELP", {rect_pos._x, rect_pos._y}, BLACK, 40));
    // //std::shared_ptr<gameEngine::encapsulation::Button> button1 = std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(650, 400), Vector<float>(100, 100), BText("HELP", Vector<int>(50, 50)), BLACK, "./assets/button_test.png");
    // _buttonManager.pushButton(button);
    // //_buttonManager.pushButton(button1);
}

void MainMenuScene::update()
{
    while(_windowManager->isRunning()) {
        _parallax.calculateParallax(0.1f, 0.5f, 1.0f);
        _windowManager->BeginDraw();
        //_windowManager->setBackgroundColor(BColor(245, 245, 245, 255));
        _parallax.drawParallax();
        _windowManager->EndDraw();
    }
}
