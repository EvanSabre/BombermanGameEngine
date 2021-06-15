/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** CheckBox
*/

#include "CheckBox.hpp"

using namespace gameEngine::object;

CheckBox::CheckBox(const Vector<float> &size,
                    const Vector<float> &pos,
                    const encapsulation::BText &content,
                    const encapsulation::BColor &color,
                    const encapsulation::BColor &selectColor,
                    bool initState,
                    const encapsulation::BColor &trueColor,
                    const encapsulation::BColor &falseColor
                )
    : AButton(size, pos, content, color, selectColor)
{
    _checkState = initState;
    _trueColor = trueColor;
    _falseColor = falseColor;

    initCheckRect();
    initText();
}

CheckBox::~CheckBox()
{
}

//-----------------

void CheckBox::initText() noexcept
{
    Vector<float> pos = (*_content).getTextPosition();
    pos._x += _rectangle.get()->setTransform()._position._x;
    pos._y += _rectangle.get()->setTransform()._position._y;

    float rect_height = _rectangle.get()->setTransform()._scale._y;
    float rect_width = _rectangle.get()->setTransform()._scale._x;
    float size = (rect_height * 20) / 100;
    pos._y += ((rect_height / 2 ) - (size / 2));
    pos._x += (rect_width * 10) / 100;
    (*_content).setTextSize(size);
    (*_content).setTextPosition(pos);
}


void CheckBox::initCheckRect() noexcept
{
    Vector3T<float> size{_rectangle.get()->setTransform()._scale};
    Vector3T<float> pos{_rectangle.get()->setTransform()._position};

    pos._x += size._x;
    pos._y += size._y;


    size._y = (size._y * 90) / 100;
    size._x = (size._x * 20) / 100;
    float padding = (_rectangle.get()->setTransform()._scale._y - size._y) / 2;
    pos._x -= (size._x + padding);
    pos._y -= (size._y + padding);


    _checkRect.setTransform().setPosition(pos);
    _checkRect.setTransform().setScale(size);
    setCheckRectColor();
}


void CheckBox::setCheckRectColor() noexcept
{
    if (_checkState) {
        _checkRect.setColor(_trueColor);
    } else {
        _checkRect.setColor(_falseColor);
    }
}

//getter

bool CheckBox::getState() const noexcept
{
    return _checkState;
}

void CheckBox::draw()
{
    this->AButton::draw();
    this->AButton::drawOutline();
    _checkRect.draw();

}

void CheckBox::toggleState() noexcept
{
    if (_checkState)
        _checkState = false;
    else
        _checkState = true;
}

bool CheckBox::isButtonReleased()
{
    bool ret = this->AButton::isButtonReleased();

    if (ret)
        toggleState();
    setCheckRectColor();
    return ret;
}
