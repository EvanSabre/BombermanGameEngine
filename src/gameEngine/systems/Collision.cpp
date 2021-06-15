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

void Collision::calculateCollisions(std::vector<gameEngine::objects::AGameObject> &objects)
{
    for (auto it = objects.begin(); it != objects.end(); it++) {
        for (auto jt = objects.begin(); it != objects.end(); it++) {

            if (it->getId() != jt->getId() && it->getQuadrant() == jt->getQuadrant()
            && it->getCollider().isColliding(jt->getCollider().getBoundingBox())) {
                it->onCollisionEnter(*jt);
            }
        }
    }
}
