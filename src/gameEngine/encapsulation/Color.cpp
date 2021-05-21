/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Collor
*/

#include "include/gameEngine/encapsulation/Color.hpp"

using namespace gameEngine;

std::ostream& operator<<(std::ostream& out, const encapsulation::Color &color)
{
    out << "Color : (" << (int)color.getRed() << ", " << (int)color.getGreen() << ", ";
    out << (int)color.getBlue() << ", " << (int)color.getAlpha() << ")";
    return out;
}


encapsulation::Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    this->_r = r;
    this->_g = g;
    this->_b = b;
    this->_a = a;
}

encapsulation::Color::Color(const Color &ref)
{
    this->_r = ref._r;
    this->_g = ref._g;
    this->_b = ref._b;
    this->_a = ref._a;
}

encapsulation::Color &encapsulation::Color::operator=(const Color &ref)
{
    if (this == &ref)
        return *this;
    this->_r = ref._r;
    this->_g = ref._g;
    this->_b = ref._b;
    this->_a = ref._a;
    return (*this);
}

encapsulation::Color::~Color()
{
}

//getter
unsigned char encapsulation::Color::getRed() const noexcept
{
    return this->_r;
}

unsigned char encapsulation::Color::getGreen() const noexcept
{
    return this->_g;
}

unsigned char encapsulation::Color::getBlue() const noexcept
{
    return this->_b;
}

unsigned char encapsulation::Color::getAlpha() const noexcept
{
    return this->_a;
}

//setter
void encapsulation::Color::setRed(unsigned char value) noexcept
{
    this->_r = value;
}

void encapsulation::Color::setGreen(unsigned char value) noexcept
{
    this->_g = value;
}

void encapsulation::Color::setBlue(unsigned char value) noexcept
{
    this->_b = value;
}

void encapsulation::Color::setAlpha(unsigned char value) noexcept
{
    this->_a = value;
}

void encapsulation::Color::copy(const Color &ref) noexcept
{
    this->_r = ref._r;
    this->_g = ref._g;
    this->_b = ref._b;
    this->_a = ref._a;
}