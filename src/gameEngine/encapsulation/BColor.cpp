/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Collor
*/

#include "BColor.hpp"

using namespace gameEngine;

std::ostream& operator<<(std::ostream& out, const encapsulation::BColor &color)
{
    out << "Color : (" << (int)color.getRed() << ", " << (int)color.getGreen() << ", ";
    out << (int)color.getBlue() << ", " << (int)color.getAlpha() << ")";
    return out;
}

encapsulation::BColor::BColor()
{
    this->_r = 0;
    this->_g = 0;
    this->_b = 0;
    this->_a = 255;
}

encapsulation::BColor::BColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    this->_r = r;
    this->_g = g;
    this->_b = b;
    this->_a = a;
}

encapsulation::BColor::BColor(const BColor &ref)
{
    this->_r = ref._r;
    this->_g = ref._g;
    this->_b = ref._b;
    this->_a = ref._a;
}

encapsulation::BColor::BColor(const Color &ref)
{
    this->_r = ref.r;
    this->_g = ref.g;
    this->_b = ref.b;
    this->_a = ref.a;
}

encapsulation::BColor &encapsulation::BColor::operator=(const BColor &ref)
{
    if (this == &ref)
        return *this;
    this->_r = ref._r;
    this->_g = ref._g;
    this->_b = ref._b;
    this->_a = ref._a;
    return (*this);
}

encapsulation::BColor &encapsulation::BColor::operator=(const TYPECOLOR &ref)
{
    this->_r = ref.r;
    this->_g = ref.g;
    this->_b = ref.b;
    this->_a = ref.a;
    return (*this);
}

encapsulation::BColor::~BColor()
{
}

//getter
unsigned char encapsulation::BColor::getRed() const noexcept
{
    return this->_r;
}

unsigned char encapsulation::BColor::getGreen() const noexcept
{
    return this->_g;
}

unsigned char encapsulation::BColor::getBlue() const noexcept
{
    return this->_b;
}

unsigned char encapsulation::BColor::getAlpha() const noexcept
{
    return this->_a;
}

Color encapsulation::BColor::getObj() const noexcept
{
    Color obj;

    obj.r = this->_r;
    obj.g = this->_g;
    obj.b = this->_b;
    obj.a = this->_a;
    return obj;
}


//setter
void encapsulation::BColor::setRed(unsigned char value) noexcept
{
    this->_r = value;
}

void encapsulation::BColor::setGreen(unsigned char value) noexcept
{
    this->_g = value;
}

void encapsulation::BColor::setBlue(unsigned char value) noexcept
{
    this->_b = value;
}

void encapsulation::BColor::setAlpha(unsigned char value) noexcept
{
    this->_a = value;
}

void encapsulation::BColor::copy(const BColor &ref) noexcept
{
    this->_r = ref._r;
    this->_g = ref._g;
    this->_b = ref._b;
    this->_a = ref._a;
}