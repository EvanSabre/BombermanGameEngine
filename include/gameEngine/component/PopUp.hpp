/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** PopUp
*/

#ifndef POPUP_HPP_
#define POPUP_HPP_

#include "ADrawable.hpp"
#include "Button.hpp"

namespace gameEngine {
    namespace component {
        class PopUp : public gameEngine::encapsulation::ADrawable {
            public:
                PopUp(const std::string &text, const Vector<float> &pos = {0,0}, const Vector<float> &size = {0,0});
                ~PopUp();

                void update() override;
                void draw() override;
                std::string getContent() const noexcept override;
                void setEnabled(bool enabled);
                bool getEnabled() const;
            protected:
                bool _enabled = true;
                gameEngine::encapsulation::Button _button;
                gameEngine::encapsulation::BText _text;
                gameEngine::encapsulation::BRectangle _rect;
            private:
        };
    }
}

#endif /* !POPUP_HPP_ */
