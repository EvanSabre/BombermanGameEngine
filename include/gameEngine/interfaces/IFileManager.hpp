/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** IFileManager
*/

#ifndef IFILEMANAGER_HPP_
#define IFILEMANAGER_HPP_

#include <string>
#include <vector>
#include "Directory.hpp"
#include "File.hpp"

namespace gameEngine
{
    namespace interfaces
    {
        class IFileManager
        {
            public:
                virtual bool checkFileExist(const std::string &) = 0;
                virtual bool checkFilePermissions(const std::string &) = 0;
                virtual File loadFile(const std::string &, bool force_creation=false) = 0;
                virtual std::string readFile(const File &) = 0;
                virtual std::string getFileName(const File &) = 0;
                virtual std::string getFilePath(const File &) = 0;
                virtual bool writeFile(File &file, const std::string &text) = 0;
                virtual Directory openDir(const std::string &path, bool force_creation=false) = 0;
                virtual std::vector<File> getDirectoryFiles(const std::string &dirpath) = 0;
        };
    };
};

#endif /* !IFILEMANAGER_HPP_ */
