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
    const int x = text.getPosition()._x;
    const int y = text.getPosition()._y;

    out << "Text : " << text.getStr()  << "\n\t";
    out << text.getColor() << " Position : (" << x << ", " << y << ")";
    out << " Size : " << text.getSize();
    return out;
}

encapsulation::BText::BText(const std::string &str, const Vector<int> &pos,
                const BColor &color, const int &size)
    : ADrawable()
{
    this->_color = color;
    this->_position = {(float)pos._x, (float)pos._y, _position._z};
    TEXT_SIZE = size;
    this->_str.assign(str);
}

encapsulation::BText::BText(const BText &ref)
{
    this->setStr(ref.getStr());
    this->setColor(ref.getColor());
    this->setPosition(ref.getPosition());
    this->setSize(ref.getSize());
    this->setSpacing(ref.getSpacing());
    this->setScale(ref.getScale());
}

encapsulation::BText &encapsulation::BText::operator=(const BText &ref)
{
    if (this == &ref)
        return *this;
    this->setStr(ref.getStr());
    this->setColor(ref.getColor());
    this->setPosition(ref.getPosition());
    this->setSize(ref.getSize());
    this->setSpacing(ref.getSpacing());
    this->setScale(ref.getScale());
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

Vector<int> encapsulation::BText::getTextPosition() const noexcept
{
    Vector<int> pos = {_position._x, _position._y};

    return pos;
}

int encapsulation::BText::getTextSize() const noexcept
{
    return (int)TEXT_SIZE;
}

encapsulation::BFont encapsulation::BText::getFont() const noexcept
{
    return this->_font;
}

float encapsulation::BText::getSpacing() const noexcept
{
    return TEXT_SPACING;
}

//--------------------------

//SETTER

void encapsulation::BText::setStr(const std::string &str) noexcept
{
    this->_str.assign(str);
}

void encapsulation::BText::setTextSize(const int &size) noexcept
{
    TEXT_SIZE = (float)size;
}

void encapsulation::BText::setTextPosition(const Vector<int> &position) noexcept
{
    this->_position = {(float)position._x, (float)position._y, _position._z};
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
    TEXT_SPACING = spacing;
}

//--------------------

//DRAW

void encapsulation::BText::draw() const noexcept
{
    if (this->_font.isLoad()) {
        Vector2 pos = {_position._x, _position._y};

        DrawTextEx(_font.getObj(), _str.c_str(), pos, SCALE_SIZE, TEXT_SPACING,
            _color.getObj());
    } else {
        DrawText(_str.c_str(), (int)_position._x, (int)_position._y, SCALE_SIZE, _color.getObj());
    }
}
