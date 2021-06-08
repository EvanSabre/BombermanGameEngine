/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Gamepad
*/

#include "Gamepad.hpp"

gameEngine::encapsulation::Gamepad::Gamepad() {}

bool gameEngine::encapsulation::Gamepad::isKeyPressed(int key, int device)
{
    return IsGamepadButtonPressed(device, key);
}

bool gameEngine::encapsulation::Gamepad::isKeyDown(int key, int device)
{
    return IsGamepadButtonDown(device, key);
}

bool gameEngine::encapsulation::Gamepad::isKeyUp(int key, int device)
{
    return IsGamepadButtonUp(device, key);
}

bool gameEngine::encapsulation::Gamepad::isKeyReleased(int key, int device)
{
    return IsGamepadButtonReleased(device, key);
}

const std::string gameEngine::encapsulation::Gamepad::getDeviceName(int device)
{
    std::string name{GetGamepadName(device)};

    name += "#" + std::to_string(device);
    return name;
}

bool gameEngine::encapsulation::Gamepad::isDeviceAvailable(int device)
{
    return IsGamepadAvailable(device);
}

bool gameEngine::encapsulation::Gamepad::isDeviceName(int device, const char *name)
{
    return IsGamepadName(device, name);
}

int gameEngine::encapsulation::Gamepad::getKeyPressed(void)
{
    return GetGamepadButtonPressed();
}

int gameEngine::encapsulation::Gamepad::getCharPressed(void)
{
    return -1;
}