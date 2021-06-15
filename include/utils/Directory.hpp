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
#include <memory>
#include "File.hpp"


class Directory
{
  public:
    Directory(const std::string &dirpath, bool force_creation=true);
    ~Directory();

    std::vector<std::shared_ptr<File>> getAllDirFiles() noexcept;
    std::shared_ptr<File> &loadFile(const std::string &filename, bool force_creation=false);

  private:
    bool nextEntry();
    std::string _dirPath;
    DIR *_directory = nullptr;
    struct dirent *_entry = nullptr;
    struct stat _entryInfo;
    std::vector<std::shared_ptr<File>> _dir_content;
};

#endif /* !READDIR_HPP_ */
