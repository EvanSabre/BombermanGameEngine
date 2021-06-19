/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** AExplosif
*/

#ifndef AEXPLOSIF_HPP_
#define AEXPLOSIF_HPP_

#include "Tile.hpp"

namespace game::objects
{
    class AExplosif : public Tile {
        public:
            // Ctor 1
            AExplosif(const std::string &id,
                const std::string &modelfilepath,
                const std::string &texturefilepath,
                const game::Tag &type,
                const Vector3T<float> &position,
                const Vector3T<float> &rotation,
                const Vector3T<float> &scale,
                const gameEngine::encapsulation::BColor &color);
            // Ctor 2
            AExplosif(const std::string &id,
                const std::shared_ptr<gameEngine::encapsulation::BModel> &model,
                const std::shared_ptr<gameEngine::encapsulation::BTexture2D> &texture,
                const game::Tag &type,
                const Vector3T<float> &position,
                const Vector3T<float> &rotation,
                const Vector3T<float> &scale);
            // copy Ctor
            AExplosif(const AExplosif &ref);
            // Dtor
            ~AExplosif();

            // Member functions
            virtual void drop() = 0;

            // Setters
            void increaseRange(const std::size_t &);
            void explode();
            void pickUpBombPass();
            void setSwitch(bool state);
            void update();

            // Getters
            std::string getPlayerId() const;
            std::size_t getRange() const;
            bool isDropped() const;
            bool isDone() const;
            bool collide() const;
            bool getSwitch() const;

        protected:
            std::string _playerId;
            std::size_t _range;
            bool _done;
            bool _collide;
            bool _dropped;
            bool _switch;
        private:
    };
}

std::ostream &operator<<(std::ostream &os, const game::objects::AExplosif &ref);

#endif /* !AEXPLOSIF_HPP_ */
