#include "Brain.hpp"


game::systems::Brain::Brain(std::shared_ptr<Map> &map, int level)
: _map(map), _level(level)
{
    
}

game::systems::Brain::~Brain() {
    
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
