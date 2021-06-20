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
#include <array>

#define GET_BOT_POS(size, vec) Vector<int>((vec._x + 3) / TILESIZE, (vec._z + 3) / TILESIZE)
//#define GET_BOT_POS_FLOAT(size, vec) Vector<float>((vec._x + 3) / TILESIZE, (vec._z + 3) / TILESIZE)
#define GET_TILE_POS(size, vec) Vector<int>(vec._x / TILESIZE, vec._z / TILESIZE)
#define GET_MAP_POS_Z(size, vec) Vector<int>((vec._x + 3) / TILESIZE, (vec._z + 3) / TILESIZE)
#define GET_MAP_POS_Z_FLOAT(size, vec) Vector<float>(size._x - (vec._x + 3) / TILESIZE, (vec._z + 3) / TILESIZE)



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
                std::string printEvent(game::Event &evt);
                void dumpStacks();
                void pushInStack(bool stackID, game::Event evt);
            protected:
                game::Event takeDecision(Vector3T<float> pos);
                void updateMaps(void);

                double _timer;
                Vector<int> _goal{0, 0};
                Vector<int> _sizeMap;
            private:

                // * Environment
                bool isADangerousZone(Vector<int> &pos);
                bool isDangerous(Vector<int> pos, Vector<int> dir = {0, 0});
                bool isSolid(Vector<int> &pos, Vector<int> &dir);
                bool isSolid(int x, int y);
                bool isWall(int x, int y);
                bool isDestructible(void);
                void updateDangerousMap(void);
                void dumpMap(void);
                void computeRangeBomb(Vector<int> &bomb);
                void updateStacks(game::Event evt);

                // * Strategy
                void setNewGoal();
                void setDirection(game::Event);
                bool needDropBomb(void);
                game::Event getEventFromDirection();
                std::vector<Vector<int>> getDirectionsAvailables();
                int giveDangerosity(game::Tag tag);

                // * OFFENSE
                game::Event computeDirection(void);
                void setNewGoalOffense();

                // * Defense
                void setNewGoalDefense();
                void defensePathFinding(int x, int y, int d, int a, int b);

                // * Attributs
                std::vector<std::shared_ptr<TILE>> &_map;
                double _basedTimer = 1;
                game::Event _decision = NULL_EVENT;
                game::Event _nextDecision;
                game::Event _previousDecision;

                Vector<int> _posBot{0, 0};
                Vector<int> _lastPosInMap{0, 0};
                std::vector<std::vector<int>> _DangerosityMap;
                std::stack<Vector<int>> _stackDangerousTile;
                std::array<std::stack<game::Event>, 2> _paths; //0 aller 1 retour
                std::stack<game::Event> _lastMoves;
                bool _pathId = false;

                std::vector<std::vector<Tag>> _tagMap;
                std::vector<std::vector<game::Event>> _directionMap;
                std::vector<std::vector<int>> _distanceMap;
                Vector<int> _direction{0, 0};
                int _level;
                gameEngine::component::Clock _clock;
                const std::array<Vector<int>, 5> directions =
                {
                    Vector<int>{0, 0},
                    Vector<int>{1, 0},
                    Vector<int>{-1, 0},
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

                const std::array<std::pair<Vector<int>, game::Event>, 5> directionsPairTab =
                {
                    std::pair<Vector<int>, game::Event>(Vector<int>(0, 0), NULL_EVENT),
                    std::pair<Vector<int>, game::Event>(Vector<int>(1, 0), MOVE_UP),
                    std::pair<Vector<int>, game::Event>(Vector<int>(-1, 0), MOVE_DOWN),
                    std::pair<Vector<int>, game::Event>(Vector<int>(0, 1), MOVE_RIGHT),
                    std::pair<Vector<int>, game::Event>(Vector<int>(0, -1), MOVE_LEFT),
                };
        };
    }
}
#endif /* !BRAIN_HPP_ */
