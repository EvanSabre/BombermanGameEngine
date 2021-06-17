/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Brain
*/

#ifndef BRAIN_HPP_
#define BRAIN_HPP_

#include "Map.hpp"
#include "SettingConf.hpp"

namespace game
{
    namespace systems
    {
        class Brain
        {
            public:
                Brain(std::shared_ptr<Map> &map, int level);
                ~Brain();
            protected:
                game::Event takeDecision();
            private:
                game::Event _decision;
                std::vector<std::shared_ptr<Tile>> _map;
                std::vector<std::vector<bool>> _isDangerousMap;
                Vector<float> _direction{0, 0};
                int _level;

                void setNewGoal(Vector<float> &pos, Vector<float> &goal);
                bool isADangerousZone(Vector<float> &pos);
                bool isDangerous(Vector<float> &pos, Vector<float> &dir);
                bool isSolid(Vector<float> &pos, Vector<float> &dir);
                bool needDropBomb();
                void setNewGoalOffense(Vector<float> &pos, Vector<float> &goal);
                void setNewGoalDefense(Vector<float> &pos, Vector<float> &goal);
                void updateDangerousMap();
                short PathFinding(Vector<float> &pos, Vector<float> &goal);
                short PathFinding(Vector<float> &pos);
                game::Event getEventFromDirection();
                const std::array<Vector<float>, 4> directions =
                {
                    Vector<float>{-1, 0},
                    Vector<float>{0, -1},
                    Vector<float>{1, 0},
                    Vector<float>{0, 1}
                };
        };
    }
}
#endif /* !BRAIN_HPP_ */
