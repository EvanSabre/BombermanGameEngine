/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** AEffect
*/

#include "AEffect.hpp"

using namespace game::objects;

AEffect::AEffect(game::EffectType_e type)
{
    _type = type;
}

AEffect::~AEffect()
{
}

//-----------------

//GETTER

game::EffectType_e AEffect::getType() const noexcept
{
    return this->_type;
}

int AEffect::getHealth() const noexcept
{
    return this->_health;
}

int AEffect::getNbBomb() const noexcept
{
    return this->_nbBomb;
}

int AEffect::getBlastPower() const noexcept
{
    return this->_blastPower;
}

Vector3T<float> AEffect::getSpeed() const noexcept
{
    return this->_speed;
}
