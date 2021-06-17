/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Gamepad
*/

#include "Gamepad.hpp"
#include <iostream>

bool gameEngine::encapsulation::Gamepad::isKeyPressed(int key)
{
    int axis = getAxisMovement();

    if (!this->isDeviceAvailable())
        return false;
    if (axis == key)
        return true;
    return IsGamepadButtonPressed(_deviceID, key - 400);
}

bool gameEngine::encapsulation::Gamepad::isKeyDown(int key)
{
    if (!this->isDeviceAvailable())
        return false;
    int axis = getAxisMovement();

    if (axis != gameEngine::KEY_NULL)
        return true;
    if (GetGamepadButtonPressed() == gameEngine::KEY_NULL)
        return getAxisMovement();
    return IsGamepadButtonDown(_deviceID, key - 400);
}

bool gameEngine::encapsulation::Gamepad::isKeyUp(int key)
{
    if (!this->isDeviceAvailable())
        return false;
    return IsGamepadButtonUp(_deviceID, key - 400);
}

bool gameEngine::encapsulation::Gamepad::isKeyReleased(int key)
{
    if (!this->isDeviceAvailable())
        return false;
    return IsGamepadButtonReleased(_deviceID, key - 400);
}

const std::string gameEngine::encapsulation::Gamepad::getDeviceName()
{
    std::string name = "";

    if (GetGamepadName(_deviceID))
        name = GetGamepadName(_deviceID);
    else
        name = std::to_string(_deviceID) + "#NotConnected";

    //name += "#" + std::to_string(_deviceID);
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

int gameEngine::encapsulation::Gamepad::getAxisMovement(void)
{
    if (GetGamepadAxisCount(_deviceID) < 0)
        return gameEngine::KEY_NULL;
    int axis0 = GetGamepadAxisMovement(_deviceID, 0);
    int axis1 = GetGamepadAxisMovement(_deviceID, 1);

    std::array<std::pair<bool, gameEngine::Key>, 4> directions =
    {
        std::make_pair<bool, gameEngine::Key>((-1 <= axis1 && axis1 < 1) && axis0 == -1, gameEngine::GAMEPAD_BUTTON_LEFT_FACE_LEFT),
        std::make_pair<bool, gameEngine::Key>((-1 <= axis1 && axis1 < 1) && axis0 == 1, gameEngine::GAMEPAD_BUTTON_LEFT_FACE_RIGHT),
        std::make_pair<bool, gameEngine::Key>((-1 <= axis0 && axis0 < 1) && axis1 == -1, gameEngine::GAMEPAD_BUTTON_LEFT_FACE_UP),
        std::make_pair<bool, gameEngine::Key>((-1 <= axis0 && axis0 < 1) && axis1 == 1, gameEngine::GAMEPAD_BUTTON_LEFT_FACE_DOWN)
    };
    for (auto &i : directions) {
        if (i.first)
            return i.second;
    }
    return gameEngine::KEY_NULL;
}

int gameEngine::encapsulation::Gamepad::getKeyPressed(void)
{
    if (GetGamepadButtonPressed() == gameEngine::KEY_NULL)
        return getAxisMovement();
    return GetGamepadButtonPressed() + 400;
}