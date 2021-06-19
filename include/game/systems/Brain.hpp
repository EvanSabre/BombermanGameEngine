/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Brain
*/

#ifndef BRAIN_HPP_
#define BRAIN_HPP_

#include "Tile.hpp"
#include "SettingConf.hpp"
#include "Clock.hpp"
#include <stack>

#define GET_MAP_POS(size, vec) Vector<int>(size._x - 1 - vec._x / TILESIZE, vec._y / TILESIZE)
#define GET_MAP_POS_Z(size, vec) Vector<int>(size._x - 1 - vec._x / TILESIZE, vec._z / TILESIZE)
#define GET_MAP_POS_Z_FLOAT(size, vec) Vector<float>(size._x - 1 - vec._x / TILESIZE, vec._z / TILESIZE)



#define TILE game::objects::Tile

namespace game
{
    namespace systems
    {
        class Brain
        {
            public:
                Brain(std::vector<std::shared_ptr<TILE>> &map, int level, Vector<int> sizeMap);
                ~Brain();
                void setGoal(Vector3T<float> pos) noexcept;
                void printEvent(game::Event &evt);
            protected:
                game::Event takeDecision(Vector3T<float> pos);
                void updateMaps(void);

                double _timer;
                Vector<int> _goal{0, 0};
                Vector<int> _sizeMap;
            private:

                // * Environment
                bool isADangerousZone(Vector<int> &pos);
                bool isDangerous(Vector<int> &pos, Vector<int> dir = {0, 0});
                bool isSolid(Vector<int> &pos, Vector<int> &dir);
                bool isSolid(int x, int y);
                bool isWall(int x, int y);
                void updateDangerousMap(void);
                void dumpMap(void);
                void computeRangeBomb(Vector<int> &bomb);

                // * Strategy
                void setNewGoal(Vector<int> &pos, Vector<int> &goal);
                bool needDropBomb(void);
                game::Event getEventFromDirection();


                // * OFFENSE
                short PathFinding(Vector<int> &pos, Vector<int> &goal);
                void computeDirection(void);
                void setNewGoalOffense(Vector<int> &pos, Vector<int> &goal);

                // * Defense
                short PathFinding(Vector<int> &pos);
                void setNewGoalDefense(Vector<int> &pos, Vector<int> &goal);
                void defensePathFinding(int x, int y, int d, int a, int b);

                // * Attributs
                double _basedTimer = 0.5;
                game::Event _decision;
                game::Event _nextDecision;
                Vector<int> _posInMap{0, 0};
                Vector<float> _posInMapFloat{0, 0};
                Vector<int> _lastPosInMap{0, 0};
                std::vector<std::shared_ptr<TILE>> &_map;
                std::vector<std::vector<bool>> _isDangerousMap;
                std::stack<Vector<int>> _stackDangerousTile;
                std::vector<std::vector<Tag>> _tagMap;
                std::vector<std::vector<game::Event>> _directionMap;
                std::vector<std::vector<int>> _distanceMap;
                Vector<int> _direction{0, 0};
                int _level;
                gameEngine::component::Clock _clock;
                const std::array<Vector<int>, 5> directions =
                {
                    Vector<int>{-0, 0},
                    Vector<int>{-1, 0},
                    Vector<int>{1, 0},
                    Vector<int>{0, 1},
                    Vector<int>{0, -1}
                };

                const std::array<game::Event, 5> events =
                {
                    NULL_EVENT,
                    MOVE_UP,
                    MOVE_DOWN,
                    MOVE_RIGHT,
                    MOVE_LEFT
                };
        };
    }
}
#endif /* !BRAIN_HPP_ */