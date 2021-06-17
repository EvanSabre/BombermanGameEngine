/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** InputButton
*/

#ifndef INPUTBUTTON_HPP_
#define INPUTBUTTON_HPP_

#include "Button.hpp"

namespace gameEngine {
    namespace object {
        class InputButton : public encapsulation::AButton {
            public:
                InputButton(const Vector<float> &size, const Vector<float> &pos,
                const encapsulation::BText &content, const encapsulation::BColor &color,
                const encapsulation::BColor &selectColor = BLACK);
                ~InputButton();

                std::string getInput() const noexcept;
                void getNextChar() noexcept;
                void updateInput();

                void update() override;
                void draw() override;

            protected:
                encapsulation::BText _content;
                std::string _input;
                int _currentChar;
            private:
        };
    }
}

#endif /* !INPUTBUTTON_HPP_ */
