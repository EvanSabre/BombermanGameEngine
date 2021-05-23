/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** WindowManager
*/

#include "game/managers/WindowManager.hpp"

game::Managers::WindowManager::WindowManager()
{
    _height = 0;
    _width = 0;
    _windowName = "";
    is2D = false;
    is3D = false;
}

game::Managers::WindowManager::~WindowManager()
{
    if (IsWindowReady())
        CloseWindow();
}

bool game::Managers::WindowManager::createWindow(std::string name, int height, int width)
{
    _height = height;
    _width = width;
    _windowName = name;
    InitWindow(width, height, name.c_str());
    if (!IsWindowReady()) {
        dprintf(2, "Error initializing window\n");
        return false;
    }
    return true;
}

void game::Managers::WindowManager::resizeWindow(int height, int width)
{
    _height = height;
    _width = width;
    SetWindowSize(width, height);
}

void game::Managers::WindowManager::deleteWindow(void)
{
    if (IsWindowReady())
        CloseWindow();
}

void *game::Managers::WindowManager::getWindow(void) const
{
    return _window;
}

void game::Managers::WindowManager::setFullScreen(void)
{
    ToggleFullscreen();
}

void game::Managers::WindowManager::setBackgroundColor(Color color)
{
    ClearBackground(color);
}

void game::Managers::WindowManager::set3DMode(camera camera)
{
    if (is2D)
        EndMode2D();
    BeginMode3D(camera);
}

void game::Managers::WindowManager::set2DMode(camera camera)
{
    if (is3D)
        EndMode3D();
    BeginMode2D(camera);
}
