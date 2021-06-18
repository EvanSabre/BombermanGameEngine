/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** ChooseProfileScene
*/

#include "ChooseProfileScene.hpp"

using namespace game::scenes;
#define BACKGROUND_BUTTON "./assets/Backgrounds/SupernovaBG.png"
#define CONTROLLER "./assets/Backgrounds/manette.png"
#define KEYPAD "./assets/Backgrounds/keypad.png"
static const Vector<float> SCALE_GAMEPAD(0.5, 0.5);

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

    _image_controller = std::make_shared<gameEngine::encapsulation::BTexture2D>();
    _image_controller->loadFromFile(CONTROLLER);
    _image_controller->setEnabled(true);
    _image_controller->setPos(Vector<int>(pos._x * 1.85, pos._y * 0.2));

    std::vector<std::shared_ptr<gameEngine::encapsulation::ADrawable>> profileContent;

    for (auto &user : _info->_userManager->getUsers()) {
        profileContent.push_back(std::make_shared<TEXT>(user->name, size, BLACK, 40));
    }
    _inputButton = std::make_unique<INPUT_BUTTON>(sizebutton, posbutton, 10, TEXT("", size, BLACK, 40), RED, BLACK);
    profileContent.push_back(std::make_shared<TEXT>("", size, BLACK, 40));

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
    _ProfilesIndicationGameWon = TEXT("Game Won: ", Vector<float>(pos._x + size._x * 0.1, pos._y + size._y * 0.45),
                              WHITE,
                              30);
    _ProfilesIndicationGamePlayed = TEXT("Game Played: ", Vector<float>(pos._x + size._x * 0.1, pos._y + size._y * 0.55),
                              WHITE,
                              30);
    _ProfilesIndicationCreated = TEXT("Created: ", Vector<float>(pos._x + size._x * 0.1, pos._y + size._y * 0.65),
                              WHITE,
                              30);
    _ProfilesIndicationBeKilled = TEXT("Be Killed: ", Vector<float>(pos._x + size._x * 0.1, pos._y + size._y * 0.75),
                              WHITE,
                              30);
    _ProfilesIndicationKills = TEXT("Kills: ", Vector<float>(pos._x + size._x * 0.1, pos._y + size._y * 0.85),
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
        _ProfilesIndicationGameWon.setColor(BLACK);
        _ProfilesIndicationGamePlayed.setColor(BLACK);
        _ProfilesIndicationCreated.setColor(BLACK);
        _ProfilesIndicationBeKilled.setColor(BLACK);
        _ProfilesIndicationKills.setColor(BLACK);
    }
    else {
        _ProfilesIndicationGameWon.setColor(WHITE);
        _ProfilesIndicationGamePlayed.setColor(WHITE);
        _ProfilesIndicationCreated.setColor(WHITE);
        _ProfilesIndicationBeKilled.setColor(WHITE);
        _ProfilesIndicationKills.setColor(WHITE);
    }
    //_ProfilesIndication.setStr(nb_entity + "/ 4 profiles maximum");
    return;
}

void ChooseProfileScene::draw()
{
    _background->draw();
    _zoneStat->draw();
    //_profileKeypad->draw();
    //_image_controller->draw();
    _image_controller->drawEx(SCALE_GAMEPAD);
    _profileSelector->draw();
    if (_nbContents - 1 == _profileSelector->getIdActualContent())
        _inputButton->draw();
    _buttonManager.drawButtons();
    _ProfilesIndicationGameWon.draw();
    _ProfilesIndicationGamePlayed.draw();
    _ProfilesIndicationCreated.draw();
    _ProfilesIndicationBeKilled.draw();
    _ProfilesIndicationKills.draw();
}
