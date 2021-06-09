/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** InputManager
*/

#include "InputManager.hpp"

gameEngine::managers::InputManager::~InputManager()
{}

bool gameEngine::managers::InputManager::isKeyPressed(int key)
{
    return input->isKeyPressed(key, _id);
}

bool gameEngine::managers::InputManager::isKeyReleased(int key)
{
    return input->isKeyPressed(key, _id);
}

int gameEngine::managers::InputManager::getLastKeyPressed()
{
    return input->getKeyPressed();
}


bool gameEngine::managers::InputManager::mapDefaultKeys(int, int)
{
    
}
