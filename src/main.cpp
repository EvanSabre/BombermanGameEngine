/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** main
*/

#include "raylib.h"
#include "BCamera.hpp"
#include "BModel.hpp"
#include "BTexture2D.hpp"
#include "WindowManager.hpp"
#include "AudioManager.hpp"
#include "Map.hpp"

using namespace gameEngine;
#include "gameEngine/managers/InputManager.hpp"
#include "game/scenes/MainMenuScene.hpp"
#include "SceneManager.hpp"
#include "gameEngine/exceptions/NoSceneException.hpp"
#include <memory>

#define WIN_HEIGHT 1080
#define WIN_WIDTH 1920

int main()
{
    std::shared_ptr<gameEngine::managers::WindowManager> win = std::make_shared<gameEngine::managers::WindowManager>();
    gameEngine::scenes::SceneInfo info;
    std::string nextScene;

    win->createWindow("Bomberman", {WIN_WIDTH, WIN_HEIGHT});
    std::shared_ptr<gameEngine::interfaces::IScene> scene = game::managers::SceneManager::loadScene("menu", win, info);

    scene->start();
    while (win->isRunning()) {
        nextScene = scene->update();
        if (nextScene != "") {
            try {
                scene = game::managers::SceneManager::loadScene(nextScene, win, info);
            } catch (NoSceneException &e) {
                return 84;
            }
            win->setBackgroundColor(WHITE);
            win->clear(WHITE);
            scene->start();
        }
        win->BeginDraw();
        win->clear();
        scene->draw();
        win->EndDraw();
    }
    return 0;
}
