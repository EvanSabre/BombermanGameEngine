/*
** EPITECH PROJECT, 2021
** B-OOP-400-REN-4-1-arcade-arthur.jourdan
** File description:
** Directory
*/

#include "Directory.hpp"

Directory::Directory(const std::string &dirpath)
{
    this->_dirPath = dirpath;
    this->_directory = opendir(dirpath.c_str());
    if (!this->_directory)
        throw std::invalid_argument(
            std::string("Read Dir: fail to open directory ") + dirpath);
    this->_entry = nullptr;
}

Directory::~Directory()
{
    closedir(this->_directory);
}

bool Directory::nextEntry()
{
    this->_entry = readdir(this->_directory);

    if (!this->_entry)
        return false;


    Directory::file_info_t file;

    std::string entry_path =
        this->_dirPath + "/" + std::string(this->_entry->d_name);
    file.path = entry_path;
    stat(entry_path.c_str(), &file.stat);
    file.name = std::string(this->_entry->d_name);
    this->_dir_content.push_back(file);
    return true;
}

// getter
const std::string Directory::getEntryName() const
{
    return this->_dir_content.back().name;
}

const std::string Directory::getEntryPath() const
{
    return this->_dir_content.back().path;
}

const Directory::file_info_t Directory::getFileInfo() const noexcept
{
    return this->_dir_content.back();
}

std::vector<Directory::file_info_t> Directory::readAllDir() noexcept
{
    while(this->nextEntry());
    return this->_dir_content;
}

File Directory::getEntryAsFile() const noexcept
{
    File file{getEntryPath()};
    return file;
}
