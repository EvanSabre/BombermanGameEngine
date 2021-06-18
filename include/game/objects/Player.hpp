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

//typedef void (game::nibbler::*eventFct)(void);

namespace game
{
    namespace objects
    {
        class Player;

        class Player : public Character
        {
        public:
            Player(const std::string &id, const std::string &name, const std::string &text,
            const std::string &model, const std::string &animWalk, const std::string &animIdl, std::shared_ptr<game::User> &userLinked);
            ~Player();

            void update() override;

        private:
            std::shared_ptr<game::User> &_profil;
        };
    } // namespace objects
} // namespace game

#endif /* !PLAYER_HPP_ */
