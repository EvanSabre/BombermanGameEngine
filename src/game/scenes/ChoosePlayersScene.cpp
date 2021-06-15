/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** ChoosePlayersScene
*/

#include "ChoosePlayersScene.hpp"
#include "Button.hpp"
#include "InputButton.hpp"

using namespace game::scenes;


ChoosePlayersScene::ChoosePlayersScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, const std::shared_ptr<gameEngine::scenes::SceneInfo> &info) :
AScene(windowManager, info)
{
}

ChoosePlayersScene::~ChoosePlayersScene()
{
}

void ChoosePlayersScene::start()
{
    Vector<float> size(WINDOW_X / 2, WINDOW_Y / 1.5);
    Vector<float> pos(WINDOW_X / 4, WINDOW_Y / 7);
    //Vector<float> pos(WINDOW_X);

    _Mainrect = std::make_shared<RECTANGLE>(size, pos, RED);
    std::vector<std::shared_ptr<gameEngine::encapsulation::ADrawable>> contents;
    _playerSelector = std::make_shared<SELECTOR>("Choose a number of players", contents, Vector<float>(size._x, size._y * 0.5), Vector<float>(pos._x * 0.5, pos._y * 0.5), BLUE);
    _botSelector = std::make_shared<SELECTOR>("Choose a number of bots", contents, size, pos, YELLOW);
    //std::shared_ptr<gameEngine::encapsulation::BTexture2D> text = std::make_shared<gameEngine::encapsulation::BTexture2D>();

    //rect->draw();
    // text->loadFromImgRelRect(PLAY_BUTTON, size);
    // text->setPos(Vector<int>(middle._x, middle._y));

    //std::shared_ptr<gameEngine::object::InputButton> input =
    //std::make_shared<gameEngine::object::InputButton>(size, middle1, gameEngine::encapsulation::BText("Input Name"), LIGHTGRAY, RED);

    //gameEngine::encapsulation::BText strText("PLAY", Vector<float>(middle2._x + size._x / 2, middle2._y), WHITE, 30);
    //strText.setTextPosition(Vector<float>(middle2._x + size._x / 2 - strText.getTextSize(), middle2._y));
    //std::shared_ptr<gameEngine::encapsulation::Button> button =
    //std::make_shared<gameEngine::encapsulation::Button>(size, middle2, strText, LIGHTGRAY);
    //_buttonManager.pushButton(button);
    //_buttonManager.pushButton(input);
}

std::string ChoosePlayersScene::update()
{
    _buttonManager.updateButtons();
    _botSelector->update();
    _playerSelector->update();
    if (_buttonManager.isButtonClicked("PLAY")) {
        std::cout << "Clicked play button\n";
        return "play";
    }
    return "";
}

void ChoosePlayersScene::draw()
{
    _Mainrect->draw();
    _botSelector->draw();
    _playerSelector->draw();
    //_buttonManager.drawButtons();
}
