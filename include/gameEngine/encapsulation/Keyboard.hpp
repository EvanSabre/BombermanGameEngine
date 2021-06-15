/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Keyboard
*/

#ifndef KEYBOARD_HPP_
#define KEYBOARD_HPP_

#include "gameEngine/interfaces/IInput.hpp"

namespace gameEngine
{
    namespace encapsulation
    {
        class Keyboard : public gameEngine::interfaces::IInput
        {
            public:
                Keyboard(int deviceID=0) : _deviceID(deviceID) {}
                ~Keyboard() = default;
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
                int _deviceID = 0;
        };
    }
}

#endif /* !KEYBOARD_HPP_ */
