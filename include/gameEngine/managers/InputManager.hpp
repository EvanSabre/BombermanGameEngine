/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** KeyboardManager
*/

#ifndef KEYBOARDMANAGER_HPP_
#define KEYBOARDMANAGER_HPP_

#include "IInput.hpp"
#include "raylib.h"
//#include <bits/stdc++.h>

namespace gameEngine
{

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

    // std::unordered_map<Event, InputFunc> ExampleMap =
    // {
    //     {MOVE_UP_IN_MENU, {&gameEngine::interfaces::IInput::isKeyPressed, KEY_UP}}
    //     {MOVE_UP_IN_MENU, {&gameEngine::interfaces::IInput::isKeyPressed, GAMEPAD_LEFT_UP}}
    // };

    namespace managers
    {
        template <typename E>
        class InputManager
        {

            public:
                InputManager(const UserInputs &inputList, std::unordered_map<E, InputFunc> keymap)
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

                //TODO: fix by queue
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
