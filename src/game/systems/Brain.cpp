#include "Brain.hpp"
#include "Map.hpp"


#define GET_MAP_POS(vec) Vector<int>(vec._x / TILESIZE, vec._y / TILESIZE)

using namespace game::systems;

Brain::Brain(std::vector<std::shared_ptr<TILE>> &map, int level, Vector<int> sizeMap)
: _map(map), _level(level)
{
    Vector<int> posInMap{0, 0};
    for (int x = 0; x < sizeMap._x; x++)
    {
        _isDangerousMap.push_back(std::vector<bool>{0});
        _tagMap.push_back(std::vector<Tag>{0});
        for (int y = 0; y < sizeMap._y; y++) {
            _isDangerousMap[x].push_back(false);
            _tagMap[x].push_back(NONE);
        }
    }
    for (auto &tile : _map)
    {
        posInMap = {(int) tile->getTransform().getPosition()._x, (int) tile->getTransform().getPosition()._y};
        posInMap = GET_MAP_POS(posInMap);
    }

}

Brain::~Brain()
{
}

game::Event Brain::takeDecision()
{
    int dir;

    if (!_level)
        dir = std::rand() % 4 + 1;
    return (game::Event) dir;
}

void Brain::setNewGoal(Vector<float> &pos, Vector<float> &goal)
{
    if (this->isADangerousZone(pos))
        this->setNewGoalOffense(pos, goal);
    else
        this->setNewGoalDefense(pos, goal);
}


bool Brain::isADangerousZone(Vector<float> &pos)
{
    return true;
}

void Brain::setNewGoalOffense(Vector<float> &pos, Vector<float> &goal)
{
    short dir;
    if (_level)
        dir = std::rand() % 4;
    else
        dir = std::rand() % 4; // TODO: calcul de direction en cherchant le player le plus proche
    _direction = directions[dir];

    if (!isDangerous(pos, _direction) && isSolid(pos, _direction))
    {
        goal += _direction;
        if (needDropBomb())
            _decision = VALIDATE;
    }
}

void Brain::setNewGoalDefense(Vector<float> &pos, Vector<float> &goal)
{
   short newDir = PathFinding(pos);
   goal += directions[newDir];
}

void Brain::updateDangerousMap()
{

}

game::Event Brain::getEventFromDirection()
{
    return game::Event::NULL_EVENT;
}

bool Brain::isDangerous(Vector<float> &pos, Vector<float> &dir)
{
    return true;
}

bool Brain::isSolid(Vector<float> &pos, Vector<float> &dir)
{
    return true;
}

short Brain::PathFinding(Vector<float> &pos)
{
    return 1;
}

short Brain::PathFinding(Vector<float> &pos, Vector<float> &goal)
{
    return 1;
}

bool Brain::needDropBomb()
{
    return true;
}