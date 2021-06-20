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
#include "PowerUpTile.hpp"
#include "ExplosionAnimation.hpp"

#define EXPLOSIONPATH "assets/All/Models/Explosion.obj"
#define EXPLOSIONTEXT "assets/All/Textures/Tile.png"

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
            void explode(const game::objects::AExplosif &);
            int checkTilesExplosion(const Vector3T<float> &pos, bool first);

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
            std::shared_ptr<gameEngine::encapsulation::BModel> _explosionH;
            std::shared_ptr<gameEngine::encapsulation::BModel> _explosionV;
            gameEngine::encapsulation::BTexture2D _texture;
            std::unordered_map<game::Tag_e, std::shared_ptr<game::objects::PowerUpTile>> _powerUps;
            bool _explode;
            std::vector<std::shared_ptr<game::objects::ExplosionAnimation>> _explosion;
    };
}

#endif /* !EXPLOSIONMANAGER_HPP_ */
