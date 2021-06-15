/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** ADropable
*/

#include "ADropable.hpp"

game::objects::ADropable::ADropable(const std::string &modelfilePath,
                           const std::string &texturefilePath,
                           const Vector3T<float> &pos,
                           const gameEngine::encapsulation::BColor &color,
                           const float &scale,
                           const game::Tag &type)
    : game::objects::Tile(modelfilePath, texturefilePath, type, pos)
{
}

game::objects::ADropable::~ADropable()
{
}
