/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** InputButton
*/

#include "InputButton.hpp"

using namespace gameEngine;
using namespace gameEngine::object;

#define MAX_INPUTS 15

InputButton::InputButton(const Vector<float> &size, const Vector<float> &pos, const int &maxInput, const encapsulation::BText &content,
                const encapsulation::BColor &color, const encapsulation::BColor &selectColor) :
            AButton(size, pos, content, color, selectColor), _currentChar(0), _maxInput(maxInput)
{
    _content.setTextPosition(Vector<float>(pos._x, pos._y - size._y / 2));
    _content.setTextSize(size._x / maxInput);
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
    if (_input.size() >= _maxInput)
        return;
    _currentChar = GetCharPressed();
    while (_currentChar > 0) {
        if ((_currentChar >= 32 && _currentChar <= 125)) {
            _input.push_back((char)_currentChar);
            _action = false;
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
    updateState();
    if (_action) {
        _input.erase();
        _content.setStr(_input);
        updateInput();
    }
}

std::string InputButton::getContent() const noexcept
{
    return _content.getStr();
}