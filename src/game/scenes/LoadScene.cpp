/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** LoadScene
*/

#include "LoadScene.hpp"

using namespace game::scenes;

#define BACKGROUND_BUTTON "./assets/Backgrounds/SupernovaBG.png"
#define SAVES_PATH "./Saves"
#define SAVES_LEN 6

LoadScene::LoadScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, std::shared_ptr<game::managers::GameManager> &info) :
AScene(windowManager, info), _background(BACKGROUND_BUTTON)
{
}

LoadScene::~LoadScene()
{
}

std::vector<std::shared_ptr<gameEngine::encapsulation::ADrawable>> LoadScene::initDefault()
{
    Vector<float> pos(WINDOW_X / 4, WINDOW_Y / 7);

    std::vector<std::shared_ptr<gameEngine::encapsulation::ADrawable>> defaultVec =
    {
        std::make_shared<TEXT>("No game saved", pos, BLACK, 60)
    };
    _canSave = false;
    return defaultVec;
}

std::vector<std::shared_ptr<gameEngine::encapsulation::ADrawable>> LoadScene::loadSaves()
{
    char *path = realpath(SAVES_PATH, NULL);
    Vector<float> pos(WINDOW_X / 2, WINDOW_Y / 7);

    if (path == NULL) {
        return initDefault();
    }
    _canSave = true;
    std::vector<std::shared_ptr<gameEngine::encapsulation::ADrawable>> vec;
    Directory dir = _fileManager.loadDir(path, false);
    size_t namePos;
    std::string tmp;
    for (auto it : dir.getSubDirNames()) {
        if ((namePos = it.find("Saves/")) != it.npos)
            namePos += SAVES_LEN;
        tmp = it.substr(namePos);
        vec.push_back(std::make_shared<TEXT>(tmp, pos, BLACK, 60));

    }
    return vec;
}

void LoadScene::start()
{
    std::vector<std::shared_ptr<gameEngine::encapsulation::ADrawable>> saves = loadSaves();
    Vector<float> size(WINDOW_X / 2, WINDOW_Y / 1.5);
    Vector<float> pos(WINDOW_X / 4, WINDOW_Y / 7);

    _saveSelector =
    std::make_unique<gameEngine::component::Selector>("Choose a saved game", saves, Vector<float>(pos._x, pos._y * 1.2), size, 30, DARKGRAY);
    _saveSelector->setContentPos(Vector<float>(WINDOW_X / 2.1, WINDOW_Y / 2.3));

    gameEngine::encapsulation::BText backText("Back", Vector<float>(WINDOW_X * 0.1 + 80, WINDOW_Y * 0.8 + 65), WHITE, 40);
    std::shared_ptr<gameEngine::encapsulation::Button> backButton =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(250, 70), Vector<float>(WINDOW_X * 0.1, WINDOW_Y * 0.8 + 50), backText, DARKGRAY, WHITE, PLAY_BUTTON);

    gameEngine::encapsulation::BText playText("Play", Vector<float>(WINDOW_X * 0.8 + 80, WINDOW_Y * 0.8 + 65), WHITE, 40);
    std::shared_ptr<gameEngine::encapsulation::Button> playButton =
    std::make_shared<gameEngine::encapsulation::Button>(Vector<float>(250, 70), Vector<float>(WINDOW_X * 0.8, WINDOW_Y * 0.8 + 50), playText, DARKGRAY, WHITE, PLAY_BUTTON);

    backButton->setCallback([](std::shared_ptr<game::managers::GameManager> info) { info->setCurrentScene("menu"); }, _info);
    _buttonManager.pushButton(playButton);
    _buttonManager.pushButton(backButton);
}

void LoadScene::update()
{
    _buttonManager.updateButtons();
    _saveSelector->update();
    if (_canSave && _buttonManager.isButtonClicked("Play")) {
        _info->setSave(true);
        _info->setSavePath(_saveSelector->getCurrentContent()->getContent());
        game::systems::LoadParser parser(_info->getSavePath());
        std::pair<std::vector<std::vector<int>>, std::string> res = parser.loadMap();
        _info->setUniverse(res.second);
        _info->setSavedMap(res.first);
        _info->setSavedPlayers(parser.loadPlayers());
        _info->setCurrentScene("play");
    }
}

void LoadScene::draw()
{
    _background.draw();
    _saveSelector->draw();
    _buttonManager.drawButtons();
}
