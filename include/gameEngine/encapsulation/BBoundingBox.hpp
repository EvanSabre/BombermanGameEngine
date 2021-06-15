/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** BBoundingBox
*/

#ifndef BBOUNDINGBOX_HPP_
#define BBOUNDINGBOX_HPP_

#include "raylib.h"
#include "Vector3T.hpp"

namespace gameEngine {
    namespace encapsulation {
        class BBoundingBox {
            public:
                BBoundingBox(const Vector3T<float> &min, const Vector3T<float> &max);
                ~BBoundingBox();

                bool checkCollision(const BBoundingBox &ref);
                void setBoundingBox(const Vector3T<float> &min, const Vector3T<float> &max);
                Vector3T<float> getMin() const;
                Vector3T<float> getMax() const;
                BoundingBox _box;
            private:
                Vector3T<float> _min;
                Vector3T<float> _max;
        };
    }
}

#endif /* !BBOUNDINGBOX_HPP_ */
