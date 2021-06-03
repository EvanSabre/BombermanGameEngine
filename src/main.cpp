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
#include "Map.hpp"

using namespace gameEngine;

int main(void)
{
    const int screenWidth = 960;
    const int screenHeight = 720;

    game::Managers::WindowManager window{};
    window.createWindow("Model example", {screenWidth, screenHeight});

    encapsulation::BCamera cam{};
    cam.setPosition({50, 50, 50});
    cam.setTarget({0, 10, 0});
    cam.setUp({0, 1, 0});
    cam.setFovy(45);
    cam.setProjection(CAMERA_PERSPECTIVE);

    Map map(15);
    map.dump();

    cam.setMode(CAMERA_FREE);

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        cam.update();
        BeginDrawing();
        {
            ClearBackground(RAYWHITE);

            window.set3DMode(cam);
            {
                map.draw();
                DrawGrid(20, 10.0f);         // Draw a grid
            }
            cam.endMode();
            DrawFPS(10, 10);
        }
        EndDrawing();
    }
    window.deleteWindow();
    return 0;
}
