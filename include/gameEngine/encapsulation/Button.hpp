/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Button
*/

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include "AButton.hpp"

namespace gameEngine {
    namespace encapsulation {
        class Button : public AButton {
            public:
                Button(const Vector<float> &size, const Vector<float> &pos,
                        const std::string &content, const int &textSize, const BColor &color = BLACK,
                        const BColor &selectColor = RED,
                        const std::string &textureFile = "",
                        float rotation = 0, int nbFrames = 1);
                Button(const Vector<float> &size, const Vector<float> &pos,
                        const BText &content, const BColor &color = BLACK,
                        const BColor &selectColor = RED,
                        const std::string &textureFile = "",
                        float rotation = 0, int nbFrames = 1);
                Button(const std::shared_ptr<BTexture2D> &text, const std::shared_ptr<BRectangle> &rect, const std::shared_ptr<BText> &content);
                ~Button();

                //operator
                Button &operator=(const Button &ref);

                //getter
                BTexture2D getTexture() const;
                BRectangle getFrameRect() const;
                bool getButtonPressed() const;
                int getNbFrames() const;

                //setter
                void setNbFrames(const int &nb);
                void setFrameRect(const BRectangle &rect);
                void setFrameRectSize(const Vector<float> &size);

                //Checkers
                void update() override;
                void draw() override;
            private:
                int _nbFrames;
                bool _buttonPressed;
                std::shared_ptr<BColor> _selectColor;
                std::shared_ptr<BTexture2D> _texture;
                std::shared_ptr<BRectangle> _frameRec;
        };
    } //encapsulation
} //gameEngine

#endif /* !BUTTON_HPP_ */
