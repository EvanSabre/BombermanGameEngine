/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** AButton
*/

#include "AButton.hpp"

using namespace gameEngine::encapsulation;

AButton::AButton(const Vector<float> &size, const Vector<float> &pos, const BText &content,
const BColor &color, const BColor &selectColor, float rotation)
{
    _selectColor = std::make_shared<BColor>(selectColor);
    _rectangle = std::make_shared<BRectangle>(size, pos, color, rotation);
    _content = std::make_shared<BText>(content);
    _state = gameEngine::interfaces::IButton::NORMAL;

}

AButton::AButton(const std::shared_ptr<BRectangle> &rect, const std::shared_ptr<BText> &text)
{
    _rectangle = rect;
    _content = text;
    _state = gameEngine::interfaces::IButton::NORMAL;
}

AButton::~AButton()
{
}

//GETTERS
Vector<float> AButton::getPos() const noexcept
{
    return _rectangle->getRectPosition();
}

Vector<float> AButton::getSize() const noexcept
{
    return _rectangle->getRectSize();
}

BText AButton::getContent() const noexcept
{
    return *_content;
}

AButton::State AButton::getState() const noexcept
{
    return _state;
}

//SETTERS
void AButton::setPos(const Vector<float> &pos)
{
    _rectangle->setRectPosition(pos);
}

void AButton::setRotation(const float &rotation)
{
    _rectangle->setRotation(rotation);
}

void AButton::setSize(const Vector<float> &size)
{
    _rectangle->setRectSize(size);
}

void AButton::setColor(const BColor &color)
{
    _rectangle->setColor(color);
}

void AButton::setContentStr(const std::string &str)
{
    _content->setStr(str);
}

bool AButton::isInsideButton(const Vector<float> &point)
{
    if (_rectangle->checkPointInside(point)) {
        _state = MOUSE_HOVER;
        return true;
    }
    _state = NORMAL;
    return false;
}

bool AButton::isButtonPressed(const Vector<float> &mousePos)
{
    if (isInsideButton(mousePos) && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        _state = PRESSED;
        return true;
    }
    return false;
}

bool AButton::isButtonReleased()
{
    if (_state == PRESSED && IsMouseButtonReleased(MOUSE_BUTTON_RIGHT)) {
        _state = NORMAL;
        return true;
    }
    return false;
}

void AButton::update()
{
    Vector2 tmp = GetMousePosition();
    Vector<float> vec(tmp.x, tmp.y);

    isButtonPressed(vec);
    isInsideButton(vec);
    isButtonReleased();
}

void AButton::drawButtonRect()
{
    _rectangle->draw();
    _content->draw();
}

void AButton::drawOutline()
{
    if (_state == MOUSE_HOVER || _state == PRESSED)
        _rectangle->drawLines(*_selectColor);
}

void AButton::draw()
{
    drawButtonRect();
}
