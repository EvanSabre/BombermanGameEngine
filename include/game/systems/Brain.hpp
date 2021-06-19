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
            protected:
                game::Event takeDecision(Vector3T<float> pos);
                void updateMaps(void);
                double _timer;
            private:
                double _basedTimer = 0.5;
                game::Event _decision;
                game::Event _nextDecision;
                Vector<int> _posInMap{0, 0};
                Vector<int> _lastPosInMap{0, 0};
                std::vector<std::shared_ptr<TILE>> &_map;
                std::vector<std::vector<bool>> _isDangerousMap;
                std::vector<std::vector<Tag>> _tagMap;
                std::vector<std::vector<game::Event>> _directionMap;
                std::vector<std::vector<int>> _distanceMap;
                Vector<int> _direction{0, 0};
                int _level;
                Vector<int> _sizeMap;
                gameEngine::component::Clock _clock;

                void setNewGoal(Vector<int> &pos, Vector<int> &goal);
                bool isADangerousZone(Vector<int> &pos);
                bool isDangerous(Vector<int> &pos, Vector<int> &dir);
                bool isSolid(Vector<int> &pos, Vector<int> &dir);
                bool isSolid(int x, int y);
                bool needDropBomb(void);
                void setNewGoalOffense(Vector<int> &pos, Vector<int> &goal);
                void setNewGoalDefense(Vector<int> &pos, Vector<int> &goal);
                void updateDangerousMap(void);
                short PathFinding(Vector<int> &pos, Vector<int> &goal);
                short PathFinding(Vector<int> &pos);
                void defensePathFinding(int x, int y, int d, int a, int b);
                void dumpMap(void);
                void computeDirection(void);
                game::Event getEventFromDirection();
                const std::array<Vector<int>, 4> directions =
                {
                    Vector<int>{-1, 0},
                    Vector<int>{0, -1},
                    Vector<int>{1, 0},
                    Vector<int>{0, 1}
                };

                const std::array<game::Event, 4> events =
                {
                    MOVE_DOWN,
                    MOVE_LEFT,
                    MOVE_UP,
                    MOVE_RIGHT
                };
        };
    }
}
#endif /* !BRAIN_HPP_ */