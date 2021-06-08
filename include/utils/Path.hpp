/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Path
*/

#ifndef PATH_HPP_
#define PATH_HPP_

#include <string>
#include <algorithm>

#define LINUX_PATH_SEPARATOR "/"
#define WINDOWS_PATH_SEPARATOR "\\"

#ifdef _WIN32
    #define PATH_SEPARATOR WINDOWS_PATH_SEPARATOR
#else
    #define PATH_SEPARATOR LINUX_PATH_SEPARATOR
#endif


class Path {
    public:
        static std::string getOSPath(const std::string &path) noexcept;

};

#endif /* !PATH_HPP_ */
