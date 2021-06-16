/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Selector
*/

#ifndef SELECTOR_HPP_
#define SELECTOR_HPP_

#include "Button.hpp"
#include "ButtonManager.hpp"
#include <vector>

#define BUTTON gameEngine::encapsulation::Button
#define TEXT gameEngine::encapsulation::BText
#define RECTANGLE gameEngine::encapsulation::BRectangle

typedef enum SelectorEvent
{
    NONE,
    NEXT,
    PREV
}SelectorEvent;

//passer path_texture du bouton


namespace gameEngine
{
    namespace component
    {
        class Selector
        {
            public:
                Selector(
                    const std::string &name,
                    std::vector<std::shared_ptr<gameEngine::encapsulation::ADrawable>> &contents,
                    Vector<float> pos,
                    Vector<float> size,
                    int sizeText,
                    gameEngine::encapsulation::BColor color = WHITE,
                    gameEngine::encapsulation::BColor colorText = BLACK);
                ~Selector();

                Vector<float> getContentEmplacementSize(void);
                Vector<float> getContentEmplacementPos(void);
                std::shared_ptr<gameEngine::encapsulation::ADrawable> &getCurrentContent();

                void draw();
                void update();
            private:
                SelectorEvent getEvent(void);
                gameEngine::managers::ButtonManager _buttonManager;
                std::unique_ptr<RECTANGLE> _mainRect = nullptr;
                std::shared_ptr<BUTTON> _buttonNext = nullptr;
                std::shared_ptr<BUTTON> _buttonPrev = nullptr;
                std::unique_ptr<TEXT> _title = nullptr;
                std::vector<std::shared_ptr<gameEngine::encapsulation::ADrawable>> _contents;
                int _iCurrent = 0;
                Vector<float> _contentSize = {0, 0};
                Vector<float> _contentPos = {0, 0};
        };
    };
};
#endif /* !SELECTOR_HPP_ */
