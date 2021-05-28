/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** InputManager
*/

#include "InputManager.hpp"

game::Managers::InputManager::~InputManager()
{
    
}

bool game::Managers::InputManager::isKeyPressed(int key)
{
    return input->isKeyPressed(key);
}

bool game::Managers::InputManager::isKeyReleased(int key)
{
    return input->isKeyPressed(key);
}

int game::Managers::InputManager::getKeyPressed()
{
    return input->getKeyPressed()
}

template <typename E>
bool game::Managers::InputManager::mapKey(int key, E interpret_value)
{
    
}

bool game::Managers::InputManager::mapDefaultKeys(int, int)
{
    
}
