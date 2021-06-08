/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** AFileManager
*/

#include "AFileManager.hpp"

bool AFileManager::checkFileExist(const std::string &name)
{
    struct stat buffer;
    return stat(name.c_str(), &buffer) == 0;
}

File AFileManager::loadFile(const std::string &path)
{
    File file(path);

    return file;
}

std::string AFileManager::readFile(const File &file)
{
    std::string text;

    try
    {
        text = file.read();
        return text;
    }
    catch(const std::exception& e)
    {
        std::cerr << "AFileManager.cpp:34 -> " << e.what() << std::endl;
        throw e;
    }
}

std::string AFileManager::getFileName(const File &file)
{
    return file.getName();
}

std::string AFileManager::getFilePath(const File &file)
{
    file.getPath();
}

// std::vector<File> AFileManager::getDirectoryFiles(const File &) {

// }

bool AFileManager::writeFile(File &file, const std::string &text)
{
    try
    {
        file.write(text);
    }
    catch(const std::exception& e)
    {
        std::cerr << "AFileManager.cpp:66 -> " << e.what() << '\n';
        throw e;
    }
}
