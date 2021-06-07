/*******************************************************************************************
*
*   raylib [models] example - Models loading
*
*   raylib supports multiple models file formats:
*
*     - OBJ > Text file, must include vertex position-texcoords-normals information,
*             if files references some .mtl materials file, it will be loaded (or try to)
*     - GLTF > Modern text/binary file format, includes lot of information and it could
*              also reference external files, raylib will try loading mesh and materials data
*     - IQM > Binary file format including mesh vertex data but also animation data,
*             raylib can load .iqm animations.
*
*   This example has been created using raylib 2.6 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014-2019 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "BCamera.hpp"
#include "BModel.hpp"
#include "BTexture2D.hpp"
#include "WindowManager.hpp"

#include "raylib.h"
using namespace gameEngine;

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    game::Managers::WindowManager window{};
    window.createWindow("Model example", {screenWidth, screenHeight});
    //InitWindow(screenWidth, screenHeight, "raylib [models] example - models loading");

    // Define the camera to look into our 3d world
    encapsulation::BCamera cam{};
    cam.setPosition({50, 50, 50});
    cam.setTarget({0, 10, 0});
    cam.setUp({0, 1, 0});
    cam.setFovy(45);
    cam.setProjection(CAMERA_PERSPECTIVE);

    encapsulation::BModel my_model{"./resources/models/castle.obj"};
   // Model model = LoadModel("./resources/models/castle.obj");                 // Load model
    encapsulation::BTexture2D my_texture{};
    my_texture.loadFromFile("./resources/models/castle_diffuse.png");
    //model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = my_texture.getObj();              // Set map diffuse texture
    my_model.setTexture(0, MATERIAL_MAP_DIFFUSE, my_texture);
    my_model.setPosition({0, 0, 0});
    my_model.setColor(WHITE);


    encapsulation::BTexture2D my_texture_2{};
    my_texture_2.loadFromFile("./resources/models/castle_diffuse.png");
    encapsulation::BModel model_copy{"./resources/models/castle.obj"};
    model_copy = my_model;
    model_copy.setPosition({10, 0, 0});
    model_copy.setTexture(0, MATERIAL_MAP_DIFFUSE, my_texture_2);
   // BoundingBox bounds = GetMeshBoundingBox(model.meshes[0]);  // Set model bounds

    // NOTE: bounds are calculated from the original size of the model,
    // if model is scaled on drawing, bounds must be also scaled

    cam.setMode(CAMERA_FREE);
    bool selected = false;          // Selected object flag

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        cam.update();

        // Load new models/textures on drag&drop
        if (IsFileDropped()) {
            int count = 0;
            char **droppedFiles = GetDroppedFiles(&count);

            if (count == 1) // Only support one file dropped
            {
                if (IsFileExtension(droppedFiles[0], ".obj") ||
                    IsFileExtension(droppedFiles[0], ".gltf") ||
                    IsFileExtension(droppedFiles[0], ".iqm"))       // Model file formats supported
                {
                    my_model.load(droppedFiles[0]);
                    my_model.setTexture(0, MATERIAL_MAP_DIFFUSE, my_texture);

                   // bounds = GetMeshBoundingBox(model.meshes[0]);

                    // TODO: Move camera position from target enough distance to visualize model properly
                }
                else if (IsFileExtension(droppedFiles[0], ".png"))  // Texture file formats supported
                {
                    my_texture.unload();
                    my_texture.loadFromFile(droppedFiles[0]);
                    my_model.setTexture(0, MATERIAL_MAP_DIFFUSE, my_texture);
                }
            }
            ClearDroppedFiles();    // Clear internal buffers
        }

        // Select model on mouse click
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            // Check collision between ray and box
            // if (CheckCollisionRayBox(GetMouseRay(GetMousePosition(), camera), bounds)) selected = !selected;
            // else selected = false;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            window.set3DMode(cam);

                my_model.draw();
                model_copy.draw();
                //DrawModel(model, position, 1.0f, WHITE);        // Draw 3d model with texture

                DrawGrid(20, 10.0f);         // Draw a grid

              //  if (selected) DrawBoundingBox(bounds, GREEN);   // Draw selection box

            cam.endMode();

            DrawText("Drag & drop model to load mesh/texture.", 10, GetScreenHeight() - 20, 10, DARKGRAY);
            if (selected) DrawText("MODEL SELECTED", GetScreenWidth() - 110, 10, 10, GREEN);

            DrawText("(c) Castle 3D model by Alberto Cano", screenWidth - 200, screenHeight - 20, 10, GRAY);

            DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    my_texture.unload();
    my_model.unload();         // Unload model

    window.deleteWindow();
    //--------------------------------------------------------------------------------------

    return 0;
}