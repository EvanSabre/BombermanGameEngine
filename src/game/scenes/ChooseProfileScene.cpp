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
static const Vector<float> SCALE_KEYPAD(0.5, 0.5);

ChooseProfileScene::ChooseProfileScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, std::shared_ptr<game::managers::GameManager> &info) :
AScene(windowManager, info), _acceptPopUp("This username has already been taken", Vector<float>(windowManager->getWindowSize()._x / 2, windowManager->getWindowSize()._y / 2), Vector<float>(500, 200))
{
    _audio = std::make_shared<gameEngine::managers::AudioManager>();
    _audio->loadMusicStreamFromFile("./assets/All/Music/Menu.mp3");
    _audio->loadSoundFromFile("./assets/All/Sound/Button.wav", "button");

    _audio->setMusicVolume(_info->getMusicVolume() / 100);
    _audio->setSoundVolume(_info->getSoundVolume() / 100);
}

ChooseProfileScene::~ChooseProfileScene()
{
}

void ChooseProfileScene::start()
{
    Vector<float> size(WINDOW_X / 2, WINDOW_Y / 1.5);
    Vector<float> pos(WINDOW_X / 4, WINDOW_Y * 0.30);
    Vector<float> posbutton(WINDOW_X / 2.5, WINDOW_Y * 0.42);
    Vector<float> sizebutton(WINDOW_X / 5, WINDOW_Y / 12);
    _background = std::make_unique<IMAGE>(BACKGROUND_BUTTON);
    _zoneStat = std::make_unique<RECTANGLE>(size, pos, BLANKGRAY);

    _acceptPopUp.setEnabled(false);
    _image_controller = std::make_shared<gameEngine::encapsulation::BTexture2D>();
    if (_info->nbPlayersConfirmed == 0)
        _image_controller->loadFromFile(KEYPAD);
    else
        _image_controller->loadFromFile(CONTROLLER);
    _image_controller->setEnabled(true);
    _image_controller->setPos(Vector<int>(pos._x * 1.85, pos._y * 0.2));
    _image_controller->setColor(RED);

    _info->_userManager->getUserInputs().size();
    _InputIndication = TEXT(_info->_userManager->getUserInputs().at(_info->nbPlayersConfirmed + 1)->getDeviceName(),
                            Vector<float>(pos._x * 1.80, pos._y * 0.7),
                            BLACK,
                            30);

    for (auto &user : _info->_userManager->getUsers()) {
        _profileContent.push_back(std::make_shared<TEXT>(user->name, size, BLACK, 40));
    }
    TEXT inputText("Enter a Username", posbutton, BLACK, 20);
    _inputButton = std::make_unique<INPUT_BUTTON>(sizebutton, posbutton, 10, inputText, BLANKGRAY, false, BLACK);
    _profileContent.push_back(std::make_shared<TEXT>("", size, BLACK, 40));

    _profileSelector = std::make_unique<SELECTOR>("Choose a profile", _profileContent, Vector<float>(pos._x * 1.3, pos._y * 1.2), Vector<float>(size._x * 0.7, size._y * 0.3), 30, BLACK);

    gameEngine::encapsulation::BText backText("Back", Vector<float>(WINDOW_X * 0.1 + 80, WINDOW_Y * 0.8 + 65), WHITE, 40);
    std::shared_ptr<gameEngine::encapsulation::Button> backButton =
        std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(250, 70), Vector<float>(WINDOW_X * 0.1, WINDOW_Y * 0.8 + 50), backText, DARKGRAY, WHITE, PLAY_BUTTON);

    gameEngine::encapsulation::BText playText("Play", Vector<float>(WINDOW_X * 0.8 + 80, WINDOW_Y * 0.8 + 65), WHITE, 40);
    std::shared_ptr<gameEngine::encapsulation::Button> playButton =
        std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(250, 70), Vector<float>(WINDOW_X * 0.8, WINDOW_Y * 0.8 + 50), playText, DARKGRAY, WHITE, PLAY_BUTTON);

    _buttonManager.pushButton(backButton);
    _buttonManager.pushButton(playButton);
    _ProfilesIndicationGameWon = TEXT("Game Won: ", Vector<float>(pos._x + size._x * 0.1, pos._y + size._y * 0.45),
                              BLACK,
                              30);
    _ProfilesIndicationGamePlayed = TEXT("Game Played: ", Vector<float>(pos._x + size._x * 0.1, pos._y + size._y * 0.55),
                              BLACK,
                              30);
    _ProfilesIndicationCreated = TEXT("Created: ", Vector<float>(pos._x + size._x * 0.1, pos._y + size._y * 0.65),
                              BLACK,
                              30);
    _ProfilesIndicationBeKilled = TEXT("Be Killed: ", Vector<float>(pos._x + size._x * 0.1, pos._y + size._y * 0.75),
                              BLACK,
                              30);
    _ProfilesIndicationKills = TEXT("Kills: ", Vector<float>(pos._x + size._x * 0.1, pos._y + size._y * 0.85),
                              BLACK,
                              30);

    _ProfilesGameWon = TEXT("", Vector<float>(pos._x + size._x * 0.5, pos._y + size._y * 0.45),
                              BLACK,
                              30);
    _ProfilesGamePlayed = TEXT("", Vector<float>(pos._x + size._x * 0.5, pos._y + size._y * 0.55),
                              BLACK,
                              30);
    _ProfilesCreated = TEXT("", Vector<float>(pos._x + size._x * 0.5, pos._y + size._y * 0.65),
                              BLACK,
                              30);
    _ProfilesBeKilled = TEXT("", Vector<float>(pos._x + size._x * 0.5, pos._y + size._y * 0.75),
                              BLACK,
                              30);
    _ProfilesKills = TEXT("", Vector<float>(pos._x + size._x * 0.5, pos._y + size._y * 0.85),
                              BLACK,
                              30);

    _nbContents = _profileSelector->getNbContent();
    _audio->playMusic();
}

void ChooseProfileScene::createNewProfile()
{
    Vector<float> size(WINDOW_X / 2.1, WINDOW_Y / 2.3);

    if (_info->_userManager->findUser(_inputButton->getInput())) {
        _acceptPopUp.setEnabled(true);

        return;
    }
    try {
        _info->_userManager->createUser(_inputButton->getInput());
    } catch (UserManagmentError &e) {
        throw IndieError("Error in new profile");
    }
    auto it = _profileContent.end();
    _profileContent.insert(it, std::make_shared<TEXT>(_inputButton->getInput(), size, BLACK, 40));
    _profileContent.push_back(std::make_shared<TEXT>(_inputButton->getInput(), size, BLACK, 40));
    _profileSelector->setContent(_profileContent);
    _profileSelector->setICurrent(_profileContent.size() - 1);
}

void ChooseProfileScene::update()
{
    if (!_windowManager->isRunning()) {
        _info->setQuit(true);
    }
    _buttonManager.updateButtons();
    _profileSelector->update();
    _inputButton->update();
    _InputIndication.setStr(_info->_userManager->getUserInputs().at(_info->nbPlayersConfirmed + 1)->getDeviceName());
    if (_inputButton->checkValidate()) {
        createNewProfile();
    }
    try {
        _cUser = _info->_userManager->getUser(_profileSelector->getCurrentContent()->getContent());
        _ProfilesBeKilled.setStr(std::to_string(_cUser->beKilled));
        _ProfilesCreated.setStr(TimestampUtil::timestampToString(_cUser->created));
        _ProfilesGamePlayed.setStr(std::to_string(_cUser->gamesPlayed));
        _ProfilesGameWon.setStr(std::to_string(_cUser->gamesWon));
        _ProfilesKills.setStr(std::to_string(_cUser->kills));
    } catch (UserManagmentError &e) {
        _cUser = nullptr;
        _ProfilesBeKilled.setStr("");
        _ProfilesCreated.setStr("");
        _ProfilesGamePlayed.setStr("");
        _ProfilesGameWon.setStr("");
        _ProfilesKills.setStr("");
    }
    if (_buttonManager.isButtonClicked("Play") && _cUser != nullptr) {
        _info->nbPlayersConfirmed++;
        _info->pushPlayer(_cUser);
        _audio->playSoundWaitEnd("button");
        sleep(1);
        if (_info->nbPlayersConfirmed == _info->nbPlayers)
            _info->setCurrentScene("play");
        else
            _info->setCurrentScene("chooseProfile");
    }
    if (_buttonManager.isButtonClicked("Back")) {
        _audio->playSoundWaitEnd("button");
        _info->setCurrentScene("choosePlayers");
    }
    _audio->updateMusicStream();
    _acceptPopUp.update();
}

void ChooseProfileScene::draw()
{
    _background->draw();
    _zoneStat->draw();
    if (_info->nbPlayersConfirmed == 0)
        _image_controller->drawEx(SCALE_KEYPAD);
    else
        _image_controller->drawEx(SCALE_GAMEPAD);
    if (!_acceptPopUp.getEnabled()) {
        _profileSelector->draw();
        _buttonManager.drawButtons();
        _inputButton->setCanInput(true);
    } else {
        _inputButton->setCanInput(false);
    }
    if (_nbContents - 1 == _profileSelector->getIdActualContent())
        _inputButton->draw();
    _buttonManager.drawButtons();
    _InputIndication.draw();
    _ProfilesIndicationGameWon.draw();
    _ProfilesIndicationGamePlayed.draw();
    _ProfilesIndicationCreated.draw();
    _ProfilesIndicationBeKilled.draw();
    _ProfilesIndicationKills.draw();
    _ProfilesGameWon.draw();
    _ProfilesGamePlayed.draw();
    _ProfilesCreated.draw();
    _ProfilesBeKilled.draw();
    _ProfilesKills.draw();

    _acceptPopUp.draw();

}
