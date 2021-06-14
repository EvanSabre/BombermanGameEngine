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

MainMenuScene::MainMenuScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, const gameEngine::scenes::SceneInfo &info)
: AScene(windowManager, info)
{
}

MainMenuScene::~MainMenuScene()
{
}

void MainMenuScene::start()
{
    Vector<float> size(300, 200);
    Vector<float> middle(_windowManager->getWindowSize()._x/3 - size._x / 2, _windowManager->getWindowSize()._y/3 - size._y / 2);

    // std::shared_ptr<gameEngine::encapsulation::BRectangle> rect = std::make_shared<gameEngine::encapsulation::BRectangle>(size, middle);
    // std::shared_ptr<gameEngine::encapsulation::BTexture2D> text = std::make_shared<gameEngine::encapsulation::BTexture2D>();

    // text->loadFromImgRelRect(PLAY_BUTTON, size);
    // text->setPos(Vector<int>(middle._x, middle._y));

    std::shared_ptr<gameEngine::object::InputButton> input =
    std::make_shared<gameEngine::object::InputButton>(size, middle, gameEngine::encapsulation::BText("Input Name"), LIGHTGRAY, RED);

    std::shared_ptr<gameEngine::encapsulation::Button> button =
    std::make_shared<gameEngine::encapsulation::Button>(size, middle, gameEngine::encapsulation::BText("PLAY"), LIGHTGRAY);
    // std::shared_ptr<gameEngine::encapsulation::Button> button =
    // std::make_shared<gameEngine::encapsulation::Button>(text, rect, std::make_shared<gameEngine::encapsulation::BText>("PLAY"));

    _parallax.initParallax(BACKGROUND, MIDGROUND, FOREGROUND);
    _buttonManager.pushButton(button);
    _buttonManager.pushButton(input);
}

std::string MainMenuScene::update()
{
    _parallax.calculateParallax(0.1f, 0.5f, 1.0f);
    _buttonManager.updateButtons();
    if (_buttonManager.isButtonClicked("PLAY")) {
        std::cout << "Clicked play button\n";
        return "play";
    }
    return "";
}

void MainMenuScene::draw()
{
    _parallax.drawParallax();
    _buttonManager.drawButtons();
}
