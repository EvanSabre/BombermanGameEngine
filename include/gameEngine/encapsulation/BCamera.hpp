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
#include "Vector3T.hpp"
#include "ICamera.hpp"

namespace gameEngine
{
    namespace encapsulation
    {
        class BCamera : public gameEngine::interfaces::ICamera
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
                void setPosition(const Vector3T<float> &pos) noexcept;
                void setTarget(const Vector3T<float> &target) noexcept;
                void setUp(const Vector3T<float> &up) noexcept;
                void setFovy(float fov) noexcept;
                void setProjection(CameraProjection projection) noexcept;

                void update() noexcept;
                void setMode(CameraMode mode) noexcept;

            //draw
                void beginMode() const noexcept final;
                void endMode() const noexcept final;

        protected:
        private:
            Camera _camera;
        };
    } // namespace encapsulation

} // namespace gameEngine


#endif /* !BCAMERA_HPP_ */
