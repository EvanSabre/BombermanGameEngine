/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Dropable
*/

#ifndef DROPABLE_HPP_
#define DROPABLE_HPP_

#include "TimedObject.hpp"

namespace game {
    namespace objects {
        class Dropable : public TimedObject {
        public:
            typedef enum dropable_type {
                BOMBPACK
            } dropable_type_e;

            Dropable(const std::string &id,
                const std::string &name,
                dropable_type_e type,
                std::chrono::milliseconds availaible_time,
                int bomb = 0);
            ~Dropable();
            void draw() const noexcept;
            void onOverTime();

            int BombEffect() const noexcept;

        protected:
        private:
            int _bomb;
        };
    }
}

#endif /* !DROPABLE_HPP_ */
