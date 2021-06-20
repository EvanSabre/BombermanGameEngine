#include "Brain.hpp"
#include "Map.hpp"
#include <algorithm>

using namespace game::systems;

static Vector<float> getMiddlePos(const Vector<float> &pos)
{
    return Vector<float>({
        (float)((float)((int)(pos._x / TILESIZE) + 0.5) * TILESIZE),
        (float)((float)((int)(pos._y / TILESIZE) + 0.5) * TILESIZE)});
}

void Brain::dumpStacks()
{
    std::cout << "Stack[0]: ";

    while(!_paths[0].empty())
    {
        std::cout << "<< " << printEvent(_paths[0].top());
        _paths[0].pop();
    }
    std::cout << std::endl;

    std::cout << "Stack[1]: ";

    while(!_paths[1].empty())
    {
        std::cout << "<< " << printEvent(_paths[1].top());
        _paths[1].pop();
    }
    std::cout << std::endl;
}


Brain::Brain(std::vector<std::shared_ptr<TILE>> &map, int level, Vector<int> sizeMap)
: _timer(0.5), _map(map), _sizeMap(sizeMap), _level(level), _nextDecision(NULL_EVENT)
{
    Vector<int> tilePosInMap{0, 0};

    for (int x = 0; x < _sizeMap._x; x++) {
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
        tilePosInMap = GET_TILE_POS(_sizeMap, tile->getTransform().getPosition());
        _tagMap[tilePosInMap._x][tilePosInMap._y] = tile->getTag();
    }
}

Brain::~Brain()
{
}

void Brain::computeDirection()
{
    std::vector<game::Event> dirAvailables;
    std::vector<game::Event>::iterator it;

    std::cout << "RIGHT " <<_posInMap._x << " " << _posInMap._y + 1 << std::endl;
    std::cout << "LEFT " <<_posInMap._x << " " << _posInMap._y -1 << std::endl;
    std::cout << "DOWN " <<_posInMap._x-1 << " " <<  _posInMap._y << std::endl;
    std::cout << "UP " <<_posInMap._x+1 << " " << _posInMap._y << std::endl;
    // if (!isSolid(_posInMap._x, _posInMap._y) && !isDangerous(_posInMap, directions[0]))
    //     dirAvailables.push_back(game::Event::NULL_EVENT);
    if (!isSolid(_posInMap._x, _posInMap._y + 1) && !isDangerous(_posInMap, directions[3]))
        dirAvailables.push_back(game::Event::MOVE_RIGHT);
    if (!isSolid(_posInMap._x, _posInMap._y - 1) && !isDangerous(_posInMap, directions[4]))
        dirAvailables.push_back(game::Event::MOVE_LEFT);
    if (!isSolid(_posInMap._x - 1, _posInMap._y) && !isDangerous(_posInMap, directions[2]))
        dirAvailables.push_back(game::Event::MOVE_DOWN);
    if (!isSolid(_posInMap._x + 1, _posInMap._y) && !isDangerous(_posInMap, directions[1]))
        dirAvailables.push_back(game::Event::MOVE_UP);
    _direction = directions[0];
    _nextDecision = _decision;
    std::cout << "Directions " << dirAvailables.size() << std::endl;
    std::cout << "Bot position" << _posInMap << std::endl;
    for (auto &i : dirAvailables)
    {
        if (std::rand() % 2 == 0)
        {
            _nextDecision = i;
            std::cout << "Event setted ";
            printEvent(_nextDecision);
            _direction = directions[(int) _nextDecision];
            break;
        }
        printEvent(i);
    }
    //dumpMap();
}

std::string Brain::printEvent(game::Event &evt)
{
    switch ((int) evt)
        {
            case 0:
                return "NULL_EVENT";
                break;
            case 1:
                return "MOVE_UP";
                break;
            case 2:
                return "MOVE_DOWN";
                break;
            case 3:
                return "MOVE_RIGHT";
                break;
            case 4:
                return "MOVE_LEFT";
                break;
            case 5:
                return "VALIDATE";
                break;
            default:
                break;
        }
    return "NULL_EVENT";
}

static bool checkPos(Vector<float> bot, Vector<float> goal, int pad)
{
    return (bot._x < goal._x + pad && bot._x > goal._x - pad &&
            bot._y < goal._y + pad && bot._y > goal._y - pad);
}

game::Event Brain::takeDecision(Vector3T<float> pos)
{
    static game::Event event = VALIDATE;


    _posInMap = GET_BOT_POS(_sizeMap, pos);
    Vector<float> posInMapFloat = {pos._x + 5, pos._z + 5};
    Vector<float> goalInMapFloat = getMiddlePos({_goal._x * TILESIZE, _goal._y * TILESIZE});

    //_nextDecision = NULL_EVEN"T;
    if (checkPos(posInMapFloat, goalInMapFloat, 2)) {
        if (_decision !=  NULL_EVENT && _decision != VALIDATE)
            _paths[_pathId].push(_decision);
        std::cout << "Goal JOINED" << _posInMap << _goal << std::endl;
        dumpStacks();
        setNewGoal(_posInMap, _goal);
    }
    if (event == VALIDATE)
        _decision = _previousDecision;
    else if (_decision != VALIDATE)
        _decision = _nextDecision;
    event = _decision;
    return _decision;
}

void Brain::setGoal(Vector3T<float> pos) noexcept
{
    _goal = GET_MAP_POS_Z(_sizeMap, pos);
}

void Brain::setNewGoal(Vector<int> &pos, Vector<int> &goal)
{
    std::cout << "Offense" << std::endl;
    this->setNewGoalOffense(pos, goal);
    // if (!this->isDangerous(pos)) {
    // }
    // else
    // {
    //     std::cout << "Defense" << std::endl;
    //     this->setNewGoalDefense(pos, goal);
    //     //computeDirection();

    // }
}

game::Event Brain::updateStacks()
{
    game::Event evt = UNKNOWN;

    if (!_paths[_pathId].empty())
    {
        _paths[!_pathId].push(_paths[_pathId].top());
        evt = _paths[_pathId].top();
        _paths[_pathId].pop();
    }
    return UNKNOWN;
}

void Brain::setNewGoalOffense(Vector<int> &pos, Vector<int> &goal)
{
    static bool first = true;

    _nextDecision = updateStacks();
    if (_nextDecision == UNKNOWN)
        computeDirection();
    std::cout << "Set new Goal on";
    printEvent(_nextDecision);
    _goal._x = _posInMap._x + _direction._x;
    _goal._y = _posInMap._y + _direction._y;
    std::cout << "Set new objectif on " << _goal << std::endl;

    if (!first && isDestructible() && _decision != VALIDATE) {
        _previousDecision = _decision;
        _decision = VALIDATE;
        _pathId = !_pathId;
        dumpStacks();
        computeDirection();
    }
    else
        first = false;
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
        tilePosInMap = GET_TILE_POS(_sizeMap, tile->getTransform().getPosition());
        _tagMap[tilePosInMap._x][tilePosInMap._y] = tile->getTag();
        if (_tagMap[tilePosInMap._x][tilePosInMap._y] == BOMB) {
            _stackDangerousTile.push(tilePosInMap);
        }
    }
    _tagMap[_posInMap._x][_posInMap._y] = CHARACTER;
    updateDangerousMap();
}

void Brain::computeRangeBomb(Vector<int> &bomb)
{
    bool yPosProtected = false;
    bool xPosProtected = false;
    bool xNegProtected = false;
    bool yNegProtected = false;

    _isDangerousMap[bomb._x][bomb._y] = true;
    for (int x = 1; x < 3; x++)
    {
        if (!xPosProtected && !isWall(bomb._x + x, bomb._y))
            _isDangerousMap[bomb._x + x][bomb._y] = true;
        else
            xPosProtected = true;
        if (!xNegProtected && !isWall(bomb._x - x, bomb._y))
            _isDangerousMap[bomb._x - x][bomb._y] = true;
        else
            xNegProtected = true;
    }
        for (int y = 1; y < 3; y++)
        {
            if (!yPosProtected && !isWall(bomb._x, bomb._y + y))
                _isDangerousMap[bomb._x][bomb._y + y] = true;
            else
                yPosProtected = true;
            if (!yNegProtected && !isWall(bomb._x, bomb._y - y))
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

bool Brain::isDangerous(Vector<int> pos, Vector<int> dir)
{
    Vector<int> newPos{pos._x += dir._x, pos._y += dir._y};

    return _isDangerousMap[newPos._x][newPos._y];
}

bool Brain::isSolid(Vector<int> &pos, Vector<int> &dir)
{
    Vector<int> newPos{pos._x += dir._x, pos._y += dir._y};

    if (pos._x < 0 || pos._x > _sizeMap._x || pos._y < 0 || pos._y > _sizeMap._y)
        return true;
    if (_tagMap[newPos._x][newPos._y] == WALL || _tagMap[newPos._x][newPos._y] == BRICK || _tagMap[newPos._x][newPos._y] == BORDER)
        return true;
    return false;
}

bool Brain::isSolid(int x, int y)
{
    if (x < 0 || x > _sizeMap._x || y < 0 || y > _sizeMap._y)
        return true;
    if (_tagMap[x][y] == WALL || _tagMap[x][y] == BRICK || _tagMap[x][y] == BORDER)
        return true;
    return false;
}

bool Brain::isWall(int x, int y)
{
    if (x < 0 || x > _sizeMap._x || y < 0 || y > _sizeMap._y)
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

bool Brain::isDestructible()
{
    return (_tagMap[_posInMap._x][_posInMap._y + 1] == BRICK ||
           _tagMap[_posInMap._x][_posInMap._y - 1] == BRICK ||
           _tagMap[_posInMap._x + 1][_posInMap._y] == BRICK ||
           _tagMap[_posInMap._x - 1][_posInMap._y] == BRICK);
}

void Brain::dumpMap()
{
    std::string c = " ";
    std::cout << "TagMap" << std::endl;
    for (int x = _sizeMap._x - 1; x >= 0; x--)
    {
        std::cout << std::endl;
        for (int y = 0; y < _sizeMap._y; y++) {
            if (_tagMap[x][y] == Tag::BRICK)
                c = "*";
            else if(_tagMap[x][y] == Tag::WALL)
                c = "x";
            else if(_tagMap[x][y] == Tag::NONE)
                c = " ";
            else
                c = std::to_string((int) _tagMap[x][y]);
            std::cout << "[" << c << "]";
        }
    }
    std::cout << std::endl;

    std::cout << "\r\nDangerous Map" << std::endl;
    for (int x = _sizeMap._x - 1; x >= 0; x--)
    {
        std::cout << std::endl;
        for (int y = 0; y < _sizeMap._y; y++)
            std::cout << "[" << _isDangerousMap[x][y] << "]";
    }
    std::cout << std::endl;

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

