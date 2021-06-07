/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BAudio
*/

#ifndef BAUDIO_HPP_
#define BAUDIO_HPP_

#include "raylib.h"
#include <stdexcept>

namespace gameEngine
{
    namespace encapsulation
    {
        class BAudio
        {
        public:
            static void init();
            static void close(void) noexcept;
            static bool isReady(void) noexcept;
            static void setVolume(float volume) noexcept;
        };
    } // namespace encapsulation

} // namespace gameEngine

#endif /* !BAUDIO_HPP_ */
