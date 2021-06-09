/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Gamepad
*/

#include "Gamepad.hpp"


bool gameEngine::encapsulation::Gamepad::isKeyPressed(int key)
{
    return IsGamepadButtonPressed(_deviceID, key);
}

bool gameEngine::encapsulation::Gamepad::isKeyDown(int key)
{
    return IsGamepadButtonDown(_deviceID, key);
}

bool gameEngine::encapsulation::Gamepad::isKeyUp(int key)
{
    return IsGamepadButtonUp(_deviceID, key);
}

bool gameEngine::encapsulation::Gamepad::isKeyReleased(int key)
{
    return IsGamepadButtonReleased(_deviceID, key);
}

const std::string gameEngine::encapsulation::Gamepad::getDeviceName()
{
    std::string name{GetGamepadName(_deviceID)};

    name += "#" + std::to_string(_deviceID);
    return name;
}

bool gameEngine::encapsulation::Gamepad::isDeviceAvailable()
{
    return IsGamepadAvailable(_deviceID);
}

bool gameEngine::encapsulation::Gamepad::isDeviceName(const char *name)
{
    return IsGamepadName(_deviceID, name);
}

int gameEngine::encapsulation::Gamepad::getKeyPressed(void)
{
    return GetGamepadButtonPressed();
}

int gameEngine::encapsulation::Gamepad::getCharPressed(void)
{
    return -1;
}