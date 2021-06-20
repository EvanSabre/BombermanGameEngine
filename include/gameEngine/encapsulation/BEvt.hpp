/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BEvt
*/

#ifndef BEVT_HPP_
#define BEVT_HPP_

#include "IInput.hpp"

namespace gameEngine::encapsulation
{
    class BEvt {
    public:
        static bool isKeyPressed(gameEngine::Key key);
        static bool isKeyDown(gameEngine::Key key);
        static bool isKeyUp(gameEngine::Key key);
        static bool isKeyReleased(gameEngine::Key key);
        static bool isMouseBtnPressed(gameEngine::Key key);
        static bool isMouseBtnReleased(gameEngine::Key key);
        static bool isMouseBtnDown(gameEngine::Key key);
        static bool isMouseBtnUp(gameEngine::Key key);
        static gameEngine::Key getKeyPressed(void);
    };
} // namespace gameEngine::encapsulation

#endif /* !BEVT_HPP_ */
