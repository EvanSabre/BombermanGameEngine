/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** TimedObject
*/

#include "TimedObject.hpp"

using namespace game::objects;

TimedObject::TimedObject(double life_time)
    : game::objects::Tile()
{
    this->_lifeTime = life_time;
}

TimedObject::~TimedObject()
{
}

//---------------------

//GETTER

double TimedObject::getLifeTime() const noexcept
{
    return this->_lifeTime;
}

double TimedObject::getRemainedTime() const noexcept
{
    double remain_time = _lifeTime - this->getElapsedTime();

    if (remain_time < 0) {
        return 0;
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

//----------------

//----------------

//PRIVATE FUNCTIONS

void TimedObject::updateLastTimeCheck() noexcept
{
    this->_lastLifeTimeCheckPoint = this->getElapsedTime();
}

void TimedObject::updateLifeTime() noexcept
{
    if (isTimeOver() && (_lastLifeTimeCheckPoint) < _lifeTime) {
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
