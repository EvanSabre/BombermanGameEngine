#include "Brain.hpp"
#include "Map.hpp"

using namespace game::systems;

Brain::Brain(std::vector<std::shared_ptr<TILE>> &map, int level, Vector<int> sizeMap)
: _timer(0.5), _map(map), _level(level), _sizeMap(sizeMap), _nextDecision(NULL_EVENT)
{
    Vector<int> tilePosInMap{0, 0};
    for (int x = 0; x < sizeMap._x; x++) {
        _isDangerousMap.push_back(std::vector<bool>{0});
        _tagMap.push_back(std::vector<Tag>{0});
        _directionMap.push_back(std::vector<game::Event>{0});
        _distanceMap.push_back(std::vector<int>{0});
        for (int y = 0; y < sizeMap._y; y++) {
            _isDangerousMap[x].push_back(false);
            _tagMap[x].push_back(NONE);
            _directionMap[x].push_back(NULL_EVENT);
            _distanceMap[x].push_back(-1);
        }
    }
    for (auto &tile : _map) {
        tilePosInMap = {(int) tile->getTransform().getPosition()._x, (int) tile->getTransform().getPosition()._z};
        tilePosInMap = GET_MAP_POS(tilePosInMap);
        std::cout << "tag = " << tile->getTag() << tile->getTransform().getPosition() << std::endl;
        _tagMap[tilePosInMap._x][tilePosInMap._y] = tile->getTag();
    }
    dumpMap();
}

Brain::~Brain()
{
}

game::Event Brain::takeDecision(Vector3T<float> pos)
{
    int dir;

    _posInMap = GET_MAP_POS_Z(pos);
    setNewGoal(_posInMap, _direction);
    // if (_level)
    //     return (game::Event)(std::rand() % 5);
    // else
    //     return (game::Event)(std::rand() % 5);

    if (_clock.getElapsedTime() > _timer) {
        dir = (game::Event)(std::rand() % 5);
        _direction = directions[dir];
        _nextDecision = getEventFromDirection();
        _timer = _basedTimer;
        _clock.restart();
    }
    _decision = _nextDecision;
    return _decision;
}

void Brain::setNewGoal(Vector<int> &pos, Vector<int> &goal)
{
    if (!this->isADangerousZone(pos))
        this->setNewGoalOffense(pos, goal);
    else
        this->setNewGoalDefense(pos, goal);
}

bool Brain::isADangerousZone(Vector<int> &pos)
{
    return true;
}

void Brain::setNewGoalOffense(Vector<int> &pos, Vector<int> &goal)
{
    short dir;
    if (_level)
        dir = std::rand() % 4;
    else
        dir = std::rand() % 4; // TODO: calcul de direction en cherchant le player le plus proche
    _direction = directions[dir];
    // _direction = directions[dir];
    // _decision = this->getEventFromDirection();

    // if (!isDangerous(pos, _direction) && isSolid(pos, _direction))
    // {
    //     goal += _direction;
    //     if (needDropBomb())
    //         _decision = VALIDATE;
    // }
}

void Brain::setNewGoalDefense(Vector<int> &pos, Vector<int> &goal)
{
   //short newDir = PathFinding(pos);
   //goal += directions[newDir];
   _decision = getEventFromDirection();
}

void Brain::updateMaps(std::vector<std::shared_ptr<TILE>> &map)
{
    //TODO: pas de push back juste si la case a changé la remplacer par la nouvelle valeur;
}

void Brain::updateDangerousMap()
{
    //TODO: pas de push back juste si la case a changé la remplacer par la nouvelle valeur;
}

game::Event Brain::getEventFromDirection()
{
    for (int i = 0; i < 5; i++) {
        if (_direction == directions[i])
            return events[i];
    }
    return NULL_EVENT;
}

bool Brain::isDangerous(Vector<int> &pos, Vector<int> &dir)
{
    Vector<int> newPos = (pos += dir);

    if (_isDangerousMap[newPos._x][newPos._y] == true)
        return true;
    return false;
}

bool Brain::isSolid(Vector<int> &pos, Vector<int> &dir)
{
    Vector<int> newPos = (pos += dir);

    if (_tagMap[newPos._x][newPos._y] == WALL)
        return true;
    return false;
}

bool Brain::isSolid(int x, int y)
{
    if (_tagMap[x][y] == WALL)
        return true;
    return false;
}

void Brain::defensePathFinding(int x, int y, int d, int a, int b)
{
    if (!isSolid(y + a, x + b) && _distanceMap[y][(size_t)x+b]==-1)
    {
        _directionMap[(size_t)y + (size_t)a][(size_t)x + (size_t)b] = _directionMap[y][x];
        _distanceMap[(size_t)y + (size_t)a][(size_t)x + (size_t)b] = (game::Event)(d + 1);
    }

}

short Brain::PathFinding(Vector<int> &pos)
{
    int d = 0;

    for (int x=0; x< _sizeMap._y; x++) {
        for (int y=0; y < _sizeMap._x; y++) {
            if (_distanceMap[y][x] == d) {
                defensePathFinding(x, y, d, 0, 1);
                defensePathFinding(x, y, d, 0, -1);
                defensePathFinding(x, y, d, 1, 0);
                defensePathFinding(x, y, d, -1, 0);
            }
        }
    }
    (void) pos;
    return 1;
}

short Brain::PathFinding(Vector<int> &pos, Vector<int> &goal)
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