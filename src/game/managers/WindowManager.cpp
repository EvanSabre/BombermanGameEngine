/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** WindowManager
*/

#include "game/managers/WindowManager.hpp"

game::Managers::WindowManager::WindowManager()
{
    _size._x = 0;
    _size._y = 0;
    _windowName = "";
    is2D = false;
    is3D = false;
}

game::Managers::WindowManager::~WindowManager()
{
    if (IsWindowReady())
        CloseWindow();
}

bool game::Managers::WindowManager::createWindow(std::string name, Vector<int> size)
{
    _size = size;
    _windowName = name;
    InitWindow(size._x, size._y, name.c_str());
    if (!IsWindowReady()) {
        std::cerr << "WINDOW: Eroor initializing" << std::endl;
        return false;
    }
    return true;
}

void game::Managers::WindowManager::resizeWindow(const Vector<int> &size)
{
    _size._y = size._y;
    _size._x = size._x;
    SetWindowSize(size._x, size._y);
}

void game::Managers::WindowManager::deleteWindow(void)
{
    if (IsWindowReady())
        CloseWindow();
}

bool game::Managers::WindowManager::isRunning() const noexcept
{
    if (!WindowShouldClose())
        return true;
    return false;
}


// void *game::Managers::WindowManager::getWindow(void) const
// {
//     return GetWindowHandle();
// }

void game::Managers::WindowManager::setFullScreen(void)
{
    ToggleFullscreen();
}

void game::Managers::WindowManager::setBackgroundColor(const gameEngine::encapsulation::BColor &color)
{
    ClearBackground(color.getObj());
}

void game::Managers::WindowManager::set3DMode(const gameEngine::encapsulation::BCamera &camera)
{
    if (is2D)
        EndMode2D();
    camera.beginMode();
}

void game::Managers::WindowManager::set2DMode(const gameEngine::encapsulation::BCamera2D &camera)
{
    if (is3D)
        EndMode3D();
    camera.beginMode();
}

Vector<int> game::Managers::WindowManager::getWindowSize() const
{
    return _size;
}
