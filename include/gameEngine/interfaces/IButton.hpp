/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** IButton
*/

#ifndef IBUTTON_HPP_
#define IBUTTON_HPP_

#include "Vector.hpp"
#include "BTexture2D.hpp"
#include "BRectangle.hpp"
#include "BColor.hpp"
#include <string>

namespace gameEngine {
    namespace interfaces {
        class IButton {
            public:
                enum State {
                    NORMAL,
                    MOUSE_HOVER,
                    PRESSED
                };
                virtual ~IButton() = default;

                virtual bool isInsideButton(const Vector<float> &point) = 0;
                virtual bool isButtonPressed(const Vector<float> &mousePos) = 0;
                virtual bool isButtonReleased() = 0;
                virtual void update() = 0;
                virtual void draw() = 0;

            protected:
            private:
        };
    }
}

#endif /* !IBUTTON_HPP_ */
