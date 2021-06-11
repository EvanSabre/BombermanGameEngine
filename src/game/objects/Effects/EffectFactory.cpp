/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** EffectFactory
*/

#include "EffectFactory.hpp"

using namespace game::objects;

const std::unordered_map<game::EffectType_e, BuildEffectFct> EffectFactory::_producer = {
    {game::EffectType_e::HEALTH, &EffectFactory::makeHealthUP},
};

EffectFactory::IEffect_unq EffectFactory::makeEffect(game::EffectType_e type)
{
    EffectFactory::IEffect_unq efx = nullptr;

    try
    {
        efx = _producer.at(type)();
    }
    catch(const std::exception& e)
    {
        throw std::invalid_argument("Effect Factory : unknown type");
    }
    return efx;
}

EffectFactory::IEffect_unq EffectFactory::makeHealthUP() noexcept
{
    EffectFactory::IEffect_unq efx = std::make_unique<HealthUp>();
    return efx;
}


