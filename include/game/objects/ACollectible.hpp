/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** ACollectible
*/

#ifndef ACOLLECTIBLE_HPP_
#define ACOLLECTIBLE_HPP_

#include "Tile.hpp"

using namespace game::objects;

namespace game::objects {
    class ACollectible : public Tile {
        public:
            ACollectible(const std::string &,
                         const std::string &,
                         const Vector3T<float> &,
                         const BColor &,
                         const float &,
                         const TileType &);
            ~ACollectible();

            // member function
            virtual void usePowerUp(/* Player &player */) = 0;

        protected:
        private:
    };
}

#endif /* !ACOLLECTIBLE_HPP_ */
