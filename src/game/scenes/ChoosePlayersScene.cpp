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
#define PIRATE_UNIVERSE "./assets/Backgrounds/pirate_universe.png"
#define SAMOURAI_UNIVERSE "./assets/Backgrounds/samourai_universe.png"
#define VIKING_UNIVERSE "./assets/Backgrounds/viking_universe.png"


ChoosePlayersScene::~ChoosePlayersScene()
{
}

ChoosePlayersScene::ChoosePlayersScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, std::shared_ptr<game::managers::GameManager> &info) :
AScene(windowManager, info), _universe("Vikings")
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
        std::make_shared<TEXT>("0", size, BLACK, 40),
        std::make_shared<TEXT>("1", size, BLACK, 40),
        std::make_shared<TEXT>("2", size, BLACK, 40),
        std::make_shared<TEXT>("3", size, BLACK, 40),
        std::make_shared<TEXT>("4", size, BLACK, 40),
    };

    std::vector<std::shared_ptr<gameEngine::encapsulation::BModel>> modelList =
    {
        std::make_shared<gameEngine::encapsulation::BModel>("./assets/Pirates/Models/Character.iqm", Vector3T<float>(3, 4, 0)),
        std::make_shared<gameEngine::encapsulation::BModel>("./assets/Samurai/Models/Character.iqm", Vector3T<float>(3, 4, 0)),
        std::make_shared<gameEngine::encapsulation::BModel>("./assets/Vikings/Models/Character.iqm", Vector3T<float>(3, 4, 0)),
    };

    _textures = {
        std::make_shared<gameEngine::encapsulation::BTexture2D>("./assets/Pirates/Textures/Character.png"),
        std::make_shared<gameEngine::encapsulation::BTexture2D>("./assets/Samurai/Textures/Character.png"),
        std::make_shared<gameEngine::encapsulation::BTexture2D>("./assets/Vikings/Textures/Character.png")
    };

    modelList[0]->setTexture(0, MATERIAL_MAP_DIFFUSE, *_textures[0]);
    modelList[1]->setTexture(0, MATERIAL_MAP_DIFFUSE, *_textures[1]);
    modelList[2]->setTexture(0, MATERIAL_MAP_DIFFUSE, *_textures[2]);

    modelList[0]->setTransform().setScale(Vector3T<float>(0.1, 0.1, 0.1));
    modelList[1]->setTransform().setScale(Vector3T<float>(0.1, 0.1, 0.1));
    modelList[2]->setTransform().setScale(Vector3T<float>(0.1, 0.1, 0.1));

    modelList[0]->setTransform().setPosition(Vector3T<float>(80, 10, 140));
    modelList[1]->setTransform().setPosition(Vector3T<float>(80, 10, 140));
    modelList[2]->setTransform().setPosition(Vector3T<float>(80, 10, 140));

    modelList[0]->setTransform().setRotation(Vector3T<float>(180, 90, 0));
    modelList[1]->setTransform().setRotation(Vector3T<float>(180, 90, 0));
    modelList[2]->setTransform().setRotation(Vector3T<float>(180, 90, 0));

    for (int i = 0; i < 3; i++)
        modelList[i]->rotate();

    std::vector<std::shared_ptr<gameEngine::encapsulation::BModel>> chooseUniverse =
    {
        modelList[0],
        modelList[1],
        modelList[2],
        // std::make_shared<IMAGE>(PIRATE_UNIVERSE, "Pirates"),
        // std::make_shared<IMAGE>(VIKING_UNIVERSE, "Vikings"),
        // std::make_shared<IMAGE>(SAMOURAI_UNIVERSE, "Samurai"),

    };

    _universeSelector =
    std::make_unique<gameEngine::component::TSelector<gameEngine::encapsulation::BModel>>("Choose an universe", chooseUniverse, Vector<float>(pos._x * 2.0, pos._y * 0.9), Vector<float>(size._x * 0.95, size._y * 1), 20, DARKGRAY, WHITE, true);
    _playerSelector = std::make_unique<SELECTOR>("Choose a number of players", playerContent, Vector<float>(pos._x * 0.3, pos._y * 1.5), Vector<float>(size._x * 0.7, size._y * 0.3), 20, DARKGRAY);
    _botSelector = std::make_unique<SELECTOR>("Choose a number of bots", botContent, Vector<float>(pos._x * 0.3, pos._y * 3.5), Vector<float>(size._x * 0.7, size._y * 0.3), 20, DARKGRAY);
    std::shared_ptr<BUTTON> backButton = std::make_shared<BUTTON>(Vector<float>(size._x * 0.2, size._y * 0.2),
                                            Vector<float>(WINDOW_X * 0.1, WINDOW_Y * 0.8),
                                            "Back",
                                            30,
                                            BLUE,
                                            WHITE,
                                            BACKGROUND_BUTTON);
    std::shared_ptr<BUTTON> playButton = std::make_shared<BUTTON>(Vector<float>(size._x * 0.2, size._y * 0.2),
                                            Vector<float>(WINDOW_X * 0.8, WINDOW_Y * 0.8),
                                            "Play",
                                            30,
                                            BLUE,
                                            WHITE,
                                            BACKGROUND_BUTTON);
    backButton->setCallback([](std::shared_ptr<game::managers::GameManager> info) { info->setCurrentScene("menu");}, _info);
    _buttonManager.pushButton(backButton);
    _buttonManager.pushButton(playButton);
    _PlayersIndication = TEXT("",
                              Vector<float>(pos._x * 0.2 + size._x * 0.5, pos._y + size._y * 0.9),
                              WHITE,
                              30);
}

void ChoosePlayersScene::update()
{
    if (!_windowManager->isRunning()) {
        _info->setQuit(true);
    }
    _universeSelector->update();
    _buttonManager.updateButtons();
    _botSelector->update();
    _playerSelector->update();

    if (_buttonManager.isButtonClicked("Play")) {
        std::cout << _universeSelector->getIdActualContent() << std::endl;
        _info->setUniverse(UNIVERSE.at(_universeSelector->getIdActualContent()));
        _info->setCurrentScene("chooseProfile");
    }
    int nbBots = std::atoi(_botSelector->getCurrentContent()->getContent().c_str());
    int nbPlayers = std::atoi(_playerSelector->getCurrentContent()->getContent().c_str());
    //_universeSelector->getCurrentContent()->setTransform().setPosition(Vector3T<float>(1280, 400, 0));

    std::string nb_entity = std::to_string(nbBots + nbPlayers);
    if (std::atoi(nb_entity.c_str()) > 4 || std::atoi(nb_entity.c_str()) < 1) {
        _PlayersIndication.setColor(RED);
        _buttonManager.setEnabledButton("Play", false);
    } else {
        _info->nbPlayers = nbPlayers;
        _info->nbBots = nbBots;
        _buttonManager.setEnabledButton("Play", true);
        _PlayersIndication.setColor(WHITE);
    }
    _PlayersIndication.setStr(nb_entity + "/ 4 Players maximum");
}

void ChoosePlayersScene::draw()
{
    _background->draw();
    _playerSelector->draw();
    _botSelector->draw();
    _buttonManager.drawButtons();
    _universeSelector->draw();
    _PlayersIndication.draw();
}

// * Callbacks
