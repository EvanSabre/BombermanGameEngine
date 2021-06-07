/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Character
*/

#include "Character.hpp"

using namespace game;

objects::Character::Character(
                        const std::string &id,
                        const std::string &name,
                        const Vector3T<float> &pos
                        ) : gameEngine::objects::Moveable(id)
{
    this->_name = name;
    this->setPostion(pos);
}

objects::Character::~Character()
{
}

//getter

std::string objects::Character::getName() const noexcept
{
    return this->_name;
}
