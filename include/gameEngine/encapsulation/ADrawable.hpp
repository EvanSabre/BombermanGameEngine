/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** ADrawable
*/

#ifndef ADRAWABLE_HPP_
#define ADRAWABLE_HPP_

#include "IDrawable.hpp"
#include "Transform.hpp"

namespace gameEngine
{
    namespace encapsulation
    {
        class ADrawable : public gameEngine::interfaces::IDrawable
        {
        public:
            ADrawable();
            ~ADrawable();

            //getter
                gameEngine::encapsulation::BColor getColor() const noexcept final;
                Vector3T<float> getPosition() const noexcept final;
                Vector3T<float> getRotation() const noexcept final;
                Vector3T<float> getSize() const noexcept final;
                Vector3T<float> getScale() const noexcept final;
                Vector3T<float> getScaledSize() const noexcept final;

            //setter
                void setColor(const gameEngine::encapsulation::BColor &color) noexcept override;
                void setPosition(const Vector3T<float> &pos) noexcept override;
                void setRotation(const Vector3T<float> &pos) noexcept override;
                void setSize(const Vector3T<float> &size) noexcept override;
                void setScale(const Vector3T<float> &scale) noexcept override;
                void setScale(const float &scale) noexcept override;

            //draw
                void draw() const noexcept override;

        protected:
            Vector3T<float> _size{1, 1, 1};
            gameEngine::component::Transform _transform;
            gameEngine::encapsulation::BColor _color = WHITE;
            Vector3T<float> _scale{1, 1, 1};

        private:
        };
    } // namespace encpasulation

} // namespace gameEngine

#endif /* !ADRAWABLE_HPP_ */
