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
    : ADrawable()
{
    this->setRectPosition(pos);
    this->setRectSize(size);
    this->_color = color;
    this->_rotation = rotation;
}

encapsulation::BRectangle::BRectangle(const BRectangle &ref)
{
    this->setRectPosition(ref.getRectPosition());
    this->setRectSize(ref.getRectSize());
    this->_rotation = ref.getRotation();
    this->_color = ref.getColor();
}

encapsulation::BRectangle &encapsulation::BRectangle::operator=(const BRectangle &ref)
{
    if (this ==  &ref)
        return *this;
    this->setRectPosition(ref.getRectPosition());
    this->setRectSize(ref.getRectSize());
    this->_rotation = ref.getRotation();
    this->_color = ref.getColor();
    return *this;
}

encapsulation::BRectangle::~BRectangle()
{
    std::cout << "Rectangle destory\n";
}

//----------------------------

//GETTER

Rectangle encapsulation::BRectangle::getObj() const noexcept
{
    Rectangle rec;

    rec.height = getHeight() * _scale;
    rec.width = getWidth() * _scale;
    rec.x = getX();
    rec.y = getY();
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
    return _position._x;
}

float encapsulation::BRectangle::getY() const noexcept
{
    return _position._y;
}

float encapsulation::BRectangle::getRotation() const noexcept
{
    return this->_rotation;
}

Vector<float> encapsulation::BRectangle::getRectSize() const noexcept
{
    return {_size._x, _size._y};
}

Vector<float> encapsulation::BRectangle::getRectPosition() const noexcept
{
    return {_position._x, _position._y};
}

//-----------------------------------------

//SETTER

void encapsulation::BRectangle::setX(const float &x) noexcept
{
    this->_position._x = x;
}

void encapsulation::BRectangle::setY(const float &y) noexcept
{
    this->_position._y = y;
}

void encapsulation::BRectangle::setWidth(const float &width) noexcept
{
    this->_size._x = width;
}

void encapsulation::BRectangle::setRectSize(const Vector<float> &size) noexcept
{
    _size = {size._x, size._y, _size._z};
}

void encapsulation::BRectangle::setRectPosition(const Vector<float> &pos) noexcept
{
    _position = {pos._x, pos._y, _position._z};
}

void encapsulation::BRectangle::setHeight(const float &height) noexcept
{
    this->_size._y = height;
}

void encapsulation::BRectangle::setRotation(const float &rotation) noexcept
{
    this->_rotation = rotation;
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

bool encapsulation::BRectangle::checkPointInside(const Vector<float> &point) const noexcept
{
    Vector2 vec;

    vec.x = point._x;
    vec.y = point._y;
    return CheckCollisionPointRec(vec, this->getObj());
}
