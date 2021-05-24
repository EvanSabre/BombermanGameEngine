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
    out << "Rectangle : posiotion (" << ref.getX() << ", " << ref.getY() << ") ";
    out << "| size : (" << ref.getWidth() << ", " << ref.getHeight() << ") ";
    out << "| " << ref.getColor();
    return out;
}


encapsulation::BRectangle::BRectangle(float width, float height, float x, float y,
                        const BColor &color, float rotation)
{
    this->_x = x;
    this->_y = y;
    this->_width = width;
    this->_height = height;
    this->_color = color;
    this->_rotation = rotation;
}

encapsulation::BRectangle::BRectangle(const BRectangle &ref)
{
    this->_x = ref.getX();
    this->_y = ref.getY();
    this->_width = ref.getWidth();
    this->_height = ref.getHeight();
    this->_rotation = ref.getRotation();
    this->_color = ref.getColor();
}

encapsulation::BRectangle &encapsulation::BRectangle::operator=(const BRectangle &ref)
{
    if (this ==  &ref)
        return *this;
    this->_x = ref.getX();
    this->_y = ref.getY();
    this->_width = ref.getWidth();
    this->_height = ref.getHeight();
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

    rec.height = this->_height;
    rec.width = this->_width;
    rec.x = this->_x;
    rec.y = this->_y;
    return rec;
}

float encapsulation::BRectangle::getWidth() const noexcept
{
    return this->_width;
}

float encapsulation::BRectangle::getHeight() const noexcept
{
    return this->_height;
}

float encapsulation::BRectangle::getX() const noexcept
{
    return this->_x;
}

float encapsulation::BRectangle::getY() const noexcept
{
    return this->_y;
}

float encapsulation::BRectangle::getRotation() const noexcept
{
    return this->_rotation;
}

encapsulation::BColor encapsulation::BRectangle::getColor() const noexcept
{
    return this->_color;
}


//-----------------------------------------

//SETTER

void encapsulation::BRectangle::setX(const float &x) noexcept
{
    this->_x = x;
}

void encapsulation::BRectangle::setY(const float &y) noexcept
{
    this->_y = y;
}

void encapsulation::BRectangle::setWidth(const float &width) noexcept
{
    this->_width = width;
}

void encapsulation::BRectangle::setHeight(const float &height) noexcept
{
    this->_height = height;
}

void encapsulation::BRectangle::setRotation(const float &rotation) noexcept
{
    this->_rotation = rotation;
}

void encapsulation::BRectangle::setColor(const BColor &color) noexcept
{
    this->_color = color;
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
