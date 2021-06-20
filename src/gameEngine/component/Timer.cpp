/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** Timer
*/

#include "Timer.hpp"

using namespace gameEngine::component;

Timer::Timer(const double &duration) : _format("")
{
    _duration = duration;
}

Timer::~Timer()
{
    if (!_isDone) {
        _isDone = true;
        _pause = false;
        wait();
    }
}

void Timer::timerExecute()
{
    char cFormat[100];
    int min;
    int sec;
    std::mutex mtx;

    _clock.restart();
    while (_duration >= 0 && _isDone == false) {
        while(_pause);
        if (_clock.getElapsedTime() >= 1) {
            _clock.restart();
            mtx.lock();
            min = _duration / 60;
            if ((int)_duration % 60 == 0) {
                sec = 0;
                snprintf(cFormat, 100, "%i:%i0", min, sec);
            } else {
                sec = _duration >= 60 ? _duration - 60 : _duration;
                snprintf(cFormat, 100, "%i:%i", min, sec);
            }
            _format = cFormat;
            _currentTime.setStr(_format);
            _duration--;
            std::memset(cFormat, 0, sizeof(cFormat));
            mtx.unlock();
        }
    }
}

void Timer::update()
{
}

void Timer::setPause(bool pause)
{
    _pause = pause;
}

double Timer::getDuration() const noexcept
{
    return _duration;
}

void Timer::wait()
{
    _timerThread->join();
}

void Timer::draw()
{
    _currentTime.draw();
}

std::string Timer::getContent() const noexcept
{
    return _currentTime.getStr();
}

void Timer::startThread()
{
    _timerThread = std::make_unique<std::thread>(&Timer::timerExecute, this);
}

gameEngine::encapsulation::BText &Timer::getCurrentTime()
{
    return _currentTime;
}

void Timer::setDuration(const double &duration)
{
    _duration = duration;
}

void Timer::setIsDone(bool isDone)
{
    _isDone = isDone;
}

void Timer::setTimePos(const Vector<float> &pos)
{
    _currentTime.setTextPosition(pos);
}

void Timer::addToDuration(const double &add)
{
    _duration += add;
}
