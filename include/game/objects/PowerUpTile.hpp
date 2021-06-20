/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** PowerUpTile
*/

#ifndef POWERUPTILE_HPP_
#define POWERUPTILE_HPP_

#include "Tile.hpp"

namespace game::objects
{
    class PowerUpTile : public Tile
    {
    public:
        PowerUpTile(const std::shared_ptr<gameEngine::encapsulation::BModel> &model,
            const std::shared_ptr<gameEngine::encapsulation::BTexture2D> &texture,
            const game::Tag &type,
            const Vector3T<float> &position = {0, 0, 0},
            const Vector3T<float> &rotation = {0, 0, 0},
            const Vector3T<float> &scale = {1, 1, 1},
            float idleSpeed = 0.1,
            float minHeight = 10,
            float maxHeight = 20
            );
        PowerUpTile(const PowerUpTile &ref);
        ~PowerUpTile();


        void update() final;

    private:
        float _idleSpeed = 0.1;
        Vector3T<float> _speed = {0, 0, 0};
        Vector3T<float> _rotationSpeed = {1, 1, 1};
        float _minHeight = 1;
        float _maxHeight = 10;

    private:
        void checkHeight() noexcept;

};
} // namespace game::objects

#endif /* !POWERUPTILE_HPP_ */
