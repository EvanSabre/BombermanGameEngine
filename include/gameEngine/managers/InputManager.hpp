/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** KeyboardManager
*/

#ifndef KEYBOARDMANAGER_HPP_
#define KEYBOARDMANAGER_HPP_

#include "gameEngine/interfaces/IInput.hpp"
#include <unordered_map>
#include <memory>
#include "raylib.h"
#include <string>

namespace gameEngine
{
    namespace managers
    {
        template <typename E>
        class InputManager
        {
            public:
                InputManager(gameEngine::interfaces::IInput *input, E interpret_values, int id=0);
                ~InputManager();
                bool isKeyPressed(int key) {return input->isKeyPressed(key, _id)};
                bool isKeyReleased(int key) {return input->isKeyReleased(key, _id)};
                bool isKeyDown(int key) {return input->isKeyDown(key, _id)};
                bool getLastEvent(int event) {return input->isKeyReleased(key, _id)};
                int getLastKeyPressed(void);
                bool mapDefaultKeys(int, int);
                bool mapKey(int key, E interpret_value) {}

            private:
                std::unordered_map<int, E> _Eventsmap;
                int _id;
                std::unique_ptr<gameEngine::interfaces::IInput> input;
        };

    }
}

#endif /* !KEYBOARDMANAGER_HPP_ */
