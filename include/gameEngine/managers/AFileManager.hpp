/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** AFileManager
*/

#ifndef AFILEMANAGER_HPP_
#define AFILEMANAGER_HPP_

#include "IFileManager.hpp"

//Un save manager heritera de cette abastraction en ayant pour attribut une

namespace gameEngine
{
    namespace managers
    {
        class AFileManager
        {
            public:
                AFileManager() = default;
                ~AFileManager() = default;
                File loadFile(const std::string &, bool force_creation=false);
                Directory loadDir(const std::string &, bool force_creation=false);
                std::string readFile(const File &);
                std::string readFile(const std::string &);
                std::string getFileName(const File &);
                std::string getFilePath(const File &);
                std::vector<std::shared_ptr<File>> getDirectoryFiles(Directory &);
                bool writeFile(File &, const std::string &text, bool rewrite=false);
        };
    };
};

#endif /* !AFILEMANAGER_HPP_ */
