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
    Vector<float> pos(WINDOW_X / 4, WINDOW_Y * 0.30);
    Vector<float> posbutton(WINDOW_X / 2.3, WINDOW_Y * 0.42);
    Vector<float> sizebutton(WINDOW_X / 8, WINDOW_Y / 10);

    _background = std::make_unique<IMAGE>(BACKGROUND_BUTTON);
    _zoneStat = std::make_unique<RECTANGLE>(size, pos, GRAY);

    // std::vector<std::shared_ptr<gameEngine::encapsulation::ADrawable>> profileKey =
    // {
    //     std::make_shared<TEXT>("1", size, BLACK, 40)
    // };

    std::vector<std::shared_ptr<gameEngine::encapsulation::ADrawable>> profileContent;

    //_info->_userManager->createUser("Evan");
    for (auto &user : _info->_userManager->getUsers()) {
        profileContent.push_back(std::make_shared<TEXT>(user->name, size, BLACK, 40));
    }
    _inputButton = std::make_unique<INPUT_BUTTON>(sizebutton, posbutton, TEXT("", size, BLACK, 40), RED, BLACK);
    profileContent.push_back(std::make_shared<TEXT>("", size, BLACK, 40));

    //_profileKeypad = std::make_unique<TEXT>("Keypad per user", profileKey, Vector<float>(pos._x * 1.0, pos._y * 3.5), Vector<float>(size._x, size._y * 0.3), 30, GRAY);
    _profileSelector = std::make_unique<SELECTOR>("Choose a profile", profileContent, Vector<float>(pos._x * 1.0, pos._y * 1.2), Vector<float>(size._x, size._y * 0.3), 30, GRAY);
    _profileSelector->setContentPos(Vector<float>(WINDOW_X / 2.1, WINDOW_Y / 2.3));
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
    _ProfilesIndicationGame = TEXT("Game Won: ", Vector<float>(pos._x + size._x * 0.1, pos._y + size._y * 0.45),
                              WHITE,
                              30);
    _ProfilesIndicationPlayed = TEXT("Played: ", Vector<float>(pos._x + size._x * 0.1, pos._y + size._y * 0.65),
                              WHITE,
                              30);
    _ProfilesIndicationKilled = TEXT("Killed: ", Vector<float>(pos._x + size._x * 0.1, pos._y + size._y * 0.85),
                              WHITE,
                              30);

    _nbContents = _profileSelector->getNbContent();
}

void ChooseProfileScene::update()
{
    if (!_windowManager->isRunning()) {
        _info->setQuit(true);
    }
    _buttonManager.updateButtons();
    _profileSelector->update();
    _inputButton->update();
    //_profileKeypad->update();

    if (_buttonManager.isButtonClicked("Play")) {
        return;
    }
    std::string nb_entity = std::to_string(std::atoi(_profileSelector->getCurrentContent()->getContent().c_str()));
    if (std::atoi(nb_entity.c_str()) > 4 || std::atoi(nb_entity.c_str()) < 1) {
        _ProfilesIndicationGame.setColor(BLACK);
        _ProfilesIndicationPlayed.setColor(BLACK);
        _ProfilesIndicationKilled.setColor(BLACK);
    }
    else {
        _ProfilesIndicationGame.setColor(WHITE);
        _ProfilesIndicationPlayed.setColor(WHITE);
        _ProfilesIndicationKilled.setColor(WHITE);
    }
    //_ProfilesIndication.setStr(nb_entity + "/ 4 profiles maximum");
    return;
}

void ChooseProfileScene::draw()
{
    _background->draw();
    _zoneStat->draw();
    //_profileKeypad->draw();
    _profileSelector->draw();
    if (_nbContents - 1 == _profileSelector->getIdActualContent())
        _inputButton->draw();
    _buttonManager.drawButtons();
    _ProfilesIndicationGame.draw();
    _ProfilesIndicationPlayed.draw();
    _ProfilesIndicationKilled.draw();
}