/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** Tile
*/

#ifndef TILE_HPP_
#define TILE_HPP_

#include "GameObject.hpp"
#include "BTexture2D.hpp"
#include "BModel.hpp"
#include "Vector3T.hpp"

using namespace gameEngine::encapsulation;

namespace game::objects {
    class Tile : public GameObject {
        public:
            enum TileType {
                NONE,
                WALL,
                PATH,
                BRICK,
                COLLECTIBLE,
            };

            Tile(const std::string &modelfilepath = "",
                 const std::string &texturefilepath = "",
                 const Vector3T<float> &pos = {0, 0, 0},
                 const BColor &color = WHITE,
                 const float &scale = 1,
                 const TileType &type = NONE);
            Tile(const Tile &);
            ~Tile();

            // member functions
            void createTile(const std::string &,
                            const std::string &,
                            const Vector3T<float> &,
                            const BColor &,
                            const float &,
                            const TileType &);

            // getters
            BTexture2D getTexture() const;
            BModel &getModel();
            TileType getType() const;
            Vector3T<float> getPos() const;

            // setters
            void setTexture(const BTexture2D &);
            void setModel(const BModel &);
            void setType(const TileType &);
            void setPos(const Vector3T<float> &);

        protected:
            BModel _model;
            BTexture2D _texture;
            TileType _type;
            Vector3T<float> _pos;
        private:
    };
}

#endif /* !TILE_HPP_ */
