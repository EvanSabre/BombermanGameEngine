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
    namespace managers {
        class ButtonManager {
            public:
                ButtonManager();
                ~ButtonManager();

                bool isButtonClicked(const Vector<float> &pos);
                bool isButtonClicked(const std::string &content);
                bool isButtonClicked(const std::string &buttonContent, const Vector<float> &pos);

                bool createButton(const BTexture2D &texture, const BRectangle &rect, const BText &content);
                void pushButton(std::shared_ptr<encapsulation::Button> button);

                std::shared_ptr<gameEngine::encapsulation::Button> getClickedButton(const Vector<float> &pos);
                std::vector<std::shared_ptr<gameEngine::encapsulation::Button>> getCurrentButtons() const;
                void drawButtons();
                void updateButtons();
            private:
                std::vector<std::shared_ptr<gameEngine::encapsulation::Button>> _currentButtons;
        };
    }
}
#endif /* !BUTTONMANAGER_HPP_ */
