/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** TutorialScene
*/

#include "TutorialScene.hpp"

using namespace game::scenes;

#ifdef _WIN32
#define NEWLINE "\r\n"
#elif defined macintosh // OS 9
#define NEWLINE "\r"
#else
#define NEWLINE "\n" // Linux
#endif

TutorialScene::TutorialScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, std::shared_ptr<game::managers::GameManager> &info)
: AScene(windowManager, info)
{
    char lines[13][85] = {
        "Welcome to BOMBERVERSE: the Multiverse Bomberman...",
        "In this tutorial we will teach you the basic steps to play.",
        "MOVEMENTS : ",
        "You can move up, down, right and left on a map made of tiles. ",
        "You can drop bombs using the Space button (default).",
        "Bombs will explode in 2 seconds and destroy the breakable crates.",
        "Upon being destroyed they sometimes drop Potions ",
        "that will boost your stats or heal you.",
        "OBJECTIVES : ",
        "You start with 1 and only life, try to not get blasted",
        "The objective is to have the better SCORE at the end of the timer,",
        "or to KILL every other opponent.",
        "GOOD LUCK and have FUN !"
        };
    for (int i = 0; i < 13; i++) {
        _tutorialText += std::string(lines[i]);
        _tutorialText += std::string(NEWLINE);
        if (i == 1 || i == 7 || i == 13)
            _tutorialText += std::string(NEWLINE);
    }
    _audio = std::make_shared<gameEngine::managers::AudioManager>();
    _audio->loadMusicStreamFromFile("./assets/All/Music/Credits.mp3");
    _audio->loadSoundFromFile("./assets/All/Sound/Button.wav", "button");
    _audio->setMusicVolume(_info->getMusicVolume() / 100);
    _audio->setSoundVolume(_info->getSoundVolume() / 100);
    _background.loadFromFile("./assets/Backgrounds/credits_background.png");
}

TutorialScene::~TutorialScene()
{
}

void TutorialScene::start()
{
    _audio->playMusic();

    Vector<float> size(300, 200);
    Vector<float> middle(_windowManager->getWindowSize()._x / 2, _windowManager->getWindowSize()._y / 2);
    _title = std::make_shared<gameEngine::encapsulation::BSdf>("TUTORIAL", 100, WHITE, Vector3T<float>(middle._x - 250, 60, 0));

    _text = std::make_shared<gameEngine::encapsulation::BText>(_tutorialText, Vector<float>(400, 200), WHITE, 35);

    //back to menu
    gameEngine::encapsulation::BText quitText("Back to Menu", Vector<float>(40, 1010), WHITE, 30);
    quitText.setFont(_font);
    std::shared_ptr<gameEngine::encapsulation::Button> buttonQuit =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(250, 50), Vector<float>(20, 1000), quitText, DARKGRAY, WHITE, PLAY_BUTTON);

    _buttonManager.pushButton(buttonQuit);
}

void TutorialScene::update()
{
    _buttonManager.updateButtons();
    if (_buttonManager.isButtonClicked("Back to Menu")) {
        _audio->playSoundWaitEnd("button");
        _info->setCurrentScene("menu");
    }
    _audio->updateMusicStream();
}

void TutorialScene::draw()
{
    _background.draw();
    _title->draw();
    _text->draw();
    _buttonManager.drawButtons();
}
