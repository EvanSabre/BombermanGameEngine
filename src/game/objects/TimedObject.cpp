/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** TimedObject
*/

#include "TimedObject.hpp"

using namespace game::objects;

TimedObject::TimedObject(const std::string &id,
    const std::chrono::milliseconds &life_time)
    : gameEngine::objects::AGameObject(id)
{
    this->_lifeTime = life_time;
}

TimedObject::~TimedObject()
{
}

//---------------------

//GETTER

std::chrono::milliseconds TimedObject::getLifeTime() const noexcept
{
    return this->_lifeTime;
}

std::chrono::milliseconds TimedObject::getElapsedTime() const noexcept
{
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

    std::chrono::duration<double> diff = now - _startLifePoint;
    auto delta_t = std::chrono::duration_cast<std::chrono::milliseconds>(diff);
    return delta_t;
}

std::chrono::milliseconds TimedObject::getRemainedTime() const noexcept
{
    std::chrono::milliseconds remain_time = _lifeTime - this->getElapsedTime();

    if (remain_time.count() <= 0) {
        std::chrono::milliseconds buf(0);
        return buf;
    }
    return remain_time;
}

bool TimedObject::isTimeOver() const noexcept
{
    if (getElapsedTime() > _lifeTime)
        return true;
    return false;
}

//----------------

//SETTER

void TimedObject::setModel(gameEngine::encapsulation::BModel *model) noexcept
{
    this->_model = model;
}


//----------------

void TimedObject::draw() const noexcept
{
    if (_model != nullptr)
        _model->draw();
}



//----------------

//PRIVATE FUNCTIONS

void TimedObject::updateLastTimeCheck() noexcept
{
    this->_lastLifeTimeCheckPoint = std::chrono::system_clock::now();
}

void TimedObject::updateLifeTime() noexcept
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

//-------------------

//AGAMEOBJECT FUNCTIONS

void TimedObject::Update()
{
    this->updateLifeTime();
}
