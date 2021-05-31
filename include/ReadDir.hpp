/*
** EPITECH PROJECT, 2021
** B-OOP-400-REN-4-1-arcade-arthur.jourdan
** File description:
** ReadDir
*/

#ifndef READDIR_HPP_
#define READDIR_HPP_

#include <sys/stat.h>
#include <string>
#include <dirent.h>
#include <stdexcept>

class ReadDir {
  public:
    explicit ReadDir(const std::string &dirpath);
    ~ReadDir();

    // false -> end of reading
    bool nextEntry();

    // getter
    const std::string getEntryName() const;
    const std::string getEntryPath() const;

    static bool isSameFile(const std::string &first, const std::string
                                                         &second);

  private:
    std::string _dirPath;
    DIR *_directory = nullptr;
    struct dirent *_entry = nullptr;
    struct stat _entryInfo;
};

#endif /* !READDIR_HPP_ */