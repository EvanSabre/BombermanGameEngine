/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Chraracter
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <string>
#include "Moveable.hpp"

namespace game
{
    namespace objects
    {
        class Character : public gameEngine::objects::Moveable
        {
        public:
            Character(
                        const std::string &id,
                        const std::string &name,
                        const Vector3T<float> &pos = {0, 0, 0}
                        );
            ~Character();

            //getter
                std::string getName() const noexcept;

        protected:
        private:
            std::string _name;
        };
    } // namespace objects
} // namespace game

#endif /* !CHARACTER_HPP_ */
