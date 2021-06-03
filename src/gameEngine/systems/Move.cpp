/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Move
*/

#include "Move.hpp"

using namespace gameEngine;

const std::unordered_map<systems::Move::direction_e, systems::moveFct> systems::Move::_movement = {
    {systems::Move::direction_e::RIGHT, &systems::Move::moveRight},
    {systems::Move::direction_e::LEFT, &systems::Move::moveLeft},
    {systems::Move::direction_e::FORWARD, &systems::Move::moveForward},
    {systems::Move::direction_e::BACKWARD, &systems::Move::moveBackward},
    {systems::Move::direction_e::UP, &systems::Move::moveUp},
    {systems::Move::direction_e::DOWN, &systems::Move::moveDown}
};

void systems::Move::move(Vector3T<float> &pos, const Vector3T<float> velocity, std::size_t tick) noexcept
{
    Vector3T<float> distance = velocity;

    distance = distance * tick;
    pos = pos + distance;
}

void systems::Move::moveRight(Vector3T<float> &pos, const float velocity, std::size_t tick) noexcept
{
    Vector3T<float> speed = {velocity, 0, 0};
    Move::move(pos, speed, tick);
}

void systems::Move::moveLeft(Vector3T<float> &pos, const float velocity, std::size_t tick) noexcept
{
    Vector3T<float> speed = {-velocity, 0, 0};
    Move::move(pos, speed, tick);
}

void systems::Move::moveForward(Vector3T<float> &pos, const float velocity, std::size_t tick) noexcept
{
    Vector3T<float> speed = {0, velocity, 0};
    Move::move(pos, speed, tick);
}

void systems::Move::moveBackward(Vector3T<float> &pos, const float velocity, std::size_t tick) noexcept
{
    Vector3T<float> speed = {0, -velocity, 0};
    Move::move(pos, speed, tick);
}

void systems::Move::moveUp(Vector3T<float> &pos, const float velocity, std::size_t tick) noexcept
{
    Vector3T<float> speed = {0, 0, velocity};
    Move::move(pos, speed, tick);
}

void systems::Move::moveDown(Vector3T<float> &pos, const float velocity, std::size_t tick) noexcept
{
    Vector3T<float> speed = {0, 0, -velocity};
    Move::move(pos, speed, tick);
}

void systems::Move::moveDirection(Vector3T<float> &pos, const float velocity,
                                     std::size_t tick, const direction_e direction)
{
    systems::moveFct action = nullptr;

    try
    {
        action = _movement.at(direction);
        action(pos, velocity, tick);
    }
    catch(const std::exception& e)
    {
        throw std::invalid_argument("Move : Unknow Direction");
    }
}
