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


ChoosePlayersScene::ChoosePlayersScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, const std::shared_ptr<game::managers::GameManager> &info) :
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

    _Mainrect = std::make_shared<RECTANGLE>(size, pos, RED);
    std::vector<std::shared_ptr<gameEngine::encapsulation::ADrawable>> contents;
    _playerSelector = std::make_shared<SELECTOR>("Choose a number of players", contents, Vector<float>(pos._x * 1.0, pos._y * 1.5), Vector<float>(size._x, size._y * 0.3), 20, YELLOW);
    _botSelector = std::make_shared<SELECTOR>("Choose a number of bots", contents, Vector<float>(pos._x * 1.0, pos._y * 3.5), Vector<float>(size._x, size._y * 0.3), 20, GREEN);
}

void ChoosePlayersScene::update()
{
    _buttonManager.updateButtons();
    _botSelector->update();
    _playerSelector->update();
    if (_buttonManager.isButtonClicked("PLAY")) {
        std::cout << "Clicked play button\n";
        return;
    }
    return;
}

void ChoosePlayersScene::draw()
{
    _Mainrect->draw();
    _botSelector->draw();
    _playerSelector->draw();
    _buttonManager.drawButtons();
}
