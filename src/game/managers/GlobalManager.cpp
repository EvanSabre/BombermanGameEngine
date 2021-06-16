/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** GlobalManager
*/

#include "GlobalManager.hpp"

#define WIN_HEIGHT 1080
#define WIN_WIDTH 1920
#define ICON_PATH "./assets/BomberVerseIcon-1.png"

game::managers::GlobalManager::GlobalManager()
{
    _windowManager = std::make_shared<gameEngine::managers::WindowManager>();
    _windowManager->createWindow("Bomberverse", {WIN_WIDTH, WIN_HEIGHT});
    _windowManager->setWindowIcon(ICON_PATH);
    _gameManager = std::make_shared<game::managers::GameManager>("menu");
    //@TODO init gameManager
    _currentScene = game::managers::SceneManager::loadScene(_gameManager->getCurrentScene(), _windowManager, _gameManager);
}

game::managers::GlobalManager::~GlobalManager()
{
}

void game::managers::GlobalManager::run()
{
    _currentScene->start();
    while (!_gameManager->haveToQuit()) {
        _currentScene->update();
        if (_gameManager->haveToChange())
            loadNewScene(_gameManager->getCurrentScene());
        _windowManager->BeginDraw();
        _windowManager->clear();
        _currentScene->draw();
        _windowManager->EndDraw();
    }
}

void game::managers::GlobalManager::loadNewScene(const std::string &sceneName)
{
    if (sceneName == "")
        return;
    _currentScene.reset();
    try {
        _currentScene = game::managers::SceneManager::loadScene(sceneName, _windowManager, _gameManager);
    } catch (NoSceneException &e) {
        throw LoadingError("Could not load scene");
    }
    _windowManager->setBackgroundColor(WHITE);
    _windowManager->clear();
    _currentScene->start();
}
