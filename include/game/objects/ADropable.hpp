/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** ADropable
*/

#ifndef ADROPABLE_HPP_
#define ADROPABLE_HPP_

#include "Tile.hpp"

using namespace game::objects;

namespace game::objects {
    class ADropable : public Tile {
        public:
            ADropable(const std::string &,
                         const std::string &,
                         const Vector3T<float> &,
                         const BColor &,
                         const float &,
                         const TileType &);
            ~ADropable();

            virtual void Explosion_bomb() = 0;

        protected:
        private:
    };
}
#endif /* !ADROPABLE_HPP_ */
