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
    class User
    {
        public:
            User(const std::string &name,
                const std::string &pathToSave,
                int gamesPlayed,
                int gamesWon,
                time_t created,
                std::vector<std::string> trophies,
                int kills,
                int beKilled
                );
            ~User();

            void setId(int Id) {_Id = Id;}
            int &getId(void);
            std::string &getName(void) {return _name;}
            std::string &getPathToSave(void) {return _pathToSave;}
            int &getGamesPlayed(void) {return _gamesPlayed;}
            int &getGamesWon(void) {return _gamesWon;}
            time_t &getCreated(void) {return _created;}
            std::vector<std::string> &getTrophies() {return _trophies;}
            int &getKills(void) {return _kills;}
            int &getBeKilled(void) {return _beKilled;}
            int &getRatio(void) { return _ratio;}

        private:
            int _Id = -1;
            std::string _name{0};
            std::string _pathToSave{0};
            int _gamesPlayed = 0;
            int _gamesWon = 0;
            time_t _created;
            std::vector<std::string> _trophies;
            int _kills = 0;
            int _beKilled = 0;
            int _ratio = 0;
    };
};

#endif /* !USER_HPP_ */
