/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** Map
*/

#include "Map.hpp"

Map::Map(const std::size_t &size, const std::size_t &seed)
    : _seed(seed)
{
    setSize(size);
    if (!_seed)
        generateSeed();
    generateMap();
    generateMapTiles();
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
            temp.push_back(MAPBRICK);
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
            if (!i || !j || i == SIZE_X - 1 || j == SIZE_Y - 1)
                _map[i][j] = MAPWALL; // border_blocks + middle_walls
            else if (EVEN(i) && EVEN(j))
                _map[i][j] = MAPBORDR; // walls_block + middle_walls
            else if (!(std::rand() % (int)((float)_size / 3.5)) ||
                SPAWN1 || SPAWN2 || SPAWN3 || SPAWN4 || SPAWN5 || SPAWN6)
                _map[i][j] = MAPPATH; // random_path + spawners_path
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

void Map::generateMapTiles()
{
    _brickMod = std::make_shared<gameEngine::encapsulation::BModel>(BLOCKPATHOBJ, Vector3T<float>(0, 0, 0), WHITE, 0.5);
    _wallMod = std::make_shared<gameEngine::encapsulation::BModel>(BLOCKPATHOBJ, Vector3T<float>(0, 0, 0), WHITE, 0.5);
    _pathMod = std::make_shared<gameEngine::encapsulation::BModel>(BLOCKPATHOBJ, Vector3T<float>(0, 0, 0), WHITE, 0.5);
    _borderMod = std::make_shared<gameEngine::encapsulation::BModel>(BLOCKPATHOBJ, Vector3T<float>(0, 0, 0), WHITE, 0.5);
    _brickTex = std::make_shared<gameEngine::encapsulation::BTexture2D>(BRICKTILEPNG);
    _wallTex = std::make_shared<gameEngine::encapsulation::BTexture2D>(WALLTILEPNG);
    _pathTex = std::make_shared<gameEngine::encapsulation::BTexture2D>(PATHTILEPNG);
    _borderTex = std::make_shared<gameEngine::encapsulation::BTexture2D>(BORDERTILEPNG);

    for (std::size_t i = 0; i < SIZE_X; i++) {
        for (std::size_t j = 0; j < SIZE_Y; j++) {
            _tiledMap.push_back(Tile(_pathMod, _pathTex, PATH, Vector3T<float>((float)i, 0, (float)j)));
            if (_map[i][j] == MAPBRICK)
                _tiledMap.push_back(Tile(_brickMod, _brickTex, BRICK, Vector3T<float>((float)i, 1, (float)j)));
            else if (_map[i][j] == MAPWALL)
                _tiledMap.push_back(Tile(_wallMod, _wallTex, WALL, Vector3T<float>((float)i, 1, (float)j)));
            else if (_map[i][j] == MAPBORDR)
                _tiledMap.push_back(Tile(_borderMod, _borderTex, BORDER, Vector3T<float>((float)i, 1, (float)j)));
        }
    }
}

void Map::draw()
{
    for (auto &it : _tiledMap) {
        it.draw();
    }
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
    _size = (size < 9) ? 9 : size + 1 - size % 2;
}

void Map::setSeed(const std::size_t &seed)
{
    _seed = seed;
}
