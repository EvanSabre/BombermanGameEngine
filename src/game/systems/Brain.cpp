#include "Brain.hpp"
#include "Map.hpp"
#include <algorithm>

using namespace game::systems;

Brain::Brain(std::vector<std::shared_ptr<TILE>> &map, int level, Vector<int> sizeMap)
: _timer(0.5), _map(map), _sizeMap(sizeMap), _level(level), _nextDecision(NULL_EVENT)
{
    Vector<int> tilePosInMap{0, 0};
    for (int x = 0; x < sizeMap._x; x++) {
        _isDangerousMap.push_back(std::vector<bool>{0});
        _tagMap.push_back(std::vector<Tag>{0});
        _directionMap.push_back(std::vector<game::Event>{0});
        _distanceMap.push_back(std::vector<int>{-1});
        for (int y = 0; y < sizeMap._y; y++) {
            _isDangerousMap[x].push_back(false);
            _tagMap[x].push_back(NONE);
            _directionMap[x].push_back(NULL_EVENT);
            _distanceMap[x].push_back(-1);
        }
    }
    for (auto &tile : _map) {
        tilePosInMap = {(int) tile->getTransform().getPosition()._x, (int) tile->getTransform().getPosition()._z};
        tilePosInMap = GET_MAP_POS(_sizeMap, tilePosInMap);
        _tagMap[tilePosInMap._x][tilePosInMap._y] = tile->getTag();
    }
    dumpMap();
}

Brain::~Brain()
{
}

void Brain::computeDirection()
{
    std::vector<game::Event> dirAvailables;
    std::vector<game::Event>::iterator it;

    //dirAvailables.push_back(game::Event::NULL_EVENT);
    if (!isSolid(_posInMap._x, _posInMap._y + 1))
        dirAvailables.push_back(game::Event::MOVE_RIGHT);
    if (!isSolid(_posInMap._x, _posInMap._y - 1))
        dirAvailables.push_back(game::Event::MOVE_LEFT);
    if (!isSolid(_posInMap._x - 1, _posInMap._y))
        dirAvailables.push_back(game::Event::MOVE_UP);
    if (!isSolid(_posInMap._x + 1, _posInMap._y))
        dirAvailables.push_back(game::Event::MOVE_DOWN);
    std::cout << "Directions " << dirAvailables.size() << std::endl;
    for (auto &i : dirAvailables)
    {
        if (std::rand() % 2 == 0)
        {
            _nextDecision = i;
            std::cout << "Event setted ";
            printEvent(_nextDecision);
        }
        printEvent(i);
    }
    // do {
    //     _nextDecision = (game::Event)(std::rand() % dirAvailables.size());
    //     it = std::find (dirAvailables.begin(), dirAvailables.end(), _nextDecision);
    // } while (it == dirAvailables.end());
    _direction = directions[(int) _nextDecision - 1];

}

void Brain::printEvent(game::Event &evt)
{
    switch ((int) evt)
        {
            case 0:
                std::cout << "NULL_EVENT" << std::endl;
                break;
            case 1:
                std::cout << "MOVE_UP" << std::endl;
                break;
            case 2:
                std::cout << "MOVE_DOWN" << std::endl;
                break;
            case 3:
                std::cout << "MOVE_RIGHT" << std::endl;
                break;
            case 4:
                std::cout << "MOVE_LEFT" << std::endl;
                break;
            default:
                break;
        }
}

game::Event Brain::takeDecision(Vector3T<float> pos)
{
    //_posInMapFloat = GET_MAP_POS_Z_FLOAT(_sizeMap, pos);
    _posInMap = GET_MAP_POS_Z(_sizeMap, pos);

    //std::cout << pos << std::endl;
    // if (_posInMapFloat == _goal) {
    //     setNewGoal(_posInMap, _direction);
    //     //exit(0);
    // }

    if (_clock.getElapsedTime() > _timer) {
        std::cout << _posInMap << _goal << std::endl;
        std::cout << "Move" << std::endl;
        //computeDirection();
        setNewGoal(_posInMap, _direction);
        //_nextDecision = getEventFromDirection();
        _timer = _basedTimer;
        _clock.restart();
    }
    _decision = _nextDecision;
    return _decision;
}

void Brain::setGoal(Vector3T<float> pos) noexcept
{
    _goal = GET_MAP_POS_Z(_sizeMap, pos);
}

void Brain::setNewGoal(Vector<int> &pos, Vector<int> &goal)
{
    if (!this->isDangerous(pos)) {
        std::cout << "Offense" << std::endl;
        this->setNewGoalOffense(pos, goal);
    }
    else
    {
        std::cout << "Defense" << std::endl;
        this->setNewGoalDefense(pos, goal);
        //computeDirection();

    }
}

void Brain::setNewGoalOffense(Vector<int> &pos, Vector<int> &goal)
{
    short dir;

    if (_level)
        dir = std::rand() % 5;
    else
        dir = std::rand() % 5; // TODO: calcul de direction en cherchant le player le plus proche
    _direction = directions[dir];
    _nextDecision = events[dir];
    computeDirection();
    if (!isDangerous(pos, _direction) && !isSolid(pos, _direction))
    {
        _goal += _direction;
        if (needDropBomb())
            _nextDecision = VALIDATE;
    }
}

void Brain::setNewGoalDefense(Vector<int> &pos, Vector<int> &goal)
{
   short newDir = PathFinding(pos);
   //goal += directions[newDir];
   _decision = getEventFromDirection();
}

void Brain::updateMaps()
{
    Vector<int> tilePosInMap{0, 0};

    for (auto &line : _tagMap) {
        for (auto &tile : line)
            tile = NONE;
    }
    for (auto &line : _isDangerousMap) {
        for (auto tile : line)
            tile = false;
    }
    for (auto &tile : _map) {
        tilePosInMap = {(int) tile->getTransform().getPosition()._x, (int) tile->getTransform().getPosition()._z};
        tilePosInMap = GET_MAP_POS(_sizeMap, tilePosInMap);
        _tagMap[tilePosInMap._x][tilePosInMap._y] = tile->getTag();
        if (_tagMap[tilePosInMap._x][tilePosInMap._y] == BOMB)
            _stackDangerousTile.push(tilePosInMap);
    }
    updateDangerousMap();
    //dumpMap();
}

void Brain::computeRangeBomb(Vector<int> &bomb)
{
    bool yPosProtected = false;
    bool xPosProtected = false;
    bool xNegProtected = false;
    bool yNegProtected = false;

    for (int x = 0; x < 3; x++)
        {
            if (!isWall(bomb._x + x, bomb._y) && !xPosProtected)
                _isDangerousMap[bomb._x + x][bomb._y] = true;
            else
                xPosProtected = true;
            if (!isWall(bomb._x - x, bomb._y) && !xNegProtected)
                _isDangerousMap[bomb._x - x][bomb._y] = true;
            else
                xNegProtected = true;
        }
        for (int y = 0; y < 3; y++)
        {
            if (!isWall(bomb._x, bomb._y + y) && !yPosProtected)
                _isDangerousMap[bomb._x][bomb._y + y] = true;
            else
                yPosProtected = true;
            if (!isWall(bomb._x, bomb._y - y) && !yNegProtected)
                _isDangerousMap[bomb._x][bomb._y - y] = true;
            else
                yNegProtected = true;
        }
}

void Brain::updateDangerousMap()
{
    while (!_stackDangerousTile.empty()) {
        computeRangeBomb(_stackDangerousTile.top());
        _stackDangerousTile.pop();
    }
}

game::Event Brain::getEventFromDirection()
{
    for (int i = 0; i < 5; i++) {
        if (_direction == directions[i])
            return events[i];
    }
    return NULL_EVENT;
}

bool Brain::isDangerous(Vector<int> &pos, Vector<int> dir)
{
    Vector<int> newPos = (pos += dir);

    if (_isDangerousMap[newPos._x][newPos._y] == true)
        return true;
    return false;
}

bool Brain::isSolid(Vector<int> &pos, Vector<int> &dir)
{
    Vector<int> newPos = (pos += dir);

    if (pos._x < 0 || pos._x >= _sizeMap._x || pos._y < 0 || pos._y >= _sizeMap._y)
        return true;
    if (_tagMap[newPos._x][newPos._y] == WALL || _tagMap[newPos._x][newPos._y] == BRICK || _tagMap[newPos._x][newPos._y] == BORDER)
        return true;
    return false;
}

bool Brain::isSolid(int x, int y)
{
    if (x < 0 || x >= _sizeMap._x || y < 0 || y >= _sizeMap._y)
        return true;
    if (_tagMap[x][y] == WALL || _tagMap[x][y] == BRICK || _tagMap[x][y] == BORDER)
        return true;
    return false;
}

bool Brain::isWall(int x, int y)
{
    if (x < 0 || x >= _sizeMap._x || y < 0 || y >= _sizeMap._y)
        return true;
    if (_tagMap[x][y] == WALL || _tagMap[x][y] == BORDER)
        return true;
    return false;
}

void Brain::defensePathFinding(int x, int y, int d, int a, int b)
{
    if (!isSolid(y + a, x + b) && _distanceMap[y][x+b]==-1)
    {
        _directionMap[y + a][x + b] = _directionMap[y][x];
        _distanceMap[y + a][x + b] = (game::Event)(d + 1);
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
    return false;
}

void Brain::dumpMap()
{
    // std::string c = " ";
    // std::cout << "TagMap" << std::endl;
    // for (int x = 0; x < _sizeMap._x; x++)
    // {
    //     std::cout << std::endl;
    //     for (int y = 0; y < _sizeMap._y; y++) {
    //         if (_tagMap[x][y] == Tag::BRICK)
    //             c = "*";
    //         else if(_tagMap[x][y] == Tag::WALL)
    //             c = "x";
    //         else if(_tagMap[x][y] == Tag::NONE)
    //             c = " ";
    //         else
    //             c = std::to_string((int) _tagMap[x][y]);
    //         std::cout << "[" << c << "]";
    //     }
    // }
    // std::cout << std::endl;

    // std::cout << "\r\nDangerous Map" << std::endl;
    // for (int x = 0; x < _sizeMap._x; x++)
    // {
    //     std::cout << std::endl;
    //     for (int y = 0; y < _sizeMap._y; y++)
    //         std::cout << "[" << _isDangerousMap[x][y] << "]";
    // }
    // std::cout << std::endl;

    // std::cout << "\r\nDistance Map" << std::endl;
    // for (int x = 0; x < _sizeMap._x; x++)
    // {
    //     std::cout << std::endl;
    //     for (int y = 0; y < _sizeMap._y; y++)
    //         std::cout << "[" << _distanceMap[x][y] << "]";
    // }
    // std::cout << std::endl;

    // std::cout << "\r\nDirection Map" << std::endl;
    // for (int x = 0; x < _sizeMap._x; x++)
    // {
    //     std::cout << std::endl;
    //     for (int y = 0; y < _sizeMap._y; y++)
    //         std::cout << "[" << _directionMap[x][y] << "]";
    // }
    // std::cout << std::endl;
}
