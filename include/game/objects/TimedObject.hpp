/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** TimedObject
*/

#ifndef TIMEDOBJECT_HPP_
#define TIMEDOBJECT_HPP_

#include "Tile.hpp"
#include "Clock.hpp"

namespace game
{
    namespace objects
    {
        class TimedObject : public Clock, public Tile
        {
        public:
            //handle timle in seconds
            TimedObject(double life_time);
            ~TimedObject();

            //getter
                double getLifeTime() const noexcept;
                double getRemainedTime() const noexcept;
                bool isTimeOver() const noexcept;

            void Update();

            virtual void onOverTime() = 0;

        protected:
            gameEngine::encapsulation::BModel *_model = nullptr;

        private:
            double _lifeTime;
            double _lastLifeTimeCheckPoint = 0;

        private:
            void updateLastTimeCheck() noexcept;

            //update _lastCheck adnd lauch onOvertime if neccessary
                void updateLifeTime() noexcept;

        };

    } // namespace systems
} // namespace gmae



#endif /* !TIMEDOBJECT_HPP_ */
