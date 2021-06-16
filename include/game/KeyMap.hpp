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
        BACK,
    }Event;

    // std::unordered_map<Event, gameEngine::Controller> defaultKeymap =
    // {
    //     {MOVE_UP,
    //         gameEngine::Controller(&gameEngine::interfaces::IInput::isKeyPressed,
    //             gameEngine::AttachedKeys(gameEngine::GAMEPAD_BUTTON_LEFT_FACE_UP, gameEngine::KEY_UP))
    //     }
    //     //{MOVE_DOWN, std::make_pair<gameEngine::InputFunc, gameEngine::Key>(&gameEngine::interfaces::IInput::isKeyPressed, gameEngine::GAMEPAD_BUTTON_LEFT_FACE_DOWN)},
    //     //{MOVE_RIGHT, std::make_pair<gameEngine::InputFunc, gameEngine::Key>(&gameEngine::interfaces::IInput::isKeyPressed, gameEngine::GAMEPAD_BUTTON_LEFT_FACE_RIGHT)},
    //     //{MOVE_LEFT, std::make_pair<gameEngine::InputFunc, gameEngine::Key>(&gameEngine::interfaces::IInput::isKeyPressed, gameEngine::GAMEPAD_BUTTON_LEFT_FACE_LEFT)},
    //     //{VALIDATE, std::make_pair<gameEngine::InputFunc, gameEngine::Key>(&gameEngine::interfaces::IInput::isKeyPressed, gameEngine::GAMEPAD_BUTTON_RIGHT_FACE_DOWN)},
    //     //{BACK, std::make_pair<gameEngine::InputFunc, gameEngine::Key>(&gameEngine::interfaces::IInput::isKeyPressed, gameEngine::GAMEPAD_BUTTON_RIGHT_FACE_DOWN)},
    // };
};

#endif /* !KEYMAP_HPP_ */
