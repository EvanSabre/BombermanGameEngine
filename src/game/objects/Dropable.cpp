/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Dropable
*/

#include "Dropable.hpp"

using namespace game::objects;

Dropable::Dropable(const std::string &id,
                const std::string &name,
                dropable_type_e type,
                std::chrono::milliseconds availaible_time,
                int bomb)
    : TimedObject(id, (std::chrono::milliseconds)5000)
{
}

Dropable::~Dropable()
{
}

void Dropable::draw() const noexcept
{
    if (!this->isTimeOver())
        this->TimedObject::draw();
}

void Dropable::onOverTime()
{
}

int Dropable::getBombEffect() const noexcept
{
    return this->_bomb;
}