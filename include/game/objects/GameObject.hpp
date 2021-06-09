/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** GameObject
*/

#ifndef GAMEOBJECT_HPP_
#define GAMEOBJECT_HPP_

#include <iostream>

namespace game::objects {
    class GameObject {
        public:
            GameObject();
            ~GameObject();

            // getters
            std::size_t getId() const;

            // setters
            void setId(const std::size_t &);

        protected:
            std::size_t _id;
        private:
    };
}

#endif /* !GAMEOBJECT_HPP_ */
