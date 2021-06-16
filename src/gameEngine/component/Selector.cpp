/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Selector
*/

#include "Selector.hpp"
#include "Path.hpp"

using namespace gameEngine::component;

#define NEXT_BUTTON_PATH Path::getOSPath("./arrow_next.png")
#define PREV_BUTTON_PATH Path::getOSPath("./arrow_next.png")

Selector::Selector(
    const std::string &name,
    const std::vector<std::shared_ptr<gameEngine::encapsulation::ADrawable>> &contents,
    Vector<float> pos,
    Vector<float> size,
    gameEngine::encapsulation::BColor color,
    gameEngine::encapsulation::BColor colorText
    )
{
    Vector<float> sizeButton(size._x * 0.1, size._x * 0.1);
    _title = std::make_unique<TEXT>(name,
                                    Vector<float>(pos._x * 0.5, pos._y * 0.1),
                                    colorText,
                                    size._x / size._y,
                                    nullptr);
    _buttonNext = std::make_unique<BUTTON>(sizeButton, Vector<float>(pos._x * 0.9, pos._y * 0.5), TEXT("Next"), color, colorText, NEXT_BUTTON_PATH);
    _buttonPrev = std::make_unique<BUTTON>(sizeButton, Vector<float>(pos._x * 0.1, pos._y * 0.5), TEXT("Prev"), color, colorText, PREV_BUTTON_PATH);
    _mainRect = std::make_unique<RECTANGLE>(size, pos, color);
    _contents = contents;
    _contentPos = Vector<float>(pos._x * 0.5, pos._y * 0.5);
    _contentSize = Vector<float>(size._x * 0.3, size._y * 0.3);
}

Selector::~Selector()
{
    
}

Vector<float> Selector::getContentEmplacementSize(void)
{
    return _contentSize;
}

Vector<float> Selector::getContentEmplacementPos(void)
{
    return _contentPos;
}

std::shared_ptr<gameEngine::encapsulation::ADrawable> &Selector::getCurrentContent()
{
    return _contents[_iCurrent];
}

void Selector::draw()
{
    _mainRect->draw();
    _buttonNext->draw();
    _buttonPrev->draw();
    _title->draw();
    _contents[_iCurrent]->draw();
}

void Selector::update()
{
    switch (this->getEvent())
    {
        case NEXT:
            _iCurrent += 1;
            if (_iCurrent > (int)_contents.size())
                _iCurrent = 0;
            break;
        case PREV:
            _iCurrent -= 1;
            if (_iCurrent < 0)
                _iCurrent = _contents.size();
            break;
        default:
            break;
    }
}

SelectorEvent Selector::getEvent(void)
{
    if (_buttonNext->getButtonPressed())
        return SelectorEvent::NEXT;
    else if (_buttonPrev->getButtonPressed())
        return SelectorEvent::PREV;
    return SelectorEvent::NONE;
}
