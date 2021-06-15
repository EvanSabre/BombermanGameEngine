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
#include "IEffect.hpp"
#include "EffectFactory.hpp"

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
                size_t getScore() const noexcept;

            //setter
                void addScore(const size_t value) noexcept;
                void subScore(const size_t value) noexcept;
                void setModel(gameEngine::encapsulation::BModel *model) noexcept;

            //action
            //vo dropBomb() const noexcept;


            void draw() const noexcept;
            //tmp for test : to delete
                void OnCollisionEnter(const AGameObject &collision);
                void OnCollisionExit(const AGameObject &collision);
                void Update();
               game::Tag_e getTag() const noexcept override;

        protected:
            size_t _score = 0;
            int _nbBomb = 1;
            int _bombRange = 1;
            int _health = 1;
            int _lives = 1;

        private:
            std::string _name;
            gameEngine::encapsulation::BModel *_model = nullptr;

        private:
            void addPowerUpEffec(const game::interfaces::IEffect *efx) noexcept;
        };
    } // namespace objects
} // namespace game

#endif /* !CHARACTER_HPP_ */
