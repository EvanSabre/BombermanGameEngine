/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** GlobalManager
*/

#include "GlobalManager.hpp"

#define WIN_HEIGHT 1080
#define WIN_WIDTH 1920

using namespace game::managers;

GlobalManager::GlobalManager()
{
    _windowManager = std::make_shared<gameEngine::managers::WindowManager>();
    _windowManager->createWindow("Bomberman", {WIN_WIDTH, WIN_HEIGHT});
    _sceneInfo = std::make_shared<gameEngine::scenes::SceneInfo>();
    //@TODO init sceneInfo
    _currentScene = game::managers::SceneManager::loadScene("choosePlayers", _windowManager, _sceneInfo);
}

GlobalManager::~GlobalManager()
{
}

void GlobalManager::run()
{
    _currentScene->start();
    while (_windowManager->isRunning()) {
        loadNewScene(_currentScene->update());
        _windowManager->BeginDraw();
        _windowManager->clear();
        _currentScene->draw();
        _windowManager->EndDraw();
    }
}

void GlobalManager::loadNewScene(const std::string &sceneName)
{
    if (sceneName == "")
        return;
    _currentScene.reset();
    try {
        _currentScene = game::managers::SceneManager::loadScene(sceneName, _windowManager, _sceneInfo);
    } catch (NoSceneException &e) {
        throw LoadingError("Could not load scene");
    }
    _windowManager->setBackgroundColor(WHITE);
    _windowManager->clear();
    _currentScene->start();
}
