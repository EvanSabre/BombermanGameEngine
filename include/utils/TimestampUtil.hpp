/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** TimestampUtil
*/

#ifndef TIMESTAMPUTIL_HPP_
#define TIMESTAMPUTIL_HPP_

#include <time.h>
#include <string>
#include <sstream>
#include <ctime>


class TimestampUtil {
    public:
        ~TimestampUtil();

        static std::string timestampToString(const time_t &timestamp);
    protected:
    private:
};

#endif /* !TIMESTAMPUTIL_HPP_ */
