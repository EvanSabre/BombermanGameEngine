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
            Player(const std::string &id, const std::string &name, const std::string &text,
            const std::string &model, const std::string &animWalk, const std::string &animIdl);
            ~Player();

            void handleKeyEvent() noexcept;
            void update() override;

        private:
            typedef int my_key;
            std::unordered_map<my_key, playerKeyEvt> _key_event = {
                {KEY_DOWN, &Player::moveLeft},
                {KEY_UP, &Player::moveRight},
                {KEY_RIGHT, &Player::moveForward},
                {KEY_LEFT, &Player::moveBackward}
            };
        };
    } // namespace objects
} // namespace game

#endif /* !PLAYER_HPP_ */
