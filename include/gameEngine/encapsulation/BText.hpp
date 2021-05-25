/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BText
*/

#ifndef BTEXT_HPP_
#define BTEXT_HPP_

#include <string>
#include <stdexcept>
#include "BColor.hpp"
#include "Vector.hpp"
#include "raylib.h"

namespace gameEngine
{
    namespace encapsulation
    {
        class BText
        {
        public:
            BText(const std::string &str,
                const Vector<int> &pos = {0, 0},
                const BColor &color = BColor{},
                const int &size = 10
                );
            BText(const BText &ref);
            BText &operator=(const BText &ref);
            ~BText();

            //getter
                [[nodiscard]] std::string getStr() const noexcept;
                [[nodiscard]] BColor getColor() const noexcept;
                [[nodiscard]] Vector<int> getPosition() const noexcept;
                [[nodiscard]] int getSize() const noexcept;

            //setter
                void setStr(const std::string &str) noexcept;
                void setSize(const int &size) noexcept;
                void setPosition(const Vector<int> &position) noexcept;
                void setColor(const BColor &color) noexcept;

            //draw
                void draw() const noexcept;
        protected:
        private:
            std::string _str{};
            BColor _color;
            int _size;
            Vector<int> _pos = {0, 0};
        };
    }
}

std::ostream& operator<<(std::ostream& out, const gameEngine::encapsulation::BText &text);

#endif /* !BTEXT_HPP_ */
