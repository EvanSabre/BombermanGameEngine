/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** IGameObject
*/

#ifndef IGAMEOBJECT_HPP_
#define IGAMEOBJECT_HPP_

#include <string>
#include "Vector3T.hpp"
#include "Move.hpp"

namespace gameEngine
{
    namespace interfaces
    {
        class IGameObject {
        public:
            virtual ~IGameObject() = default;

            virtual void OnCollisionEnter() = 0;
            virtual void OnCollisionExit() = 0;
            virtual void Update() = 0;


        };
    } // namespace interfaces

} // namespace gameEngine

#endif /* !IGAMEOBJECT_HPP_ */
