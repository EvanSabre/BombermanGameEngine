/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** PopUp
*/

#include "PopUp.hpp"

using namespace gameEngine::component;

PopUp::PopUp(const std::string &text, const Vector<float> &pos, const Vector<float> &size) : _buttonText("Validate", Vector<float>(pos._x + 40, pos._y + size._y / 2), WHITE, 30),
                                                                                             _button(Vector<float>(135, 30), Vector<float>(pos._x + 40, pos._y + size._y / 2), _buttonText, DARKGRAY, WHITE, "./assets/Backgrounds/button_background1.png"),
                                                                                             _text(text, Vector<float>(pos._x + 10, pos._y + 30), WHITE, 20),
                                                                                             _rect(size, pos, BLACK)
{
}

PopUp::~PopUp()
{
}

void PopUp::setEnabled(bool enabled)
{
    _enabled = enabled;
}

bool PopUp::getEnabled() const
{
    return _enabled;
}

void PopUp::update()
{
    _button.update();
    if (_button.checkAction()) {
        _enabled = false;
    }
}

void PopUp::draw()
{
    if (_enabled) {
        _rect.draw();
        _text.draw();
        _button.draw();
    }
}

std::string PopUp::getContent() const noexcept
{
    return _text.getStr();
}
