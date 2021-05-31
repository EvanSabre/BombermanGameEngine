/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Animation
*/

#include "Animation.hpp"

using namespace gameEngine;

Animation::Animation(const encapsulation::BModel &model, const encapsulation::BModelAnimation &anim) :
_model(model), _anim(anim), _frameCounter(0)
{
}

Animation::~Animation()
{
}

void Animation::updateModelAnimation()
{
    _frameCounter++;
    UpdateModelAnimation(_model.getObj(), _anim.getModelAnimation(), _frameCounter);
    if (_frameCounter >= _anim.getAnimFrameCount())
        _frameCounter = 0;
}
