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
        class IFileManager {
        public:
            virtual ~IFileManager() = default;

            virtual bool checkFileExist(const std::string &path) = 0;
            virtual bool checkFilePermis(const std::string &path) = 0;

            //virtual File loadFile(const std::string &paht) = 0;
            //virtual void closeFiel(File &file) = 0;

            //virtual std::string readFile(const File &file) = 0;
            //virtual std::vector<std::string> readFile(const File &file) = 0;


            //virtual std::string getFilePath(const File &file) = 0;
            //virtual std::string getFileName(const File &file) = 0;
            //virtual std::vector<std::string> getDirectoryFiles(const File &file) = 0;
        };

    } // namespace Interfaces
} // namespace gameEngine

#endif /* !IFILEMANAGER_HPP_ */
