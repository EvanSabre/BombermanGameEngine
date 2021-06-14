/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** CheckBoxManager
*/

#ifndef CHECKBOXMANAGER_HPP_
#define CHECKBOXMANAGER_HPP_

#include "ButtonManager.hpp"
#include "CheckBox.hpp"

namespace gameEngine {
    namespace managers {
        class CheckBoxManager {
            public:
                CheckBoxManager();
                ~CheckBoxManager();

                bool isClicked(const Vector<float> &pos);
                bool isClicked(const std::string &content);
                bool isClicked(const std::string &Content, const Vector<float> &pos);

                void createCheckBown(const std::shared_ptr<BTexture2D> &texture, const std::shared_ptr<BRectangle> &rect, const std::shared_ptr<BText> &content);
                void pushElt(std::shared_ptr<encapsulation::CheckBox> button);

                std::shared_ptr<gameEngine::encapsulation::CheckBox> getClickedElt(const Vector<float> &pos);
                std::vector<std::shared_ptr<gameEngine::encapsulation::CheckBox>> getCurrentElts() const;
                void draw();
                void update();
            private:
                std::vector<std::shared_ptr<gameEngine::encapsulation::CheckBox>> _currentElts;
        };
    }
}
#endif /* !CHECKBOXMANAGER_HPP_ */
