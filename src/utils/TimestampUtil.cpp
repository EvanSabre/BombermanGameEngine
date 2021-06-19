/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** TimestampUtil
*/

#include "TimestampUtil.hpp"

TimestampUtil::~TimestampUtil()
{
}

std::string TimestampUtil::timestampToString(const time_t &timestamp)
{
    std::stringstream ss;
    std::tm *ptm = std::localtime(&timestamp);
    char buffer[32];

    std::strftime(buffer, 32, "%a, %d.%m.%Y %H:%M:%S", ptm);
    return std::string(buffer);
}
