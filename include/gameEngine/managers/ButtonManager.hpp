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

                void setCallBackForButton(const std::string &content, std::shared_ptr<game::managers::GameManager> info,
                std::function<void(std::shared_ptr<game::managers::GameManager> info)> func);
                void setEnabledButton(const std::string &content, bool enabled);
                void createButton(const std::shared_ptr<BTexture2D> &texture, const std::shared_ptr<BRectangle> &rect, const std::shared_ptr<BText> &content);
                void pushButton(std::shared_ptr<encapsulation::AButton> button);

                std::vector<std::shared_ptr<gameEngine::encapsulation::AButton>> getCurrentButtons() const;
                void drawButtons();
                void updateButtons();
            private:
                std::vector<std::shared_ptr<gameEngine::encapsulation::AButton>> _currentButtons;
        };
    }
}
#endif /* !BUTTONMANAGER_HPP_ */
