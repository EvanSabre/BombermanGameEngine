/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** ACollectible
*/

#include "ACollectible.hpp"

game::objects::ACollectible::ACollectible(const std::string &modelfilePath,
                           const std::string &texturefilePath,
                           const Vector3T<float> &pos,
                           const gameEngine::encapsulation::BColor &color,
                           const float &scale,
                           const game::Tag &type,
                           const Vector3T<float> &rotation
                           )
    : game::objects::Tile(modelfilePath, texturefilePath, type, pos, rotation, Vector3T<float>(scale, scale, scale), color)
{
}

game::objects::ACollectible::~ACollectible()
{
}
