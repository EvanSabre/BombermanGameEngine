/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** main
*/

#include "gameEngine/encapsulation/Keyboard.hpp"
#include "gameEngine/DLLoader.hpp"
#include "game/scenes/MainMenuScene.hpp"
#include "SceneManager.hpp"
#include <memory>

#define WIN_HEIGHT 450
#define WIN_WIDTH 800

int main(void)
{
    std::shared_ptr<gameEngine::managers::WindowManager> win = std::make_shared<gameEngine::managers::WindowManager>();
    gameEngine::scenes::SceneInfo info;

    win->createWindow("Bomberman", {WIN_WIDTH, WIN_HEIGHT});
    std::shared_ptr<gameEngine::interfaces::IScene> scene = game::managers::SceneManager::loadScene("menu", win, info);
    scene->start();
    scene->update();
    return 0;
}
