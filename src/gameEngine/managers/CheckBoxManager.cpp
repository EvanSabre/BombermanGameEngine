/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** CheckBoxManager
*/

#include "CheckBoxManager.hpp"

using namespace gameEngine::managers;
using namespace gameEngine::encapsulation;

CheckBoxManager::CheckBoxManager()
{}

CheckBoxManager::~CheckBoxManager()
{}

bool CheckBoxManager::isClicked(const Vector<float> &pos)
{
    for (auto it : _currentElts) {
        if (it->isButtonPressed(pos))
            return true;
    }
    return false;
}

bool CheckBoxManager::isClicked(const std::string &content)
{
    Vector2 mouse;

    for (auto it : _currentElts) {
        if (it->getContent().getStr() == content) {
            mouse = GetMousePosition();
            return it->isButtonPressed(Vector<float>(mouse.x, mouse.y));
        }
    }
    return false;
}

bool CheckBoxManager::isClicked(const std::string &CheckBoxContent, const Vector<float> &mousePos)
{
    for (auto it : _currentElts) {
        if (it->getContent().getStr() == CheckBoxContent && it->isButtonPressed(mousePos))
            return true;
    }
    return false;
}

std::shared_ptr<gameEngine::encapsulation::CheckBox> CheckBoxManager::getClickedElt(const Vector<float> &pos)
{
    // for (auto it = _currentCheckBoxs.begin(); it != _currentCheckBoxs.end(); it++) {
    //     if (it->isCheckBoxPressed(pos))
    //         return std::make_shared<gameEngine::encapsulation::CheckBox>(it);
    // }
    return nullptr;
}

void CheckBoxManager::createCheckBown(const std::shared_ptr<BTexture2D> &texture, const std::shared_ptr<BRectangle> &rect, const std::shared_ptr<BText> &content)
{
    std::shared_ptr<CheckBox> CheckBox = std::make_shared<gameEngine::encapsulation::CheckBox>(texture, rect, content);

    _currentElts.push_back(CheckBox);
    return;
    //return true;
}

void CheckBoxManager::pushElt(std::shared_ptr<gameEngine::encapsulation::CheckBox> CheckBox)
{
    _currentElts.push_back(CheckBox);
}

std::vector<std::shared_ptr<gameEngine::encapsulation::CheckBox>> CheckBoxManager::getCurrentElts() const
{
    return _currentElts;
}

void CheckBoxManager::draw()
{
    for (auto it : _currentElts) {
        it->draw();
    }
}

void CheckBoxManager::update()
{
    for (auto it : _currentElts) {
        it->update();
    }
}