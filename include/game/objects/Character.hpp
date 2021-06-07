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
#include "BModel.hpp"

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
                ssize_t getScore() const noexcept;

            //setter
                void addScore(const size_t value) noexcept;
                void subScore(const size_t value) noexcept;


            //action
            //void dropBomb() const noexcept;

            //tmp for test : to delete
                void OnCollisionEnter(const AGameObject &collision);
                void OnCollisionExit(const AGameObject &collision);
                void Update();


        protected:
            ssize_t _score = 0;

        private:
            std::string _name;
           // gameEngine::encapsulation::BModel _model;
        };
    } // namespace objects
} // namespace game

#endif /* !CHARACTER_HPP_ */
