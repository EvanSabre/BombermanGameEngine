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


    ReadDir::file_info_t file;

    std::string entry_path =
        this->_dirPath + "/" + std::string(this->_entry->d_name);
    file.path = entry_path;
    stat(entry_path.c_str(), &file.stat);
    file.name = std::string(this->_entry->d_name);
    this->_dir_content.push_back(file);
    return true;
}

// getter
const std::string ReadDir::getEntryName() const
{
    return this->_dir_content.back().name;
}

const std::string ReadDir::getEntryPath() const
{
    return this->_dir_content.back().path;
}

const ReadDir::file_info_t ReadDir::getFileInfo() const noexcept
{
    return this->_dir_content.back();
}

std::vector<ReadDir::file_info_t> ReadDir::readAllDir() noexcept
{
    while(this->nextEntry());
    return this->_dir_content;
}

//---------------------------

//Satic Functions

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