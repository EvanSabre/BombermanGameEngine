/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** UserManager
*/

#include "UserManager.hpp"
#include "Errors.hpp"


#define FILE_USER_EXT ".user"

std::vector<std::string> splitString(std::string & s, const char *splitter);

game::managers::UserManager::UserManager(const std::string &pathDatabase)
{
    _pathDatabase = pathDatabase;
    _usersFile = this->getDirectoryFiles(pathDatabase);
}



std::shared_ptr<game::User> importUserFromFile(std::shared_ptr<File> &userFile)
{
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
    std::string content;
    std::vector<std::string> contentArr;

    try {
        content = userFile.get()->read();
        contentArr = splitString(content, "\n");
    }
    catch (const UserManagmentError &e)
    {
        std::cout << e.what() << std::endl;
    }

    for (size_t i = 0; i <; i++)
    {
        /* code */
    }
}


std::shared_ptr<game::User> game::managers::UserManager::loadUserFromDB(const std::string &name)
{
    std::string filename(name);
    filename += FILE_USER_EXT;
    for (auto&file : _usersFile) {
        if (file.get()->getName() == filename)
            return importUserFromFile(file);
    }
}

bool game::managers::UserManager::findUserInDB(const std::string &name) {
    
}

User &game::managers::UserManager::getUser(size_t & id) {
    
}

void game::managers::UserManager::saveUser(const std::shared_ptr<User> &user) {
    
}

bool game::managers::UserManager::assignInputToUser(int IdUser, const std::string &name) {
    
}

void game::managers::UserManager::removeInputToUser(const std::string &name) {
    
}

std::shared_ptr<gameEngine::interfaces::IInput> game::managers::UserManager::createInput(InputType_e type) {
    
}
