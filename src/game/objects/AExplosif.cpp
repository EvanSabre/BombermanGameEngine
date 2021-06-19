/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** AExplosif
*/

#include "AExplosif.hpp"

using namespace game::objects;

AExplosif::AExplosif(
    const std::string &id,
    const std::string &modelfilepath,
    const std::string &texturefilepath,
    const game::Tag &type,
    const Vector3T<float> &position,
    const Vector3T<float> &rotation,
    const Vector3T<float> &scale,
    const gameEngine::encapsulation::BColor &color)
    : Tile(modelfilepath, texturefilepath, type, position, rotation, scale, color),
      _playerId(id),
      _range(3),
      _done(false),
      _collide(true),
      _dropped(false),
      _switch(false)
{
}

AExplosif::AExplosif(
    const std::string &id,
    const std::shared_ptr<gameEngine::encapsulation::BModel> &model,
    const std::shared_ptr<gameEngine::encapsulation::BTexture2D> &texture,
    const game::Tag &type,
    const Vector3T<float> &position,
    const Vector3T<float> &rotation,
    const Vector3T<float> &scale)
    : Tile(model, texture, type, position, rotation, scale),
      _playerId(id),
      _range(3),
      _done(false),
      _collide(true),
      _dropped(false),
      _switch(false)
{
}

AExplosif::AExplosif(const AExplosif &ref)
    : Tile(ref),
     _playerId(ref._playerId),
     _range(ref._range),
     _done(ref._done),
     _collide(ref._collide),
     _dropped(ref._dropped),
     _switch(ref._switch)
{
}

AExplosif::~AExplosif()
{
}

// Setters
void AExplosif::increaseRange(const std::size_t &range)
{
    _range += range;
}

void AExplosif::explode()
{
    _done = true;
}

void AExplosif::update()
{
}

void AExplosif::pickUpBombPass()
{
    _collide = false;
}

void AExplosif::setSwitch(bool state)
{
    _switch = state;
}

// Getters
std::string AExplosif::getPlayerId() const
{
    return _playerId;
}

std::size_t AExplosif::getRange() const
{
    return _range;
}

bool AExplosif::isDropped() const
{
    return _dropped;
}

bool AExplosif::isDone() const
{
    return _done;
}

bool AExplosif::collide() const
{
    return _collide;
}

bool AExplosif::getSwitch() const
{
    return _switch;
}

// Operators
std::ostream &operator<<(std::ostream &os, const game::objects::AExplosif &ref)
{
    os << "Explosif:" << std::endl;
    os << "  playerID = " << ref.getPlayerId() << std::endl;
    os << "  range    = " << ref.getRange() << std::endl;
    os << "  done     = " << (ref.isDone() ? "true" : "false") << std::endl;
    os << "  collide  = " << (ref.collide() ? "true" : "false") << std::endl;
    return os;
}
