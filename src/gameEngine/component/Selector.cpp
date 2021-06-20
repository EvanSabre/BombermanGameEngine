/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Selector
*/

#include "Selector.hpp"
#include "Path.hpp"
#include "BModel.hpp"

using namespace gameEngine::component;

#define NEXT_BUTTON_PATH Path::getOSPath("./assets/Backgrounds/arrow_next.png")
#define PREV_BUTTON_PATH Path::getOSPath("./assets/Backgrounds/arrow_previous.png")
#define SELECTOR_ASSET "./assets/Backgrounds/button_background2.png"
static const Vector<float> SCALE_SELECTOR(0.5, 0.5);

Selector::Selector(
    const std::string &name,
    std::vector<std::shared_ptr<gameEngine::encapsulation::ADrawable>> &contents,
    Vector<float> pos,
    Vector<float> size,
    int sizeText,
    gameEngine::encapsulation::BColor colorText)
{
    Vector<float> sizeButton(size._x * 0.1, size._x * 0.1);
    _title = std::make_unique<TEXT>(name,
                                    Vector<float>(pos._x + size._x * 0.35, pos._y + size._y * 0.1),
                                    colorText,
                                    sizeText,
                                    nullptr);
    _buttonNext = std::make_shared<BUTTON>(sizeButton,
                                            Vector<float>(pos._x + size._x * 0.8, pos._y + size._y * 0.25),
                                            TEXT("Next"),
                                            BLUE,
                                            colorText,
                                            NEXT_BUTTON_PATH);
    _buttonPrev = std::make_shared<BUTTON>(sizeButton,
                                            Vector<float>(pos._x + size._x * 0.1, pos._y + size._y * 0.25),
                                            TEXT("Prev"),
                                            BLUE,
                                            colorText,
                                            PREV_BUTTON_PATH);
    _mainRect = std::make_unique<IMAGE>(SELECTOR_ASSET, "test");
    _mainRect->setEnabled(true);
    _mainRect->setPos(Vector<int>(pos._x, pos._y));
    //_mainRect->setTransform().setScale(Vector3T<float>(size._x, size._y, 0));
    _contents = contents;
    _contentPos = Vector<float>(pos._x + size._x * 0.5, pos._y + size._y * 0.4);
    _contentSize = sizeButton;
    _buttonManager.pushButton(_buttonNext);
    _buttonManager.pushButton(_buttonPrev);

    for (auto &i : _contents)
        i->setTransform().setPosition(Vector3T<float>(_contentPos._x, _contentPos._y, 0));
}

Selector::~Selector()
{
}

std::shared_ptr<gameEngine::encapsulation::ADrawable> &Selector::getCurrentContent()
{
    return _contents[_iCurrent];
}

void Selector::setICurrent(const int &iCurrent)
{
    _iCurrent = iCurrent;
}

void Selector::setContent(const std::vector<std::shared_ptr<gameEngine::encapsulation::ADrawable>> &content)
{
    _contents = content;
}

void Selector::draw()
{
    _mainRect->drawEx(Vector<float>(2.3, 1));
    //_mainRect->draw();
    _buttonManager.drawButtons();
    _contents[_iCurrent]->draw();
    _title->draw();
}

void Selector::update()
{
    _buttonManager.updateButtons();
    enum SelectorEvent event = getEvent();

    switch (event)
    {
        case SelectorEvent::NEXT:
            _iCurrent += 1;
            std::cout << "NEXT currentElem = "<< std::to_string(_iCurrent) <<std::endl;
            if (_iCurrent > (int)_contents.size() - 1)
                _iCurrent = 0;
            break;
        case SelectorEvent::PREV:
            _iCurrent -= 1;
            std::cout << "PREV currentElem = "<< std::to_string(_iCurrent) <<std::endl;
            if (_iCurrent < 0)
                _iCurrent = _contents.size() - 1;
            break;
        default:
            break;
    }
}


SelectorEvent Selector::getEvent(void)
{
    if (_buttonManager.isButtonClicked("Next") == true) {
        printf("NEXT\n");
        return SelectorEvent::NEXT;
    } else if (_buttonManager.isButtonClicked("Prev"))
        return SelectorEvent::PREV;
    return SelectorEvent::NONE;
}

void Selector::setContentPos(Vector<float> pos)
{
    _contentPos = pos;
    for (auto &i : _contents) {
        printf("SET CONTENT i = %s\n", i->getContent().c_str());
        i->setTransform().setPosition(Vector3T<float>(_contentPos._x, _contentPos._y, 0));
    }
    //exit(0);
}

int Selector::getNbContent()
{
    return (int)_contents.size();
}

int Selector::getIdActualContent()
{
    return _iCurrent;
}
