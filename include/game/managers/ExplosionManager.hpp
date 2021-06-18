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

namespace game::manager
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
            bool checkTilesExplosion(const game::objects::Tile &);

            // Setters
            void setObjects(
                const std::vector<std::shared_ptr<game::objects::Character>> players,
                const std::vector<std::shared_ptr<game::objects::Tile>> tiles);
            void pushBomb(const std::shared_ptr<game::objects::AExplosif> &bomb);

            // Getters
            std::vector<std::shared_ptr<game::objects::AExplosif>> &getBombs();
            std::vector<std::shared_ptr<game::objects::Tile>> &getTiles();

        protected:
        private:
            std::vector<std::shared_ptr<game::objects::Character>> _players;
            std::vector<std::shared_ptr<game::objects::Tile>> _tiles;
            std::vector<std::shared_ptr<game::objects::AExplosif>> _bombs;
    };
}

#endif /* !EXPLOSIONMANAGER_HPP_ */
