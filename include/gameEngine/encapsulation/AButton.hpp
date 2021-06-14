/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** AButton
*/

#ifndef ABUTTON_HPP_
#define ABUTTON_HPP_

#include "IButton.hpp"


namespace gameEngine {
    namespace encapsulation {
        class AButton : public interfaces::IButton {
            public:
                AButton(const Vector<float> &size, const Vector<float> &pos, const BText &content,
                const BColor &color = BLACK, const BColor &selectColor = RED, float rotation = 0);
                AButton(const std::shared_ptr<BRectangle> &rect, const std::shared_ptr<BText> &text);
                ~AButton();

                //getter
                Vector<float> getPos() const noexcept;
                Vector<float> getSize() const noexcept;
                State getState() const noexcept;
                BText getContent() const noexcept;

                //setter
                void setPos(const Vector<float> &pos);
                void setRotation(const float &rotation);
                void setSize(const Vector<float> &size);
                void setColor(const BColor &color);
                void setContentStr(const std::string &str);

                bool isInsideButton(const Vector<float> &point);
                bool isButtonPressed(const Vector<float> &mousePos);
                bool isButtonReleased();
                void drawButtonRect();
                void drawOutline();
                void update();
                void draw();

            protected:
                State _state;
                std::shared_ptr<BText> _content;
                std::shared_ptr<BRectangle> _rectangle;
                std::shared_ptr<BColor> _selectColor;
            private:
        };
    }
}

#endif /* !ABUTTON_HPP_ */
