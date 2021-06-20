/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** Timer
*/

#ifndef TIMER_HPP_
#define TIMER_HPP_

#include "Clock.hpp"
#include "ADrawable.hpp"
#include "BText.hpp"
#include <thread>
#include <mutex>
#include <cstring>

namespace gameEngine {
    namespace component {
        class Timer : public gameEngine::encapsulation::ADrawable {
            public:
                Timer(const double &duration = 120);
                ~Timer();

                double getDuration() const noexcept;
                void setPause(bool pause);
                void setDuration(const double &duration);
                void setTimePos(const Vector<float> &pos);
                void setIsDone(bool isDone);
                void startThread();
                gameEngine::encapsulation::BText &getCurrentTime();
                std::string getContent() const noexcept;
                void draw();
                void wait();
                void timerExecute();
                void addToDuration(const double &add);
                void update() override;
            protected:
                bool _pause = false;
                double _duration;
                bool _isDone = false;
                std::unique_ptr<std::thread> _timerThread;
                gameEngine::component::Clock _clock;
                std::string _format;
                gameEngine::encapsulation::BText _currentTime;
            private:
        };
    }
}

#endif /* !TIMER_HPP_ */
