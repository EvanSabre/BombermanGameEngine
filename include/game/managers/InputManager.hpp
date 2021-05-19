/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** KeyboardManager
*/

#ifndef KEYBOARDMANAGER_HPP_
#define KEYBOARDMANAGER_HPP_

#include "gameEngine/interfaces/IInputManager.hpp"
#include <unordered_map>
#include <string>

namespace game {

namespace Managers {

// *sera parent des classes de système d'inputKeyboardMenu, KeyboardGameplay, GamePadMenu ...
// *EX de mappage de touches dans le jeu bomberman:
// *  KeyboardGameplay  :    SPACE-->PAUSE
// *  KeyboardMenu  :    SPACE-->VALIDATE_CHOICE
// *  GamepadGameplay  :    XBOX_KEY-->PAUSE

// ! chaque scène contiendra un ou plusieurs InputManager
// * exemple: MainMenu --> [KeyBoardMenu, GamePadMenu]

//dans la partie Game SuperInputManager class ? pour choisir entre plusieurs systèmes
// ! chaque Player contient son tableau d'inputManagers et puet switch en fonction de si il est sur le menu ou en jeu
// * exemple: Player1 --> [GamePadGameplay, GamePadMenu]

template <typename K, typename V>
class InputManager : public gameEngine::Interfaces::IInputManager
{
    public:
        virtual InputManager(<K>keys, <V>interpret_values, std::string id={0});
        ~InputManager();
        bool isKeyPressed(int) final;
        bool isKeyReleased(int) final;
        int getKeyPressed() final;
        bool mapKey(int, int) final;
        bool mapDefaultKeys(int, int);
        bool isConnected();

    private:
        std::unordered_map<K,V> _keymap;
        std::string _id;

};

}
}

#endif /* !KEYBOARDMANAGER_HPP_ */
