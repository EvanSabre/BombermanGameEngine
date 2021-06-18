/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** AButton
*/

#include "AButton.hpp"

using namespace gameEngine::encapsulation;


AButton::AButton(const Vector<float> &size, const Vector<float> &pos, const std::string &content,
const int &textSize, const BColor &color, const BColor &selectColor, float rotation)
{
    _selectColor = std::make_shared<BColor>(selectColor);
    _rectangle = std::make_shared<BRectangle>(size, pos, color, rotation);
    _content = std::make_shared<BText>(content, pos, BLACK, textSize);
    _state = gameEngine::interfaces::IButton::NORMAL;
    _action = false;
    _enabled = true;
    _focus = false;
    _callback = nullptr;
}

AButton::AButton(const Vector<float> &size, const Vector<float> &pos, const BText &content,
const BColor &color, const BColor &selectColor, float rotation)
{
    _selectColor = std::make_shared<BColor>(selectColor);
    _rectangle = std::make_shared<BRectangle>(size, pos, color, rotation);
    _content = std::make_shared<BText>(content);
    _state = gameEngine::interfaces::IButton::NORMAL;
    _action = false;
    _enabled = true;
    _callback = nullptr;
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

bool AButton::getEnabled() const noexcept
{
    return _enabled;
}


//SETTERS
void AButton::setEnabled(bool enabled)
{
    _enabled = enabled;
}

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
std::shared_ptr<game::managers::GameManager> &infoPtr)
{
    _infoPtr = infoPtr;
    _callback = func;
}

bool AButton::isInsideButton(const Vector<float> &point)
{
    if (_rectangle->checkPointInside(point)) {
        return true;
    }
    return false;
}

bool AButton::isButtonPressed(const Vector<float> &mousePos)
{
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        return true;
    }
    return false;
}

bool AButton::isButtonReleased()
{
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        return true;
    }
    return false;
}

bool AButton::isFocus()
{
    return _focus;
}

bool AButton::checkAction()
{
    if (_action) {
        _action = false;
        return true;
    }
    return false;
}


void AButton::updateState()
{
    Vector2 tmp = GetMousePosition();
    Vector<float> vec(tmp.x, tmp.y);

    if (_enabled && isInsideButton(vec)) {
        _focus = true;
        if(isButtonPressed(vec)) {
            _state = PRESSED;
        } else {
            _state = MOUSE_HOVER;
        }
        if (isButtonReleased()) {
            _action = true;
            _state = NORMAL;
        }
    } else {
        _focus = false;
        _state = NORMAL;
    }
    if (_action && _callback != nullptr)
        _callback(_infoPtr);
}

void AButton::update()
{
    updateState();
}

void AButton::drawButtonText()
{
    _content->draw();
}

void AButton::drawButtonRect()
{
    _rectangle->draw();
}

void AButton::drawOutline()
{
    if (_state == MOUSE_HOVER)
        _rectangle->drawLines(*_selectColor);
    if (_state == PRESSED)
        _rectangle->drawLines(BLUE);
}

void AButton::draw()
{
    drawButtonRect();
    drawButtonText();
}
