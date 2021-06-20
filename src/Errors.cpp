/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Errors
*/

#include "Errors.hpp"

IndieError::IndieError(std::string const &message,
    std::string const &component,
    const std::string &side
    )
{
    this->_message = message;
    this->_component = component;
    _message.append(" [").append(_component).append("]");
    _side = side;
}

const std::string &IndieError::getComponent() const noexcept
{
    return this->_component;
}

const char *IndieError::what() const noexcept
{
    return _message.c_str();
}

const std::string &IndieError::getSide() const noexcept
{
    return _side;
}

gameError::gameError(std::string const &message,
            std::string const &component
            )
    : IndieError(message, component, "GAME")
{
}

ConfigError::ConfigError(std::string const &message)
    : gameError(message, "CONFIG")
{
}


engineError::engineError(std::string const &message,
            std::string const &component
            )
    : IndieError(message, component)
{
}


LoadingError::LoadingError(const std::string &filepath,
                        std::string const &message,
                         std::string const &component
                         )
    : engineError(message + filepath, component)
{
}

