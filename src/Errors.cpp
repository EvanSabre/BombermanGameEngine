/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Errors
*/

#include "Errors.hpp"

IndeeError::IndeeError(std::string const &message,
    std::string const &component,
    const std::string &side
    )
{
    this->_message = message;
    this->_componnent = component;
    _message.append(" [").append(_componnent).append("]");
    _side = side;
}

const std::string &IndeeError::getComponent() const noexcept
{
    return this->_componnent;
}

const std::string &IndeeError::getSide() const noexcept
{
    return _side;
}

const char *IndeeError::what() const noexcept
{
    return _message.c_str();
}


gameError::gameError(std::string const &message,
            std::string const &component
            )
    : IndeeError(message, component, "GAME")
{
}

engineError::engineError(std::string const &message,
            std::string const &component
            )
    : IndeeError(message, component)
{
}


LoadingError::LoadingError(const std::string &filepath,
                        std::string const &message,
                         std::string const &component
                         )
    : engineError(message + filepath, component)
{
}

