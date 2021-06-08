/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Gamepad
*/

#ifndef GAMEPAD_HPP_
#define GAMEPAD_HPP_

#include <raylib.h>
#include "gameEngine/interfaces/IInput.hpp"

namespace gameEngine
{
    namespace encapsulation
    {
        class Gamepad : public gameEngine::interfaces::IInput
        {
            public:
                Gamepad();
                ~Gamepad() = default;
                bool isKeyPressed(int key, int device=-1) override;
                bool isKeyDown(int key, int device=-1) override;
                bool isKeyUp(int key, int device=-1) override;
                bool isKeyReleased(int key, int device=-1) override;
                const std::string getDeviceName(int device=-1) override;
                bool isDeviceAvailable(int device) override;
                bool isDeviceName(int device, const char *name) override;
                int getKeyPressed(void) override;
                int getCharPressed(void) override;
        };
    }
}

#endif /* !GAMEPAD_HPP_ */
