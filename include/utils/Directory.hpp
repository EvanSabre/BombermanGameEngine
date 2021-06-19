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
  #include <direct.h>
#else
  #include <dirent.h>
#endif
#include <vector>
#include <stdexcept>
#include <memory>
#include "File.hpp"
#include <filesystem>

class Directory
{
  public:
    Directory(const std::string &dirpath, bool force_creation=true);
    ~Directory();

    std::vector<std::shared_ptr<File>> getAllDirFiles() noexcept;
    std::vector<std::string> getSubDirNames();
    std::shared_ptr<File> &loadFile(const std::string &filename, bool force_creation=false);

  private:
    std::string _dirPath;
    bool _directory = false;
    std::vector<std::shared_ptr<File>> _dir_content;
};

#endif /* !READDIR_HPP_ */
