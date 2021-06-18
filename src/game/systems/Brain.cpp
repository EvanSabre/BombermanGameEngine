#include "Brain.hpp"
#include "Map.hpp"


#define GET_MAP_POS(vec) Vector<int>(vec._x / TILESIZE, vec._y / TILESIZE)

using namespace game::systems;

Brain::Brain(std::vector<std::shared_ptr<TILE>> &map, int level, Vector<int> sizeMap)
: _map(map), _level(level), _sizeMap(sizeMap)
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
        posInMap = {(int) tile->getTransform().getPosition()._x, (int) tile->getTransform().getPosition()._z};
        posInMap = GET_MAP_POS(posInMap);
        std::cout << "tag = " << tile->getTag() << tile->getTransform().getPosition() << std::endl;
        _tagMap[posInMap._x][posInMap._y] = tile->getTag();
    }
    dumpMap();
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
    (void) pos;
    (void) dir;
    return true;
}

bool Brain::isSolid(Vector<float> &pos, Vector<float> &dir)
{
    (void) pos;
    (void) dir;
    return true;
}

short Brain::PathFinding(Vector<float> &pos)
{
    (void) pos;
    return 1;
}

short Brain::PathFinding(Vector<float> &pos, Vector<float> &goal)
{
    (void) pos;
    (void) goal;
    return 1;
}

bool Brain::needDropBomb()
{
    return true;
}

void Brain::dumpMap()
{
    std::cout << "TagMap" << std::endl;
    for (int x = 0; x < _sizeMap._x; x++)
    {
        std::cout << std::endl;
        for (int y = 0; y < _sizeMap._y; y++)
            std::cout << "[" << _tagMap[x][y] << "]";
    }
    std::cout << std::endl;

    std::cout << "\r\nDangerous Map" << std::endl;
    for (int x = 0; x < _sizeMap._x; x++)
    {
        std::cout << std::endl;
        for (int y = 0; y < _sizeMap._y; y++)
            std::cout << "[" << _isDangerousMap[x][y] << "]";
    }
    std::cout << std::endl;
}