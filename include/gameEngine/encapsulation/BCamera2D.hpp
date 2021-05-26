/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BCamera2D
*/

#ifndef BCAMERA2D_HPP_
#define BCAMERA2D_HPP_

#include "Vector.hpp"
#include "raylib.h"
#include "ICamera.hpp"

namespace gameEngine
{
    namespace encapsulation
    {
        class BCamera2D : public gameEngine::interfaces::ICamera
        {
        public:
            BCamera2D();
            BCamera2D(const BCamera2D &ref);
            BCamera2D &operator=(const BCamera2D &ref);
            ~BCamera2D();

        //getter
            [[nodiscard]] Camera2D getObj() const noexcept;
            [[nodiscard]] Vector<float> getOffset() const noexcept;
            [[nodiscard]] Vector<float> getTarget() const noexcept;
            [[nodiscard]] float getRotation() const noexcept;
            [[nodiscard]] float getZoom() const noexcept;

        //setter
            void setOffset(const Vector<float> &offset) noexcept;
            void setTarget(const Vector<float> &target) noexcept;
            void setRotation(float rotation) noexcept;
            void rotateLeft(float value) noexcept;
            void rotateRight(float value) noexcept;
            void setZoom(float zoom) noexcept;
            void unzoom(float value) noexcept;
            void zoom(float value) noexcept;

            void resetObj() noexcept;
        //Draw
            void beginMode() const noexcept final;
            void endMode() const noexcept final;

        private:
            Camera2D _camera;
        };

    } // namespace encapsulation

} // namespace gameEngine


#endif /* !BCAMERA2D_HPP_ */
