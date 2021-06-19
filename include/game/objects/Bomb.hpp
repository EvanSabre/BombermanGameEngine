/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** Bomb
*/

#ifndef BOMB_HPP_
#define BOMB_HPP_

#include "Clock.hpp"
#include "AExplosif.hpp"
#include <thread>
#include <mutex>

namespace game::objects
{
    class Bomb : public AExplosif {
        public:
            // Ctor 1
            Bomb(const std::string &id,
                const std::string &modelfilepath = "assets/All/Models/Bomb.obj",
                const std::string &texturefilepath = "assets/All/Textures/Tile.png",
                const game::Tag &type = BOMB,
                const Vector3T<float> &position = {0, 0, 0},
                const Vector3T<float> &rotation = {0, 0, 0},
                const Vector3T<float> &scale = {1, 1, 1},
                const gameEngine::encapsulation::BColor &color = WHITE);
            // Ctor 2
            Bomb(const std::string &id,
                const std::shared_ptr<gameEngine::encapsulation::BModel> &model,
                const std::shared_ptr<gameEngine::encapsulation::BTexture2D> &texture,
                const game::Tag &type = NONE,
                const Vector3T<float> &position = {0, 0, 0},
                const Vector3T<float> &rotation = {0, 0, 0},
                const Vector3T<float> &scale = {1, 1, 1});
            // copy Ctor
            Bomb(const Bomb &ref);
            // Dtor
            ~Bomb();

            // Member functions
            void drop() final;
            void countdown();

        protected:
        private:
            std::unique_ptr<std::thread> _countdown;
    };
}

#endif /* !BOMB_HPP_ */
