/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** Exception
*/

#include "gameEngine/exceptions/Exception.hpp"

Exception::Exception(std::string const &message) : _message(message)
{
}

const char *Exception::what() const noexcept
{
    return this->_message.c_str();
}
