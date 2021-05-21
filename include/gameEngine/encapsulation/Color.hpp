/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Color
*/

#ifndef COLOR_HPP_
#define COLOR_HPP_

#include <iostream>

namespace gameEngine
{
    namespace encapsulation
    {
        class Color
        {
        public:
            Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
            Color(const Color &ref);
            Color &operator=(const Color &ref);
            ~Color();

            //getter
                [[nodiscard]] unsigned char getRed() const noexcept;
                [[nodiscard]] unsigned char getGreen() const noexcept;
                [[nodiscard]] unsigned char getBlue() const noexcept;
                [[nodiscard]] unsigned char getAlpha() const noexcept;

            //setter
                void setRed(unsigned char value) noexcept;
                void setGreen(unsigned char value) noexcept;
                void setBlue(unsigned char value) noexcept;
                void setAlpha(unsigned char value) noexcept;

                void copy(const Color &ref) noexcept;

        protected:
        private:
            unsigned char _r;
            unsigned char _g;
            unsigned char _b;
            unsigned char _a;
        };
    } // namespace encapsulation

} // namespace gameEngine

std::ostream& operator<<(std::ostream& out, const gameEngine::encapsulation::Color &color);

#endif /* !COLOR_HPP_ */
