/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** TimedObject
*/

#include "TimedObject.hpp"

using namespace game;

objects::TimedObject::TimedObject(const std::string &id,
    const std::chrono::microseconds &life_time)
    : gameEngine::objects::AGameObject(id)
{
    this->_lifeTime = life_time;
}

objects::TimedObject::~TimedObject()
{
}

//---------------------

//GETTER


std::chrono::microseconds objects::TimedObject::getLifeTime() const noexcept
{
    return this->_lifeTime;
}

std::chrono::milliseconds objects::TimedObject::getElapsedTime() const noexcept
{
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

    std::chrono::duration<double> diff = now - _startLifePoint;
    auto delta_t = std::chrono::duration_cast<std::chrono::milliseconds>(diff);
    return delta_t;
}

std::chrono::milliseconds objects::TimedObject::getRemainedTime() const noexcept
{
    std::chrono::milliseconds remain_time = _lifeTime - this->getElapsedTime();

    if (remain_time.count() <= 0) {
        std::chrono::milliseconds buf(0);
        return buf;
    }
    return remain_time;
}

bool objects::TimedObject::isTimeOver() const noexcept
{
    if (getElapsedTime() > _lifeTime)
        return true;
    return false;
}

//----------------

//SETTER

void objects::TimedObject::setModel(gameEngine::encapsulation::BModel *model) noexcept
{
    this->_model = model;
}


//----------------

void objects::TimedObject::draw() const noexcept
{
    if (_model != nullptr)
        _model->draw();
}



//----------------

//PRIVATE FUNCTIONS

void objects::TimedObject::updateLastTimeCheck() noexcept
{
    this->_lastLifeTimeCheckPoint = std::chrono::system_clock::now();
}

void objects::TimedObject::updateLifeTime() noexcept
{
    std::chrono::duration<double> diff = _lastLifeTimeCheckPoint - _startLifePoint;
    auto delta_t = std::chrono::duration_cast<std::chrono::milliseconds>(diff);
    if (this->isTimeOver() &&
         delta_t <= _lifeTime
    ) {
        this->onOverTime();
    }
    this->updateLastTimeCheck();
}

