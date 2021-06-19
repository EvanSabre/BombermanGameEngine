/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** ExplosionManager
*/

#ifndef EXPLOSIONMANAGER_HPP_
#define EXPLOSIONMANAGER_HPP_

#include "Bomb.hpp"
#include "Player.hpp"
#include "Animation.hpp"
#include "AudioManager.hpp"

#define MODELEXPLOSION   "assets/All/Models/HealthUp.obj"
#define TEXTUREEXPLOSION "assets/All/Textures/Tile.png"
#define ANIMEXPLOSION    ""

namespace game::managers
{
    class ExplosionManager {
        public:
            ExplosionManager(
                const std::vector<std::shared_ptr<game::objects::Character>> players,
                const std::vector<std::shared_ptr<game::objects::Tile>> tiles);
            ~ExplosionManager();

            // Member functions
            void draw();
            void update();
            void updateExplosionAnimation();
            void explode(const game::objects::AExplosif &);
            bool checkTilesExplosion(const Vector3T<float> &pos);

            // Setters
            void setObjects(
                const std::vector<std::shared_ptr<game::objects::Character>> players,
                const std::vector<std::shared_ptr<game::objects::Tile>> tiles);
            void pushBomb(const std::shared_ptr<game::objects::AExplosif> &bomb);

            // Getters
            std::vector<std::shared_ptr<game::objects::AExplosif>> &getBombs();
            std::vector<std::shared_ptr<game::objects::Tile>> &getTiles();
            std::vector<std::shared_ptr<game::objects::Character>> &getPlayers();

        protected:
            std::shared_ptr<gameEngine::managers::AudioManager> _audio = nullptr;
        private:
            std::vector<std::shared_ptr<game::objects::Character>> _players;
            std::vector<std::shared_ptr<game::objects::Tile>> _tiles;
            std::vector<std::shared_ptr<game::objects::AExplosif>> _bombs;
            std::shared_ptr<gameEngine::encapsulation::BModelAnimation> _anim;
            std::shared_ptr<gameEngine::encapsulation::BModel> _model;
            std::shared_ptr<gameEngine::encapsulation::BTexture2D> _texture;
            std::shared_ptr<gameEngine::Animation> _animRef;
            std::vector<std::unique_ptr<gameEngine::Animation>> _anims;
    };
}

#endif /* !EXPLOSIONMANAGER_HPP_ */
