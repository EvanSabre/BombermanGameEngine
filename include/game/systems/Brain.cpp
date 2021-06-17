#include "Brain.hpp"
#include "Map.hpp"


#define GET_MAP_POS(vec) Vector<int>(vec._x / TILESIZE, vec._y / TILESIZE)


game::systems::Brain::Brain(std::vector<std::shared_ptr<TILE>> &map, int level, Vector<int> sizeMap)
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
        posInMap = {tile->getTransform().getPosition()._x, tile->getTransform().getPosition()._y};
        posInMap = GET_MAP_POS(posInMap);
    }

}

game::systems::Brain::~Brain()
{
    
}

game::Event game::systems::Brain::takeDecision()
{
}

void game::systems::Brain::setNewGoal(Vector<float> &pos, Vector<float> &goal)
{
    if (this->isADangerousZone(pos))
        this->setNewGoalOffense(pos, goal);
    else
        this->setNewGoalDefense(pos, goal);
}

bool game::systems::Brain::isADangerousZone(Vector<float> &pos) {
    
}

void game::systems::Brain::setNewGoalOffense(Vector<float> &pos, Vector<float> &goal)
{
    short dir;
    if (_level)
        dir= std::rand() % 4;
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

void game::systems::Brain::setNewGoalDefense(Vector<float> &pos, Vector<float> &goal)
{
   short newDir = PathFinding(pos);
   goal += directions[newDir];
}

void game::systems::Brain::updateDangerousMap() {
    
}

game::Event game::systems::Brain::getEventFromDirection()
{
}
