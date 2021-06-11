/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** OneUp
*/

#include "OneUp.hpp"

using namespace game::objects;

OneUp::OneUp()
    : AEffect(game::EffectType::LIFE)
{
    _extraLife = 1;
}

OneUp::~OneUp()
{
}
