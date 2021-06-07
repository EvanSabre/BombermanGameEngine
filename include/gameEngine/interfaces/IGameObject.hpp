/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** IGameObject
*/

#ifndef IGAMEOBJECT_HPP_
#define IGAMEOBJECT_HPP_

#include <string>
#include "Vector3T.hpp"
#include "Move.hpp"

namespace gameEngine
{
    namespace interfaces
    {
        class IGameObject {
        public:
            virtual ~IGameObject() = default;

            virtual Vector3T<float> getPosition() const noexcept = 0;
            virtual Vector3T<float> getSpeed() const noexcept = 0;
            virtual const std::string getId() const noexcept = 0;

            virtual void setPostion(const Vector3T<float> &pos) noexcept = 0;
            virtual void setSpeed(const Vector3T<float> &spped) noexcept = 0;

            //?? or just put it in constructor
            //virtual void setId(const std::string &id) noexcept = 0;


            //put it there or make a IMovable ?
            virtual void move(const std::size_t &tick) noexcept = 0;

            virtual void moveDirection(std::size_t tick,
                const gameEngine::systems::Move::direction_e direction) = 0;

            virtual void moveRight(std::size_t tick) noexcept = 0;
            virtual void moveLeft(std::size_t tick) noexcept = 0;
            virtual void moveForward(std::size_t tick) noexcept = 0;
            virtual void moveBackward(std::size_t tick) noexcept = 0;
            virtual void moveUp(std::size_t tick) noexcept = 0;
            virtual void moveDown(std::size_t tick) noexcept = 0;

            //which type to put here
            //virtual ?? copy(const std::string &new_id) const noexcept = 0;

        };
    } // namespace interfaces

} // namespace gameEngine

#endif /* !IGAMEOBJECT_HPP_ */
