/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BombUp
*/

#include "BombUp.hpp"

using namespace game::objects;

BombUp::BombUp()
    : AEffect(game::EffectType::BOMBPOWER)
{
    _bombPower = 1;
}

BombUp::~BombUp()
{
}
