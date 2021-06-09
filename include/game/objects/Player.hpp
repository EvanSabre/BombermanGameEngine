/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <string>
#include <unordered_map>
#include "raylib.h"
#include "Character.hpp"
#include "Keyboard.hpp"

#ifndef CALL_MEMBER_FN
    #define CALL_MEMBER_FN(object, ptrToMember) ((object).*(ptrToMember))
#endif


//typedef void (game::nibbler::*eventFct)(void);


namespace game
{
    namespace objects
    {
        class Player;

        typedef void (game::objects::Player::*playerKeyEvt)(size_t tick);

        class Player : public Character
        {
        public:
            Player(const std::string &id, const std::string &name);
            ~Player();

            void handleKeyEvent() noexcept;


        private:
            typedef int my_key;
            std::unordered_map<my_key, playerKeyEvt> _key_event = {
                {KEY_LEFT, &Player::moveLeft},
                {KEY_RIGHT, &Player::moveRight},
                {KEY_UP, &Player::moveForward},
                {KEY_DOWN, &Player::moveBackward}
            };
        };
    } // namespace objects
} // namespace game

#endif /* !PLAYER_HPP_ */
