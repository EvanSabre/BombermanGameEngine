/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** main
*/

#include "raylib.h"
#include "gameEngine/encapsulation/Keyboard.hpp"
#include "gameEngine/encapsulation/Gamepad.hpp"
#include "gameEngine/managers/AFileManager.hpp"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    gameEngine::encapsulation::Gamepad gamepad;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");

    Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2 };

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    for (int i = -100; i < 100; i++) {
        if (gamepad.isDeviceAvailable(i)) {
            printf("i = %d\n", i);
            //printf("NAME = %s#%d\n", gamepad.getDeviceName(i).c_str(), i);
            //exit(i);
        }
    }
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (gamepad.isKeyDown(GAMEPAD_BUTTON_LEFT_FACE_RIGHT, 0)) ballPosition.x += 2.0f;
        if (gamepad.isKeyDown(GAMEPAD_BUTTON_LEFT_FACE_LEFT, 0)) ballPosition.x -= 2.0f;
        if (gamepad.isKeyDown(GAMEPAD_BUTTON_LEFT_FACE_UP, 0)) ballPosition.y -= 2.0f;
        if (gamepad.isKeyDown(GAMEPAD_BUTTON_LEFT_FACE_DOWN, 0)) ballPosition.y += 2.0f;
        if (gamepad.isKeyDown(GAMEPAD_BUTTON_RIGHT_FACE_RIGHT, 0)) ballPosition.y += 2.0f;
        //----------------------------------------------------------------------------------
        DrawText(TextFormat("GP0: %s", GetGamepadName(0)), 10, 10, 10, BLACK);
        DrawText(TextFormat("GP1: %s", GetGamepadName(1)), 10, 20, 10, BLACK);
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawCircleV(ballPosition, 50, MAROON);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
