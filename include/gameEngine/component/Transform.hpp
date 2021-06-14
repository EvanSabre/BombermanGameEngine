/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** Transform
*/

#ifndef TRANSFORM_HPP_
#define TRANSFORM_HPP_

#include "Vector3T.hpp"
#include <cmath>

namespace gameEngine {
    namespace component {
        class Transform {
            public:
                Transform(const Vector3T<float> &pos = {0, 0, 0},
                          const Vector3T<float> &rot = {0, 0, 0},
                          const Vector3T<float> &sca = {1, 1, 1});
                Transform(const Transform &t);
                ~Transform();

                //Rotate the transform so that it faces the destination;
                void LookAt(const Transform &destination);
                void Rotate(float xAngle, float yAngle, float zAngle);

                Vector3T<float> getPosition() const;
                Vector3T<float> getRotation() const;
                Vector3T<float> getScale() const;

                void setPosition(const Vector3T<float> &pos);
                void setRotation(const Vector3T<float> &rot);
                void setScale(const Vector3T<float> &sca);

                bool operator==(const Transform &ref);
                bool operator!=(const Transform &ref);

                Transform &operator<<(const Transform &ref);
                Transform &operator=(const Transform &ref);

                Vector3T<float> _position;
                Vector3T<float> _rotation;
                Vector3T<float> _scale;
            protected:
            private:
        };
    }
}
#endif /* !TRANSFORM_HPP_ */
