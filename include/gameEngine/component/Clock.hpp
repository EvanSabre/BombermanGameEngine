/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include <chrono>

class Clock {
    public:
        Clock();
        ~Clock();

        double getElapsedTime() const;
        void restart();
    protected:
        std::chrono::high_resolution_clock::time_point _begin;
    private:
};

#endif /* !CLOCK_HPP_ */
