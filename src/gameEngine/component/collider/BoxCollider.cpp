/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** BoxCollider
*/

#include "BoxCollider.hpp"

using namespace gameEngine::component;

BoxCollider::BoxCollider(const Vector3T<float> &min, const Vector3T<float> &max, bool enabled)
    : Collider(enabled), _box(min, max)
{}

BoxCollider::~BoxCollider()
{}

gameEngine::encapsulation::BBoundingBox &BoxCollider::getBoundingBox()
{
    return _box;
}

bool BoxCollider::isColliding(const gameEngine::encapsulation::BBoundingBox &ref)
{
    return _box.checkCollision(ref);
}
