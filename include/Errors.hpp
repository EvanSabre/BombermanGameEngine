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


class IndieError : public std::exception
{
public:
    IndieError(std::string const &message,
    std::string const &component = "Unknown",
    const std::string &side = "UNKNOWN"
    );

    const std::string &getComponent() const noexcept;
    const std::string &getSide() const noexcept;
    const char *what() const noexcept override;

private:
    std::string _message;
    std::string _component;
    std::string _side;
};

class UserManagmentError : public IndieError
{
public:
    UserManagmentError(std::string const &message = "UserManagmentError",
                         std::string const &component = "UserManager.cpp") : IndieError(message, component) {}
};

class gameError : public IndieError
{
public:
    gameError(std::string const &message = "GameError",
            std::string const &component = "Unknown"
            );
};

class ConfigError : public gameError
{
public:
    ConfigError(std::string const &message = "ConfigError");
};


class engineError : public IndieError
{
public:
    engineError(std::string const &message = "EngineError",
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


class NoSceneException : public IndieError {
    public:
        NoSceneException(std::string const &message = "NoScene Error") : IndieError(message) {}
};


#endif /* !ERRORS_HPP_ */
