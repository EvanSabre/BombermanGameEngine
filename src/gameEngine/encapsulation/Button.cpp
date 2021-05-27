/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Button
*/

#include "Button.hpp"

using namespace gameEngine::encapsulation;
using namespace gameEngine;

Button::Button(const Vector<float> &size, const Vector<float> &pos, const BColor &color,
                const std::string &content, float rotation, const std::string &textureFile) :
_rectangle(size, pos, color, rotation)
{
    if (textureFile != "")
        _texture.loadFromFile(textureFile);
    _state = NORMAL;
    _buttonPressed = false;
    _content = content;
}

Button::~Button()
{
    _texture.unload();
}

Vector<float> Button::getPos() const
{
    return _rectangle.getPos();
}

Vector<float> Button::getSize() const
{
    return _rectangle.getSize();
}

std::string Button::getContent() const
{
    return _content;
}

Button::State Button::getState() const
{
    return _state;
}

bool Button::getButtonPressed() const
{
    return _buttonPressed;
}

bool Button::isInsideButton(Vector<float> point)
{
    Vector2 vec;

    vec.x = point._x;
    vec.y = point._y;
    if (CheckCollisionPointRec(vec, _rectangle.getObj())) {
        _state = MOUSE_HOVER;
        return true;
    }
    _state = NORMAL;
    return false;
}

bool Button::isButtonPressed(Vector<float> mousePos)
{
    if (isInsideButton(mousePos) && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        _state = PRESSED;
        return true;
    }
    return false;
}

bool Button::isButtonReleased()
{
    if (_state == PRESSED && IsMouseButtonReleased(MOUSE_BUTTON_RIGHT)) {
        _buttonPressed = true;
        return true;
    }
    return false;
}