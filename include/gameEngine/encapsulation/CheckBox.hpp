/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** CheckBox
*/

#ifndef CHECKBOX_HPP_
#define CHECKBOX_HPP_

#include "AButton.hpp"
#include "Button.hpp"
namespace gameEngine
{
    namespace encapsulation
    {
        class CheckBox : public AButton
        {
        public:
            CheckBox(const Vector<float> &size, const Vector<float> &pos,
                    const BText &content,
                    const BColor &color = BLACK,
                    bool initState = true,
                    const BColor &tueColor = GREEN,
                    const BColor &falseColor = RED,
                    const BColor &selectColor = RED,
                    const std::string &textureFile = "",
                    float rotation = 0, int nbFrames = 1);
            CheckBox(const std::shared_ptr<BTexture2D> &text, const std::shared_ptr<BRectangle> &rect, const std::shared_ptr<BText> &content);
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
