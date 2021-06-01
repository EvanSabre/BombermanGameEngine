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
{
    this->_color = color;
    this->_pos = pos;
    this->_size = size;
    this->_str.assign(str);
}

encapsulation::BText::BText(const BText &ref)
{
    this->_str.assign(ref.getStr());
    this->_color = ref.getColor();
    this->_pos = ref.getPosition();
    this->_size = ref.getSize();
}

encapsulation::BText &encapsulation::BText::operator=(const BText &ref)
{
    if (this == &ref)
        return *this;
    this->_str.assign(ref.getStr());
    this->_color = ref.getColor();
    this->_pos = ref.getPosition();
    this->_size = ref.getSize();
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

encapsulation::BColor encapsulation::BText::getColor() const noexcept
{
    return this->_color;
}

Vector<int> encapsulation::BText::getPosition() const noexcept
{
    return this->_pos;
}

int encapsulation::BText::getSize() const noexcept
{
    return this->_size;
}

encapsulation::BFont encapsulation::BText::getFont() const noexcept
{
    return this->_font;
}

float encapsulation::BText::getSpacing() const noexcept
{
    return _spacing;
}



//--------------------------

//SETTER

void encapsulation::BText::setStr(const std::string &str) noexcept
{
    this->_str.assign(str);
}

void encapsulation::BText::setSize(const int &size) noexcept
{
    this->_size = size;
}

void encapsulation::BText::setPosition(const Vector<int> &position) noexcept
{
    this->_pos = position;
}

void encapsulation::BText::setColor(const BColor &color) noexcept
{
    this->_color = color;
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
    _spacing = spacing;
}


//--------------------

//DRAW

void encapsulation::BText::draw() const noexcept
{
    if (this->_font.isLoad()) {
        Vector2 pos = {(float)_pos._x, (float)_pos._y};

        DrawTextEx(_font.getObj(), _str.c_str(), pos, _size , _spacing,
            _color.getObj());
    } else {
        DrawText(_str.c_str(), _pos._x, _pos._y, _size, _color.getObj());
    }
}
