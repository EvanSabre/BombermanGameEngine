/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** EffectFactory
*/

#ifndef EFFECTFACTORY_HPP_
#define EFFECTFACTORY_HPP_

#include <string>

#include "IEffect.hpp"
#include "HealthUp.hpp"
#include "OneUp.hpp"
#include "SpeedUp.hpp"
#include "BombUp.hpp"
#include "FireUp.hpp"
#include <memory>
#include <unordered_map>
#include <stdexcept>

namespace game
{
    namespace objects
    {
        class EffectFactory;

        typedef std::unique_ptr<game::interfaces::IEffect> (*BuildEffectFct)();


        class EffectFactory {
        public:
            using IEffect_unq = std::unique_ptr<game::interfaces::IEffect>;
            static IEffect_unq makeEffect(const std::string &type);

            static IEffect_unq makeHealthUP() noexcept;
            static IEffect_unq makeBombUP() noexcept;
            static IEffect_unq makeFireUP() noexcept;
            static IEffect_unq makeSpeedUP() noexcept;
            static IEffect_unq makeOneUP() noexcept;

        private:
            static const std::unordered_map<std::string, BuildEffectFct> _producer;

        };
    } // namespace objects
} // namespace game

#endif /* !EFFECTFACTORY_HPP_ */
