/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Animation
*/

#include "gameEngine/Animation.hpp"

using namespace gameEngine;

Animation::Animation(const encapsulation::BModel &model, const encapsulation::BModelAnimation &anim) :
_model(model), _anim(anim), _frameCounter(0)
{
}

Animation::Animation(const std::string &modelPath, const std::string &animPath, const std::string &texturePath = "") :
_model(modelPath), _anim(animPath), _texture(texturePath)
{
    if (texturePath != "")
        _model.setTexture(0, MAP_DIFFUSE, _texture);
}

Animation::~Animation()
{
}

void Animation::updateModelAnimation()
{
    if (_model.isLoad() && _anim.isLoad()) {
        _frameCounter++;
        UpdateModelAnimation(_model.getObj(), _anim.getModelAnimation()[0], _frameCounter);
    }
    if (_frameCounter >= _anim.getAnimFrameCount()) {
        _frameCounter = 0;
    }
}

void Animation::refresh()
{
    _model.draw();
}