/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** Collision
*/

#include "Collision.hpp"

using namespace gameEngine::systems;

Collision::Collision()
{}

Collision::~Collision()
{}

void Collision::calculateCollisions(const std::vector<gameEngine::objects::AGameObject> &objects)
{
    for (auto it : objects) {
        for (auto jt : objects) {
            if (it.getId() != jt.getId() && it.getQuadrant() == jt.getQuadrant()
            && it.getCollider().isColliding(jt.getCollider().getBoundingBox())) {
                it.OnCollisionEnter(jt);
            }
        }
    }
}
