/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BTexture
*/

#ifndef BTEXTURE2D_HPP_
#define BTEXTURE2D_HPP_

#include "raylib.h"
#include "BImage.hpp"
#include "Vector.hpp"
#include "BColor.hpp"

namespace gameEngine
{
    namespace encapsulation
    {
        class BTexture2D
        {
        public:
            BTexture2D(const std::string &filePath);
            BTexture2D();
            ~BTexture2D();

        //getter
            [[nodiscard]] Texture2D getObj() const noexcept;
            [[nodiscard]] bool isLoad() const noexcept;
            [[nodiscard]] BColor getColor() const noexcept;
            [[nodiscard]] Vector<int> getPos() const noexcept;

        //setter
            void setPos(const Vector<int> &pos) noexcept;
            void setColor(const BColor &color) noexcept;

            //trhrow runtime error if img is not load
            void loadFromImg(const BImage &img);

            void loadFromFile(const std::string &filepath);
            void unload() noexcept;

        //draw
            void draw() const noexcept;
            void drawRect(const BRectangle &rect, Vector<float> pos) const noexcept;

        private:
            Texture2D _texture;
            Vector<int> _pos{0, 0};
            BColor _color{WHITE};

        private:
            void resetObj() noexcept;
        };

    } // namespace encapsulation

} // namespace gameEngine


#endif /* !BTEXTURE2D_HPP_ */
