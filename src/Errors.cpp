/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Errors
*/

#include "Errors.hpp"

IndieError::IndieError(std::string const &message, std::string const &component)
{
    this->_message = message;
    this->_component = component;
}

const std::string &IndieError::getComponent() const noexcept
{
    return this->_component;
}

const char *IndieError::what() const noexcept
{
    std::string msg(_component + ": " + _message);
    printf("MYERROR %s\n", msg.c_str());
    return msg.c_str();
}