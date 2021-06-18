/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Bot
*/

#include "Bot.hpp"

using namespace game::objects;

Bot::Bot(const std::string &id, const std::string &name, const std::string &text,
         const std::string &model, const std::string &animWalk, const std::string &animIdle,
         std::vector<std::shared_ptr<game::objects::Tile>> &map, int level, Vector<int> sizeMap)
        : Character(id, name, text, model, animWalk, animIdle), Brain(map, level, sizeMap)
{
}

Bot::~Bot()
{
}



void Bot::update()
{
    //if (!_isMoving) {
    this->setCurrentEvent(takeDecision(this->getTransform().getPosition()));
    //std::cout << "Bot update and move " << _currentEvent << std::endl;
    //}
    handleEvent();
    updateModelAnimation();
}