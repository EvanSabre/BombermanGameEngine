/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Color
*/

#ifndef COLOR_HPP_
#define COLOR_HPP_

#include <iostream>
#include "raylib.h"

namespace gameEngine
{
    namespace encapsulation
    {
        class Colour
        {
        public:
            Colour(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
            Colour(const Color &ref);
            Colour(const Colour &ref);
            Colour &operator=(const Colour &ref);
            Colour &operator=(const Color &ref);
            ~Colour();

            //getter
                [[nodiscard]] unsigned char getRed() const noexcept;
                [[nodiscard]] unsigned char getGreen() const noexcept;
                [[nodiscard]] unsigned char getBlue() const noexcept;
                [[nodiscard]] unsigned char getAlpha() const noexcept;
                [[nodiscard]] Color getObj() const noexcept;

            //setter
                void setRed(unsigned char value) noexcept;
                void setGreen(unsigned char value) noexcept;
                void setBlue(unsigned char value) noexcept;
                void setAlpha(unsigned char value) noexcept;

                void copy(const Colour &ref) noexcept;

        protected:
        private:
            unsigned char _r;
            unsigned char _g;
            unsigned char _b;
            unsigned char _a;
        };
    } // namespace encapsulation

} // namespace gameEngine

std::ostream& operator<<(std::ostream& out, const gameEngine::encapsulation::Colour &color);

#endif /* !COLOR_HPP_ */
