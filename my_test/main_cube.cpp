/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** main
*/

#include <iostream>
#include "BText.hpp"
#include "Vector.hpp"
#include "BRectangle.hpp"
#include "BImage.hpp"
#include "BCamera.hpp"
#include "WindowManager.hpp"

using namespace gameEngine;

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    game::Managers::WindowManager window{};
    window.createWindow("Cube Example", {screenWidth, screenHeight});

    // Define the camera to look into our 3d world
    encapsulation::BCamera cam{};
    cam.setPosition({0, 10, 10});
    cam.setTarget({0, 0, 0});
    cam.setUp({0, 1, 0});
    cam.setFovy(45);
    cam.setProjection(CAMERA_PERSPECTIVE);

    Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };

    encapsulation::BText welcome_text{"welcome to the third dimension!", {10, 40}, DARKGRAY, 20};

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            window.set3DMode(cam);

                DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
                DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);

                DrawGrid(10, 1.0f);

            cam.endMode();
            //EndMode3D();

            welcome_text.draw();

            DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    window.deleteWindow();
    //--------------------------------------------------------------------------------------

    return 0;
}