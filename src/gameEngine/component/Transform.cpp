/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** Transform
*/

#include "Transform.hpp"

using namespace gameEngine::component;

Transform::Transform(const Vector3T<float> &pos,
                     const Vector3T<float> &rot,
                     const Vector3T<float> &sca)
    : _position(pos), _rotation(rot), _scale(sca)
{
}

Transform::~Transform()
{
}

Transform::Transform(const Transform &t)
{
    _position = t._position;
    _rotation = t._rotation;
    _scale = t._scale;
}

void Transform::LookAt(const Transform &dest)
{
    _rotation._x = std::atan((dest._position._x - _position._x) / (dest._position._y - _position._y));
    _rotation._y = std::atan((dest._position._y - _position._y) / (dest._position._z - _position._z));
    _rotation._z = std::atan((dest._position._z - _position._z) / (dest._position._x - _position._x));
}

void Transform::Rotate(float xAngle, float yAngle, float zAngle)
{
    _rotation._x = (xAngle / (float)180) * M_PI; // degree to radian (180° -> PI)
    _rotation._y = (yAngle / (float)180) * M_PI;
    _rotation._z = (zAngle / (float)180) * M_PI;
}

void Transform::setPosition(const Vector3T<float> &pos)
{
    _position = pos;
}

void Transform::setRotation(const Vector3T<float> &rot)
{
    _rotation = rot;
}

void Transform::setScale(const Vector3T<float> &scale)
{
    _scale = scale;
}

Vector3T<float> Transform::getPosition() const
{
    return _position;
}

Vector3T<float> Transform::getRotation() const
{
    return _rotation;
}

Vector3T<float> Transform::getScale() const
{
    return _scale;
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
    std::cout << "Scale {" << _scale._x << ", " << _scale._y << ", " << _scale._z << "}" << std::endl;
    return *this;
}

Transform &Transform::operator=(const Transform &ref)
{
    _position = ref._position;
    _rotation = ref._rotation;
    _scale = ref._scale;
    return *this;
}
