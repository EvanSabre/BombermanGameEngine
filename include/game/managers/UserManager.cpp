#include "UserManager.hpp"

std::vector<std::string> splitString(std::string & s, const char *splitter);

game::managers::UserManager::UserManager(const std::string &pathDatabase)
{
    _pathDatabase = pathDatabase;
    _usersFile = this->getDirectoryFiles(pathDatabase);
}


#define FILE_USER_EXT ".user"

std::shared_ptr<game::User> importUserFromFile(File &userFile)
{

}


std::shared_ptr<game::User> game::managers::UserManager::loadUserFromDB(const std::string &name)
{
    std::string filename(name);
    filename += FILE_USER_EXT;
    for (auto&file : _usersFile)
    {
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
