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
#include "BTexture2D.hpp"

#include <unistd.h>
#include <fstream>

using namespace gameEngine;

int main(void)
{
    encapsulation::BText text{"hello world!"};
    //std::cout << text << std::endl;
    encapsulation::BRectangle rect{{100, 100}};
    rect.setColor(RED);
    if (access("./assets/test_image.png", F_OK ) != -1)
        std::cout << "Access to file ok" << std::endl;
    encapsulation::BImage img{"./assets/test_image.png"};
    // try
    // {
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    //     return 84;
    // }


    // text.setSize(100);
    // text.setPosition({190, 200});
   // text.setColor(BLACK);
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    encapsulation::BTexture2D my_texture{};
    my_texture.loadFromImg(img);
   // Image my_img = LoadImage("./assets/test_image.png");
   // Texture2D texture = LoadTextureFromImage(img.getObj());

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        BeginDrawing();

        ClearBackground(RAYWHITE);

       // DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

       // rect.draw();
        //DrawTexture(texture, 0, 0, WHITE);
        my_texture.draw();
        text.draw();
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    my_texture.unload();

    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------


    return 0;
}