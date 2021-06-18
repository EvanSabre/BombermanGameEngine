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
    _content.setTextSize(size._x / 2 / maxInput);
    _content.setTextPosition(content.getTextPosition());
    _content.setColor(content.getColor());
    _content.setStr(content.getStr());
    //_content.setColor(color);
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
    if (_input.size() >= _maxInput) {
        return;
    }
    getNextChar();
    while (_currentChar > 0) {
        if ((_currentChar >= 32 && _currentChar <= 125)) {
            _input.push_back((char)_currentChar);
        }
        getNextChar();
        if (IsKeyPressed(KEY_BACKSPACE) && !_input.empty())
            _input.pop_back();
        _content.setStr(_input);
    }
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
    if (isFocus())
        updateInput();
    if (checkAction()) {
        _input.erase();
        _content.setStr(_input);
    }
}

std::string InputButton::getContent() const noexcept
{
    return _content.getStr();
}
