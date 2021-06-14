/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** CheckBox
*/

#include "CheckBox.hpp"

using namespace gameEngine::encapsulation;

CheckBox::CheckBox(const Vector<float> &size,
                    const Vector<float> &pos,
                    const BText &content,
                    const BColor &color,
                    bool initState,
                    const BColor &trueColor,
                    const BColor &falseColor,
                    const BColor &selectColor,
                    const std::string &textureFile,
                    float rotation, int nbFrames
                )
    : AButton(size, pos, content, color)
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
    _checkRect.setSize({size._x, size._y, 0});
}


void CheckBox::setCheckRectColor() noexcept
{
    if (_checkState)
        _checkRect.setColor(_trueColor);
    else
        _checkRect.setColor(_falseColor);
}


CheckBox::CheckBox(const std::shared_ptr<BTexture2D> &text, const std::shared_ptr<BRectangle> &rect, const std::shared_ptr<BText> &content)
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
    // if (_checkState)
    //     this->gameEngine::encapsulation::Button::setColor(_trueColor);
    // else
    //     this->gameEngine::encapsulation::Button::setColor(_falseColor);
    this->AButton::draw();
    _checkRect.draw();
}