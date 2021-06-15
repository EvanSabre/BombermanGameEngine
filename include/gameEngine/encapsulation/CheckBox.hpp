/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** CheckBox
*/

#ifndef CHECKBOX_HPP_
#define CHECKBOX_HPP_

#include "AButton.hpp"

namespace gameEngine
{
    namespace object
    {
        class CheckBox : public gameEngine::encapsulation::AButton
        {
        public:
            CheckBox(const Vector<float> &size,
                    const Vector<float> &pos,
                    const encapsulation::BText &content,
                    const encapsulation::BColor &color = WHITE,
                    const encapsulation::BColor &selectColor = RED,
                    bool initState = true,
                    const encapsulation::BColor &trueColor = GREEN,
                    const encapsulation::BColor &falseColor = RED
                );
            ~CheckBox();

            bool getState() const noexcept;
            void draw() override;
            bool isButtonReleased() override;

        private:
            bool _checkState;
            gameEngine::encapsulation::BColor _trueColor;
            gameEngine::encapsulation::BColor _falseColor;
            gameEngine::encapsulation::BRectangle _checkRect{{0, 0}};

        private:
            void initCheckRect() noexcept;
            void initText() noexcept;
            void setCheckRectColor() noexcept;

            void toggleState() noexcept;
        };
    } // namespace encapsulation
} // namespace gameEngine

#endif /* !CHECKBOX_HPP_ */
