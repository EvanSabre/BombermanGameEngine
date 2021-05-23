/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** ButtonManager
*/

#ifndef BUTTONMANAGER_HPP_
#define BUTTONMANAGER_HPP_

#include "Button.hpp"
#include <string>
#include <vector>

namespace game {
    namespace Managers {
        class ButtonManager {
            public:
                ButtonManager();
                ~ButtonManager();

                bool isButtonClicked(Vector<double> pos);
                bool isButtonClicked(const std::string &buttonContent, Vector<double> pos);
                gameEngine::Button createButton(Vector<double> pos, Vector<double> size);
                std::vector<gameEngine::Button> getCurrentButtons() const;
            private:
                std::vector<gameEngine::Button> _currentButtons;
        };
    }
}
#endif /* !BUTTONMANAGER_HPP_ */
