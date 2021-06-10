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
#ifdef _WIN64
  #include "Bdirent.h"
#else
  #include <dirent.h>
#endif
#include <vector>
#include <stdexcept>

#include "File.hpp"


class Directory
{
  public:
    Directory(const std::string &dirpath, bool force_creation=false);
    ~Directory();

    // false -> end of reading
    bool nextEntry();

    // getter
    const std::string getEntryName() const;
    const std::string getEntryPath() const;
    std::vector<File> getAllDirFiles() noexcept;

    File &loadFile(const std::string &filename, bool force_creation=false);
    File getEntryAsFile() const noexcept;

  private:
    std::string _dirPath;
    DIR *_directory = nullptr;
    struct dirent *_entry = nullptr;
    struct stat _entryInfo;
    std::vector<File> _dir_content;
};

#endif /* !READDIR_HPP_ */
