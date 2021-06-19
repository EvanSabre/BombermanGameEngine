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
#include <queue>

namespace gameEngine
{

    //Chaque scene s'envoie un vector de User_Infos, le menu principal ne gère que le joueur 1 avec son keyboard

    //TODO: Every scene should contain an InputManager and an associated Keymap
    //TODO: every scene enum Actions; // c'est ce qui est templatisé sous E dans inputManager

    namespace managers
    {
        template <typename E>
        class InputManager
        {
            public:
                InputManager(const UserInputs &inputList, std::unordered_map<E, std::pair<gameEngine::Key, gameEngine::Key>> keymap)
                {
                    this->setKeymap(keymap);
                    _inputList = inputList;
                }

                ~InputManager() = default;
                bool isUserKeyPressed(int userID, Key key)
                {
                    auto search = _inputList.find(userID);

                    if (search != _inputList.end())
                        return search->second->isKeyPressed(key);
                    return false;
                }

                bool isUserKeyReleased(int userID, Key key)
                {
                    auto search = _inputList.find(key);

                    if (search != _inputList.end())
                        return search->second->isKeyReleased(key);
                    return false;

                }

                bool isUserKeyDown(int userID, Key key)
                {
                    auto search = _inputList.find(key);

                    if (search != _inputList.end())
                        return search->second->isKeyDown(key);
                    return false;

                }

                bool isUserKeyUp(int userID, Key key)
                {
                    auto search = _inputList.find(key);

                    if (search != _inputList.end())
                        return search->second->isKeyUp(key);
                    return false;

                }

                std::unordered_map<int, bool> isUsersKeyPressed(Key key)
                {
                    std::unordered_map<int, bool> results;

                    for (auto &input : _inputList)
                        results.emplace(std::make_pair(input.first, input.second->isKeyPressed(key)));
                    return results;
                }

                std::unordered_map<int, bool> isUsersKeyReleased(Key key)
                {
                    std::unordered_map<int, bool> results;

                    for (auto &input : _inputList)
                        results.emplace(std::make_pair(input.first, input.second->isKeyReleased(key)));
                    return results;
                }

                std::unordered_map<int, bool> isUsersKeyDown(Key key)
                {
                    std::unordered_map<int, bool> results;

                    for (auto &input : _inputList)
                        results.emplace(std::make_pair(input.first, input.second->isKeyDown(key)));
                    return results;
                }

                std::unordered_map<int, bool> isUsersKeyUp(Key key)
                {
                    std::unordered_map<int, bool> results;

                    for (auto &input : _inputList)
                        results.emplace(std::make_pair(input.first, input.second->isKeyUp(key)));
                    return results;
                }

                bool isUserEventHappened(int userID, E event)
                {
                    auto searchUser = _inputList.find(userID);
                    auto searchEvent = _keymap.find(event);

                    if (searchUser != _inputList.end())
                    {
                        if (searchEvent != _keymap.end())
                            return (searchUser->second.get()->*searchEvent->second.first)(searchEvent->second.second.first) ||
                            (searchUser->second.get()->*searchEvent->second.first)(searchEvent->second.second.second);
                    }
                    return false;
                }

                std::unordered_map<int, bool> isUsersEventHappened(E event)
                {
                    std::unordered_map<int, bool> results;
                    auto searchEvent = _keymap.find(event);

                    for (auto &[id ,input] : _inputList) {
                        if (searchEvent != _keymap.end())
                            results.emplace(std::make_pair(id, false));
                        else
                            results.emplace(std::make_pair(id, ((input.get()->*searchEvent->second.first)(searchEvent->second.second.first)) ||
                            ((input.get()->*searchEvent->second.first)(searchEvent->second.second.second))
                            ));
                    }
                    return results;
                }

                Key getLastKeyPressedByAUser()
                {
                    if (_inputList.empty())
                        return KEY_NULL;
                    for(auto &input : _inputList) {
                        if (input.second->isDeviceAvailable())
                            return (Key) input.second->getKeyPressed();
                    }
                    return KEY_NULL;
                }

                std::vector<std::pair<int, E>> pollEvents()
                {
                    std::vector<std::pair<int, E>> results;
                    for (auto &[id, input] : _inputList) {
                        for (auto &[event, pairFunc] : _keymap) {
                            if((input.get()->*pairFunc.first)(pairFunc.second.first) || (input.get()->*pairFunc.first)(pairFunc.second.second)) {
                                // std::cout << "Joueur "<< id << " Pressed " << event << std::endl;
                                results.push_back(std::make_pair(id, event));
                            }
                        }
                    }
                    return results;
                }

                E getLastEventPressedByAUser()
                {
                    if (_inputList.empty())
                        return -1;
                    Key key = _inputList[0]->getKeyPressed();

                    if (_keymap.find(key))
                        return _keymap[key];
                    return -1;
                }

                void removeMapKey(E event, Controller func)
                {
                    for(auto it = _keymap.begin(); it != _keymap.end();)
                    {
                        if(it->first == event && it->second == func)
                            it = _keymap.erase(it);
                        else
                            ++it;
                    }
                }

                void setKeymap(std::unordered_map<E, gameEngine::AttachedKeys> keymap)
                {
                    _keymap.clear();
                    for (auto &[event, keybinding] : keymap)
                    {
                        if ((int) event < 5) {
                            _keymap.insert({event, Controller(&gameEngine::interfaces::IInput::isKeyDown, keybinding)});
                            std::cout << event << std::endl;
                        }
                        else
                            _keymap.insert({event, Controller(&gameEngine::interfaces::IInput::isKeyPressed, keybinding)});
                    }
                }

                void mapKey(E event, gameEngine::Key key, bool gamepadOrSecond)
                {
                    for (auto &i : _keymap)
                    {
                        if (i->first == event && gamepadOrSecond)
                            i->second->second->second = key;
                        else if (i->first == event && !gamepadOrSecond)
                            i->second->second->first = key;
                    }
                }

                void mapKey(E event, Controller func)
                {
                    for(auto it = _keymap.begin(); it != _keymap.end();)
                    {
                        if(it->second == func)
                            it = _keymap.erase(it);
                        else
                            ++it;
                    }
                    _keymap.emplace(event, func);
                }



            private:
                std::unordered_map<E, Controller> _keymap;
                UserInputs _inputList;
        };
    }
}

#endif /* !KEYBOARDMANAGER_HPP_ */
