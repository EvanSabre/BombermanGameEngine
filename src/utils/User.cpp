#include "User.hpp"

game::User::User(const std::string &name,
                    const std::string &pathToSave,
                    int gamesPlayed,
                    int gamesWon,
                    time_t created,
                    std::vector<std::string> trophies,
                    int kills,
                    int beKilled
)
{
    _name = name;
    _pathToSave = pathToSave;
    _gamesPlayed = gamesPlayed;
    _gamesWon = gamesWon;
    _created = created;
    _trophies = trophies;
    _kills = kills;
    _beKilled = beKilled;
    _ratio = kills / beKilled;
}

game::User::~User()
{
    
}