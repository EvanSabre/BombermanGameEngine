/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** AGameObject
*/

#include "AGameObject.hpp"

using namespace gameEngine;

objects::AGameObject::AGameObject(const std::string &id, const Vector3T<float> &pos, const Vector3T<float> &rot,
const Vector3T<float> &colliderMin, const Vector3T<float> &colliderMax, bool colliderEnabled) :
_transform(pos, rot), _collider(colliderMin, colliderMax, colliderEnabled)
{
    this->_id = id;
    this->_quadrant = Quadrants::UNDEFINED;
}

objects::AGameObject::~AGameObject()
{}

objects::AGameObject &objects::AGameObject::operator=(const objects::AGameObject &obj)
{
    if (this == &obj)
        return (*this);
    _transform = obj._transform;
    _collider = obj._collider;
    _quadrant = obj._quadrant;
    return (*this);
}


objects::AGameObject::AGameObject(const objects::AGameObject &obj) :
_transform(obj._transform), _collider(obj._collider), _quadrant(obj._quadrant)
{

}
//---------------

//GETTER

const std::string objects::AGameObject::getId() const noexcept
{
    return this->_id;
}

Quadrants objects::AGameObject::getQuadrant() const noexcept
{
    return this->_quadrant;
}

component::BoxCollider objects::AGameObject::getCollider() const noexcept
{
    return this->_collider;
}

component::Transform objects::AGameObject::getTransform() const noexcept
{
    return this->_transform;
}

//----------------

//SETTER

component::Transform &objects::AGameObject::setTransform()
{
    return this->_transform;
}

//----------------
