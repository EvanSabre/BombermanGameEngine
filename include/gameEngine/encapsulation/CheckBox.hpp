/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** CheckBox
*/

#ifndef CHECKBOX_HPP_
#define CHECKBOX_HPP_

#include "Button.hpp"

namespace gameEngine
{
    namespace encapsulation
    {
        class CheckBox : public Button
        {
        public:
            CheckBox(const Vector<float> &size, const Vector<float> &pos,
                    const BText &content,
                    bool initState = true,
                    const BColor &color = BLACK,
                    const BColor &selectColor = RED,
                    const std::string &textureFile = "",
                    float rotation = 0, int nbFrames = 1);
            CheckBox(const std::shared_ptr<BTexture2D> &text, const std::shared_ptr<BRectangle> &rect, const std::shared_ptr<BText> &content);
            ~CheckBox();

            bool getState() const noexcept;
            void draw() noexcept;

        private:
            bool _checkState;
        };
    } // namespace encapsulation
} // namespace gameEngine

#endif /* !CHECKBOX_HPP_ */
