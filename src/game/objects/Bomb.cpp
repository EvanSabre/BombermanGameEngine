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
    _switch = true;
    if (!_dropped) {
        _dropped = true;
        _countdown = std::make_unique<std::thread>(&Bomb::countdown, this);
    }
}

void Bomb::countdown()
{
    std::mutex mtx;

    std::this_thread::sleep_for(std::chrono::milliseconds(4000)); // 4 seconds

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
