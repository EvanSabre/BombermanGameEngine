/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** InputButton
*/

#include "InputButton.hpp"

using namespace gameEngine;
using namespace gameEngine::object;

#define MAX_INPUT 15

InputButton::InputButton(const Vector<float> &size, const Vector<float> &pos, const encapsulation::BText &content,
                const encapsulation::BColor &color, const encapsulation::BColor &selectColor) :
            AButton(size, pos, content, color, selectColor), _currentChar(0)
{
    _content.setTextPosition(pos);
    _content.setTextSize(size._x / MAX_INPUT);
    _content.setColor(BLACK);
}

InputButton::~InputButton()
{
}

std::string InputButton::getInput() const noexcept
{
    return _input;
}

void InputButton::getNextChar() noexcept
{
    _currentChar = GetCharPressed();
}

void InputButton::updateInput()
{
    _currentChar = GetCharPressed();
    while (_currentChar > 0) {
        if ((_currentChar >= 32 && _currentChar <= 125)) {
            _input.push_back((char)_currentChar);
        }
        _currentChar = GetCharPressed();
    }
    if (IsKeyPressed(KEY_BACKSPACE) && !_input.empty())
        _input.pop_back();
    _content.setStr(_input);
}

void InputButton::draw()
{
    drawButtonRect();
    drawOutline();
    _content.draw();
}

void InputButton::update()
{
    updateInput();
    updateState();
}
