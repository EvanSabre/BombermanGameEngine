<<<<<<< HEAD
// #include <fstream>

// #include <boost/archive/text_oarchive.hpp>
// #include <boost/archive/text_iarchive.hpp>

// class Note
// {
//         private:
//                 friend class boost::serialization::access;

//                 template<class Archive>
//                 void serialize(Archive & ar, const unsigned int version) {
//                         (void) version;
//                         ar & numerateur;
//                         ar & denominateur;
//                         ar & name;
//                 }
//                 int numerateur;
//                 int denominateur;
//                 std::string name;

//         public:
//                 Note() {};
//                 Note(int n, int d, std::string name) : numerateur(n), denominateur(d), name(name) {}
// };


// int main()
// {
//         std::ofstream ofs("fichierDeSerialisation");

//         // Vous avez vu comme je travaille bien ? :)
//         const Note maNoteDePhysisque(20, 20, "Totosdf");
//         {
//                 boost::archive::text_oarchive oa(ofs);
//                 oa << maNoteDePhysisque;
//         }

//         /** Quelque temps plus tard… ***/

//         Note monAncienneNote;

//         {
//                 std::ifstream ifs("fichierDeSerialisation");
//                 boost::archive::text_iarchive ia(ifs);

//                 ia >> monAncienneNote;
//         }
//         //printf("Note: %d / %d\n", monAncienneNote.numerateur, monAncienneNote.denominateur);

//         return 0;
// }
=======
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

    Vector3 position = { 0.0f, 0.0f, 0.0f };            // Set model position

    // Load animation data
    gameEngine::Animation animation("resources/guy/guy.iqm", "resources/guy/guyanim.iqm", "resources/guy/guytex.png");
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
                animation.refresh();
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
>>>>>>> master
