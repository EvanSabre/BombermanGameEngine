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
                        const BText &content, const BColor &color = BLACK,
                        const std::string &textureFile = "",
                        float rotation = 0, int nbFrames = 1);
                Button(const std::shared_ptr<BTexture2D> &text, const std::shared_ptr<BRectangle> &rect, const std::shared_ptr<BText> &content);
                ~Button();

                //operator
                Button &operator=(const Button &ref);

                //getter
                Vector<float> getPos() const;
                Vector<float> getSize() const;
                BText getContent() const;
                BTexture2D getTexture() const;
                BRectangle getRect() const;
                BRectangle getFrameRect() const;
                State getState() const;
                bool getButtonPressed() const;
                int getNbFrames() const;

                //setter
                void setPos(const Vector<float> &pos);
                void setRotation(const float &rotation);
                void setSize(const Vector<float> &size);
                void setColor(const BColor &color);
                void setContentStr(const std::string &str);
                void setNbFrames(const int &nb);
                void setFrameRect(const BRectangle &rect);
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
                std::shared_ptr<BTexture2D> _texture;
                std::shared_ptr<BRectangle> _rectangle;
                std::shared_ptr<BRectangle> _frameRec;
                std::shared_ptr<BText> _content;
        };
    } //encapsulation
} //gameEngine

#endif /* !BUTTON_HPP_ */
