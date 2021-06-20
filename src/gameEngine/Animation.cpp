/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Animation
*/

#include "gameEngine/Animation.hpp"

using namespace gameEngine;

Animation::Animation(
    const std::shared_ptr<encapsulation::BModel> &model,
    const std::shared_ptr<encapsulation::BModelAnimation> &anim)
    : _model(model), _anim(anim), _frameCounter(0)
{
}

Animation::Animation(const Animation &ref)
    : _model(ref._model), _anim(ref._anim), _frameCounter(ref._frameCounter)
{
}

Animation::Animation(const std::shared_ptr<Animation> &ref)
    : _model(ref->_model), _anim(ref->_anim), _frameCounter(ref->_frameCounter)
{
}

Animation::~Animation()
{
}

void Animation::updateModelAnimation()
{
    // std::cout << _pos << std::endl;
    if (_model->isLoad() && _anim->isLoad()) {
        _frameCounter++;
        UpdateModelAnimation(
            _model->getObj(),
            _anim->getModelAnimation()[0],
            _frameCounter);
    }
    if (_frameCounter >= _anim->getAnimFrameCount()) {
        _frameCounter = 0;
        // delete this;
    }
}

void Animation::refresh()
{
    _model->draw();
}

void Animation::setPos(const Vector3T<float> &pos)
{
    _pos = pos;
    _model->setTransform().setPosition(pos);
}

Vector3T<float> Animation::getPos() const
{
    return _pos;
}
