/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** ExplosionAnimation
*/

#include "ExplosionAnimation.hpp"

using namespace game::objects;

ExplosionAnimation::ExplosionAnimation(
    const std::shared_ptr<gameEngine::encapsulation::BModel> &modH,
    const Vector3T<float> &posH,
    const Vector3T<float> &scaleH,
    const std::shared_ptr<gameEngine::encapsulation::BModel> &modV,
    const Vector3T<float> &posV,
    const Vector3T<float> &scaleV)
    : _modelH(modH), _posH(posH), _scaleH(scaleH),
      _modelV(modV), _posV(posV), _scaleV(scaleV)
{
    _clock = std::make_unique<gameEngine::component::Clock>();
}

ExplosionAnimation::~ExplosionAnimation()
{
}
