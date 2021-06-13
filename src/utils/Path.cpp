/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Path
*/

#include "Path.hpp"

static void replaceAllOcur(std::string &str, const std::string &to_replace,
    const std::string &to_assign)
{
    size_t sep_idx = str.find(to_replace, 0);

    while(sep_idx  != std::string::npos) {
        str.replace(sep_idx, to_replace.length(), to_assign);
        sep_idx += to_assign.length();
        sep_idx = str.find(to_replace, sep_idx);
    }
}

std::string Path::getOSPath(const std::string &path) noexcept
{
    std::string new_path{path};
    std::string linux_sep = LINUX_PATH_SEPARATOR;
    std::string windows_sep = WINDOWS_PATH_SEPARATOR;
    std::string os_sep = PATH_SEPARATOR;

    replaceAllOcur(new_path, linux_sep, os_sep);
    replaceAllOcur(new_path, windows_sep, os_sep);
    return new_path;
}
