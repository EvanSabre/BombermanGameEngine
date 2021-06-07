/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** main
*/

#include "raylib.h"
#include "gameEngine/encapsulation/Keyboard.hpp"
#include "gameEngine/DLLoader.hpp"
#include "game/scenes/MainMenuScene.hpp"
#include <memory>

int main(void)
{
    std::shared_ptr<gameEngine::interfaces::IScene> menu = std::make_shared<game::scenes::MainMenuScene>();

    menu->start();
    menu->update();
    return 0;
}
