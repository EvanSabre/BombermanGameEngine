#include "Brain.hpp"
#include "Map.hpp"
#include <algorithm>

using namespace game::systems;

#define BOMBRANGE 3
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

static Vector<float> getMiddlePos(const Vector<float> &pos)
{
    return Vector<float>({
        (float)((float)((int)(pos._x / TILESIZE) + 0.5) * TILESIZE),
        (float)((float)((int)(pos._y / TILESIZE) + 0.5) * TILESIZE)});
}

void Brain::dumpStacks()
{
    std::cout << "Stack[0]: ";
    std::stack<game::Event> path_aller= _paths[0];
    std::stack<game::Event> path_back= _paths[1];

    while(!path_aller.empty())
    {
        std::cout << ">> " << printEvent(path_aller.top());
        path_aller.pop();
    }
    std::cout << std::endl;

    std::cout << "Stack[1]: ";

    while(!path_back.empty())
    {
        std::cout << ">> " << printEvent(path_back.top());
        path_back.pop();
    }
    std::cout << std::endl;
}

int Brain::giveDangerosity(game::Tag tag)
{
    switch (tag)
    {
        case WALL:
            return 100;
        case BRICK:
            return 50;
        case BORDER:
            return 100;
        case PATH:
            return 0;
        case BOMBUP:
            return -1;
        case HEALTHUP:
            return -1;
        case FIREUP:
            return -1;
        case ONEUP:
            return -1;
        case SPEEDUP:
            return -1;
        case BOMBPASS:
            return -1;
        case CHARACTER:
            return 0;
        case BOMB:
            return BOMBRANGE;
        default:
            return 0;
    }
    return 0;
}

Brain::Brain(std::vector<std::shared_ptr<TILE>> &map, int level, Vector<int> sizeMap)
: _timer(0.5), _sizeMap(sizeMap), _map(map), _nextDecision(NULL_EVENT), _level(level)
{
    Vector<int> tilePosInMap{0, 0};
    std::cout << "HEllo" << std::endl;

    for (int x = 0; x < _sizeMap._x; x++) {
        _DangerosityMap.push_back(std::vector<int>{0});
        for (int y = 0; y < sizeMap._y; y++)
            _DangerosityMap[x].push_back(0);
    }
    for (auto &tile : _map) {
        tilePosInMap = GET_TILE_POS(_sizeMap, tile->getTransform().getPosition());
        _DangerosityMap[tilePosInMap._x][tilePosInMap._y] = giveDangerosity(tile->getTag());
    }
    std::cout << "HEllo" << std::endl;
}

Brain::~Brain()
{
}

std::vector<Vector<int>> Brain::getDirectionsAvailables()
{
    std::vector<Vector<int>> dirAvailables;

    if (!isDangerous(_posBot, directions[3]))
        dirAvailables.push_back(_posBot + directions[3]);
    if (!isDangerous(_posBot, directions[4]))
        dirAvailables.push_back(_posBot + directions[4]);
    if (!isDangerous(_posBot, directions[2]))
        dirAvailables.push_back(_posBot + directions[2]);
    if (!isDangerous(_posBot, directions[1]))
        dirAvailables.push_back(_posBot + directions[1]);
    return dirAvailables;
}

game::Event Brain::computeDirection()
{
    //std::vector<Vector<int>> dirAvailables = getDirectionsAvailables();
    std::vector<Vector<int>>::iterator it;


    //it = std::find(dirAvailables.begin(), dirAvailables.end(), _direction);
    //if (it != dirAvailables.end() && _nextDecision != NULL_EVENT)
    //return _nextDecision;
    // for (auto &i : dirAvailables)
    // {
    //     if (_DangerosityMap[i._x][i._y] < _DangerosityMap[selected._x][selected._y]) {
    //         selected = i;
    //     }
    //     // else if (_DangerosityMap[i._x][i._y] == _DangerosityMap[selected._x][selected._y])
    //     // {
    //     // }

    // }
    game::Event event = _nextDecision;
    int min = 0;
    int idx = 0;
    std::vector<game::Event> list(0);
    for (auto i : directions) {
            Vector<int> posToCheck(_posBot + i);
            if (_DangerosityMap[posToCheck._x][posToCheck._y] <= min) {
                // for (auto it : directionsPairTab)
                //     if (it.first == i)
                //         event = it.second;
                event = events[idx];
                min = _DangerosityMap[posToCheck._x][posToCheck._y];
            }
            // std::cout <<"(selected, _posBot)" << selected << _posBot << std::endl;
            // std::cout <<"event:" << printEvent(i.second) << "" << i.first << std::endl;
            // this->_direction = i.first;
            idx++;
    }
    idx = 0;
    int temp = 0;
    for (auto i : directions) {
        Vector<int> posToCheck(_posBot + i);
        if (_DangerosityMap[posToCheck._x][posToCheck._y] == min) {
            std::cout << "bot   " << _posBot << std::endl;
            std::cout << "i     " << i << std::endl;
            std::cout << "check " << posToCheck << std::endl;
            list.push_back(events[idx]);
            temp++;
        }
        idx++;
    }
    if (!temp)
        return event;
    else
        return (list.at(std::rand() % list.size()));
    //if (!isSolid(_posBot._x, _posBot._y) && !isDangerous(_posBot, directions[0]))
    //    dirAvailables.push_back(game::Event::NULL_EVENT);
    //_direction = directions[0];
    //_nextDecision = _decision;
    // std::cout << "Directions " << dirAvailables.size() << std::endl;
    // //std::cout << "Bot position" << _posBot << std::endl;
    // size_t inc = 0;
    // for (auto &i : dirAvailables)
    // {
    //     if (std::rand() % 2 == 0 || dirAvailables.size() == 1 || inc == dirAvailables.size() - 1)
    //     {
    //         std::cout << "Compute Next decision" << printEvent(i) << std::endl;
    //         return i;
    //     }
    //     inc++;
    //     //std::cout << "Event not choosed " << printEvent(i) << std::endl;
    // }
    // return NULL_EVENT;
    // //dumpMap();
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

void Brain::pushInStack(bool stackID, game::Event evt)
{
    game::Event to_push;

    switch ((int) evt)
        {
            case 0:
                to_push = NULL_EVENT;
                break;
            case 1:
                to_push = MOVE_DOWN;
                break;
            case 2:
                to_push = MOVE_UP;
                break;
            case 3:
                to_push = MOVE_LEFT;
                break;
            case 4:
                to_push = MOVE_RIGHT;
                break;
            default:
                to_push = UNKNOWN;
                break;
        }
    _paths[stackID].push(to_push);
}

game::Event Brain::takeDecision(Vector3T<float> pos)
{
    //static game::Event event = VALIDATE;

    std::cout << std::endl << "UPDATE" << std::endl;
    _posBot = GET_BOT_POS(_sizeMap, pos);
    Vector<float> posInMapFloat = {pos._x + 5, pos._z + 5};
    Vector<float> goalInMapFloat = getMiddlePos(Vector<float>(_goal._x * TILESIZE, _goal._y * TILESIZE));

    //_nextDecision = NULL_EVEN"T;
    if (checkPos(posInMapFloat, goalInMapFloat, 2)) {
        std::cout << std::endl << "TAKE DECISION" << std::endl << std::endl;
        // dumpMap();
        setDirection(computeDirection());
        // dumpStacks();
        // if (!_paths[_pathId].empty() && (_decision !=  NULL_EVENT && _decision != VALIDATE)) {
        //     pushInStack(_pathId, _decision);
        // }
        // std::cout << "Goal JOINED" << _posBot << _goal << std::endl;
        setNewGoal();
        std::cout << "Compute Next decision -> " << printEvent(_nextDecision) << std::endl;
        // std::cout << "\nMOVE START" << std::endl << std::endl;
    }
    // if (event == VALIDATE)
    //     _decision = _previousDecision;
    // if (_decision != VALIDATE)
    std::cout << "Almost END UPDATE" << std::endl;
    if (_decision == VALIDATE) {
        _decision = _nextDecision;
        return VALIDATE;
    }
    _decision = _nextDecision;
    std::cout << "END UPDATE" << std::endl;
    //event = _decision;
    // std::cout << "Decisions(prev, curr, next)" << printEvent(_previousDecision) << printEvent(_decision) << printEvent(_nextDecision) << std::endl;
    return _decision;
}

void Brain::setGoal(Vector3T<float> pos) noexcept
{
    _goal = GET_MAP_POS_Z(_sizeMap, pos);
}

void Brain::setNewGoal()
{
    // //std::cout << "New botPos" << _posBot << std::endl;
    //dumpMap();
    // if (_paths[_pathId].empty() && this->isDangerous(_posBot)) {
    //     std::cout << "Defense" << std::endl;
    //     this->setNewGoalDefense();
    // } else {
    std::cout << "Offense" << std::endl;
    this->setNewGoalOffense();
    //}
}

void Brain::updateStacks(game::Event evt)
{
    if (!_paths[!_pathId].empty())
    {
        pushInStack(_pathId, _paths[!_pathId].top());
        setDirection(_paths[!_pathId].top());
        _paths[!_pathId].pop();
    }
    else {
        if (isDangerous(_posBot += directions[(int) evt]))
            setNewGoalDefense();
        pushInStack(_pathId, evt);
    }
}

void Brain::setDirection(game::Event event)
{
    std::cout << "nextEvent = " << printEvent(event) << std::endl;
    _nextDecision = event;
    _direction = directions[(int) _nextDecision];
    _goal._x = _posBot._x + _direction._x;
    _goal._y = _posBot._y + _direction._y;
}

void Brain::setNewGoalOffense()
{
    // std::cout << "Set new Goal on my" << printEvent(_nextDecision) << std::endl;
    // std::cout << "New goalPos" << _goal << std::endl;

    if (isDestructible() && _decision != VALIDATE) {
        //_previousDecision = _decision;
        _decision = VALIDATE;
        // std::cout << "On pete une bombe pathId =" << _pathId << std::endl;
        //dumpStacks();
        // std::cout << "du coup on se casse en " << printEvent(_nextDecision) << std::endl;
    }
    else {
        //std::cout << "setNewGlobalOffense:" << std::endl;
        //std::cout << "_decision = " << printEvent(_decision) << std::endl;
        //std::cout << "_pathId = " << _pathId << std::endl;
        //dumpStacks();
        //if (_decision == VALIDATE)
        //    _pathId = !_pathId;
        setDirection(computeDirection());
        //updateStacks(_nextDecision);
        // std::cout << "after:" << std::endl;
        // dumpStacks();
        // std::cout << "_nextdecision = " << printEvent(_nextDecision) << std::endl;
        // std::cout << "_pathId = " << _pathId << std::endl;
    }
}

void Brain::setNewGoalDefense()
{
    //dumpStacks();
    //setDirection(updateStacks());
    setDirection(computeDirection());
    std::cout << _posBot << "Je suis en defense donc " << printEvent(_nextDecision) << std::endl;
    //if (isDangerous(_goal)) {
    //    setDirection(computeDirection());
    //    std::cout << "Dsl trop dangereux détour par " << printEvent(_nextDecision) <<  std::endl;
    //}
    dumpStacks();
}

void Brain::updateMaps()
{
    Vector<int> tilePosInMap{0, 0};

    for (auto &line : _DangerosityMap) {
        for (auto &tile : line)
            tile = 0;
    }

    std::cout << "UpdateMap" << std::endl;
    for (auto &tile : _map) {
        tilePosInMap = GET_TILE_POS(_sizeMap, tile->getTransform().getPosition());
        _DangerosityMap[tilePosInMap._x][tilePosInMap._y] = giveDangerosity(tile->getTag());
        if (_DangerosityMap[tilePosInMap._x][tilePosInMap._y] == BOMBRANGE) {
            _stackDangerousTile.push(tilePosInMap);
        }
    }
    _DangerosityMap[_posBot._x][_posBot._y] = giveDangerosity(CHARACTER);
    updateDangerousMap();
}

void Brain::computeRangeBomb(Vector<int> &bomb)
{
    bool yPosProtected = false;
    bool xPosProtected = false;
    bool xNegProtected = false;
    bool yNegProtected = false;

    _DangerosityMap[bomb._x][bomb._y] = BOMBRANGE;
    for (int x = 1; x < BOMBRANGE; x++)
    {
        std::cout << "x = " << x << std::endl;
        if (!xPosProtected && !isWall(bomb._x + x, bomb._y))
            _DangerosityMap[bomb._x + x][bomb._y] = BOMBRANGE - x;
        else
            xPosProtected = true;
        if (!xNegProtected && !isWall(bomb._x - x, bomb._y))
            _DangerosityMap[bomb._x - x][bomb._y] = BOMBRANGE - x;
        else
            xNegProtected = true;
    }
        for (int y = 1; y < BOMBRANGE; y++)
        {
            if (!yPosProtected && !isWall(bomb._x, bomb._y + y))
                _DangerosityMap[bomb._x][bomb._y + y] = BOMBRANGE - y;
            else
                yPosProtected = true;
            if (!yNegProtected && !isWall(bomb._x, bomb._y - y))
                _DangerosityMap[bomb._x][bomb._y - y] = BOMBRANGE - y;
            else
                yNegProtected = true;
        }
}

void Brain::updateDangerousMap()
{
    while (!_stackDangerousTile.empty()) {
        std::cout << "before" << std::endl;
        computeRangeBomb(_stackDangerousTile.top());
        std::cout << "while" << std::endl;
        _stackDangerousTile.pop();
        std::cout << "after" << std::endl;
    }
}

bool Brain::isDangerous(Vector<int> pos, Vector<int> dir)
{
    Vector<int> newPos{pos._x += dir._x, pos._y += dir._y};

    return _DangerosityMap[newPos._x][newPos._y] > BOMBRANGE;
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
    if (_DangerosityMap[x][y] == 100 || _DangerosityMap[x][y] == 100)
        return true;
    return false;
}

bool Brain::isDestructible()
{
    // std::cout << "isDestructible :" << (_tagMap[_posBot._x][_posBot._y + 1] == BRICK ||
    //        _tagMap[_posBot._x][_posBot._y - 1] == BRICK ||
    //        _tagMap[_posBot._x + 1][_posBot._y] == BRICK ||
    //        _tagMap[_posBot._x - 1][_posBot._y] == BRICK) << std::endl;
    return (_DangerosityMap[_posBot._x][_posBot._y + 1] == 50 ||
           _DangerosityMap[_posBot._x][_posBot._y - 1] == 50 ||
           _DangerosityMap[_posBot._x + 1][_posBot._y] == 50 ||
           _DangerosityMap[_posBot._x - 1][_posBot._y] == 50);
}

void Brain::dumpMap()
{
    std::string c = " ";
    std::cout << "TagMap" << std::endl;
    for (int x = _sizeMap._x - 1; x >= 0; x--)
    {
        std::cout << std::endl;
        for (int y = 0; y < _sizeMap._y; y++) {
            if (_DangerosityMap[x][y] == 50)
                c = "*";
            else if(_DangerosityMap[x][y] == 100)
                c = "x";
            else if(_DangerosityMap[x][y] == 0)
                c = " ";
            else
                c = _DangerosityMap[x][y];
            std::cout << "[" << _DangerosityMap[x][y] << "]";
        }
    }
    std::cout << std::endl;

}

