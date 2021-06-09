/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** KeyboardManager
*/

#ifndef KEYBOARDMANAGER_HPP_
#define KEYBOARDMANAGER_HPP_

#include "gameEngine/encapsulation/Keyboard.hpp"
#include "gameEngine/encapsulation/Gamepad.hpp"
#include <unordered_map>
#include <memory>
#include "raylib.h"
#include <string>
#include <vector>
#include <bits/stdc++.h>

namespace gameEngine
{
    // ! every scene must define her enum

    //chaque scene à sa map--><Action, function>
    //chaque scene à sa map--><Key, Action>
    enum Key
    {
        KEY_NULL            = 0,
        KEY_APOSTROPHE      = 39,
        KEY_COMMA           = 44,
        KEY_MINUS           = 45,
        KEY_PERIOD          = 46,
        KEY_SLASH           = 47,
        KEY_ZERO            = 48,
        KEY_ONE             = 49,
        KEY_TWO             = 50,
        KEY_THREE           = 51,
        KEY_FOUR            = 52,
        KEY_FIVE            = 53,
        KEY_SIX             = 54,
        KEY_SEVEN           = 55,
        KEY_EIGHT           = 56,
        KEY_NINE            = 57,
        KEY_SEMICOLON       = 59,
        KEY_EQUAL           = 61,
        KEY_A               = 65,
        KEY_B               = 66,
        KEY_C               = 67,
        KEY_D               = 68,
        KEY_E               = 69,
        KEY_F               = 70,
        KEY_G               = 71,
        KEY_H               = 72,
        KEY_I               = 73,
        KEY_J               = 74,
        KEY_K               = 75,
        KEY_L               = 76,
        KEY_M               = 77,
        KEY_N               = 78,
        KEY_O               = 79,
        KEY_P               = 80,
        KEY_Q               = 81,
        KEY_R               = 82,
        KEY_S               = 83,
        KEY_T               = 84,
        KEY_U               = 85,
        KEY_V               = 86,
        KEY_W               = 87,
        KEY_X               = 88,
        KEY_Y               = 89,
        KEY_Z               = 90,
        KEY_SPACE           = 32,
        KEY_ESCAPE          = 256,
        KEY_ENTER           = 257,
        KEY_TAB             = 258,
        KEY_BACKSPACE       = 259,
        KEY_INSERT          = 260,
        KEY_DELETE          = 261,
        KEY_RIGHT           = 262,
        KEY_LEFT            = 263,
        KEY_DOWN            = 264,
        KEY_UP              = 265,
        KEY_PAGE_UP         = 266,
        KEY_PAGE_DOWN       = 267,
        KEY_HOME            = 268,
        KEY_END             = 269,
        KEY_CAPS_LOCK       = 280,
        KEY_SCROLL_LOCK     = 281,
        KEY_NUM_LOCK        = 282,
        KEY_PRINT_SCREEN    = 283,
        KEY_PAUSE           = 284,
        KEY_F1              = 290,
        KEY_F2              = 291,
        KEY_F3              = 292,
        KEY_F4              = 293,
        KEY_F5              = 294,
        KEY_F6              = 295,
        KEY_F7              = 296,
        KEY_F8              = 297,
        KEY_F9              = 298,
        KEY_F10             = 299,
        KEY_F11             = 300,
        KEY_F12             = 301,
        KEY_LEFT_SHIFT      = 340,
        KEY_LEFT_CONTROL    = 341,
        KEY_LEFT_ALT        = 342,
        KEY_LEFT_SUPER      = 343,
        KEY_RIGHT_SHIFT     = 344,
        KEY_RIGHT_CONTROL   = 345,
        KEY_RIGHT_ALT       = 346,
        KEY_RIGHT_SUPER     = 347,
        KEY_KB_MENU         = 348,
        KEY_LEFT_BRACKET    = 91,
        KEY_BACKSLASH       = 92,
        KEY_RIGHT_BRACKET   = 93,
        KEY_GRAVE           = 96,
        KEY_KP_0            = 320,
        KEY_KP_1            = 321,
        KEY_KP_2            = 322,
        KEY_KP_3            = 323,
        KEY_KP_4            = 324,
        KEY_KP_5            = 325,
        KEY_KP_6            = 326,
        KEY_KP_7            = 327,
        KEY_KP_8            = 328,
        KEY_KP_9            = 329,
        KEY_KP_DECIMAL      = 330,
        KEY_KP_DIVIDE       = 331,
        KEY_KP_MULTIPLY     = 332,
        KEY_KP_SUBTRACT     = 333,
        KEY_KP_ADD          = 334,
        KEY_KP_ENTER        = 335,
        KEY_KP_EQUAL        = 336,
        KEY_BACK            = 4,
        KEY_MENU            = 82,
        KEY_VOLUME_UP       = 24,
        KEY_VOLUME_DOWN     = 25,
        //TODO: rajouter + 400 au get_key return du gamepad
        //TODO: enlever -400 au get_key return du gamepad
        GAMEPAD_BUTTON_LEFT_FACE_UP = 401,
        GAMEPAD_BUTTON_LEFT_FACE_RIGHT = 402,
        GAMEPAD_BUTTON_LEFT_FACE_DOWN = 403,
        GAMEPAD_BUTTON_LEFT_FACE_LEFT = 404,

        // This normally corresponds with PlayStation and Xbox controllers
        // XBOX: [Y,X,A,B]
        // PS3: [Triangle,Square,Cross,Circle]
        // No support for 6 button controllers though..
        GAMEPAD_BUTTON_RIGHT_FACE_UP = 405,
        GAMEPAD_BUTTON_RIGHT_FACE_RIGHT = 405,
        GAMEPAD_BUTTON_RIGHT_FACE_DOWN = 406,
        GAMEPAD_BUTTON_RIGHT_FACE_LEFT = 407,

        // Triggers
        GAMEPAD_BUTTON_LEFT_TRIGGER_1 = 408,
        GAMEPAD_BUTTON_LEFT_TRIGGER_2 = 409,
        GAMEPAD_BUTTON_RIGHT_TRIGGER_1 = 410,
        GAMEPAD_BUTTON_RIGHT_TRIGGER_2 = 411,

        // These are buttons in the center of the gamepad
        GAMEPAD_BUTTON_MIDDLE_LEFT = 412,     // PS3 Select
        GAMEPAD_BUTTON_MIDDLE = 413,          // PS Button/XBOX Button
        GAMEPAD_BUTTON_MIDDLE_RIGHT = 414,    // PS3 Start

        // These are the joystick press in buttons
        GAMEPAD_BUTTON_LEFT_THUMB = 415,
        GAMEPAD_BUTTON_RIGHT_THUMB = 416
    };

    //Chaque scene s'envoie un vector de User_Infos, le menu principal ne gère que le joueur 1 avec son keyboard

    //TODO: Every scene should contain an InputManager and an associated Keymap
    //TODO: every scene enum Actions; // c'est ce qui est templatisé sous E dans inputManager
    //* for example see below:
    // Keymap_t default_Keymap=
    // {
    //     {Key::KEY_UP, INGAME_MOVE_UP},
    //     {Key::KEY_DOWN, INGAME_MOVE_DOWN},
    //     {Key::KEY_RIGHT, INGAME_MOVE_RIGHT},
    //     {Key::KEY_LEFT, INGAME_MOVE_LEFT},

    //template <typename E>
    typedef std::unordered_map<int, std::shared_ptr<gameEngine::interfaces::IInput>> UserInputs; // <id, Keyboard or Gamepad>
    typedef bool (gameEngine::interfaces::IInput::*InputFunc)(int, int);
    typedef std::pair<InputFunc, Key> keyEvent;
    //TODO: ajouter une map tel que dessous dans scene
    // std::unordered_map<int, keyEvent> ExampleMap =
    // {
    //     {1, {&gameEngine::interfaces::IInput::isKeyPressed, KEY_UP}}
    // };

    namespace managers
    {
        template <typename E>
        class InputManager
        {

            public:
                InputManager(UserInputs inputList, std::unordered_map<E, InputFunc> keymap)
                {
                    _inputList = inputList;
                    _keymap = keymap;
                }
                ~InputManager() = default;
                bool isUserKeyPressed(int userID, Key key)
                {
                    auto search = _inputList.find(userID);

                    if (search != _inputList.end())
                        return search->second.get()->isKeyPressed(key);
                    return false;
                }

                bool isUserKeyReleased(int userID, Key key)
                {
                    auto search = _inputList.find(key);

                    if (search != _inputList.end())
                        return search->second.get()->isKeyReleased(key);
                    return false;

                }

                bool isUserKeyDown(int userID, Key key)
                {
                    auto search = _inputList.find(key);

                    if (search != _inputList.end())
                        return search->second.get()->isKeyDown(key);
                    return false;

                }

                bool isUserKeyUp(int userID, Key key)
                {
                    auto search = _inputList.find(key);

                    if (search != _inputList.end())
                        return search->second.get()->isKeyUp(key);
                    return false;

                }

                std::unordered_map<int, bool> isUsersKeyPressed(Key key)
                {
                    std::unordered_map<int, bool> results;

                    for (auto &input : _inputList)
                        results.emplace(std::make_pair(input.first, input.second.get()->isKeyPressed(key)));
                    return results;
                }

                std::unordered_map<int, bool> isUsersKeyReleased(Key key)
                {
                    std::unordered_map<int, bool> results;

                    for (auto &input : _inputList)
                        results.emplace(std::make_pair(input.first, input.second.get()->isKeyReleased(key)));
                    return results;
                }

                std::unordered_map<int, bool> isUsersKeyDown(Key key)
                {
                    std::unordered_map<int, bool> results;

                    for (auto &input : _inputList)
                        results.emplace(std::make_pair(input.first, input.second.get()->isKeyDown(key)));
                    return results;
                }

                std::unordered_map<int, bool> isUsersKeyUp(Key key)
                {
                    std::unordered_map<int, bool> results;

                    for (auto &input : _inputList)
                        results.emplace(std::make_pair(input.first, input.second.get()->isKeyUp(key)));
                    return results;
                }

                bool isUserEventHappened(int userID, E event)
                {
                    auto searchUser = _inputList.find(userID);
                    auto searchEvent = _keymap.find(event);

                    if (searchUser != _inputList.end())
                    {
                        if (searchEvent != _keymap.end())
                            return searchUser->second.get()->*searchEvent->second.first(searchEvent->second.second);
                    }
                    return false;
                }

                std::unordered_map<int, bool> isUsersEventHappened(E event)
                {
                    std::unordered_map<int, bool> results;
                    auto searchEvent = _keymap.find(event);

                    for (auto &input : _inputList) {
                        if (searchEvent != _keymap.end())
                            results.emplace(std::make_pair(input.first, false));
                        else
                            results.emplace(std::make_pair(input.first, input.second.get()->*searchEvent->second.first(searchEvent->second.second)));
                    }
                    return results;
                }

                Key getLastKeyPressedByAUser()
                {
                    if (_inputList.empty())
                        return -1;
                    Key key = _inputList[0].get()->getKeyPressed();

                    if (_keymap.find(key))
                        return _keymap[key];
                    return -1;
                }

                std::vector<std::pair<int, E>> pollEvents()
                {
                    std::vector<std::pair<int, E>> results;

                    for (auto &input : _inputList) {
                        for (auto &event : _keymap) {
                            if (input.second.get()->*event->second.first(event->second.second))
                                results.push_back(std::make_pair(input.first, event->first));
                        }
                    }
                    return results;
                }

                E getLastEventPressedByAUser()
                {
                    if (_inputList.empty())
                        return -1;
                    Key key = _inputList[0].get()->getKeyPressed();

                    if (_keymap.find(key))
                        return _keymap[key];
                    return -1;
                };

            private:
                std::unordered_map<Key, E> _keymap;
                UserInputs _inputList;
        };
    }
}

#endif /* !KEYBOARDMANAGER_HPP_ */
