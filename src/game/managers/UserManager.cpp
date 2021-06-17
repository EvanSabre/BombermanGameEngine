/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** UserManager
*/

#include "UserManager.hpp"
#include "Errors.hpp"
#include "Path.hpp"


#define FILE_USER_EXT ".user"

using namespace game::managers;

std::vector<std::string> splitString(std::string s, const char *splitter)
{
   size_t pos = 0;
   std::string delimiter (splitter);
   std::string token;
   std::vector<std::string> ret;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        ret.push_back(token);
    s.erase(0, pos + delimiter.length());
    }
    ret.push_back(s);
    return ret;
}

UserManager::UserManager(const std::string &pathDatabase) : _database(this->loadDir(pathDatabase, true))
{
    _pathDatabase = pathDatabase;
    _usersFile = _database.getAllDirFiles();

    if (_usersFile.empty())
        return;
    for (auto &file : _usersFile)
    {
        std::cout << "File recover user: " << file->getName() << std::endl;
        _users.push_back(importUserFromFile(file));
    }
    for (auto &user : _users)
        std::cout << "Database recover user: " << user->name << std::endl;
}

UserManager::~UserManager()
{
    for (auto &user : _users)
        this->saveUser(user);
}

void UserManager::interpretLine(std::vector<std::string> line, std::shared_ptr<game::User>& user)
{
    if (line.size() != 2)
        throw UserManagmentError("Error Line in UserFile");
    else if (line[0] == "CREATED")
        user->created = std::atoi(line[1].c_str());
    else if (line[0] == "GAMES_PLAYED")
        user->gamesPlayed = std::atoi(line[1].c_str());
    else if (line[0] == "GAMES_WON")
        user->gamesWon = std::atoi(line[1].c_str());
    else if (line[0] == "KILLS")
        user->kills = std::atoi(line[1].c_str());
    else if (line[0] == "GAMES")
        user->trophies = splitString(line[1].erase(line[1].size() - 1), ",");
    else if (line[0] == "BE_KILLED")
        user->beKilled = std::atoi(line[1].c_str());
    else
        throw UserManagmentError("Undetected attribut");
}

std::shared_ptr<game::User> UserManager::importUserFromFile(std::shared_ptr<File> &userFile)
{
    std::shared_ptr<game::User> user = std::make_shared<game::User>();

    user->pathToSave = userFile->getPath();
    user->name = splitString(userFile->getName(), ".user")[0];

    try {
        for (auto &line : userFile->readLines())
            this->interpretLine(splitString(line, "="), user);
    }
    catch (const UserManagmentError &e)
    {
        std::cout << e.what() << std::endl;
        throw e;
    }
    return user;
}

std::shared_ptr<game::User> UserManager::loadUserFromDB(const std::string &name)
{
    std::string filename(name + FILE_USER_EXT);

    for (auto&file : _usersFile) {
        if (file->getName() == filename)
            return importUserFromFile(file);
    }
    throw UserManagmentError("loadUserFromDB : " + name);
}

bool UserManager::findUser(const std::string &name) const noexcept
{
    for (auto&user : _users) {
        if (user->name == name)
            return true;
    }
    return false;
}

std::shared_ptr<game::User> &UserManager::getUser(const std::string& name)
{
    for (auto&user : _users) {
        std::cout << user << std::endl;
        if (user->name == name)
            return user;
    }
    throw UserManagmentError("getUser(Not found) : " + name);
}

std::shared_ptr<game::User> &UserManager::getUser(int & id)
{
    for (auto&user : _users) {
        if (user->Id == id)
            return user;
    }
    throw UserManagmentError("getUser(Not found) : " + std::to_string(id));
}

std::vector<std::shared_ptr<game::User>> &UserManager::getUsers()
{
    return _users;
}

std::shared_ptr<game::User> &UserManager::createUser(const std::string &name)
{
    std::string pathUser = Path::getOSPath(this->_pathDatabase + name + FILE_USER_EXT);

    if (this->findUser(name))
        throw UserManagmentError("createUser(Already Exist) : " + name);

    _usersFile.push_back(std::make_shared<File>(this->loadFile(pathUser, true)));
    _users.push_back(importUserFromFile(_usersFile.back()));
    _users.back()->created = time(NULL);
    _users.back()->pathToSave = pathUser;
    _users.back()->name = name;
    this->saveUser(_users.back());
    return _users.back();
}

void UserManager::saveUser(const std::shared_ptr<User> &user)
{
    std::string text = "GAMES_PLAYED=" + std::to_string(user->gamesPlayed) +
        "\nGAMES_WON=" + std::to_string(user->gamesWon) + "\nCREATED=" + std::to_string(user->created) +
        "\nKILLS=" + std::to_string(user->kills) + "\nBE_KILLED=" + std::to_string(user->beKilled);

    for (auto&file : _usersFile) {
        if (file->getPath() == user->pathToSave)
            return file->write(text, true);
    }
    throw UserManagmentError("saveUser(unable to find userFile): " + user->name);
}

bool UserManager::assignInputToUser(int IdUser, const std::string &name) noexcept
{
    try
    {
        getUser(name)->Id = IdUser;
        return true;
    }
    catch (const UserManagmentError &e)
    {
        std::cerr << e.what() << std::endl;
        return false;
    }
}

void UserManager::removeInputToUser(const std::string &name) noexcept
{
    try
    {
        getUser(name)->Id = -1;
    }
    catch (const UserManagmentError &e)
    {
        std::cerr << e.what() << std::endl;
        return;
    }
}

//TODO : mapKey
//TODO: make une unordredmap GLOBAL EVENT
