/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Collor
*/

#include "include/gameEngine/encapsulation/Colour.hpp"

using namespace gameEngine;

std::ostream& operator<<(std::ostream& out, const encapsulation::Colour &color)
{
    out << "Color : (" << (int)color.getRed() << ", " << (int)color.getGreen() << ", ";
    out << (int)color.getBlue() << ", " << (int)color.getAlpha() << ")";
    return out;
}


encapsulation::Colour::Colour(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    this->_r = r;
    this->_g = g;
    this->_b = b;
    this->_a = a;
}

encapsulation::Colour::Colour(const Colour &ref)
{
    this->_r = ref._r;
    this->_g = ref._g;
    this->_b = ref._b;
    this->_a = ref._a;
}

encapsulation::Colour::Colour(const Color &ref)
{
    this->_r = ref.r;
    this->_g = ref.g;
    this->_b = ref.b;
    this->_a = ref.a;
}

encapsulation::Colour &encapsulation::Colour::operator=(const Color &ref)
{
    if (this == &ref)
        return *this;
    this->_r = ref._r;
    this->_g = ref._g;
    this->_b = ref._b;
    this->_a = ref._a;
    return (*this);
}

encapsulation::Colour::~Color()
{
}

//getter
unsigned char encapsulation::Colour::getRed() const noexcept
{
    return this->_r;
}

unsigned char encapsulation::Colour::getGreen() const noexcept
{
    return this->_g;
}

unsigned char encapsulation::Colour::getBlue() const noexcept
{
    return this->_b;
}

unsigned char encapsulation::Colour::getAlpha() const noexcept
{
    return this->_a;
}

//setter
void encapsulation::Colour::setRed(unsigned char value) noexcept
{
    this->_r = value;
}

void encapsulation::Colour::setGreen(unsigned char value) noexcept
{
    this->_g = value;
}

void encapsulation::Colour::setBlue(unsigned char value) noexcept
{
    this->_b = value;
}

void encapsulation::Colour::setAlpha(unsigned char value) noexcept
{
    this->_a = value;
}

void encapsulation::Colour::copy(const Color &ref) noexcept
{
    this->_r = ref._r;
    this->_g = ref._g;
    this->_b = ref._b;
    this->_a = ref._a;
}