/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** ButtonManager
*/

#include "ButtonManager.hpp"
using namespace game;
using namespace Managers;

ButtonManager::ButtonManager()
{}

ButtonManager::~ButtonManager()
{}

bool ButtonManager::isButtonClicked(Vector<double> pos)
{
    for (auto it : _currentButtons) {
        if (it.getPos() == pos) {
            return true;
        }
    }
    return false;
}

bool ButtonManager::isButtonClicked(const std::string &buttonContent, Vector<double> pos)
{
    for (auto it : _currentButtons) {
        if (it.getContent() == buttonContent && it.getPos() == pos)
            return true;
    }
    return false;
}

gameEngine::Button createButton(Vector<double> pos, Vector<double> size)
{
    
}

std::vector<gameEngine::Button> ButtonManager::getCurrentButtons() const
{
    return _currentButtons;
}