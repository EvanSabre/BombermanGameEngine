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
#include <cstdio>
#include "BFont.hpp"
#include "Vector.hpp"
#include "raylib.h"

#include "ADrawable.hpp"

namespace gameEngine
{
    namespace encapsulation
    {
        class BText : public gameEngine::encapsulation::ADrawable
        {
        public:
            BText(const std::string &str = "",
                const Vector<float> &pos = {0, 0},
                const BColor &color = BColor{},
                const int &size = 10,
                gameEngine::encapsulation::ADrawable *relativeObj = nullptr
                );
            BText(const BText &ref);
            BText &operator=(const BText &ref);
            ~BText();

            void update() override;

            //getterT
                [[nodiscard]] std::string getStr() const noexcept;
                [[nodiscard]] BFont getFont() const noexcept;
                [[nodiscard]] float getSpacing() const noexcept;

                //specializer of interface class
                [[nodiscard]] Vector<float> getTextPosition() const noexcept;
                [[nodiscard]] float getTextSize() const noexcept;

            //setter
                void setStr(const std::string &str) noexcept;
                void setFont(const BFont &font) noexcept;
                void setSpacing(const float &spacing) noexcept;
                void unloadFont() noexcept;

                //specializer of interface functions
                void setTextPosition(const Vector<float> &position) noexcept;
                void setTextSize(const float &size) noexcept;

            //draw
                void draw() override;
                std::string getContent() const noexcept override;
        private:
            //ADrawable protected vaiable
            //_position: use only x and y
            //_SIZE : x = SIZE, y = Spacing
            #define TEXT_SIZE (this->_size._x)
            #define SCALE_SIZE ((int)this->getScaledSize()._x)
            #define TEXT_SPACING (this->_size._y)

            std::string _str{};
            BFont _font;
        };
    }
}

std::ostream& operator<<(std::ostream& out, const gameEngine::encapsulation::BText &text);

#endif /* !BTEXT_HPP_ */
