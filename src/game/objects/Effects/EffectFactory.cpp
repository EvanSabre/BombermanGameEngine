/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** EffectFactory
*/

#include "EffectFactory.hpp"

using namespace game::objects;

const std::unordered_map<std::string, BuildEffectFct> EffectFactory::_producer = {
    {"HealthUp", &EffectFactory::makeHealthUP},
    {"BombUp", &EffectFactory::makeBombUP},
    {"FireUp", &EffectFactory::makeFireUP},
    {"SpeedUp", &EffectFactory::makeSpeedUP},
    {"OneUp", &EffectFactory::makeOneUP},
};

EffectFactory::IEffect_unq EffectFactory::makeEffect(const std::string &type)
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

EffectFactory::IEffect_unq EffectFactory::makeBombUP() noexcept
{
    EffectFactory::IEffect_unq efx = std::make_unique<BombUp>();
    return efx;
}

EffectFactory::IEffect_unq EffectFactory::makeFireUP() noexcept
{
    EffectFactory::IEffect_unq efx = std::make_unique<FireUp>();
    return efx;
}

EffectFactory::IEffect_unq EffectFactory::makeSpeedUP() noexcept
{
    EffectFactory::IEffect_unq efx = std::make_unique<SpeedUp>();
    return efx;
}

EffectFactory::IEffect_unq EffectFactory::makeOneUP() noexcept
{
    EffectFactory::IEffect_unq efx = std::make_unique<OneUp>();
    return efx;
}