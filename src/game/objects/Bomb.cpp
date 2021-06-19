/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** Bomb
*/

#include "Bomb.hpp"

using namespace game::objects;

Bomb::Bomb(
    const std::string &id,
    const std::string &modelfilepath,
    const std::string &texturefilepath,
    const game::Tag &type,
    const Vector3T<float> &position,
    const Vector3T<float> &rotation,
    const Vector3T<float> &scale,
    const gameEngine::encapsulation::BColor &color)
    : AExplosif(id, modelfilepath, texturefilepath, type, position, rotation, scale, color),
      _countdown(nullptr)
{
}

Bomb::Bomb(
    const std::string &id,
    const std::shared_ptr<gameEngine::encapsulation::BModel> &model,
    const std::shared_ptr<gameEngine::encapsulation::BTexture2D> &texture,
    const game::Tag &type,
    const Vector3T<float> &position,
    const Vector3T<float> &rotation,
    const Vector3T<float> &scale)
    : AExplosif(id, model, texture, type, position, rotation, scale),
      _countdown(nullptr)
{
}

Bomb::Bomb(const Bomb &ref)
    : AExplosif(ref)
{
}

Bomb::~Bomb()
{
    if (_dropped)
        _countdown->detach();
}

// Member functions
void Bomb::drop()
{
    setCollider();
    _switch = true;
    if (!_dropped) {
        _dropped = true;
        _countdown = std::make_unique<std::thread>(&Bomb::countdown, this);
    }
}

void Bomb::countdown()
{
    std::mutex mtx;

    std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // 1 seconds

    mtx.lock();
    _collide = true;
    mtx.unlock();

    std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // 2 seconds

    mtx.lock();
    std::cout << "BOOOOOM" << std::endl;
    _done = true;
    mtx.unlock();
}

// Getters
game::Tag_e getTag()
{
    return game::Tag_e::BOMB;
}

// Setters
void Bomb::setCollider() noexcept
{
    Vector3T<float> pos(this->getTransform().getPosition());
    Vector3T<float> sca(this->getTransform().getScale());

    _collider.getBoundingBox().setBoundingBox(
        {(float)(pos._x - sca._x * (float)TILESIZE * 0.5),
        pos._y,
        (float)(pos._z - sca._z * (float)TILESIZE * 0.5)},
        {(float)(pos._x + sca._x * (float)TILESIZE * 0.5),
        pos._y,
        (float)(pos._z + sca._z * (float)TILESIZE * 0.5)});
}
