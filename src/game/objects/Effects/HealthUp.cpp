/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** HealthUp
*/

#include "HealthUp.hpp"

using namespace game::objects;

HealthUp::HealthUp()
    : AEffect(game::EffectType::HEALTH)
{
    _health = 1;
}

HealthUp::~HealthUp()
{
}
