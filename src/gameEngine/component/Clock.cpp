/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** Clock
*/

#include "Clock.hpp"

using namespace gameEngine::component;

Clock::Clock()
{
    this->restart();
}

Clock::~Clock()
{
}

double Clock::getElapsedTime() const
{
    std::chrono::high_resolution_clock::time_point time = std::chrono::high_resolution_clock::now();
    int elapsed = std::chrono::duration_cast<std::chrono::microseconds>(time - _begin).count();
    double seconds = elapsed / 1000000;

    return seconds;
}

double Clock::getElapsedTime(bool milli) const
{
    (void)milli;
    std::chrono::high_resolution_clock::time_point time = std::chrono::high_resolution_clock::now();
    int elapsed = std::chrono::duration_cast<std::chrono::microseconds>(time - _begin).count();
    double milliseconds = elapsed / 1000;

    return milliseconds;
}

void Clock::restart()
{
    _begin = std::chrono::high_resolution_clock::now();
}
