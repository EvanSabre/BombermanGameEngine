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
    // Define the camera to look into our 3d world
    Camera camera = { 0 };
    camera.position = (Vector3){ 10.0f, 10.0f, 10.0f }; // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;                   // Camera mode type

    gameEngine::encapsulation::BModel model("resources/guy/guy.iqm");
    gameEngine::encapsulation::BTexture2D texture("resources/guy/guytex.png");
    model.setTexture(0, MAP_DIFFUSE, texture);

    Vector3 position = { 0.0f, 0.0f, 0.0f };            // Set model position

    // Load animation data
    gameEngine::encapsulation::BModelAnimation modelAnim("resources/guy/guyanim.iqm");
    gameEngine::Animation animation(model, modelAnim);
    //gameEngine::Animation animation()
    SetCameraMode(camera, CAMERA_FREE); // Set free camera mode

    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        UpdateCamera(&camera);

        // Play animation when spacebar is held down
        if (IsKeyDown(KEY_SPACE))
        {
            animation.updateModelAnimation();
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);

                model.draw();

                DrawGrid(10, 1.0f);         // Draw a grid

            EndMode3D();

            DrawText("PRESS SPACE to PLAY MODEL ANIMATION", 10, 10, 20, MAROON);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }
}

int main(void)
{
    InitWindow(screenWidth, screenHeight, "raylib [textures] example - sprite button");

    run();
    CloseWindow();          // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    return 0;
}