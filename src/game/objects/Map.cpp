/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** Map
*/

#include "Map.hpp"

Map::Map(const std::string &universe,
         const std::size_t &size,
         const std::size_t &seed)
    : _seed(seed), _universe(universe)
{
    std::cout << "UNIVERSE = " << _universe << std::endl;
    _BORDERPATHMOD = "assets/" + _universe + "/Models/Border.obj";
    _BORDERTILEPNG = "assets/" + _universe + "/Textures/Tile.png";
    _BRICKPATHMOD = "assets/" + _universe + "/Models/Brick.obj";
    _BRICKTILEPNG = "assets/" + _universe + "/Textures/Tile.png";
    _WALLPATHMOD = "assets/" + _universe + "/Models/Wall.obj";
    _WALLTILEPNG = "assets/" + _universe + "/Textures/Tile.png";
    _PATHPATHMOD = "assets/" + _universe + "/Models/Ground.obj";
    _PATHTILEPNG = "assets/" + _universe + "/Textures/Tile.png";
    // _PATHTILEPNG = "./resources/models/minecraft/blocks/Grass.png";
    // _PATHPATHMOD = "./resources/models/minecraft/blocks/cube.obj";

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
                _map[i][j] = MAPBORDR; // border_blocks + middle_walls
            else if (EVEN(i) && EVEN(j))
                _map[i][j] = MAPWALL; // walls_block + middle_walls
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
    _brickMod = std::make_shared<gameEngine::encapsulation::BModel>(_BRICKPATHMOD, Vector3T<float>(0, 0, 0), WHITE, Vector3T<float>(0.5, 0.5, 0.5));
    _wallMod = std::make_shared<gameEngine::encapsulation::BModel>(_WALLPATHMOD, Vector3T<float>(0, 0, 0), WHITE, Vector3T<float>(0.5, 0.5, 0.5));
    _pathMod = std::make_shared<gameEngine::encapsulation::BModel>(_PATHPATHMOD, Vector3T<float>(0, 0, 0), WHITE, Vector3T<float>(0.5, 0.5, 0.5));
    _borderMod = std::make_shared<gameEngine::encapsulation::BModel>(_BORDERPATHMOD, Vector3T<float>(0, 0, 0), WHITE, Vector3T<float>(0.5, 0.5, 0.5));
    _brickTex = std::make_shared<gameEngine::encapsulation::BTexture2D>(_BRICKTILEPNG);
    _wallTex = std::make_shared<gameEngine::encapsulation::BTexture2D>(_WALLTILEPNG);
    _pathTex = std::make_shared<gameEngine::encapsulation::BTexture2D>(_PATHTILEPNG);
    _borderTex = std::make_shared<gameEngine::encapsulation::BTexture2D>(_BORDERTILEPNG);

    _tiledMap.push_back(Tile(_pathMod, _pathTex, PATH,
        Vector3T<float>(TILESIZE * SIZE_X / 2, (-1.5) * TILESIZE, TILESIZE * SIZE_Y / 2)));
    for (std::size_t i = 0; i < SIZE_X; i++) {
        for (std::size_t j = 0; j < SIZE_Y; j++) {
            if (_map[i][j] == MAPBRICK)
                _tiledMap.push_back(Tile(_brickMod, _brickTex, BRICK,
                Vector3T<float>((float)i * TILESIZE, 1 * TILESIZE, (float)j * TILESIZE),
                Vector3T<float>(0, 0, 0),
                Vector3T<float>(0.5 * TILESIZE, 0.5 * TILESIZE, 0.5 * TILESIZE)));
            else if (_map[i][j] == MAPWALL)
                _tiledMap.push_back(Tile(_wallMod, _wallTex, WALL,
                Vector3T<float>((float)i * TILESIZE, 1 * TILESIZE, (float)j * TILESIZE),
                Vector3T<float>(0, 0, 0),
                Vector3T<float>(0.5 * TILESIZE, 0.5 * TILESIZE, 0.5 * TILESIZE)));
            else if (_map[i][j] == MAPBORDR)
                _tiledMap.push_back(Tile(_borderMod, _borderTex, BORDER,
                Vector3T<float>((float)i * TILESIZE, 1 * TILESIZE, (float)j * TILESIZE),
                Vector3T<float>(0, 0, 0),
                Vector3T<float>(0.5 * TILESIZE, 0.5 * TILESIZE, 0.5 * TILESIZE)));
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

std::vector<Tile> Map::getTiledMap() const
{
    return _tiledMap;
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
