/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** Transform
*/

#include "Transform.hpp"

using namespace gameEngine::component;

Transform::Transform(const Vector3T<float> &pos, const Vector3T<float> &rot)
{
    _position = pos;
    _rotation = rot;
}

Transform::~Transform()
{
}

void Transform::LookAt(const Transform &destination)
{

}

void Transform::Rotate(float xAngle, float yAngle, float zAngle)
{

}

Vector3T<float> Transform::getPosition() const
{
    return _position;
}

Vector3T<float> Transform::getRotation() const
{
    return _rotation;
}

bool Transform::operator==(const Transform &ref)
{
    if (_position == ref._position)
        return true;
    return false;
}

bool Transform::operator!=(const Transform &ref)
{
    if (_position != ref._position)
        return true;
    return false;
}

Transform &Transform::operator<<(const Transform &ref)
{
    std::cout << "Pos {" << _position._x << ", " << _position._y << ", " << _position._z << "}" << std::endl;
    std::cout << "Rotation {" << _rotation._x << ", " << _rotation._y << ", " << _rotation._z << "}" << std::endl;
    return *this;
}

Transform &Transform::operator=(const Transform &ref)
{
    _position = ref._position;
    _rotation = ref._rotation;
}
