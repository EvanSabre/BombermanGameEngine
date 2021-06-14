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
                    const gameEngine::encapsulation::BText &content,
                    const gameEngine::encapsulation::BColor &color = BLACK,
                    bool initState = true,
                    const gameEngine::encapsulation::BColor &tueColor = GREEN,
                    const gameEngine::encapsulation::BColor &falseColor = RED,
                    const gameEngine::encapsulation::BColor &selectColor = RED
                    );
            CheckBox(const std::shared_ptr<gameEngine::encapsulation::BRectangle> &rect, const std::shared_ptr<gameEngine::encapsulation::BText> &content);
            ~CheckBox();

            bool getState() const noexcept;
            void draw() override;

        private:
            bool _checkState;
            gameEngine::encapsulation::BColor _trueColor;
            gameEngine::encapsulation::BColor _falseColor;
            gameEngine::encapsulation::BRectangle _checkRect{{0, 0}};

        private:
            void initCheckRect() noexcept;
            void setCheckRectColor() noexcept;
        };
    } // namespace encapsulation
} // namespace gameEngine

#endif /* !CHECKBOX_HPP_ */
