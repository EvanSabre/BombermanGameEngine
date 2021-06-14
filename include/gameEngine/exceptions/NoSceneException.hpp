/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** NoSceneException
*/

#ifndef NOSCENEEXCEPTION_HPP_
#define NOSCENEEXCEPTION_HPP_

#include "Exception.hpp"

class NoSceneException : public Exception{
    public:
        NoSceneException(std::string const &message = "NoScene Error") : Exception(message) {}

    protected:
    private:
};

#endif /* !NOSCENEEXCEPTION_HPP_ */
