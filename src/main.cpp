/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** main
*/

#include <iostream>
#include "raylib.h"
#include "Button.hpp"

#define NUM_FRAMES 1

    // Initialization
    //--------------------------------------------------------------------------------------
const int screenWidth = 800;
const int screenHeight = 450;

void run()
{
    Vector2 mousePoint = { 0.0f, 0.0f };
    Texture2D button = LoadTexture("assets/button_test.png");
    Vector<float> pos(screenWidth/2.0f - button.width/2.0f, screenHeight/2.0f - button.height/2.0f);

    float frameHeight = (float)button.height/NUM_FRAMES;
    Rectangle sourceRec = { 0, 0, (float)button.width, frameHeight };

    // Define button bounds on screen
    Rectangle btnBounds = { screenWidth/2.0f - button.width/2.0f, screenHeight/2.0f - button.height/NUM_FRAMES/2.0f, (float)button.width, frameHeight };
    gameEngine::encapsulation::BText text("Press me", {pos._x, pos._y}, WHITE, 64);
    gameEngine::encapsulation::Button but({button.width, button.height}, pos, text, BLACK);
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
     // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        mousePoint = GetMousePosition();
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(RAYWHITE);
        but.drawButton();
        Vector<float> mousP(mousePoint.x, mousePoint.y);
        if (but.isButtonPressed(mousP))
            but.setContentStr("I have been pressed");
        else
            but.setContentStr("Press me");
        EndDrawing();
        //----------------------------------------------------------------------------------
    }
}

int main(void)
{
    InitWindow(screenWidth, screenHeight, "raylib [textures] example - sprite button");

    InitAudioDevice();      // Initialize audio device
    run();
    CloseAudioDevice();     // Close audio device
    CloseWindow();          // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    return 0;
}