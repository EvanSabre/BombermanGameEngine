/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** AEffect
*/

#include "AEffect.hpp"

using namespace game::objects;

AEffect::AEffect(const std::string &type)
{
    _type = type;
}

AEffect::~AEffect()
{
}

//-----------------

//GETTER

int AEffect::getLife() const noexcept
{
    return this->_extraLife;
}


std::string AEffect::getType() const noexcept
{
    return this->_type;
}

int AEffect::getMaxLife() const noexcept
{
    return this->_maxLife;
}

int AEffect::getNbBomb() const noexcept
{
    return this->_nbBomb;
}

int AEffect::getBlastPower() const noexcept
{
    return this->_blastPower;
}

int AEffect::getBombPass() const noexcept
{
    return this->_bombPass;
}

Vector3T<float> AEffect::getSpeed() const noexcept
{
    return this->_speed;
}
