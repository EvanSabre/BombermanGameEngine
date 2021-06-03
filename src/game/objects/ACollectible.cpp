/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** ACollectible
*/

#include "ACollectible.hpp"

ACollectible::ACollectible(const std::string &modelfilePath,
                           const std::string &texturefilePath,
                           const Vector3T<float> &pos,
                           const BColor &color,
                           const float &scale,
                           const TileType &type)
    : game::objects::Tile(modelfilePath, texturefilePath, pos, color, scale, type)
{
}

ACollectible::~ACollectible()
{
}
