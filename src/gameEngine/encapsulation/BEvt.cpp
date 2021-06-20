/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BEvt
*/

#include "BEvt.hpp"

using namespace gameEngine::encapsulation;

bool BEvt::isKeyPressed(int key)
{
    return IsKeyPressed(key);
}

bool BEvt::isKeyDown(int key)
{
    return IsKeyDown(key);
}

bool BEvt::isKeyUp(int key)
{
    return IsKeyUp(key);
}

bool BEvt::isKeyReleased(int key)
{
    return IsKeyReleased(key);
}

int BEvt::getKeyPressed(void)
{
    return GetKeyPressed();
}

int BEvt::getCharPressed(void)
{
    return GetCharPressed();
}


bool BEvt::isMouseBtnPressed(int key)
{
    return IsMouseButtonPressed(key);
}

bool BEvt::isMouseBtnReleased(int key)
{
    return IsMouseButtonReleased(key);
}

bool BEvt::isMouseBtnDown(int key)
{
    return IsMouseButtonDown(key);
}

bool BEvt::isMouseBtnUp(int key)
{
    return IsMouseButtonUp(key);
}

Vector<float> BEvt::getMousePosition(void)
{
    Vector2 tmp = GetMousePosition();
    Vector<float> vec(tmp.x, tmp.y);
    return vec;
}
