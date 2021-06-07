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

namespace gameEngine
{
    namespace Interfaces
    {
        class IFileManager
        {
            public:
                IFileManager();
                ~IFileManager();
                virtual bool checkFileExist(const std::string &) = 0;
                virtual bool checkFilePermissions(const std::string &) = 0;
                virtual File loadFile(const std::string &) = 0;
                virtual void CloseFile(File &) = 0;
                virtual std::string readFile(const File &) = 0;
                virtual std::vector<std::string> readFile(const File &) = 0;
                virtual std::string getFileName(const File &) = 0;
                virtual std::string getFilePath(const File &) = 0;
                virtual std::vector<std::string> getDirectoryFiles(const File &) = 0;
            protected:
            private:
        };

#endif /* !IFILEMANAGER_HPP_ */
