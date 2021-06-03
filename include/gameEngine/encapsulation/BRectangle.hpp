/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BRectangle
*/

#ifndef BRECTANGLE_HPP_
#define BRECTANGLE_HPP_

#include <iostream>
#include <string>
#include <stdexcept>
#include "raylib.h"
#include "Vector.hpp"

#include "ADrawable.hpp"

namespace gameEngine
{
    namespace encapsulation
    {
        class BRectangle : public gameEngine::encapsulation::ADrawable
        {
        public:
            BRectangle(const Vector<float> &size,
                        const Vector<float> &pos = {0, 0},
                        const BColor &color = BLACK,
                        float rotation = 0
                        );
            BRectangle(const BRectangle &ref);
            BRectangle &operator=(const BRectangle &ref);
            ~BRectangle();

            //getter
                [[nodiscard]] Rectangle getObj() const noexcept;
                [[nodiscard]] float getWidth() const noexcept;
                [[nodiscard]] float getHeight() const noexcept;
                [[nodiscard]] float getX() const noexcept;
                [[nodiscard]] float getY() const noexcept;
                [[nodiscard]] float getRotation() const noexcept;

                //specializer of Abstract class Functions
                [[nodiscard]] Vector<float> getRectSize() const noexcept;
                [[nodiscard]] Vector<float> getRectPosition() const noexcept;

            //setter
                void setX(const float &x) noexcept;
                void setY(const float &y) noexcept;
                void setWidth(const float &width) noexcept;
                void setHeight(const float &height) noexcept;
                void setRotation(const float &rotation) noexcept;

                //specializer of abstract class methods
                void setRectPosition(const Vector<float> &pos) noexcept;
                void setRectSize(const Vector<float> &size) noexcept;

            //draw
                void draw() const noexcept override;

            //collision
                bool checkCollision(const BRectangle &other) const noexcept;
                bool checkPointInside(const Vector<float> &point) const noexcept;

        private:
            //abstract class variables:
            //_position: use x and y (y can be use for cube with ineritance)
            //_size: use x and y


            float _rotation;
        };
    } // namespace encapsulation

} // namespace gameEngine

std::ostream& operator<<(std::ostream& out, const gameEngine::encapsulation::BRectangle &ref);


#endif /* !BRECTANGLE_HPP_ */
