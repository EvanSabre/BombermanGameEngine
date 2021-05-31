/*
** EPITECH PROJECT, 2021
** B-OOP-400-REN-4-1-arcade-arthur.jourdan
** File description:
** ReadDir
*/

#include "ReadDir.hpp"

ReadDir::ReadDir(const std::string &dirpath)
{
    this->_dirPath = dirpath;
    this->_directory = opendir(dirpath.c_str());
    if (!this->_directory)
        throw std::invalid_argument(
            std::string("Read Dir: fail to open directory ") + dirpath);
    this->_entry = nullptr;
}

ReadDir::~ReadDir()
{
    closedir(this->_directory);
}

bool ReadDir::nextEntry()
{
    this->_entry = readdir(this->_directory);

    if (!this->_entry)
        return false;
    std::string entry_path =
        this->_dirPath + "/" + std::string(this->_entry->d_name);
    stat(entry_path.c_str(), &this->_entryInfo);
    return true;
}

// getter
const std::string ReadDir::getEntryName() const
{
    return std::string(this->_entry->d_name);
}

const std::string ReadDir::getEntryPath() const
{
    std::string path =
        this->_dirPath + "/" + std::string(this->_entry->d_name);
    return path;
}

#include <iostream>
#include <istream>
#include <fstream>

bool ReadDir::isSameFile(const std::string &first, const std::string &second)
{
    std::ifstream my_first(first);
    std::ifstream my_second(second);

    std::istreambuf_iterator<char> my_firstIt(my_first);
    std::istreambuf_iterator<char> my_secondIt(my_second);
    std::istreambuf_iterator<char> end;

    while (my_firstIt != end && my_secondIt != end) {
        if (*my_firstIt != *my_secondIt) {
            return false;
        }
        ++my_firstIt;
        ++my_secondIt;
    }
    return (my_firstIt == end && my_secondIt == end);
}