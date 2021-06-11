/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** AGameObject
*/

#ifndef AGAMEOBJECT_HPP_
#define AGAMEOBJECT_HPP_

#include <string>
#include "Vector3T.hpp"
#include "Move.hpp"
#include "Transform.hpp"
#include "BoxCollider.hpp"

enum class Quadrants {
    TOP_RIGHT,
    TOP_LEFT,
    BOT_RIGHT,
    BOT_LEFT,
    UNDEFINED
};

namespace gameEngine
{
    namespace objects
    {
        class AGameObject
        {
        public:
            AGameObject(const std::string &id, const Vector3T<float> &pos = {0, 0, 0}, const Vector3T<float> &rot = {0, 0, 0},
                        const Vector3T<float> &colliderMin = {0, 0, 0}, const Vector3T<float> &colliderMax = {0, 0, 0}, bool colliderEnabled = true);
            ~AGameObject();

            Vector3T<float> getPosition() const noexcept;
            const std::string getId() const noexcept;
            component::BoxCollider getCollider() const noexcept;
            Quadrants getQuadrant() const noexcept;
            component::Transform getTransform() const noexcept;

            virtual void OnCollisionEnter(const AGameObject &collision) = 0;
            virtual void OnCollisionExit(const AGameObject &collision) = 0;
            virtual void Update() = 0;

            void setPostion(const Vector3T<float> &pos) noexcept;
            void setQuadrant(Quadrants quad);
        protected:
            component::Transform _transform;
            component::BoxCollider _collider;
            Quadrants _quadrant;
        private:
            std::string _id;
        };
    } // namespace systems

} // namespace gameEngine




#endif /* !AGAMEOBJECT_HPP_ */
