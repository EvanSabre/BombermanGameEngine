/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** Tile
*/

#include "Tile.hpp"

game::objects::Tile::Tile(const std::string &modelfilepath,
                          const std::string &texturefilepath,
                          const Vector3T<float> &pos,
                          const BColor &color,
                          const float &scale,
                          const TileType &type)
    : game::objects::GameObject(),
     _model(std::make_unique<BModel>(modelfilepath, pos, color, scale)),
     _texture(std::make_unique<BTexture2D>(texturefilepath)),
     _type(type),
     _pos(pos)
{
    _model->setTexture(0, MATERIAL_MAP_DIFFUSE, *_texture);
}

game::objects::Tile::Tile(const std::shared_ptr<BModel> &mod,
                          const std::shared_ptr<BTexture2D> &tex,
                          const TileType &type,
                          const Vector3T<float> &pos)
    : game::objects::GameObject(),
     _model(mod),
     _texture(tex),
     _type(type),
     _pos(pos)
{
    _model->setTexture(0, MATERIAL_MAP_DIFFUSE, *_texture);
}

game::objects::Tile::Tile(const Tile &tile)
    : _model(tile._model),
      _texture(tile._texture),
      _type(tile._type),
      _pos(tile._pos)
{
}

game::objects::Tile::~Tile()
{
}

// member functions
game::objects::Tile &game::objects::Tile::operator=(game::objects::Tile &tile)
{
    setTexture(*tile._texture);
    setModel(*tile._model);
    setType(tile._type);
    setPos(tile._pos);
    return *this;
}

void game::objects::Tile::createTile(const std::string &modelfilepath,
                                     const std::string &texturefilepath,
                                     const Vector3T<float> &pos,
                                     const BColor &color,
                                     const float &scale,
                                     const TileType &type)
{
    BModel model(modelfilepath, pos, color, scale);
    BTexture2D texture(texturefilepath);

    setTexture(texture);
    setModel(model);
    setType(type);
    setPos(pos);
}

void game::objects::Tile::draw()
{
    _model->setPosition(_pos);
    _model->draw();
}

// getters
BTexture2D game::objects::Tile::getTexture() const
{
    return *_texture;
}

BModel &game::objects::Tile::getModel()
{
    return *_model;
}

game::objects::Tile::TileType game::objects::Tile::getType() const
{
    return _type;
}

Vector3T<float> game::objects::Tile::getPos() const
{
    return _pos;
}

// setters
void game::objects::Tile::setTexture(const BTexture2D &texture)
{
    *_texture = texture;
}

void game::objects::Tile::setModel(const BModel &model)
{
    *_model = model;
}

void game::objects::Tile::setType(const TileType &type)
{
    _type = type;
}

void game::objects::Tile::setPos(const Vector3T<float> &pos)
{
    _pos = pos;
}
