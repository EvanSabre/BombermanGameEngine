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

void systems::Move::move(gameEngine::component::Transform &tr, const Vector3T<float> velocity, std::size_t tick) noexcept
{
    Vector3T<float> distance = velocity;

    distance = distance * tick;
    tr._position = tr._position + distance;
}

void systems::Move::moveRight(gameEngine::component::Transform &tr, const float velocity, std::size_t tick) noexcept
{
    Vector3T<float> speed = {velocity, 0, 0};
    Move::move(tr, speed, tick);
    tr._rotation._y = 90;
}

void systems::Move::moveLeft(gameEngine::component::Transform &tr, const float velocity, std::size_t tick) noexcept
{
    Vector3T<float> speed = {-velocity, 0, 0};
    Move::move(tr, speed, tick);
    tr._rotation._y = 90;
}

void systems::Move::moveUp(gameEngine::component::Transform &tr, const float velocity, std::size_t tick) noexcept
{
    Vector3T<float> speed = {0, velocity, 0};
    Move::move(tr, speed, tick);
}

void systems::Move::moveDown(gameEngine::component::Transform &tr, const float velocity, std::size_t tick) noexcept
{
    Vector3T<float> speed = {0, -velocity, 0};
    Move::move(tr, speed, tick);
}

void systems::Move::moveForward(gameEngine::component::Transform &tr, const float velocity, std::size_t tick) noexcept
{
    Vector3T<float> speed = {0, 0, velocity};
    Move::move(tr, speed, tick);
    tr._rotation._y = 90;
}

void systems::Move::moveBackward(gameEngine::component::Transform &tr, const float velocity, std::size_t tick) noexcept
{
    Vector3T<float> speed = {0, 0, -velocity};
    Move::move(tr, speed, tick);
    tr._rotation._y = 90;
}

void systems::Move::moveDirection(gameEngine::component::Transform &tr, const float velocity,
                                     std::size_t tick, const direction_e direction)
{
    systems::moveFct action = nullptr;

    try
    {
        action = _movement.at(direction);
        action(tr, velocity, tick);
    }
    catch(const std::exception& e)
    {
        throw std::invalid_argument("Move : Unknow Direction");
    }
}
