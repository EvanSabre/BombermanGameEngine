/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BText
*/

#include "BText.hpp"

using namespace gameEngine;

std::ostream& operator<<(std::ostream& out, const encapsulation::BText &text)
{
    const int x = text.getTransform().getPosition()._x;
    const int y = text.getTransform().getPosition()._y;

    out << "Text : " << text.getStr()  << "\n\t";
    out << text.getColor() << " Position : (" << x << ", " << y << ")";
    out << " Size : " << text.getTransform().getScale()._x;
    return out;
}

encapsulation::BText::BText(const std::string &str, const Vector<float> &pos,
                const BColor &color, const int &size,
                gameEngine::encapsulation::ADrawable *relativeObj)
    : ADrawable()
{
    this->_color = color;
    if (relativeObj != nullptr) {
        this->setTransform().setPosition({
            relativeObj->getTransform().getPosition()._x + pos._x,
            relativeObj->getTransform().getPosition()._y + pos._y,
            relativeObj->getTransform().getPosition()._z + this->getTransform().getPosition()._z});
    } else {
        this->setTransform().setPosition({
            pos._x,
            pos._y,
            this->getTransform().getPosition()._z});
    }
    this->setTransform()._scale._x = (float)size;
    this->_str.assign(str);
}

encapsulation::BText::BText(const BText &ref)
{
    this->setStr(ref.getStr());
    this->setColor(ref.getColor());
    this->setTransform().setPosition(ref.getTransform().getPosition());
    this->setTransform().setRotation(ref.getTransform().getRotation());
    this->setTransform().setScale(ref.getTransform().getScale());
    this->setSpacing(ref.getSpacing());
}

encapsulation::BText &encapsulation::BText::operator=(const BText &ref)
{
    if (this == &ref)
        return *this;
    this->setStr(ref.getStr());
    this->setColor(ref.getColor());
    this->setTransform().setPosition(ref.getTransform().getPosition());
    this->setTransform().setRotation(ref.getTransform().getRotation());
    this->setTransform().setScale(ref.getTransform().getScale());
    this->setSpacing(ref.getSpacing());
    return *this;
}

encapsulation::BText::~BText()
{
}

//------------------------

//GETTER

std::string encapsulation::BText::getStr() const noexcept
{
    return this->_str;
}

Vector<float> encapsulation::BText::getTextPosition() const noexcept
{
    Vector<float> pos(
        this->getTransform().getPosition()._x,
        this->getTransform().getPosition()._y);

    return pos;
}

float encapsulation::BText::getTextSize() const noexcept
{
    return this->getTransform().getScale()._x;
}

encapsulation::BFont encapsulation::BText::getFont() const noexcept
{
    return this->_font;
}

float encapsulation::BText::getSpacing() const noexcept
{
    return this->getTransform().getScale()._y;
}

//--------------------------

//SETTER

void encapsulation::BText::setStr(const std::string &str) noexcept
{
    this->_str.assign(str);
}

void encapsulation::BText::setTextSize(const float &size) noexcept
{
    this->setTransform()._scale._x = size;
}

void encapsulation::BText::setTextPosition(const Vector<float> &position) noexcept
{
    this->setTransform()._position._x = position._x;
    this->setTransform()._position._y = position._y;
}

void encapsulation::BText::setFont(const BFont &font) noexcept
{
    this->_font = font;
}

void encapsulation::BText::unloadFont() noexcept
{
    this->_font.unload();
}

void encapsulation::BText::setSpacing(const float &spacing) noexcept
{
    this->setTransform()._scale._y = spacing;
}

//--------------------

//DRAW
std::string encapsulation::BText::getContent() const noexcept
{
    return getStr();
}

void encapsulation::BText::draw()
{
    if (this->_font.isLoad()) {
        Vector2 pos = {
            this->getTransform().getPosition()._x,
            this->getTransform().getPosition()._y};

        DrawTextEx(
            _font.getObj(),
            _str.c_str(),
            pos,
            this->getTransform().getScale()._x,
            this->getTransform().getScale()._y,
            _color.getObj());
    } else {
        DrawText(
            _str.c_str(),
            (int)this->getTransform().getPosition()._x,
            (int)this->getTransform().getPosition()._y,
            this->getTransform().getScale()._x,
            _color.getObj());
    }
}
