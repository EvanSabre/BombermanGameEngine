/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BEvt
*/

#ifndef BEVT_HPP_
#define BEVT_HPP_

#include "IInput.hpp"
#include "Vector.hpp"

namespace gameEngine::encapsulation
{
    class BEvt {
    public:
        static bool isKeyPressed(int key);
        static bool isKeyDown(int key);
        static bool isKeyUp(int key);
        static bool isKeyReleased(int key);
        static bool isMouseBtnPressed(int key);
        static bool isMouseBtnReleased(int key);
        static bool isMouseBtnDown(int key);
        static bool isMouseBtnUp(int key);
        static int getKeyPressed(void);
        static int getCharPressed(void);
        static Vector<float> getMousePosition(void);
    };
} // namespace gameEngine::encapsulation

#endif /* !BEVT_HPP_ */
