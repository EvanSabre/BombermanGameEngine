#include "User.hpp"

gameEngine::utils::User::User(const std::string &name,
                    const std::string &pathToSave,
                    int gamesPlayed,
                    int gamesWon,
                    time_t created,
                    std::vector<std::string> trophies,
                    int kills,
                    int beKilled,
                    const std::shared_ptr<gameEngine::interfaces::IInput>& input
) : _input(input)
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

gameEngine::utils::User::~User()
{
    
}

gameEngine::UserInput gameEngine::utils::User::getInputInfo(void)
{
    gameEngine::UserInput userInput = std::make_pair(_Id, _input);
    return userInput;
}
