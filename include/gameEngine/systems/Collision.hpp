/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** Collision
*/

#ifndef COLLISION_HPP_
#define COLLISION_HPP_

#include "AGameObject.hpp"
#include <vector>

namespace gameEngine {
    namespace systems {
        class Collision {
            public:
                Collision() = default;
                ~Collision() = delete;
                static void calculateCollisions(const std::vector<objects::AGameObject> &objects);
        };
    }
}

#endif /* !COLLISION_HPP_ */
