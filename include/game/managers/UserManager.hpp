/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** UserManager
*/

#ifndef USERMANAGER_HPP_
#define USERMANAGER_HPP_

#include "game/User.hpp"
#include "gameEngine/encapsulation/Keyboard.hpp"
#include "gameEngine/encapsulation/Gamepad.hpp"
#include "gameEngine/managers/AFileManager.hpp"

namespace game
{
    namespace managers
    {
        typedef enum InputType_e
        {
            KEYBOARD,
            GAMEPAD,
        }InputType_e;

        class UserManager : public gameEngine::managers::AFileManager
        {
            public:
                UserManager(const std::string &pathDatabase);
                ~UserManager() = default;
                std::shared_ptr<User> loadUserFromDB(const std::string &name);
                bool findUserInDB(const std::string &name); // ? throw Exception if User already exists
                User &getUser(const std::string &name);
                User &getUser(size_t & id);
                void saveUser(const std::shared_ptr<User> &user);
                bool assignInputToUser(int IdUser, const std::string &name); // ? throw Exception if IIinput not accessible
                void removeInputToUser(const std::string &name);

                std::shared_ptr<gameEngine::interfaces::IInput> createInput(InputType_e type);
                const gameEngine::UserInputs &getUserInputs(void) const noexcept {return _IdInputMap;}

            private:
                //std::string 
                std::vector<std::shared_ptr<File>> _usersFile;
                std::vector<std::shared_ptr<User>> _users;
                std::unordered_map<int, User&> _IdUserMap;
                const gameEngine::UserInputs _IdInputMap =
                {
                    {1, std::make_shared<gameEngine::encapsulation::Keyboard>()},
                    {2, std::make_shared<gameEngine::encapsulation::Gamepad>(0)},
                    {3, std::make_shared<gameEngine::encapsulation::Gamepad>(1)},
                    {4, std::make_shared<gameEngine::encapsulation::Gamepad>(2)},
                };
                int _nb_gamepad = 0;
                int _nb_usersInGame = 0;
                std::string _pathDatabase{0};
                bool _keyboardAttributed = false;
        };
    }

}

#endif /* !USERMANAGER_HPP_ */
