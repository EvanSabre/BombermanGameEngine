/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** Moveable
*/

#include "Moveable.hpp"

using namespace gameEngine::objects;

Moveable::Moveable(const std::string &id) : AGameObject(id)
{
}

Moveable::~Moveable()
{}

void Moveable::move(const std::size_t &tick) noexcept
{
    gameEngine::systems::Move::move(_transform, _speed, tick);
}

void Moveable::moveDirection(std::size_t tick,
                const gameEngine::systems::Move::direction_e direction)
{
    float velocity = 0;

    if (direction == gameEngine::systems::Move::UP || direction == gameEngine::systems::Move::DOWN)
        velocity = _speed._z;
    else if (direction == gameEngine::systems::Move::RIGHT || direction == gameEngine::systems::Move::LEFT)
        velocity = _speed._x;
    else
        velocity = _speed._y;
    try
    {
        gameEngine::systems::Move::moveDirection(_transform, velocity, tick, direction);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void Moveable::moveRight(std::size_t tick) noexcept
{
    gameEngine::systems::Move::moveRight(_transform, _speed._x, tick);
}

void Moveable::moveLeft(std::size_t tick) noexcept
{
    gameEngine::systems::Move::moveLeft(_transform, _speed._x, tick);
}

void Moveable::moveForward(std::size_t tick) noexcept
{
    gameEngine::systems::Move::moveForward(_transform, _speed._y, tick);
}

void Moveable::moveBackward(std::size_t tick) noexcept
{
    gameEngine::systems::Move::moveBackward(_transform, _speed._y, tick);
}

void Moveable::moveUp(std::size_t tick) noexcept
{
    gameEngine::systems::Move::moveUp(_transform, _speed._z, tick);
}

void Moveable::moveDown(std::size_t tick) noexcept
{
    gameEngine::systems::Move::moveDown(_transform, _speed._z, tick);
}
