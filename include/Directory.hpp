/*
** EPITECH PROJECT, 2021
** B-OOP-400-REN-4-1-arcade-arthur.jourdan
** File description:
** ReadDir
*/

#ifndef DIRECTORY_HPP_
#define DIRECTORY_HPP_

#include <sys/stat.h>
#include <string>
#include <dirent.h>
#include <vector>
#include <stdexcept>

#include "File.hpp"


class Directory
{
  public:
    typedef struct file_info_t {
        struct stat stat;
        std::string name;
        std::string path;
    } file_info_t;

    Directory(const std::string &dirpath);
    ~Directory();

    // false -> end of reading
    bool nextEntry();

    // getter
    const std::string getEntryName() const;
    const std::string getEntryPath() const;
    File getEntryAsFile() const noexcept;
    const file_info_t getFileInfo() const noexcept;

    std::vector<file_info_t> readAllDir() noexcept;

  private:
    std::string _dirPath;
    DIR *_directory = nullptr;
    struct dirent *_entry = nullptr;
    struct stat _entryInfo;
    std::vector<file_info_t> _dir_content;
};

#endif /* !READDIR_HPP_ */