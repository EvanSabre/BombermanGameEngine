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

            game::EffectType_e getType() const noexcept = 0;

            int getHealth() const noexcept;

        protected:
            int _health = 0;

        private:
            game::EffectType_e _type;
        };
    } // namespace name
} // namespace game

#endif /* !AEFFECT_HPP_ */
