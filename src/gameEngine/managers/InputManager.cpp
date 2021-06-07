/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** InputManager
*/

#include "InputManager.hpp"

game::managers::InputManager::~InputManager()
{
    
}

bool game::managers::InputManager::isKeyPressed(int key)
{
    return input->isKeyPressed(key);
}

bool game::managers::InputManager::isKeyReleased(int key)
{
    return input->isKeyPressed(key);
}

int game::managers::InputManager::getKeyPressed()
{
    return input->getKeyPressed()
}


bool game::managers::InputManager::mapDefaultKeys(int, int)
{
    
}
