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
    _goal = GET_MAP_POS_Z_FLOAT(sizeMap, this->getTransform().getPosition());
    //_key_event.insert({NULL_EVENT, &Bot::stand});
}

static Vector3T<float> getMiddlePos(const Vector3T<float> &pos)
{
    return Vector3T<float>({
        (float)((float)((int)(pos._x / 10) + 0.5) * 10),
        pos._y,
        (float)((float)((int)(pos._z / 10) + 0.5) * 10)});
}

void Bot::stand(std::size_t tick)
{
    static int i = 1;
    Vector3T<float> mid(getMiddlePos(this->getTransform().getPosition()));
    std::pair<game::Event, game::Event> move({
        (mid._x - getTransform().getPosition()._x) < 0 ? MOVE_DOWN : MOVE_UP,
        (mid._z - getTransform().getPosition()._z) < 0 ? MOVE_LEFT : MOVE_RIGHT
    });

    std::cout << "STANDING" << std::endl;
    if (!(mid._x - getTransform().getPosition()._x))
        move.first = STAND;
    if (!(mid._x - getTransform().getPosition()._x))
        move.second = STAND;
    if (i && move.first != STAND)
        _key_event[move.first];
    else if (!i && move.second != STAND)
        _key_event[move.second];
    i = 1 - i;
}

Bot::~Bot()
{
}

void Bot::update()
{
    this->updateMaps();
    if (!_isMoving) {
        _timer = 0;
    }
    this->setCurrentEvent(takeDecision(this->getTransform().getPosition()));
    this->setIsMoving(false);
    //std::cout << "Bot update and move from :" << this->getTransform().getPosition() << "->";
    //this->printEvent(_currentEvent);
    //dropBomb(1);
    handleEvent();
    updateModelAnimation();
}
