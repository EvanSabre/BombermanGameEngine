/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Gamepad
*/

#ifndef GAMEPAD_HPP_
#define GAMEPAD_HPP_

#include <array>
#include "gameEngine/interfaces/IInput.hpp"

namespace gameEngine
{
    namespace encapsulation
    {
        class Gamepad : public gameEngine::interfaces::IInput
        {
            public:
                Gamepad(int deviceID=0) : _deviceID(deviceID) {}
                ~Gamepad() = default;
                bool isKeyPressed(int key) override;
                bool isKeyDown(int key) override;
                bool isKeyUp(int key) override;
                bool isKeyReleased(int key) override;
                const std::string getDeviceName(void) override;
                bool isDeviceAvailable(void) override;
                bool isDeviceName(const char *name) override;
                int getKeyPressed(void) override;
                int getDeviceID(void) override {return _deviceID;}

            private:
                int getAxisMovement(void);
                int _deviceID;
        };
    };
};

#endif /* !GAMEPAD_HPP_ */
