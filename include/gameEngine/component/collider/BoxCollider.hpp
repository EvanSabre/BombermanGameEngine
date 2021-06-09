/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** BoxCollider
*/

#ifndef BOXCOLLIDER_HPP_
#define BOXCOLLIDER_HPP_

#include "BBoundingBox.hpp"
#include "Collider.hpp"

namespace gameEngine {
    namespace component {
        class BoxCollider : public Collider {
            public:
                BoxCollider(const Vector3T<float> &min, const Vector3T<float> &max, bool enabled);
                BoxCollider(const encapsulation::BBoundingBox &box);
                ~BoxCollider();

                encapsulation::BBoundingBox getBoundingBox() const;
                bool isColliding(const encapsulation::BBoundingBox &ref);
            private:
                encapsulation::BBoundingBox _box;
        };
    }
}

#endif /* !BOXCOLLIDER_HPP_ */
