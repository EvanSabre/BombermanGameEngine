/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** AEffect
*/

#ifndef AEFFECT_HPP_
#define AEFFECT_HPP_

#include "IEffect.hpp"

namespace game
{
    namespace objects
    {
        class AEffect : public game::interfaces::IEffect
        {
        public:
            AEffect(game::EffectType_e type);
            ~AEffect();

            game::EffectType_e getType() const noexcept;

            int getHealth() const noexcept final;
            int getNbBomb() const noexcept final;
            int getBlastPower() const noexcept final;
            Vector3T<float> getSpeed() const noexcept final;

        protected:
            int _health = 0;
            int _nbBomb = 0;
            int _blastPower = 0;
            Vector3T<float> _speed{0, 0, 0};

        private:
            game::EffectType_e _type;
        };
    } // namespace name
} // namespace game

#endif /* !AEFFECT_HPP_ */
