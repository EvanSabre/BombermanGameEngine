/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Model
*/

#ifndef MODEL_HPP_
#define MODEL_HPP_

#include <iostream>
#include <string>
#include <stdexcept>
#include "raylib.h"
#include "BColor.hpp"

namespace gameEngine
{
    namespace encapsulation
    {
        class BModel
        {
        public:
            BModel(const std::string &filepath);
            //BModel(const std::string &filepath, const BMesh &mesh);
            BModel(const BModel &ref) = delete;
            BModel &operator=(const BModel &ref) = delete;
            ~BModel();

            //getter
                [[nodiscard]] Model getObj() const noexcept;
                [[nodiscard]] bool isLoad() const noexcept;

            //setter
            // Load Model from file into CPU memory (RAM)
                void load(const std::string &filepath);
                //void loadWithMesh(const std::string &filepath, const BMesh &mesh);

                void unload() noexcept;
                void unloadKeepMesh() noexcept;

            //draw
                void draw(int x, int y, int z, float scale, const BColor &color) const noexcept;

        protected:
        private:
            Model _model;
        };
    } // namespace encapsulation

} // namespace gameEngine



#endif /* !MODEL_HPP_ */
