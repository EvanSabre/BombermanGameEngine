/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** ACollectible
*/

#ifndef ACOLLECTIBLE_HPP_
#define ACOLLECTIBLE_HPP_

#include "Tile.hpp"

namespace game::objects {
    class ACollectible : public game::objects::Tile {
        public:
            ACollectible(const std::string &,
                         const std::string &,
                         const Vector3T<float> &,
                         const gameEngine::encapsulation::BColor &,
                         const float &,
                         const game::Tag &);
            ~ACollectible();

            // member function
            virtual void usePowerUp(/* Player &player */) = 0;

        protected:
        private:
    };
}

#endif /* !ACOLLECTIBLE_HPP_ */
