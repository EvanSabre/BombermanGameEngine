/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Keyboard
*/

#include "Keyboard.hpp"
#include <stdlib.h>

gameEngine::encapsulation::Keyboard::Keyboard() {}

bool gameEngine::encapsulation::Keyboard::isKeyPressed(int key, int device)
{
    return IsKeyPressed(key);
}

bool gameEngine::encapsulation::Keyboard::isKeyDown(int key, int device)
{
    return IsKeyDown(key);
}

bool gameEngine::encapsulation::Keyboard::isKeyUp(int key, int device)
{
    return IsKeyUp(key);
}

bool gameEngine::encapsulation::Keyboard::isKeyReleased(int key, int device)
{
    return IsKeyReleased(key);
}

const char *gameEngine::encapsulation::Keyboard::getDeviceName(int device)
{
    return NULL;
}

bool gameEngine::encapsulation::Keyboard::isDeviceAvailable(int device)
{
    return true;
}

bool gameEngine::encapsulation::Keyboard::isDeviceName(int device, const char *name)
{
    return true;
}

int gameEngine::encapsulation::Keyboard::getKeyPressed(void)
{
    return GetKeyPressed();
}

int gameEngine::encapsulation::Keyboard::getCharPressed(void) {
    return GetCharPressed();
}
