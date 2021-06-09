/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** IInput
*/

#ifndef IINPUT_HPP_
#define IINPUT_HPP_

namespace gameEngine
{
    namespace interfaces
    {
        class IInput
        {
            public:
                virtual ~IInput() = default;
                virtual bool isKeyPressed(int key, int device = -1) = 0;
                virtual bool isKeyDown(int key, int device = -1) = 0;
                virtual bool isKeyUp(int key, int device = -1) = 0;
                virtual bool isKeyReleased(int key, int device = -1) = 0;
                virtual const char *getDeviceName(int device = -1) = 0;
                virtual bool isDeviceAvailable(int device) = 0;
                virtual bool isDeviceName(int device, const char *name) = 0;
                virtual int getKeyPressed(void) = 0;
                virtual int getCharPressed(void) = 0;
        };
    }
}

#endif /* !IINPUT_HPP_ */
