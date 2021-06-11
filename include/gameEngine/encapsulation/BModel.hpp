/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Model
*/

#ifndef MODEL_HPP_
#define MODEL_HPP_

#include <string>
#include <stdexcept>
#include <cstring>
#include "raylib.h"
#include "BTexture2D.hpp"

#include "ADrawable.hpp"

namespace gameEngine
{
    namespace encapsulation
    {
        class BModel : public gameEngine::encapsulation::ADrawable
        {
        public:
            BModel(const std::string &filepath,
                    const Vector3T<float> &pos = {0, 0, 0},
                    const BColor &color = BColor{WHITE},
                    const Vector3T<float> &scale = {1, 1, 1}
            );
            //BModel(const std::string &filepath, const BMesh &mesh);
            BModel(const BModel &ref);
            BModel &operator=(const BModel &ref);
            ~BModel();

            //getter
                [[nodiscard]] Model getObj() const noexcept;
                [[nodiscard]] bool isLoad() const noexcept;
                [[nodiscard]] std::string getFilePath() const noexcept;

            //setter
            // Load Model from file into CPU memory (RAM)
                void load(const std::string &filepath);
                //void loadWithMesh(const std::string &filepath, const BMesh &mesh);

                void unload() noexcept;
                void unloadKeepMesh() noexcept;


                void setTexture(int material_idx, int maps_idx,
                                    const BTexture2D &texture) noexcept;

            //draw
                void draw() const noexcept final;

        private:
            std::string _filePath;
            Model _model;

        private:
            void resetObj() noexcept;
        };
    } // namespace encapsulation

} // namespace gameEngine



#endif /* !MODEL_HPP_ */
