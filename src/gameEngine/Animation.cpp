/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Animation
*/

#include "gameEngine/Animation.hpp"

using namespace gameEngine;

Animation::Animation(const encapsulation::BModel &model,
                     const encapsulation::BModelAnimation &animWalk,
                     const encapsulation::BModelAnimation &animIdle)
    : _model(model), _animWalk(animWalk), _animIdle(animIdle), _anim(animWalk), _frameCounter(0)
{
    _state = ANIMIDLE;
}

Animation::Animation(const std::string &modelPath,
                     const std::string &animWalkPath,
                     const std::string &animIdlePath,
                     const std::string &texturePath = "")
    : _model(modelPath), _animWalk(animWalkPath), _animIdle(animIdlePath), _anim(animWalkPath), _texture(texturePath)
{
    _state = ANIMIDLE;
    if (texturePath != "")
        _model.setTexture(0, MAP_DIFFUSE, _texture);
}

Animation::~Animation()
{
}

void Animation::updateModelAnimation()
{
    _anim = _state ? _animWalk : _animIdle;
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

encapsulation::BModel &Animation::getModel()
{
    return this->_model;
}
