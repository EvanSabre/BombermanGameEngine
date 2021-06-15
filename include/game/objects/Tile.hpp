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

#define TILESIZE  10
#define TILESCALE 0.15f

namespace game::objects {
    class Tile : public gameEngine::objects::AGameObject {
        public:
            // Ctor 1
            Tile(const std::string &modelfilepath = "",
                 const std::string &texturefilepath = "",
                 const game::Tag &type = NONE,
                 const Vector3T<float> &position = {0, 0, 0},
                 const Vector3T<float> &rotation = {0, 0, 0},
                 const Vector3T<float> &scale = {1, 1, 1},
                 const gameEngine::encapsulation::BColor &color = WHITE);
            // Ctor 2
            Tile(const std::shared_ptr<gameEngine::encapsulation::BModel> &model,
                 const std::shared_ptr<gameEngine::encapsulation::BTexture2D> &texture,
                 const game::Tag &type = NONE,
                 const Vector3T<float> &position = {0, 0, 0},
                 const Vector3T<float> &rotation = {0, 0, 0},
                 const Vector3T<float> &scale = {1, 1, 1});
            // copy Ctor
            Tile(const Tile &);
            // Dtor
            ~Tile();

            // member functions
            void onCollisionEnter(const gameEngine::objects::AGameObject &collision);
            void onCollisionExit(const gameEngine::objects::AGameObject &collision);
            void update();
            game::Tag_e getTag() const noexcept override;

            void draw();

            // getters
            gameEngine::encapsulation::BTexture2D getTexture() const;
            gameEngine::encapsulation::BModel &getModel();
            game::Tag getType() const;

            // setters
            void setModel(const gameEngine::encapsulation::BModel &);
            void setType(const game::Tag &);

        protected:
            std::shared_ptr<gameEngine::encapsulation::BModel> _model;
            std::shared_ptr<gameEngine::encapsulation::BTexture2D> _texture;
            game::Tag _type;
        private:
    };
}

#endif /* !TILE_HPP_ */
