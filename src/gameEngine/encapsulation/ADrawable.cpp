/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** ADrawable
*/

#include "ADrawable.hpp"

using namespace gameEngine;

encapsulation::ADrawable::ADrawable()
{
}

encapsulation::ADrawable::~ADrawable()
{
}

//-----------------------
//GETTER

gameEngine::encapsulation::BColor encapsulation::ADrawable::getColor() const noexcept
{
    return this->_color;
}

Vector3T<float> encapsulation::ADrawable::getPosition() const noexcept
{
    return this->_position;
}

Vector3T<float> encapsulation::ADrawable::getSize() const noexcept
{
    return this->_size;
}

float encapsulation::ADrawable::getScale() const noexcept
{
    return this->_scale;
}

Vector3T<float> encapsulation::ADrawable::getScaledSize() const noexcept
{
    Vector3T<float> new_vec = this->_size;
    new_vec = new_vec * this->_scale;
    return new_vec;
}

//---------------------
//SETTER

void encapsulation::ADrawable::setColor(const gameEngine::encapsulation::BColor &color) noexcept
{
    this->_color = color;
}

void encapsulation::ADrawable::setPosition(const Vector3T<float> &pos) noexcept
{
    this->_position = pos;
}

void encapsulation::ADrawable::setSize(const Vector3T<float> &size) noexcept
{
    this->_size = size;
}

void encapsulation::ADrawable::setScale(float scale) noexcept
{
    this->_scale = scale;
}

//-----------------------
//DRAW
void encapsulation::ADrawable::draw() const noexcept
{
}
