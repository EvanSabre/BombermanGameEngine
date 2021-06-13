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

namespace game::objects {
    class Tile : public gameEngine::objects::AGameObject {
        public:
            // Ctor 1
            Tile(const std::string &modelfilepath = "",
                 const std::string &texturefilepath = "",
                 game::Tag type = NONE,
                 const Vector3T<float> &pos = {0, 0, 0},
                 const Vector3T<float> &scale = {1, 1, 1},
                 const Vector3T<float> &rotation = {0, 0, 0},
                 const gameEngine::encapsulation::BColor &color = WHITE);
            // Ctor 2
            Tile(const std::shared_ptr<gameEngine::encapsulation::BModel> &model,
                 const std::shared_ptr<gameEngine::encapsulation::BTexture2D> &texture,
                 game::Tag type = NONE,
                 const Vector3T<float> &pos = {0, 0, 0},
                 const Vector3T<float> &scale = {1, 1, 1},
                 const Vector3T<float> &rotation = {0, 0, 0});
            // copy Ctor
            Tile(const Tile &);
            // Dtor
            ~Tile();

            // member functions
            void OnCollisionEnter(const gameEngine::objects::AGameObject &collision);
            void OnCollisionExit(const gameEngine::objects::AGameObject &collision);
            void Update();
            void draw();

            // getters
            gameEngine::encapsulation::BTexture2D getTexture() const;
            gameEngine::encapsulation::BModel &getModel();
            game::Tag getType() const;

            // setters
            void setTexture(const gameEngine::encapsulation::BTexture2D &);
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
