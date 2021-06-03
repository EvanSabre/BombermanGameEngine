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
            if (!i || !j || i == SIZE_X - 1 || j == SIZE_Y - 1 ||
                (EVEN(i) && EVEN(j)))
                _map[i][j] = MAPWALL; // border_walls + middle_walls
            else if (!(std::rand() % (_size / 2)) ||
                SPAWN1 || SPAWN2 || SPAWN3 || SPAWN4)
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
    std::string obj("./resources/models/cube.obj");
    // Tile path("./resources/models/cube.obj", "./resources/models/cube_diffuse.png", {0, 0, 0}, WHITE, 1, Tile::TileType::PATH);
    // Tile wall("./resources/models/cube.obj", "./resources/models/cube_diffuse.png", {0, 0, 0}, WHITE, 1, Tile::TileType::WALL);
    // Tile brck("./resources/models/cube.obj", "./resources/models/cube_diffuse.png", {0, 0, 0}, WHITE, 1, Tile::TileType::BRICK);

    // _tiles.push_back(std::make_unique<Tile>(obj, png, {0, 0, 0}, WHITE, 1, Tile::TileType::PATH));
    // _tiles.push_back(std::make_unique<Tile>(wall));
    // _tiles.push_back(std::make_unique<Tile>(brck));
    _path = std::make_unique<Tile>(obj, PATHTILEPNG, (Vector3T<float>){0, 0, 0}, WHITE, 0.321, Tile::TileType::PATH);
    _wall = std::make_unique<Tile>(obj, WALLTILEPNG, (Vector3T<float>){0, 0, 0}, WHITE, 0.321, Tile::TileType::WALL);
    _brick = std::make_unique<Tile>(obj, BRICKTILEPNG, (Vector3T<float>){0, 0, 0}, WHITE, 0.321, Tile::TileType::BRICK);
}

void Map::draw()
{
    for (std::size_t i = 0; i < SIZE_X; i++) {
        for (std::size_t j = 0; j < SIZE_Y; j++) {
            if (_map[i][j] == MAPPATH) {
                // for (auto &it : _tiles)
                //     if (it->getType() == Tile::TileType::PATH) {
                //         it->getModel().setPosition({i, 0, j});
                //         it->getModel().draw();
                //     }
                _path->getModel().setPosition({i, 0, j});
                _path->getModel().draw();
            }
             else if (_map[i][j] == MAPWALL) {
                // for (auto &it : _tiles)
                //     if (it->getType() == Tile::TileType::WALL) {
                //         it->getModel().setPosition({i, 1, j});
                //         it->getModel().draw();
                //     }
                _wall->getModel().setPosition({i, 1, j});
                _wall->getModel().draw();
            } else if (_map[i][j] == MAPBRICK) {
                // for (auto &it : _tiles)
                //     if (it->getType() == Tile::TileType::BRICK) {
                //         it->getModel().setPosition({i, 1, j});
                //         it->getModel().draw();
                //     }
                _brick->getModel().setPosition({i, 1, j});
                _brick->getModel().draw();
            }
        }
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
    _size = (size < 5) ? 5 : size + 1 - size % 2;
}

void Map::setSeed(const std::size_t &seed)
{
    _seed = seed;
}
