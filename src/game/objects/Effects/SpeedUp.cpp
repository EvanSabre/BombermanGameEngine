/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** SpeedUp
*/

#include "SpeedUp.hpp"

using namespace game::objects;

SpeedUp::SpeedUp()
    : AEffect("SpeedUp")
{
    _speed = {0.2, 0, 0.2};
}

SpeedUp::~SpeedUp()
{
}
