/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** AGameObject
*/

#ifndef AGAMEOBJECT_HPP_
#define AGAMEOBJECT_HPP_

#include "IGameObject.hpp"

namespace gameEngine
{
    namespace systems
    {
        class AGameObject : public gameEngine::interfaces::IGameObject
        {
        public:
            AGameObject(const std::string &id);
            ~AGameObject();

            Vector3T<float> getPosition() const noexcept;
            Vector3T<float> getSpeed() const noexcept;
            const std::string getId() const noexcept;

            void setPostion(const Vector3T<float> &pos) noexcept;
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
            Vector3T<float> _postion{0, 0, 0};
            Vector3T<float> _speed{0, 0, 0};

        private:
            std::string _id;
        };
    } // namespace systems

} // namespace gameEngine




#endif /* !AGAMEOBJECT_HPP_ */
