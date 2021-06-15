/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Keyboard
*/

#include "Keyboard.hpp"
#include <stdlib.h>
#include <iostream>


bool gameEngine::encapsulation::Keyboard::isKeyPressed(int key)
{
    return IsKeyPressed(key);
}

bool gameEngine::encapsulation::Keyboard::isKeyDown(int key)
{
    return IsKeyDown(key);
}

bool gameEngine::encapsulation::Keyboard::isKeyUp(int key)
{
    std::cout << "Idling" << std::endl;
    return IsKeyUp(key);
}

bool gameEngine::encapsulation::Keyboard::isKeyReleased(int key)
{
    return IsKeyReleased(key);
}

const std::string gameEngine::encapsulation::Keyboard::getDeviceName()
{
    std::string name{"Keyboard"};

    return name;
}

bool gameEngine::encapsulation::Keyboard::isDeviceAvailable()
{
    return true;
}

bool gameEngine::encapsulation::Keyboard::isDeviceName(const char *name)
{
    (void) name;
    return true;
}

int gameEngine::encapsulation::Keyboard::getKeyPressed(void)
{
    return GetKeyPressed();
}
