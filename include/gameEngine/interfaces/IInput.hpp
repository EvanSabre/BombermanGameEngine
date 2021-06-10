/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** IInput
*/

#ifndef IINPUT_HPP_
#define IINPUT_HPP_

#include <stdlib.h>
#include <string>
namespace gameEngine
{
    namespace interfaces
    {
        class IInput
        {
            public:
                virtual ~IInput() = default;
                virtual bool isKeyPressed(int key) = 0;
                virtual bool isKeyDown(int key) = 0;
                virtual bool isKeyUp(int key) = 0;
                virtual bool isKeyReleased(int key) = 0;
                virtual const std::string getDeviceName() = 0;
                virtual bool isDeviceAvailable(void) = 0;
                virtual bool isDeviceName(const char *name) = 0;
                virtual int getKeyPressed(void) = 0;
                virtual int getCharPressed(void) = 0;
                virtual int getDeviceID(void) = 0;

        };
    }
}

#endif /* !IINPUT_HPP_ */
