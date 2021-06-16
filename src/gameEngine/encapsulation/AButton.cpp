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
    Vector<float> pos(
        _rectangle->getTransform()._position._x,
        _rectangle->getTransform()._position._y);

    return pos;
}

Vector<float> AButton::getSize() const noexcept
{
    Vector<float> scale(
        _rectangle->getTransform()._scale._x,
        _rectangle->getTransform()._scale._y);

    return scale;
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
    _rectangle->setTransform()._position._x = pos._x;
    _rectangle->setTransform()._position._y = pos._y;
}

void AButton::setRotation(const float &rotation)
{
    _rectangle->setTransform()._rotation._x = rotation;
}

void AButton::setSize(const Vector<float> &size)
{
    _rectangle->setTransform()._scale._x = size._x;
    _rectangle->setTransform()._scale._y = size._y;
}

void AButton::setColor(const BColor &color)
{
    _rectangle->setColor(color);
}

void AButton::setContentStr(const std::string &str)
{
    _content->setStr(str);
}

void AButton::setCallback(std::function<void(std::shared_ptr<game::managers::GameManager> info)> func,
std::shared_ptr<game::managers::GameManager> infoPtr)
{
    _infoPtr = infoPtr;
    _callback = func;
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
    if (_state == MOUSE_HOVER && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        _state = NORMAL;
        return true;
    }
    return false;
}

void AButton::updateState()
{
    Vector2 tmp = GetMousePosition();
    Vector<float> vec(tmp.x, tmp.y);

    isInsideButton(vec);
    isButtonPressed(vec);
    if (isButtonReleased())
        _callback(_infoPtr);
}

void AButton::update()
{
    updateState();
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
