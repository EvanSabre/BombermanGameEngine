/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** ChooseProfileScene
*/

#include "ChooseProfileScene.hpp"

using namespace game::scenes;
#define BACKGROUND_BUTTON "./assets/Backgrounds/SupernovaBG.png"

ChooseProfileScene::ChooseProfileScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, std::shared_ptr<game::managers::GameManager> &info) :
AScene(windowManager, info)
{
}

ChooseProfileScene::~ChooseProfileScene()
{
}

void ChooseProfileScene::start()
{
    Vector<float> size(WINDOW_X / 2, WINDOW_Y / 1.5);
    Vector<float> pos(WINDOW_X / 4, WINDOW_Y / 7);

    _background = std::make_unique<IMAGE>(BACKGROUND_BUTTON);
    std::vector<std::shared_ptr<gameEngine::encapsulation::ADrawable>> profileContent =
    {
        std::make_shared<TEXT>("1", size, BLACK, 40),
        std::make_shared<TEXT>("2", size, BLACK, 40),
        std::make_shared<TEXT>("3", size, BLACK, 40),
        std::make_shared<TEXT>("4", size, BLACK, 40),
    };

    _profileSelector = std::make_unique<SELECTOR>("Choose a profile", profileContent, Vector<float>(pos._x * 1.0, pos._y * 1.5), Vector<float>(size._x, size._y * 0.3), 30, GRAY);
    std::shared_ptr<BUTTON> backButton = std::make_shared<BUTTON>(Vector<float>(size._x * 0.2, size._y * 0.2),
                                            Vector<float>(WINDOW_X * 0.1, WINDOW_Y * 0.8),
                                            TEXT("Back"),
                                            BLUE,
                                            WHITE,
                                            BACKGROUND_BUTTON);
    std::shared_ptr<BUTTON> playButton = std::make_shared<BUTTON>(Vector<float>(size._x * 0.2, size._y * 0.2),
                                            Vector<float>(WINDOW_X * 0.8, WINDOW_Y * 0.8),
                                            TEXT("Play"),
                                            BLUE,
                                            WHITE,
                                            BACKGROUND_BUTTON);
    playButton->setCallback([](std::shared_ptr<game::managers::GameManager> info) { info->setCurrentScene("play");}, _info);
    backButton->setCallback([](std::shared_ptr<game::managers::GameManager> info) { info->setCurrentScene("menu");}, _info);
    _buttonManager.pushButton(backButton);
    _buttonManager.pushButton(playButton);
    _ProfilesIndication = TEXT("",
                              Vector<float>(pos._x + size._x * 0.5, pos._y + size._y * 0.9),
                              WHITE,
                              30);
}

void ChooseProfileScene::update()
{
    if (!_windowManager->isRunning()) {
        _info->setQuit(true);
    }
    _buttonManager.updateButtons();
    _profileSelector->update();

    if (_buttonManager.isButtonClicked("Play")) {
        return;
    }
    std::string nb_entity = std::to_string(std::atoi(_profileSelector->getCurrentContent()->getContent().c_str()));
    if (std::atoi(nb_entity.c_str()) > 4 || std::atoi(nb_entity.c_str()) < 1)
        _ProfilesIndication.setColor(RED);
    else
        _ProfilesIndication.setColor(WHITE);
    //_ProfilesIndication.setStr(nb_entity + "/ 4 profiles maximum");
    return;
}

void ChooseProfileScene::draw()
{
    _background->draw();
    _profileSelector->draw();
    _buttonManager.drawButtons();
    _ProfilesIndication.draw();
}