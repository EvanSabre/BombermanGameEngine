/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Errors
*/

#include "Errors.hpp"

IndeeError::IndeeError(std::string const &message, std::string const &component)
{
    this->_message = message;
    this->_componnent = component;
    _message.append(" [").append(_componnent).append("]");
}

const std::string &IndeeError::getComponent() const noexcept
{
    return this->_componnent;
}

const char *IndeeError::what() const noexcept
{
    return _message.c_str();
}

LoadingError::LoadingError(const std::string &filepath,
                        std::string const &message,
                         std::string const &component
                         )
                         : IndeeError(message + filepath, component)
{
}

