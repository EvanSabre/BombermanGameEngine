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
#include <vector>
#include <stdexcept>

class ReadDir {
  public:
    typedef struct file_info_t {
        struct stat stat;
        std::string name;
        std::string path;
    } file_info_t;



    explicit ReadDir(const std::string &dirpath);
    ~ReadDir();

    // false -> end of reading
    bool nextEntry();

    // getter
    const std::string getEntryName() const;
    const std::string getEntryPath() const;
    const file_info_t getFileInfo() const noexcept;

    std::vector<file_info_t> readAllDir() noexcept;


    static bool isSameFile(const std::string &first, const std::string
                                                         &second);


  private:
    std::string _dirPath;
    DIR *_directory = nullptr;
    struct dirent *_entry = nullptr;
    struct stat _entryInfo;
    std::vector<file_info_t> _dir_content;
};

#endif /* !READDIR_HPP_ */