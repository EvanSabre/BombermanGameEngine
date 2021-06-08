/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** AFileManager
*/

#include "AFileManager.hpp"

using namespace gameEngine::managers;

File AFileManager::loadFile(const std::string &path, bool force_creation)
{
    File file(path, force_creation);
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
    return file.getPath();
}

Directory AFileManager::loadDir(const std::string &dirpath, bool force_creation)
{
    Directory directory(dirpath, force_creation);
    return directory;
}

bool AFileManager::writeFile(File &file, const std::string &text, bool rewrite)
{
    try
    {
        file.write(text, rewrite);
        return true;
    }
    catch(const std::exception& e)
    {
        std::cerr << "AFileManager.cpp:66 -> " << e.what() << '\n';
        throw e;
    }
}
