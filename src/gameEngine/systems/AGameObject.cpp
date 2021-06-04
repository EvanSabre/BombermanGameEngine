/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** AGameObject
*/

#include "AGameObject.hpp"

using namespace gameEngine;

systems::AGameObject::AGameObject(const std::string &id)
{
    this->_id = id;
}

systems::AGameObject::~AGameObject()
{
}

//---------------

//GETTER

Vector3T<float> systems::AGameObject::getPosition() const noexcept
{
    return this->_postion;
}

Vector3T<float> systems::AGameObject::getSpeed() const noexcept
{
    return this->_speed;
}

const std::string systems::AGameObject::getId() const noexcept
{
    return this->_id;
}

//----------------

//SETTER

void systems::AGameObject::setPostion(const Vector3T<float> &pos) noexcept
{
    this->_postion = pos;
}

void systems::AGameObject::setSpeed(const Vector3T<float> &speed) noexcept
{
    this->_speed = speed;
}

//----------------

//MOVE

void systems::AGameObject::move(const std::size_t &tick) noexcept
{
    systems::Move::move(_postion, _speed, tick);
}