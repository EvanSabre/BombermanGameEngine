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

int main(void)
{
    DLLoader<game::scenes::MainMenuScene> loader(std::string("game_lib.so"));

    game::scenes::MainMenuScene *menu = loader.getInstance();
    if (menu == NULL) {
        std::cout << "error\n";
        return 0;
    }
    menu->start();
    menu->update();
    return 0;
}
