/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** Exception
*/

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <exception>
#include <iostream>

class Exception : public std::exception {
    public:
        Exception(std::string const &message);
        const char *what() const noexcept override;

    private:
        std::string _message;
};

#endif /* !EXCEPTION_HPP_ */
