/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** User
*/

#ifndef USER_HPP_
#define USER_HPP_

#include "IInput.hpp"

namespace gameEngine
{
    namespace utils
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
                    int beKilled,
                    const std::shared_ptr<gameEngine::interfaces::IInput>& input
                    );
                ~User();

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

                UserInput getInputInfo(void);

            private:
                int _Id;
                std::string _name{0};
                std::string _pathToSave{0};
                int _gamesPlayed = 0;
                int _gamesWon = 0;
                time_t _created;
                std::vector<std::string> _trophies;
                int _kills = 0;
                int _beKilled = 0;
                int _ratio = 0;
                const std::shared_ptr<gameEngine::interfaces::IInput> &_input;
        };
    }
}

#endif /* !USER_HPP_ */
