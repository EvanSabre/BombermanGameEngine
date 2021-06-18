/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Animation
*/

#include "gameEngine/Animation.hpp"

using namespace gameEngine;

Animation::Animation(
    const encapsulation::BModel &model,
    const encapsulation::BTexture2D &texture,
    const encapsulation::BModelAnimation &anim)
    : _model(model), _texture(texture), _anim(anim), _frameCounter(0)
{
    _model.setTexture(0, MATERIAL_MAP_DIFFUSE, _texture);
}

Animation::~Animation()
{
}

void Animation::updateModelAnimation()
{
    std::cout << _pos << std::endl;
    // if (_model.isLoad() && _anim.isLoad()) {
    //     _frameCounter++;
    //     UpdateModelAnimation(
    //         _model.getObj(),
    //         _anim.getModelAnimation()[0],
    //         _frameCounter);
    // }
    // if (_frameCounter >= _anim.getAnimFrameCount()) {
    //     _frameCounter = 0;
    //     // delete this;
    // }
}

void Animation::refresh()
{
    _model.draw();
}

void Animation::setPos(const Vector3T<float> &pos)
{
    _pos = pos;
}

Vector3T<float> Animation::getPos() const
{
    return _pos;
}
