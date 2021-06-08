/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** AFileManager
*/

#ifndef AFILEMANAGER_HPP_
#define AFILEMANAGER_HPP_

#include "IFileManager.hpp"

class AFileManager : public gameEngine::Interfaces::IFileManager
{
    public:
        AFileManager();
        ~AFileManager();
        virtual bool checkFileExist(const std::string &) override;
        virtual bool checkFilePermissions(const std::string &) override;
        virtual File loadFile(const std::string &) override;
        virtual void closeFile(File &) override;
        virtual std::string readFile(const File &) override;
        virtual std::string getFileName(const File &) override;
        virtual std::string getFilePath(const File &) override;
        virtual std::vector<std::string> getDirectoryFiles(const File &) override;
        virtual bool writeFile(File &, const std::string &text);

    protected:
    private:
};

#endif /* !AFILEMANAGER_HPP_ */
