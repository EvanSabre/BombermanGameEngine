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
            public:
                enum State {
                    NORMAL,
                    MOUSE_HOVER,
                    PRESSED
                };
                Button(const Vector<float> &size, const Vector<float> &pos, 
                        const gameEngine::encapsulation::BText &content, const gameEngine::encapsulation::BColor &color = BLACK,
                        const std::string &textureFile = "",
                        float rotation = 0, int nbFrames = 1);
                Button(const BTexture2D &text, const BRectangle &rect, const BText &content);
                ~Button();

                //operator
                Button &operator=(const Button &ref);

                //getter
                Vector<float> getPos() const;
                Vector<float> getSize() const;
                gameEngine::encapsulation::BText getContent() const;
                gameEngine::encapsulation::BTexture2D getTexture() const;
                gameEngine::encapsulation::BRectangle getRect() const;
                gameEngine::encapsulation::BRectangle getFrameRect() const;
                State getState() const;
                bool getButtonPressed() const;
                int getNbFrames() const;

                //setter
                void setPos(const Vector<float> &pos);
                void setRotation(const float &rotation);
                void setSize(const Vector<float> &size);
                void setColor(const gameEngine::encapsulation::BColor &color);
                void setContentStr(const std::string &str);
                void setNbFrames(const int &nb);
                void setFrameRect(const gameEngine::encapsulation::BRectangle &rect);
                void setFrameRectSize(const Vector<float> &size);

                //Checkers
                bool isInsideButton(const Vector<float> &point);
                bool isButtonPressed(Vector<float> mousePos);
                bool isButtonReleased();
                void update();
                void drawButton();
            private:
                State _state;
                int _nbFrames;
                bool _buttonPressed;
                gameEngine::encapsulation::BTexture2D _texture;
                gameEngine::encapsulation::BRectangle _rectangle;
                gameEngine::encapsulation::BRectangle _frameRec;
                gameEngine::encapsulation::BText _content;
        };
    } //encapsulation
} //gameEngine

#endif /* !BUTTON_HPP_ */
