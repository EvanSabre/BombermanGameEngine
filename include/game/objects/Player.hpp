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
#include "User.hpp"

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
            const std::string &model, const std::string &animWalk, const std::string &animIdl, std::shared_ptr<game::User> &userLinked);
            ~Player();

            void handleKeyEvent() noexcept;
            void update() override;

        private:
            std::unordered_map<game::Event, playerKeyEvt> _key_event = {
                {MOVE_DOWN, &Player::moveLeft},
                {MOVE_UP, &Player::moveRight},
                {MOVE_RIGHT, &Player::moveForward},
                {MOVE_LEFT, &Player::moveBackward}
            };
            std::shared_ptr<game::User> &_profil;
        };
    } // namespace objects
} // namespace game

#endif /* !PLAYER_HPP_ */
