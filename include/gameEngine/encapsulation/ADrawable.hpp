/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** ADrawable
*/

#ifndef ADRAWABLE_HPP_
#define ADRAWABLE_HPP_

#include "AGameObject.hpp"
#include "Vector3T.hpp"
#include "BColor.hpp"

namespace gameEngine
{
    namespace encapsulation
    {
        class ADrawable : public gameEngine::objects::AGameObject
        {
        public:
            ADrawable();
            ~ADrawable();

            // member functions
            void OnCollisionEnter(const AGameObject &collision);
            void OnCollisionExit(const AGameObject &collision);
            void Update();

            //getter
            gameEngine::encapsulation::BColor getColor() const noexcept;

            //setter
            void setColor(const gameEngine::encapsulation::BColor &color) noexcept;

            //draw
            void draw() const noexcept;

        protected:
            gameEngine::encapsulation::BColor _color = WHITE;

        private:
        };
    } // namespace encpasulation
} // namespace gameEngine

#endif /* !ADRAWABLE_HPP_ */
