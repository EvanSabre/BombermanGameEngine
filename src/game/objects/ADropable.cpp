/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** ADropable
*/

#include "ADropable.hpp"

ADropable::ADropable(const std::string &modelfilePath,
                           const std::string &texturefilePath,
                           const Vector3T<float> &pos,
                           const BColor &color,
                           const float &scale,
                           const TileType &type)
    : game::objects::Tile(modelfilePath, texturefilePath, pos, color, scale, type)
{
}

ADropable::~ADropable()
{
}
