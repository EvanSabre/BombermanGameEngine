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
#define BACKGROUND_BUTTON "./assets/Backgrounds/SupernovaBG.png"

ChoosePlayersScene::~ChoosePlayersScene()
{
}

ChoosePlayersScene::ChoosePlayersScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, std::shared_ptr<game::managers::GameManager> &info) :
AScene(windowManager, info)
{
}

void ChoosePlayersScene::start()
{
    Vector<float> size(WINDOW_X / 2, WINDOW_Y / 1.5);
    Vector<float> pos(WINDOW_X / 4, WINDOW_Y / 7);

    _background = std::make_unique<IMAGE>(BACKGROUND_BUTTON);
    std::vector<std::shared_ptr<gameEngine::encapsulation::ADrawable>> playerContent =
    {
        std::make_shared<TEXT>("1", size, BLACK, 40),
        std::make_shared<TEXT>("2", size, BLACK, 40),
        std::make_shared<TEXT>("3", size, BLACK, 40),
        std::make_shared<TEXT>("4", size, BLACK, 40),
    };
    std::vector<std::shared_ptr<gameEngine::encapsulation::ADrawable>> botContent =
    {
        std::make_shared<TEXT>("1", size, BLACK, 40),
        std::make_shared<TEXT>("2", size, BLACK, 40),
        std::make_shared<TEXT>("3", size, BLACK, 40),
        std::make_shared<TEXT>("4", size, BLACK, 40),
    };
    _playerSelector = std::make_unique<SELECTOR>("Choose a number of players", playerContent, Vector<float>(pos._x * 1.0, pos._y * 1.5), Vector<float>(size._x, size._y * 0.3), 20, YELLOW);
    _botSelector = std::make_unique<SELECTOR>("Choose a number of bots", botContent, Vector<float>(pos._x * 1.0, pos._y * 3.5), Vector<float>(size._x, size._y * 0.3), 20, GREEN);
    std::shared_ptr<BUTTON> backButton = std::make_shared<BUTTON>(Vector<float>(size._x * 0.2, size._y * 0.2),
                                            Vector<float>(WINDOW_X * 0.8, WINDOW_Y * 0.8),
                                            TEXT("Back"),
                                            BLUE,
                                            WHITE,
                                            BACKGROUND_BUTTON);
    std::shared_ptr<BUTTON> playButton = std::make_shared<BUTTON>(Vector<float>(size._x * 0.2, size._y * 0.2),
                                            Vector<float>(WINDOW_X * 0.1, WINDOW_Y * 0.8),
                                            TEXT("Play"),
                                            BLUE,
                                            WHITE,
                                            BACKGROUND_BUTTON);
    playButton->setCallback([](std::shared_ptr<game::managers::GameManager> info) { info->setCurrentScene("play");}, _info);
    backButton->setCallback([](std::shared_ptr<game::managers::GameManager> info) { info->setCurrentScene("menu");}, _info);
    _buttonManager.pushButton(backButton);
    _buttonManager.pushButton(playButton);
    _PlayersIndication = TEXT("",
                              Vector<float>(pos._x + size._x * 0.5, pos._y + size._y * 0.9),
                              WHITE,
                              30);
}

void ChoosePlayersScene::update()
{
    _buttonManager.updateButtons();
    _botSelector->update();
    _playerSelector->update();

    if (_buttonManager.isButtonClicked("Play")) {
        std::cout << "Clicked play button\n";
        return;
    }
    std::string nb_entity = std::to_string(
        std::atoi(_botSelector->getCurrentContent()->getContent().c_str()) +
        std::atoi(_playerSelector->getCurrentContent()->getContent().c_str()));
    _PlayersIndication.setStr(nb_entity + "/ 4 Players maximum");
    //TODO::activate if Enabled
    return;
}

void ChoosePlayersScene::draw()
{
    _background->draw();
    _playerSelector->draw();
    _botSelector->draw();
    _buttonManager.drawButtons();
    _PlayersIndication.draw();
}


// * Callbacks