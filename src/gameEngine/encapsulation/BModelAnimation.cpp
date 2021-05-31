/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BModelAnimation
*/

#include "BModelAnimation.hpp"

using namespace gameEngine;
using namespace encapsulation;

BModelAnimation::BModelAnimation(const std::string &filePath)
{
    _anims = LoadModelAnimations(filePath.c_str(), &_animsCount);   
}

BModelAnimation::~BModelAnimation()
{
    destroyAnim();
}

void BModelAnimation::destroyAnim()
{
    for (int i = 0; i < _animsCount; i++) {
        UnloadModelAnimation(_anims[i]);
    }
    RL_FREE(_anims);
}

int BModelAnimation::getAnimFrameCount() const noexcept
{
    return _animsCount;
}

ModelAnimation BModelAnimation::getModelAnimation() const noexcept
{
    return _anims[0];
}

void BModelAnimation::loadNewAnimation(const std::string &filePath)
{
    destroyAnim();
    _anims = LoadModelAnimations(filePath.c_str(), &_animsCount);
}