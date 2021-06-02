/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** Map
*/

#include "Map.hpp"

Map::Map(const std::size_t &size)
    : _seed(0)
{
    setSize(size);
    generateSeed();
    generateMap();
}

Map::~Map()
{
}

// memeber functions

void Map::newMap()
{
    std::vector<std::vector<int>> map;

    for (auto &it : _map)
        it.clear();
    _map.clear();
    for (std::size_t i = 0; i < SIZE_X; i++) {
        std::vector<int> temp;
        for (std::size_t j = 0; j < SIZE_Y; j++)
            temp.push_back(2);
        map.push_back(temp);
    }
    _map = map;
}

void Map::generateMap()
{
    std::srand(_seed);

    newMap();
    for (std::size_t i = 0; i < SIZE_X; i++) {
        for (std::size_t j = 0; j < SIZE_Y; j++) {
            if (!i || !j || i == SIZE_X - 1 || j == SIZE_Y - 1 ||
                (ODD(i) && ODD(j)))
                _map[i][j] = 1; // border_walls + middle_walls
            else if (!(std::rand() % (_size / 2)) ||
                SPAWN1 || SPAWN2 || SPAWN3 || SPAWN4)
                _map[i][j] = 0; // random_path + spawners_path
        }
    }
}

void Map::generateSeed()
{
    std::srand(std::time(nullptr));
    _seed = std::rand();
}

void Map::dump()
{
    std::cout << "size = " << _size << " | seed = " << _seed << std::endl;
    for (auto it : _map) {
        for (auto jt : it)
            std::cout << jt << " ";
        std::cout << std::endl;
    }
}

void Map::generateTales()
{

}

// getters
std::size_t Map::getSize() const
{
    return _size;
}

std::size_t Map::getSeed() const
{
    return _seed;
}

std::vector<std::vector<int>> Map::getMap() const
{
    return _map;
}

// setters
void Map::setSize(const std::size_t &size)
{
    _size = (size < 5) ? 5 : size + 1 - size % 2;
}

void Map::setSeed(const std::size_t &seed)
{
    _seed = seed;
}
