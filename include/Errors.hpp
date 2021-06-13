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
    IndeeError(std::string const &message, std::string const &component = "Unknown");

    const std::string &getComponent() const noexcept;
    const char *what() const noexcept override;

private:
    std::string _message;
    std::string _componnent;
};

class LoadingError : public IndeeError
{
public:
    LoadingError(const std::string &filepath,
                std::string const &message = "Loading Failed : ",
                std::string const &component = "Unknown"
                );
};

#endif /* !ERRORS_HPP_ */
