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

void systems::AGameObject::moveDirection(std::size_t tick,
                const gameEngine::systems::Move::direction_e direction)
{
    float velocity = 0;

    if (direction == Move::UP || direction == Move::DOWN)
        velocity = _speed._z;
    else if (direction == Move::RIGHT || direction == Move::LEFT)
        velocity = _speed._x;
    else
        velocity = _speed._y;
    try
    {
        Move::moveDirection(_postion, velocity, tick, direction);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void systems::AGameObject::moveRight(std::size_t tick) noexcept
{
    Move::moveRight(_postion, _speed._x, tick);
}

void systems::AGameObject::moveLeft(std::size_t tick) noexcept
{
    Move::moveLeft(_postion, _speed._x, tick);
}

void systems::AGameObject::moveForward(std::size_t tick) noexcept
{
    Move::moveForward(_postion, _speed._y, tick);
}

void systems::AGameObject::moveBackward(std::size_t tick) noexcept
{
    Move::moveBackward(_postion, _speed._y, tick);
}

void systems::AGameObject::moveUp(std::size_t tick) noexcept
{
    Move::moveUp(_postion, _speed._z, tick);
}

void systems::AGameObject::moveDown(std::size_t tick) noexcept
{
    Move::moveDown(_postion, _speed._z, tick);
}
