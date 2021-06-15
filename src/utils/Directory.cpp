/*
** EPITECH PROJECT, 2021
** B-OOP-400-REN-4-1-arcade-arthur.jourdan
** File description:
** Directory
*/

#include "Directory.hpp"
#include "Path.hpp"
#include <string.h>

Directory::Directory(const std::string &dirpath, bool force_creation)
{
    this->_dirPath = dirpath;
    this->_directory = opendir(dirpath.c_str());
    if (!this->_directory && !force_creation)
        throw std::invalid_argument(
            std::string("Read Dir: fail to open directory ") + dirpath);
    else if (!this->_directory && force_creation)
    {
        mkdir(dirpath.c_str());
    }
}

Directory::~Directory()
{
}

bool Directory::nextEntry()
{
    std::string path;

    if (!this->_directory)
        return false;
    this->_entry = readdir(this->_directory);
    if (!this->_entry)
        return false;
    if (this->_entry->d_type != 8)
        return true;
    path = this->_dirPath + std::string(this->_entry->d_name);
    this->_dir_content.push_back(std::make_shared<File>(path));
    return true;
}

std::shared_ptr<File> &Directory::loadFile(const std::string &filename, bool force_creation)
{
    for (auto &i : this->_dir_content) {
        if (filename == i->getName())
            return i;
    }
    if (force_creation) {
        _dir_content.push_back(std::make_shared<File>(Path::getOSPath(this->_dirPath + "./" + filename), force_creation));
        return _dir_content.back();
    }
    throw std::runtime_error("File not found and doesn't want to be created");
}

std::vector<std::shared_ptr<File>> Directory::getAllDirFiles() noexcept
{
    this->_directory = opendir(_dirPath.c_str());
    while(this->nextEntry());
    closedir(this->_directory);
    return this->_dir_content;
}
