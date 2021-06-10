/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** Collider
*/

#include "Collider.hpp"

using namespace gameEngine::component;

Collider::Collider(bool enabled) : _enabled(enabled)
{
}

Collider::~Collider()
{
}

bool Collider::getEnabled() const
{
    return _enabled;
}
