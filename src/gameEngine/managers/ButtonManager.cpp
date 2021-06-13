/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** ButtonManager
*/

#include "ButtonManager.hpp"

using namespace gameEngine::managers;
using namespace gameEngine::encapsulation;

ButtonManager::ButtonManager()
{}

ButtonManager::~ButtonManager()
{}

bool ButtonManager::isButtonClicked(const Vector<float> &pos)
{
    for (auto it : _currentButtons) {
        if (it->isButtonPressed(pos))
            return true;
    }
    return false;
}

bool ButtonManager::isButtonClicked(const std::string &content)
{
    Vector2 mouse;

    for (auto it : _currentButtons) {
        if (it->getContent().getStr() == content) {
            mouse = GetMousePosition();
            return it->isButtonPressed(Vector<float>(mouse.x, mouse.y));
        }
    }
    return false;
}

bool ButtonManager::isButtonClicked(const std::string &buttonContent, const Vector<float> &mousePos)
{
    for (auto it : _currentButtons) {
        if (it->getContent().getStr() == buttonContent && it->isButtonPressed(mousePos))
            return true;
    }
    return false;
}

std::shared_ptr<gameEngine::encapsulation::Button> ButtonManager::getClickedButton(const Vector<float> &pos)
{
    // for (auto it = _currentButtons.begin(); it != _currentButtons.end(); it++) {
    //     if (it->isButtonPressed(pos))
    //         return std::make_shared<gameEngine::encapsulation::Button>(it);
    // }
    return nullptr;
}

void ButtonManager::createButton(const std::shared_ptr<BTexture2D> &texture, const std::shared_ptr<BRectangle> &rect, const std::shared_ptr<BText> &content)
{
    std::shared_ptr<Button> button = std::make_shared<Button>(texture, rect, content);

    _currentButtons.push_back(button);
    return;
    //return true;
}

void ButtonManager::pushButton(std::shared_ptr<gameEngine::encapsulation::Button> button)
{
    _currentButtons.push_back(button);
}

std::vector<std::shared_ptr<gameEngine::encapsulation::Button>> ButtonManager::getCurrentButtons() const
{
    return _currentButtons;
}

void ButtonManager::drawButtons()
{
    for (auto it : _currentButtons) {
        it->drawButton();
    }
}

void ButtonManager::updateButtons()
{
    for (auto it : _currentButtons) {
        it->update();
    }
}
