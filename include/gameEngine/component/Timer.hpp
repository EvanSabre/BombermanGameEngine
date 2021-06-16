/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** Timer
*/

#ifndef TIMER_HPP_
#define TIMER_HPP_

#include "Clock.hpp"

namespace gameEngine {
    namespace component {
        class Timer : public Clock {
            public:
                Timer();
                ~Timer();

            protected:
                double _duration;
            private:
        };
    }
}

#endif /* !TIMER_HPP_ */
