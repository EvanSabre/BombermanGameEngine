/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** InputManager
*/

#ifndef INPUTMANAGER_HPP_
#define INPUTMANAGER_HPP_


namespace gameEngine
{
namespace Interfaces
{

class IInputManager
{
    public:
        virtual ~IInputManager() = default;
        virtual bool isKeyPressed(int) = 0;
        virtual bool isKeyReleased(int) = 0;
        virtual int getKeyPressed() = 0;
        virtual bool mapKey(int, int) = 0;
        virtual bool mapDefaultKeys(int, int) = 0;
        virtual int getGamepadAxisCount(int gamepad) = 0;
        virtual float getGamepadAxisMovement(int gamepad, int axis) = 0;
};

}
}

#endif /* !INPUTMANAGER_HPP_ */
