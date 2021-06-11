/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** FireUp
*/

#include "FireUp.hpp"

using namespace game::objects;

FireUp::FireUp()
    : AEffect(game::EffectType::BOMBPOWER)
{
    _blastPower = 1;
}

FireUp::~FireUp()
{
}
