/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Keyboard
*/

#ifndef KEYBOARD_HPP_
#define KEYBOARD_HPP_

#include <raylib.h>
#include "gameEngine/interfaces/IInput.hpp"

namespace gameEngine
{
    namespace encapsulation
    {
        class Keyboard : public gameEngine::interfaces::IInput
        {
            public:
                Keyboard();
                ~Keyboard() = default;
                bool isKeyPressed(int key, int device = -1) override;
                bool isKeyDown(int key, int device = -1) override;
                bool isKeyUp(int key, int device = -1) override;
                bool isKeyReleased(int key, int device = -1) override;
                const char *getDeviceName(int device = -1) override;
                bool isDeviceAvailable(int device) override;
                bool isDeviceName(int device, const char *name) override;
                int getKeyPressed(void) override;
                int getCharPressed(void) override;
        };
    }
}

#endif /* !KEYBOARD_HPP_ */
