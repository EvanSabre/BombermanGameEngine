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

class IndieError : public std::exception
{
public:
    IndieError(std::string const &message, std::string const &component = "Unknown");

    const std::string &getComponent() const noexcept;
    const char *what() const noexcept override;

private:
    std::string _message;
    std::string _component;
};

class LoadingError : public IndieError
{
public:
    LoadingError(std::string const &message,
                         std::string const &component = "Unknown") : IndieError(message, component) {}
};

class UserManagmentError : public IndieError
{
public:
    UserManagmentError(std::string const &message,
                         std::string const &component = "UserManager.cpp") : IndieError(message, component) {}
};

#endif /* !ERRORS_HPP_ */
