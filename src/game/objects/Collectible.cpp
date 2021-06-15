/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Collectible
*/

#include "Collectible.hpp"

using namespace game::objects;

Collectible::Collectible(
                const std::string &id,
                const std::string &name,
                collectible_type_e type,
                std::chrono::milliseconds availaible_time,
                int health
                )
    : TimedObject(id, (std::chrono::milliseconds)5000)
{
}

Collectible::~Collectible()
{
}

//-------------------------

//OVERIDE

void Collectible::draw() const noexcept
{
    if (!this->isTimeOver())
        this->TimedObject::draw();
}

void Collectible::onOverTime()
{}

//---------------------

//GETTER

int Collectible::getHealthEfect() const noexcept
{
    return this->_health;
}