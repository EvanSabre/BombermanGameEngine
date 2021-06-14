/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Errors
*/

#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <string>
#include <exception>
#include <stdexcept>
#include <iostream>


class IndeeError : public std::exception
{
public:
    IndeeError(std::string const &message,
    std::string const &component = "Unknown",
    const std::string &side = "UNKNOWN"
    );

    const std::string &getComponent() const noexcept;
    const std::string &getSide() const noexcept;
    const char *what() const noexcept override;

private:
    std::string _message;
    std::string _componnent;
    std::string _side;
};

class gameError : public IndeeError
{
public:
    gameError(std::string const &message,
            std::string const &component = "Unknown"
            );
};

class engineError : public IndeeError
{
public:
    engineError(std::string const &message,
            std::string const &component = "Unknown"
            );
};


class LoadingError : public engineError
{
public:
    LoadingError(const std::string &filepath,
                std::string const &message = "Loading Failed : ",
                std::string const &component = "Unknown"
                );
};

class NoSceneException : public IndeeError {
    public:
        NoSceneException(std::string const &message = "NoScene Error") : IndeeError(message) {}
};


#endif /* !ERRORS_HPP_ */
