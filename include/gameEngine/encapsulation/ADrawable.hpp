/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** ADrawable
*/

#ifndef ADRAWABLE_HPP_
#define ADRAWABLE_HPP_

#include "IDrawable.hpp"

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
                Vector3T<float> getSize() const noexcept final;
                float getScale() const noexcept final;
                Vector3T<float> getScaledSize() const noexcept final;

            //setter
                void setColor(const gameEngine::encapsulation::BColor &color) noexcept override;
                void setPosition(const Vector3T<float> &pos) noexcept override;
                void setSize(const Vector3T<float> &size) noexcept override;
                void setScale(float scale) noexcept override;

            //draw
                void draw() const noexcept override;

        protected:
            Vector3T<float> _size{1, 1, 1};
            Vector3T<float> _position{0, 0, 0};
            gameEngine::encapsulation::BColor _color = WHITE;
            float _scale = 1;

        private:
        };
    } // namespace encpasulation

} // namespace gameEngine

#endif /* !ADRAWABLE_HPP_ */
