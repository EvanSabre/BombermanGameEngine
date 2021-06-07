/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** main
*/

#include <iostream>
#include "raylib.h"
#include "Button.hpp"
#include "gameEngine/Animation.hpp"

#define NUM_FRAMES 1

    // Initialization
    //--------------------------------------------------------------------------------------
const int screenWidth = 800;
const int screenHeight = 450;

void run()
{
    
}

int main(void)
{
    InitWindow(screenWidth, screenHeight, "raylib [textures] example - sprite button");

    run();
    CloseWindow();          // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    return 0;
}
