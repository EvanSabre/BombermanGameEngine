/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** WindowManager
*/

#include "gameEngine/managers/WindowManager.hpp"

using namespace gameEngine::managers;

WindowManager::WindowManager()
{
    //@todo set fps from settings variable
    SetTargetFPS(60);
    _size._x = 0;
    _size._y = 0;
    _windowName = "";
    is2D = false;
    is3D = false;
}

WindowManager::~WindowManager()
{
    if (IsWindowReady())
        CloseWindow();
}

bool WindowManager::createWindow(std::string name, Vector<int> size)
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

void WindowManager::resizeWindow(const Vector<int> &size)
{
    _size._y = size._y;
    _size._x = size._x;
    SetWindowSize(size._x, size._y);
}

void WindowManager::deleteWindow(void)
{
    if (IsWindowReady())
        CloseWindow();
}

void WindowManager::BeginDraw()
{
    BeginDrawing();
}

void WindowManager::EndDraw()
{
    EndDrawing();
}

bool WindowManager::isRunning() const noexcept
{
    if (!WindowShouldClose())
        return true;
    return false;
}

// void *WindowManager::getWindow(void) const
// {
//     return GetWindowHandle();
// }

void WindowManager::setFullScreen(void)
{
    ToggleFullscreen();
}

void WindowManager::setBackgroundColor(const gameEngine::encapsulation::BColor &color)
{
    _color = color;
}

void WindowManager::clear() noexcept
{
    ClearBackground(_color.getObj());
}

void WindowManager::clear(const gameEngine::encapsulation::BColor &color)
{
    ClearBackground(color.getObj());
}


void WindowManager::set3DMode(const gameEngine::encapsulation::BCamera &camera)
{
    if (is2D)
        EndMode2D();
    camera.beginMode();
}

void WindowManager::set2DMode(const gameEngine::encapsulation::BCamera2D &camera)
{
    if (is3D)
        EndMode3D();
    camera.beginMode();
}

Vector<int> WindowManager::getWindowSize() const
{
    return _size;
}


void WindowManager::setWindowIcon(const std::string &path)
{
    Image img = LoadImage(path.c_str());

    SetWindowIcon(img);
}
