/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BImage
*/

#ifndef BIMAGE_HPP_
#define BIMAGE_HPP_

#include <iostream>
#include <string>
#include <stdexcept>
#include "Vector.hpp"
#include "raylib.h"

namespace gameEngine
{
    namespace encapsulation
    {
        class BImage
        {
        public:
            BImage(const std::string &filepath, const Vector<int> &pos = {0, 0});
            BImage(const BImage &ref);
            BImage &operator=(const BImage &ref);
            ~BImage();

            //getter
                [[nodiscard]] Image getObj() const noexcept;
                [[nodiscard]] bool isLoad() const noexcept;
                [[nodiscard]] int getWidth() const noexcept;
                [[nodiscard]] int getHeight() const noexcept;
                [[nodiscard]] Vector<int> getSize() const noexcept;
                [[nodiscard]] Vector<int> getPosition() const noexcept;

            //setter
            // Load image from file into CPU memory (RAM)
                void load(const std::string &filpath);
                void unload() noexcept;

                void setImage(const Image &img) noexcept;
                void setImage(const Image &img, const Vector<int> &pos) noexcept;
                void setPosition(const Vector<int> &pos) noexcept;

            //transform
                void resize(const Vector<int> &newSize) noexcept;
                void scale(const float &scale) noexcept;
                void rotateRight() noexcept;
                void rotateLeft() noexcept;

                //flip vertically
                void flipV() noexcept;
                //flip horizontaly
                void flipH() noexcept;

        protected:
        private:
            Image _img;
            Vector<int> _pos{0, 0};
        };
    } // namespace encapsulation

} // namespace gameEngine

#endif /* !BIMAGE_HPP_ */
