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
#include "Vector3T.hpp"
#include "BTexture2D.hpp"

namespace gameEngine
{
    namespace encapsulation
    {
        class BModel
        {
        public:
            BModel(const std::string &filepath,
                    const Vector3T<float> &pos = {0, 0, 0},
                    const BColor &color = BColor{WHITE},
                    float scale = 1
            );
            //BModel(const std::string &filepath, const BMesh &mesh);
            BModel(const BModel &ref);
            BModel &operator=(const BModel &ref) = delete;
            ~BModel();

            //getter
                [[nodiscard]] Model getObj() const noexcept;
                [[nodiscard]] bool isLoad() const noexcept;
                [[nodiscard]] BColor getColor() const noexcept;
                [[nodiscard]] Vector3T<float> getPos() const noexcept;
                [[nodiscard]] std::string getFilePath() const noexcept;
                [[nodiscard]] float getScale() const noexcept;

            //setter
            // Load Model from file into CPU memory (RAM)
                void load(const std::string &filepath);
                //void loadWithMesh(const std::string &filepath, const BMesh &mesh);

                void unload() noexcept;
                void unloadKeepMesh() noexcept;

                void setPos(const Vector3T<float> &pos) noexcept;
                void setColor(const BColor &color) noexcept;

                void setTexture(int material_idx, int maps_idx,
                                    const BTexture2D &texture) noexcept;

            //draw
                void draw() const noexcept;

        private:
            std::string _filePath;
            Model _model;
            BColor _color{WHITE};
            float _scale = 0;
            Vector3T<float> _pos{0, 0, 0};

        private:
            void resetObj() noexcept;
        };
    } // namespace encapsulation

} // namespace gameEngine



#endif /* !MODEL_HPP_ */
