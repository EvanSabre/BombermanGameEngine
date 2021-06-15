/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** EffectFactory
*/

#ifndef EFFECTFACTORY_HPP_
#define EFFECTFACTORY_HPP_

#include <string>
#include "Tags.hpp"

#include "IEffect.hpp"
#include "HealthUp.hpp"
#include "OneUp.hpp"
#include "SpeedUp.hpp"
#include "BombUp.hpp"
#include "FireUp.hpp"
#include <memory>
#include <unordered_map>
#include <stdexcept>
#include <functional>

namespace game
{
    namespace objects
    {
        class EffectFactory;

        typedef std::unique_ptr<game::interfaces::IEffect> (*BuildEffectFct)();

        class EffectFactory {
        public:
            using IEffect_unq = std::unique_ptr<game::interfaces::IEffect>;
            static IEffect_unq makeEffect(game::Tag_e type);

        private:
            static const std::unordered_map<game::Tag_e, std::function<std::unique_ptr<game::interfaces::IEffect>()>> _efxProducer;

        };
    } // namespace objects
} // namespace game

#endif /* !EFFECTFACTORY_HPP_ */
