/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** KeyMap
*/

#ifndef KEYMAP_HPP_
#define KEYMAP_HPP_

#include "IInput.hpp"
namespace game
{
    typedef enum Event
    {
        MOVE_UP,
        MOVE_DOWN,
        MOVE_RIGHT,
        MOVE_LEFT,
        VALIDATE,
        PAUSE,
        BACK,
    }Event;

    std::unordered_map<Event, gameEngine::Controller> defaultKeymap =
    {
        {MOVE_UP,
            gameEngine::Controller(&gameEngine::interfaces::IInput::isKeyPressed,
                gameEngine::AttachedKeys(gameEngine::GAMEPAD_BUTTON_LEFT_FACE_UP, gameEngine::KEY_UP))
        }
    };

};

#endif /* !KEYMAP_HPP_ */
