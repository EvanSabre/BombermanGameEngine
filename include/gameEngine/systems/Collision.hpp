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
#include <memory>

namespace gameEngine {
    namespace systems {
        class Collision {
            public:
                Collision();
                ~Collision();
                static void calculateCollisions(std::vector<objects::AGameObject> &objects);
        };
    }
}

#endif /* !COLLISION_HPP_ */
