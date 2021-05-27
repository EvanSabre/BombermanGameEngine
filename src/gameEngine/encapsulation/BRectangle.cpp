/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BRectangle
*/

#include "BRectangle.hpp"

using namespace gameEngine;

std::ostream& operator<<(std::ostream& out, const gameEngine::encapsulation::BRectangle &ref)
{
    out << "Rectangle : position (" << ref.getX() << ", " << ref.getY() << ") ";
    out << "| size : (" << ref.getWidth() << ", " << ref.getHeight() << ") ";
    out << "| " << ref.getColor();
    return out;
}


encapsulation::BRectangle::BRectangle(const Vector<float> &size, const Vector<float> &pos,
                        const BColor &color, float rotation)
{
    this->_pos = pos;
    this->_size = size;
    this->_color = color;
    this->_rotation = rotation;
}

encapsulation::BRectangle::BRectangle(const BRectangle &ref)
{
    this->_pos = ref.getPos();
    this->_size = ref.getSize();
    this->_rotation = ref.getRotation();
    this->_color = ref.getColor();
}

encapsulation::BRectangle &encapsulation::BRectangle::operator=(const BRectangle &ref)
{
    if (this ==  &ref)
        return *this;
    this->_pos = ref.getPos();
    this->_size = ref.getSize();
    this->_rotation = ref.getRotation();
    this->_color = ref.getColor();
    return *this;
}

encapsulation::BRectangle::~BRectangle()
{}

//----------------------------

//GETTER

Rectangle encapsulation::BRectangle::getObj() const noexcept
{
    Rectangle rec;

    rec.height = this->_size._y;
    rec.width = this->_size._x;
    rec.x = this->_pos._x;
    rec.y = this->_pos._y;
    return rec;
}

float encapsulation::BRectangle::getWidth() const noexcept
{
    return this->_size._x;
}

float encapsulation::BRectangle::getHeight() const noexcept
{
    return this->_size._y;
}

float encapsulation::BRectangle::getX() const noexcept
{
    return this->_pos._x;
}

float encapsulation::BRectangle::getY() const noexcept
{
    return this->_pos._y;
}

float encapsulation::BRectangle::getRotation() const noexcept
{
    return this->_rotation;
}

Vector<float> encapsulation::BRectangle::getSize() const noexcept
{
    return this->_size;
}

Vector<float> encapsulation::BRectangle::getPos() const noexcept
{
    return this->_pos;
}

encapsulation::BColor encapsulation::BRectangle::getColor() const noexcept
{
    return this->_color;
}


//-----------------------------------------

//SETTER

void encapsulation::BRectangle::setX(const float &x) noexcept
{
    this->_pos._x = x;
}

void encapsulation::BRectangle::setY(const float &y) noexcept
{
    this->_pos._y = y;
}

void encapsulation::BRectangle::setWidth(const float &width) noexcept
{
    this->_size._x = width;
}

void encapsulation::BRectangle::setSize(const Vector<float> &size) noexcept
{
    this->_size = size;
}

void encapsulation::BRectangle::setPos(const Vector<float> &pos) noexcept
{
    this->_pos = pos;
}

void encapsulation::BRectangle::setHeight(const float &height) noexcept
{
    this->_size._y = height;
}

void encapsulation::BRectangle::setRotation(const float &rotation) noexcept
{
    this->_rotation = rotation;
}

void encapsulation::BRectangle::setColor(const BColor &color) noexcept
{
    this->_color = color;
}

//--------------------------

//TRANSFORM

void encapsulation::BRectangle::scale(const float &scale) noexcept
{
    Vector<float> new_size = {this->_size._x, this->_size._y};

    new_size._x *= scale;
    new_size._y *= scale;
    this->setSize(new_size);
}

//-------------------------------------

//DRAW

void encapsulation::BRectangle::draw() const noexcept
{
    DrawRectangleRec(this->getObj(), this->_color.getObj());
}

//--------------------------

//COLLISION

bool encapsulation::BRectangle::checkCollision(const BRectangle &other) const noexcept
{
    return CheckCollisionRecs(this->getObj(), other.getObj());
}
