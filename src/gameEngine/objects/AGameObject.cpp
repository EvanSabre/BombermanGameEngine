/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** AGameObject
*/

#include "AGameObject.hpp"

using namespace gameEngine;

objects::AGameObject::AGameObject(const std::string &id, const Vector3T<float> &pos, const Vector3T<float> &rot,
const Vector3T<float> &colliderMin, Vector3T<float> &colliderMax, bool colliderEnabled) :
_transform(pos, rot), _collider(colliderMin, colliderMax, colliderEnabled)
{
    this->_id = id;
    this->_quadrant = Quadrants::UNDEFINED;
}

objects::AGameObject::~AGameObject()
{}

//---------------

//GETTER

Vector3T<float> objects::AGameObject::getPosition() const noexcept
{
    return this->_transform.getPosition();
}

const std::string objects::AGameObject::getId() const noexcept
{
    return this->_id;
}

Quadrants objects::AGameObject::getQuadrant()
{
    return this->_quadrant;
}

component::BoxCollider objects::AGameObject::getCollider() const noexcept
{
    return this->_collider;
}

//----------------

//SETTER

void objects::AGameObject::setPostion(const Vector3T<float> &pos) noexcept
{
    this->_transform.setPosition(pos);
}

//----------------
