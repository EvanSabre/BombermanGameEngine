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
            void onCollisionEnter(const AGameObject &collision);
            void onCollisionExit(const AGameObject &collision);
            virtual void update() = 0;
            game::Tag_e getTag() const noexcept;

            //getter
            gameEngine::encapsulation::BColor getColor() const noexcept;

            //setter
            void setColor(const gameEngine::encapsulation::BColor &color) noexcept;

            //draw
            virtual void draw() = 0;
            virtual std::string getContent() const noexcept = 0;

        protected:
            gameEngine::encapsulation::BColor _color = WHITE;

        private:
        };
    } // namespace encpasulation
} // namespace gameEngine

#endif /* !ADRAWABLE_HPP_ */
