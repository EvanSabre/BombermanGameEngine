/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** Moveable
*/

#ifndef MOVEABLE_HPP_
#define MOVEABLE_HPP_

#include "AGameObject.hpp"

namespace gameEngine {
    namespace objects {
        class Moveable : AGameObject {
            public:
                Moveable(const std::string &id);
                ~Moveable();

                Vector3T<float> getSpeed() const noexcept;

                void setSpeed(const Vector3T<float> &speed) noexcept;

                //move
                void move(const std::size_t &tick) noexcept;

                void moveDirection(std::size_t tick,
                    const gameEngine::systems::Move::direction_e direction);

                void moveRight(std::size_t tick) noexcept;
                void moveLeft(std::size_t tick) noexcept;
                void moveForward(std::size_t tick) noexcept;
                void moveBackward(std::size_t tick) noexcept;
                void moveUp(std::size_t tick) noexcept;
                void moveDown(std::size_t tick) noexcept;
            protected:
                Vector3T<float> _speed{0, 0, 0};
            private:
        };
    }
}

#endif /* !MOVEABLE_HPP_ */
