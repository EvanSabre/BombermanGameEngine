/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BModelAnimation
*/

#include "BModelAnimation.hpp"
#include <iostream>

using namespace gameEngine;
using namespace encapsulation;

BModelAnimation::BModelAnimation(const std::string &filePath)
    : _loaded(false)
{
    _filePath = filePath;
    if (filePath != "") {
        _loaded = true;
        _anims = LoadModelAnimations(filePath.c_str(), &_animsCount);
    }
}

BModelAnimation::BModelAnimation(const BModelAnimation &ref)
    : _loaded(false)
{
    if (ref.getFilePath() != "") {
        _loaded = true;
        _anims = LoadModelAnimations(ref.getFilePath().c_str(), &_animsCount);
    }
}

BModelAnimation::~BModelAnimation()
{
    if (_loaded)
        destroyAnim();
}

void BModelAnimation::destroyAnim()
{
    for (int i = 0; i < _animsCount; i++) {
        UnloadModelAnimation(_anims[i]);
    }
    RL_FREE(_anims);
}

std::string BModelAnimation::getFilePath() const noexcept
{
    return _filePath;
}

int BModelAnimation::getAnimFrameCount() const noexcept
{
    if (!_loaded)
        return 0;
    return _anims[0].frameCount;
}

ModelAnimation *BModelAnimation::getModelAnimation() const noexcept
{
    return _anims;
}

void BModelAnimation::loadNewAnimation(const std::string &filePath)
{
    if (_loaded) {
        destroyAnim();
        _loaded = false;
    }
    if (filePath != "") {
        _loaded = true;
        _anims = LoadModelAnimations(filePath.c_str(), &_animsCount);
    }
}

bool BModelAnimation::isLoad()
{
    if (_anims == nullptr)
        return false;
    return true;
}
