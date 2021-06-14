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
                    const gameEngine::encapsulation::BText &content,
                    const gameEngine::encapsulation::BColor &color,
                    bool initState,
                    const gameEngine::encapsulation::BColor &trueColor,
                    const gameEngine::encapsulation::BColor &falseColor,
                    const gameEngine::encapsulation::BColor &selectColor
                )
    : AButton{size, pos, content, color}
{
    _checkState = initState;
    _trueColor = trueColor;
    _falseColor = falseColor;

    setCheckRectColor();

}

CheckBox::~CheckBox()
{
}

//-----------------

void CheckBox::initCheckRect() noexcept
{
    Vector<float> size = this->getSize();
    size._y = (size._y * 90) / 100;
    size._x = (size._x * 20) / 100;
    setCheckRectColor();
    _checkRect.setTransform().setPosition({0, 0, 0});
    _checkRect.setTransform().setScale({100, 100, 100});
}


void CheckBox::setCheckRectColor() noexcept
{
    if (_checkState)
        _checkRect.setColor(_trueColor);
    else
        _checkRect.setColor(_falseColor);
}


CheckBox::CheckBox(const std::shared_ptr<gameEngine::encapsulation::BRectangle> &rect, const std::shared_ptr<gameEngine::encapsulation::BText> &content)
    : AButton(rect, content)
{
}


//getter

bool CheckBox::getState() const noexcept
{
    return _checkState;
}

void CheckBox::draw()
{
   // this->AButton::draw();
    _checkRect.draw();
   // (*_content).setColor(BLACK);
    (*_content).setTextSize(100);
    (*_content).draw();
    std::cout << (*(_content.get())) << std::endl;
    _content.get()->draw();
}