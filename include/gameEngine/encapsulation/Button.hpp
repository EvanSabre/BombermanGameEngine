/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Button
*/

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include "Vector.hpp"
#include "BTexture2D.hpp"
#include "BRectangle.hpp"
#include "BColor.hpp"
#include <string>

namespace gameEngine {
    namespace encapsulation {
        class Button {

            enum State {
                NORMAL,
                MOUSE_HOVER,
                PRESSED
            };

            public:
                Button(const Vector<float> &size, const Vector<float> &pos, const gameEngine::encapsulation::BColor &color = BLACK,
                        const std::string &content = "", float rotation = 0, const std::string &textureFile = "");
                ~Button();

                //getter
                Vector<float> getPos() const;
                Vector<float> getSize() const;
                std::string getContent() const;
                State getState() const;
                bool getButtonPressed() const;

                bool isInsideButton(Vector<float> point);
                bool isButtonPressed(Vector<float> mousePos);
                bool isButtonReleased();
            private:
                State _state;
                std::string _content;
                bool _buttonPressed;
                gameEngine::encapsulation::BTexture2D _texture;
                gameEngine::encapsulation::BRectangle _rectangle;
        };
    } //encapsulation
} //gameEngine

#endif /* !BUTTON_HPP_ */
