/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** Tile
*/

#ifndef TILE_HPP_
#define TILE_HPP_

#include "AGameObject.hpp"
#include "BTexture2D.hpp"
#include "BModel.hpp"
#include "Vector3T.hpp"
#include "Tags.hpp"

using namespace gameEngine::encapsulation;
using namespace gameEngine::objects;

namespace game::objects {
    class Tile : public AGameObject {
        public:
            // Ctor 1
            Tile(const std::string &modelfilepath = "",
                 const std::string &texturefilepath = "",
                 const Vector3T<float> &pos = {0, 0, 0},
                 const Vector3T<float> &scale = {1, 1, 1},
                 const Vector3T<float> &rotation = {0, 0, 0},
                 const BColor &color = WHITE,
                 const game::Tag &type = NONE);
            // Ctor 2
            Tile(const std::shared_ptr<BModel> &model,
                 const std::shared_ptr<BTexture2D> &texture,
                 const Vector3T<float> &pos = {0, 0, 0},
                 const Vector3T<float> &scale = {1, 1, 1},
                 const Vector3T<float> &rotation = {0, 0, 0},
                 const game::Tag &type = NONE);
            // copy Ctor
            Tile(const Tile &);
            // Dtor
            ~Tile();

            // member functions
            void OnCollisionEnter(const AGameObject &collision);
            void OnCollisionExit(const AGameObject &collision);
            void Update();
            void draw();

            // getters
            BTexture2D getTexture() const;
            BModel &getModel();
            game::Tag getType() const;

            // setters
            void setTexture(const BTexture2D &);
            void setModel(const BModel &);
            void setType(const game::Tag &);

        protected:
            std::shared_ptr<BModel> _model;
            std::shared_ptr<BTexture2D> _texture;
            game::Tag _type;
        private:
    };
}

#endif /* !TILE_HPP_ */
