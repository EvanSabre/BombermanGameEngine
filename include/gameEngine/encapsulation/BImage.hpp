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
#include "raylib.h"

// Image LoadImage(const char *fileName);                                                             // Load image from file into CPU memory (RAM)

namespace gameEngine
{
    namespace encapsulation
    {
        class BImage
        {
        public:
            BImage(const std::string &filepath);
            BImage(const BImage &ref);
            BImage &operator=(const BImage &ref);
            ~BImage();

            //getter
                [[nodiscard]] Image getObj() const noexcept;
                [[nodiscard]] bool isLoad() const noexcept;
                [[nodiscard]] int getWidth() const noexcept;
                [[nodiscard]] int getHeight() const noexcept;

            //setter
            // Load image from file into CPU memory (RAM)
                void load(const std::string &filpath);
                void setImage(const Image &img) noexcept;

                void unload() noexcept;

        protected:
        private:
            Image _img;
        };
    } // namespace encapsulation

} // namespace gameEngine

#endif /* !BIMAGE_HPP_ */
