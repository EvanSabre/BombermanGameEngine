/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** User
*/

#ifndef USER_HPP_
#define USER_HPP_

#include "IInput.hpp"

namespace game
{
    typedef struct User
    {
        int Id = -1;
        std::string name = "";
        std::string pathToSave = "";
        int gamesPlayed = 0;
        int gamesWon = 0;
        time_t created = 0;
        std::vector<std::string> trophies;
        int kills = 0;
        int beKilled = 0;
        int ratio = 0;
    }User;
};
#endif /* !USER_HPP_ */
