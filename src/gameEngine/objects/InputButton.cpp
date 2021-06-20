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

InputButton::InputButton(const Vector<float> &size, const Vector<float> &pos, std::size_t maxInput, const encapsulation::BText &content,
                const encapsulation::BColor &color, bool relative, const encapsulation::BColor &selectColor) :
            AButton(size, pos, content, color, selectColor), _currentChar(0), _maxInput(maxInput), _canInput(true)
{
    _content->setTextSize(size._x / 2 / maxInput + content.getTextSize());
    if (relative)
        _content->setTextPosition(Vector<float>(pos._x, pos._y - content.getTextSize() / 2));
    else
        _content->setTextPosition(content.getTextPosition());
    _content->setColor(content.getColor());
    _content->setStr(content.getStr());
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

bool InputButton::checkValidate()
{
    return _validate;
}

void InputButton::setCanInput(bool can)
{
    _canInput = can;
}

void InputButton::updateInput()
{
    if (_input.size() >= (size_t)_maxInput) {
        return;
    }
    getNextChar();
    while (_currentChar > 0) {
        if ((_currentChar >= 32 && _currentChar <= 125)) {
            _input.push_back((char)_currentChar);
        }
        getNextChar();
        _content->setStr(_input);
        if (IsKeyPressed(KEY_BACKSPACE) && !_input.empty())
            _input.pop_back();
    }
}

void InputButton::draw()
{
    if (_enabled) {
        drawButtonRect();
        drawOutline();
        _content->draw();
    }
}

void InputButton::update()
{
    _validate = false;
    updateState();
    if (isFocus() && _canInput) {
        updateInput();
    }
    if (checkAction()) {
        _input.erase();
        _content->setStr(_input);
    }
    if (GetKeyPressed() == KEY_ENTER)
        _validate = true;
}

std::string InputButton::getContent() const noexcept
{
    std::cout << _content << std::endl;
    return _content->getStr();
}
