    /*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** ButtonManager
*/

#ifndef BUTTONMANAGER_HPP_
#define BUTTONMANAGER_HPP_

#include "Button.hpp"
#include <vector>
#include <memory>
#include <raylib.h>

using namespace gameEngine::encapsulation;

namespace gameEngine {
    namespace Managers {
        class ButtonManager {
            public:
                ButtonManager();
                ~ButtonManager();

                bool isButtonClicked(const Vector<float> &pos);
                bool isButtonClicked(const std::string &buttonContent, const Vector<float> &pos);
                std::shared_ptr<gameEngine::encapsulation::Button> getClickedButton(const Vector<float> &pos);
                gameEngine::encapsulation::Button createButton(const BTexture2D &texture, const BRectangle &rect, const BText &content);
                std::vector<gameEngine::encapsulation::Button> getCurrentButtons() const;
                void drawButtons();
                void updateButtons();
            private:
                std::vector<gameEngine::encapsulation::Button> _currentButtons;
        };
    }
}
#endif /* !BUTTONMANAGER_HPP_ */
