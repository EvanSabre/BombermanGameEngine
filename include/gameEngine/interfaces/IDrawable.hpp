/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** IDrawable
*/

#ifndef IDRAWABLE_HPP_
#define IDRAWABLE_HPP_

#include "Vector3T.hpp"
#include "BColor.hpp"

namespace gameEngine
{
    namespace interfaces
    {
        class IDrawable {
        public:
            virtual ~IDrawable() = default;

            virtual gameEngine::encapsulation::BColor getColor() const noexcept = 0;
            virtual Vector3T<float> getPosition() const noexcept = 0;
            virtual Vector3T<float> getRotation() const noexcept = 0;
            virtual Vector3T<float> getSize() const noexcept = 0;
            virtual Vector3T<float> getScale() const noexcept = 0;
            virtual Vector3T<float> getScaledSize() const noexcept = 0;

            virtual void setColor(const gameEngine::encapsulation::BColor &color) noexcept = 0;
            virtual void setPosition(const Vector3T<float> &pos) noexcept = 0;
            virtual void setRotation(const Vector3T<float> &pos) noexcept = 0;
            virtual void setSize(const Vector3T<float> &size) noexcept = 0;
            virtual void setScale(const Vector3T<float> &scale) noexcept = 0;
            virtual void setScale(const float &scale) noexcept = 0;

            virtual void draw() const noexcept = 0;
        };
    } // namespace interfaces
} // namespace gameEngine

#endif /* !IDRAWABLE_HPP_ */
