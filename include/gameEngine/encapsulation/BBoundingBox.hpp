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

                void setBoundingBox(const Vector3T<float> &min, const Vector3T<float> &max);
                std::tuple<Vector3T<float>, Vector3T<float>> getBoundingBox() const;
            private:
                BoundingBox _box;
        };
    }
}

#endif /* !BBOUNDINGBOX_HPP_ */
