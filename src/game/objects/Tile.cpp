/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** Tile
*/

#include "Tile.hpp"

game::objects::Tile::Tile(
    const std::string &modelfilepath,
    const std::string &texturefilepath,
    game::Tag type,
    const Vector3T<float> &position,
    const Vector3T<float> &scale,
    const Vector3T<float> &rotation,
    const gameEngine::encapsulation::BColor &color)
    : gameEngine::objects::AGameObject(""),
     _model(std::make_unique<gameEngine::encapsulation::BModel>(modelfilepath, position, color)),
     _texture(std::make_unique<gameEngine::encapsulation::BTexture2D>(texturefilepath))
{
    (void)scale;
    _type = type;
    _transform.setPosition(position);
    _transform.setRotation(rotation);
    _model->setTexture(0, MATERIAL_MAP_DIFFUSE, *_texture);
}

game::objects::Tile::Tile(
    const std::shared_ptr<gameEngine::encapsulation::BModel> &model,
    const std::shared_ptr<gameEngine::encapsulation::BTexture2D> &texture,
    game::Tag type,
    const Vector3T<float> &position,
    const Vector3T<float> &scale,
    const Vector3T<float> &rotation)
    : gameEngine::objects::AGameObject(""),
     _model(model),
     _texture(texture)
{
    (void)scale;
    _type = type;
    _transform.setPosition(position);
    _transform.setRotation(rotation);
    _model->setTexture(0, MATERIAL_MAP_DIFFUSE, *_texture);
}

game::objects::Tile::Tile(const Tile &tile)
    : gameEngine::objects::AGameObject(tile),
      _model(tile._model),
      _texture(tile._texture)
{
    _type = tile._type;
}

game::objects::Tile::~Tile()
{
}

void game::objects::Tile::OnCollisionEnter(const AGameObject &collision)
{
}

void game::objects::Tile::OnCollisionExit(const AGameObject &collision)
{
}

void game::objects::Tile::Update()
{
}

void game::objects::Tile::draw()
{
    _model->setPosition(_transform.getPosition());
    _model->draw();
}

// getters
gameEngine::encapsulation::BTexture2D game::objects::Tile::getTexture() const
{
    return *_texture;
}

gameEngine::encapsulation::BModel &game::objects::Tile::getModel()
{
    return *_model;
}

game::Tag game::objects::Tile::getType() const
{
    return _type;
}

// setters
void game::objects::Tile::setTexture(const gameEngine::encapsulation::BTexture2D &texture)
{
    *_texture = texture;
}

void game::objects::Tile::setModel(const gameEngine::encapsulation::BModel &model)
{
    *_model = model;
}

void game::objects::Tile::setType(const game::Tag &type)
{
    _type = type;
}
