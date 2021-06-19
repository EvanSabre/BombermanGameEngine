/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#define MAPPATH  0
#define MAPBORDR 1
#define MAPBRICK 2
#define MAPWALL  3



#define MINSIZE 5
#define SIZE_X  (_size)
#define SIZE_Y  (_size + 2)
#define EVEN(a) !(a % 2)
#define ODD(a)  (a % 2)
#define SPAWN1  ((i == 1 || i == 2 || i == 3 || i == SIZE_X - 2 || i == SIZE_X - 3 || i == SIZE_X - 4) && j == 1)
#define SPAWN2  ((i == 1 || i == SIZE_X - 2) && j == 2)
#define SPAWN3  ((i == 1 || i == SIZE_X - 2) && j == 3)
#define SPAWN4  ((i == 1 || i == SIZE_X - 2) && j == SIZE_Y - 3)
#define SPAWN5  ((i == 1 || i == SIZE_X - 2) && j == SIZE_Y - 4)
#define SPAWN6  ((i == 1 || i == 2 || i == 3 || i == SIZE_X - 2 || i == SIZE_X - 3 || i == SIZE_X - 4) && j == SIZE_Y - 2)

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <memory>
#include "Tile.hpp"

using namespace game::objects;

namespace game::objects {
    class Map {
        public:
            Map(const std::string &, const std::size_t &, const std::size_t &seed = 0);
            ~Map();

            // memeber functions
            void generateSeed();
            void generateMap();
            void generateTales();
            void generateMapTiles();
            void newMap();
            void dump();
            void draw();

            // getters
            std::size_t getSize() const;
            std::size_t getSeed() const;
            std::vector<std::vector<int>> getMap() const;
            std::vector<Tile> getTiledMap() const;

            // setters
            void setSize(const std::size_t &);
            void setSeed(const std::size_t &);

        protected:
        private:
            std::vector<std::vector<int>> _map;
            std::size_t _size;
            std::size_t _seed;
            std::vector<Tile> _tiledMap;

            std::string _universe;
            std::string _WALLPATHMOD;
            std::string _BRICKPATHMOD;
            std::string _PATHPATHMOD;
            std::string _BORDERPATHMOD;
            std::string _WALLTILEPNG;
            std::string _BRICKTILEPNG;
            std::string _PATHTILEPNG;
            std::string _BORDERTILEPNG;

            std::shared_ptr<gameEngine::encapsulation::BModel> _brickMod;
            std::shared_ptr<gameEngine::encapsulation::BModel> _wallMod;
            std::shared_ptr<gameEngine::encapsulation::BModel> _pathMod;
            std::shared_ptr<gameEngine::encapsulation::BModel> _borderMod;
            std::shared_ptr<gameEngine::encapsulation::BTexture2D> _wallTex;
            std::shared_ptr<gameEngine::encapsulation::BTexture2D> _pathTex;
            std::shared_ptr<gameEngine::encapsulation::BTexture2D> _brickTex;
            std::shared_ptr<gameEngine::encapsulation::BTexture2D> _borderTex;
    };
}


#endif /* !MAP_HPP_ */
