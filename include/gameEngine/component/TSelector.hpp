/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Selector
*/

#ifndef TSELECTOR_HPP_
#define TSELECTOR_HPP_

#include "Button.hpp"
#include "ButtonManager.hpp"
#include <vector>
#include "BCamera.hpp"
#include "Selector.hpp"
#include "Path.hpp"

#define BUTTON gameEngine::encapsulation::Button
#define TEXT gameEngine::encapsulation::BText
#define RECTANGLE gameEngine::encapsulation::BRectangle
#define NEXT_BUTTON_PATH Path::getOSPath("./assets/Backgrounds/arrow_next.png")
#define PREV_BUTTON_PATH Path::getOSPath("./assets/Backgrounds/arrow_previous.png")

// typedef enum TSelectorEvent
// {
//     TNONE,
//     TNEXT,
//     TPREV
// }TSelectorEvent;

//passer path_texture du bouton


namespace gameEngine
{
    namespace component
    {
        template<class T>
        class TSelector
        {
            public:
                TSelector(
                    const std::string &name,
                    std::vector<std::shared_ptr<T>> &contents,
                    Vector<float> pos,
                    Vector<float> size,
                    int sizeText,
                    gameEngine::encapsulation::BColor color = WHITE,
                    gameEngine::encapsulation::BColor colorText = BLACK,
                    bool is3D = false) {
                            _iCurrent = 0;
                            _is3D = is3D;
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
                            _mainRect = std::make_unique<RECTANGLE>(size, pos, color);
                            for (auto i : contents) {
                                _contents.push_back(i);
                            }
                            _contentPos = Vector<float>(pos._x + size._x * 0.5, pos._y + size._y * 0.4);
                            _contentSize = sizeButton;
                            _buttonManager.pushButton(_buttonNext);
                            _buttonManager.pushButton(_buttonPrev);
                            if (is3D) {
                                _cam.setPosition({-20, 180, 70});
                                _cam.setTarget({70, 0, 70});
                                _cam.setUp({0, 1, 0});
                                _cam.setFovy(55);
                                _cam.setProjection(CAMERA_PERSPECTIVE);
                            }
                    }
                ~TSelector() = default;

                std::shared_ptr<T> &getCurrentContent() { return _contents[_iCurrent]; }

                void setContent(const std::vector<std::shared_ptr<T>> &content) { _contents = content;}
                void setICurrent(const int &iCurrent) { _iCurrent = iCurrent; }
                int getNbContent() { return (int)_contents.size();}
                int getIdActualContent() { return _iCurrent; }
                void set3D(bool enabled);

                SelectorEvent getTEvent(void) {
                        if (_buttonManager.isButtonClicked("Next") == true) {
                            printf("NEXT\n");
                            return SelectorEvent::NEXT;
                        } else if (_buttonManager.isButtonClicked("Prev"))
                            return SelectorEvent::PREV;
                        return SelectorEvent::NONE;
                }
                void draw() { _mainRect->draw(); _buttonManager.drawButtons(); _title->draw();
                            if (_is3D) {
                                _cam.beginMode();
                                _contents[_iCurrent]->draw();
                                _cam.endMode();
                            } else
                                _contents[_iCurrent]->draw();
                            }
                void update() {
                        _buttonManager.updateButtons();
                        enum SelectorEvent event = getTEvent();

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
                gameEngine::encapsulation::BCamera _cam;
            private:
                gameEngine::managers::ButtonManager _buttonManager;
                std::unique_ptr<RECTANGLE> _mainRect = nullptr;
                std::shared_ptr<BUTTON> _buttonNext = nullptr;
                std::shared_ptr<BUTTON> _buttonPrev = nullptr;
                std::unique_ptr<TEXT> _title = nullptr;
                std::vector<std::shared_ptr<T>> _contents;
                int _iCurrent = 0;
                bool _is3D = false;
                Vector<float> _contentSize = {0, 0};
                Vector<float> _contentPos = {0, 0};
        };
    };
};
#endif /* !SELECTOR_HPP_ */
