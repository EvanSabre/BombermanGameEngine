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
    this->setTransform()._position._x = pos._x;
    this->setTransform()._position._y = pos._y;
    this->setTransform()._scale._x = size._x;
    this->setTransform()._scale._y = size._y;
    this->setTransform()._rotation._x = rotation;
    this->_color = color;
}

encapsulation::BRectangle::BRectangle(const BRectangle &ref)
{
    this->setTransform().setPosition(ref.getTransform().getPosition());
    this->setTransform().setScale(ref.getTransform().getScale());
    this->setTransform().setRotation(ref.getTransform().getRotation());
    this->_color = ref._color;
}

encapsulation::BRectangle &encapsulation::BRectangle::operator=(const BRectangle &ref)
{
    if (this == &ref)
        return *this;
    this->setTransform().setPosition(ref.getTransform().getPosition());
    this->setTransform().setScale(ref.getTransform().getScale());
    this->setTransform().setRotation(ref.getTransform().getRotation());
    this->_color = ref._color;
    return *this;
}

encapsulation::BRectangle::~BRectangle()
{
    std::cout << "Rectangle destory\n";
}

//----------------------------

//GETTER
std::string encapsulation::BRectangle::getContent() const noexcept
{
    return "";
}

Rectangle encapsulation::BRectangle::getObj() const
{
    Rectangle rec;

    rec.width = this->getTransform().getScale()._x;
    rec.height = this->getTransform().getScale()._y;
    rec.x = this->getTransform().getPosition()._x;
    rec.y = this->getTransform().getPosition()._y;
    return rec;
}

float encapsulation::BRectangle::getWidth() const noexcept
{
    return this->getTransform().getScale()._x;
}

float encapsulation::BRectangle::getHeight() const noexcept
{
    return this->getTransform().getScale()._y;
}

float encapsulation::BRectangle::getX() const noexcept
{
    return this->getTransform().getPosition()._x;
}

float encapsulation::BRectangle::getY() const noexcept
{
    return this->getTransform().getPosition()._y;
}

//-----------------------------------------

//SETTER

void encapsulation::BRectangle::setX(const float &x) noexcept
{
    this->setTransform()._position._x = x;
}

void encapsulation::BRectangle::setY(const float &y) noexcept
{
    this->setTransform()._position._y = y;
}

void encapsulation::BRectangle::setWidth(const float &width) noexcept
{
    this->setTransform()._scale._x = width;
}

void encapsulation::BRectangle::setHeight(const float &height) noexcept
{
    this->setTransform()._scale._y = height;
}

//-------------------------------------

//DRAW

void encapsulation::BRectangle::draw()
{
    DrawRectangleRec(this->getObj(), this->_color.getObj());
}

void encapsulation::BRectangle::drawLines(const BColor &color) const noexcept
{
    DrawRectangleLines(
        (int)this->getTransform()._position._x,
        (int)this->getTransform()._position._y,
        (int)this->getTransform()._scale._x,
        (int)this->getTransform()._scale._y,
        color.getObj());
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
