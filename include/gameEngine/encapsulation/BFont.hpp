/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BFont
*/

#ifndef BFONT_HPP_
#define BFONT_HPP_

#include "Vector.hpp"
#include "BColor.hpp"
#include "raylib.h"
#include <memory>

namespace gameEngine
{
    namespace encapsulation
    {
        class BFont
        {
        public:
            BFont();
            BFont(const BFont &ref);
            BFont &operator=(const BFont &ref);
            ~BFont();

        //getter
            [[nodiscard]] Font getObj() const noexcept;
            [[nodiscard]] bool isLoad() const noexcept;

        //setter
            //trhrow runtime error if img is not load
            //void loadFromImg(const BImage &img);

            void loadFromFile(const std::string &filepath);
            void unload() noexcept;


        private:
            std::unique_ptr<Font> _font;
            std::string _filepath;

        private:
            void resetObj() noexcept;
        };

    } // namespace encapsulation

} // namespace gameEngine


#endif /* !BFONT_HPP_ */
