/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** Collider
*/

#ifndef COLLIDER_HPP_
#define COLLIDER_HPP_

namespace gameEngine {
    namespace component {
        class Collider {
            public:
                Collider(bool enabled);
                ~Collider();

                bool getEnabled() const;
            private:
                bool _enabled = true;
        };
    }
}

#endif /* !COLLIDER_HPP_ */
