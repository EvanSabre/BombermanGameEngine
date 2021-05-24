/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BCamera
*/

#ifndef BCAMERA_HPP_
#define BCAMERA_HPP_

#include <iostream>
#include <string>
#include <stdexcept>
#include "raylib.h"

namespace gameEngine
{
    namespace encapsulation
    {
        class BCamera
        {
        public:
            BCamera();
            BCamera(const BCamera &ref);
            BCamera &operator=(const BCamera &ref);
            ~BCamera();

            //getter
                [[nodiscard]] Camera getObj() const noexcept;

            //setter
            // Load Camera from file into CPU memory (RAM)
                void setPosition(float x, float y, float z) noexcept;
                void setTarget(float x, float y, float z) noexcept;
                void setUp(float x, float y, float z) noexcept;
                void setFovy(float fov) noexcept;
                void setProjection(CameraProjection projection) noexcept;

            //draw
                // void beginMode();
                // void endMode(),
        protected:
        private:
            Camera _camera = {0};
        };
    } // namespace encapsulation

} // namespace gameEngine


#endif /* !BCAMERA_HPP_ */
