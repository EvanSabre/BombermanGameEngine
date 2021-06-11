/*
** EPITECH PROJECT, 2021
** B-OOP-400-REN-4-1-arcade-arthur.jourdan
** File description:
** Directory
*/

#include "Directory.hpp"
#include <string.h>

#ifdef __WIN32__
    #define SEP "\\"
#else
    #define SEP "/"
#endif

Directory::Directory(const std::string &dirpath, bool force_creation)
{
    this->_dirPath = dirpath;
    this->_directory = opendir(dirpath.c_str());
    if (!this->_directory && !force_creation)
        throw std::invalid_argument(
            std::string("Read Dir: fail to open directory ") + dirpath);
    else if (!this->_directory && !force_creation)
    {

    }
    this->_entry = nullptr;
}

Directory::~Directory()
{
    closedir(this->_directory);
}

bool Directory::nextEntry()
{
    this->_entry = readdir(this->_directory);

    if (!this->_entry->d_type)
        return false;

    const std::string path(this->_dirPath + "/" + std::string(this->_entry->d_name));
    this->_dir_content.push_back(std::make_shared<File>(path));
    return true;
}

const std::string Directory::getEntryName() const
{
    return this->_dir_content.back()->getName();
}

const std::string Directory::getEntryPath() const
{
    return this->_dir_content.back()->getPath();
}

std::shared_ptr<File> &Directory::loadFile(const std::string &filename, bool force_creation)
{
    for (auto &i : this->_dir_content) {
        if (filename == i->getName())
            return i;
    }
    if (force_creation) {
        _dir_content.push_back(std::make_shared<File>(this->_dirPath + SEP + filename, force_creation));
        return _dir_content.back();
    }
    throw std::runtime_error("File not found and doesn't want to be created");
}

std::vector<std::shared_ptr<File>> Directory::getAllDirFiles() noexcept
{
    while(this->nextEntry());
    return this->_dir_content;
}

std::shared_ptr<File> Directory::getEntryAsFile() const noexcept
{
    return std::make_shared<File>(getEntryPath(), false);
}
