/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** EffectFactory
*/

#include "EffectFactory.hpp"

using namespace game::objects;

const std::unordered_map<game::Tag_e, std::function<std::unique_ptr<game::interfaces::IEffect>()>> EffectFactory::_efxProducer = {
    {game::Tag::HEALTHUP,
        []() {
            return std::make_unique<game::objects::HealthUp>();
        }},
    {game::Tag::BOMBUP,
        []() {
            return std::make_unique<game::objects::BombUp>();
        }},
    {game::Tag::FIREUP,
        []() {
            return std::make_unique<game::objects::FireUp>();
        }},
    {game::Tag::SPEEDUP,
        []() {
            return std::make_unique<game::objects::SpeedUp>();
        }},
    {game::Tag::ONEUP,
        []() {
            return std::make_unique<game::objects::OneUp>();
    }}
};


EffectFactory::IEffect_unq EffectFactory::makeEffect(game::Tag_e type)
{
    try
    {
       // efx = _producer.at(type)();
        return _efxProducer.at(type)();
    }
    catch(const std::exception& e)
    {
        throw std::invalid_argument("Effect Factory : unknown type");
    }
   return nullptr;
}
