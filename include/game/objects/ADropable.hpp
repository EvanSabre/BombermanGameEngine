/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** ADropable
*/

#ifndef ADROPABLE_HPP_
#define ADROPABLE_HPP_

#include "Tile.hpp"

namespace game::objects {
    class ADropable : public game::objects::Tile {
        public:
            ADropable(const std::string &,
                      const std::string &,
                      const Vector3T<float> &,
                      const gameEngine::encapsulation::BColor &,
                      const float &,
                      const game::Tag &);
            ~ADropable();

        protected:
        private:
    };
}

#endif /* !ADROPABLE_HPP_ */
