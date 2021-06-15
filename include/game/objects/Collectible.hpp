/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Collectible
*/

#ifndef COLLECTIBLE_HPP_
#define COLLECTIBLE_HPP_

#include "TimedObject.hpp"

namespace game
{
    namespace objects
    {
        class Collectible  : public TimedObject
        {
        public:
            typedef enum collectible_type {
                HEALTHPACK
            } collectible_type_e;


            Collectible(
                const std::string &id,
                const std::string &name,
                collectible_type_e type,
                std::chrono::milliseconds availaible_time,
                int health = 0
            );
            ~Collectible();

            void draw() const noexcept;
            void onOverTime();

            int getHealthEfect() const noexcept;

        private:
            int _health;
        };
    } // namespace objects
} // namespace game

#endif /* !COLLECTIBLE_HPP_ */
