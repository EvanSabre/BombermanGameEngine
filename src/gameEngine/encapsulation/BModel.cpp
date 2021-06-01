/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BModel
*/

#include "BModel.hpp"

using namespace gameEngine;

encapsulation::BModel::BModel(const std::string &filepath, const Vector3T<float> &pos,
                                const BColor &color, float scale)
{
    this->resetObj();
    try
    {
        this->load(filepath);
    }
    catch(const std::exception& e)
    {
        throw e;
    }
    this->_color = color;
    this->_pos = pos;
    this->_scale = scale;
}

encapsulation::BModel::~BModel()
{
    if (isLoad())
        this->unload();
}

//----------------------------

//GETTER

Model encapsulation::BModel::getObj() const noexcept
{
    return this->_model;
}

bool encapsulation::BModel::isLoad() const noexcept
{
    if (this->_model.materials == nullptr)
        return false;
    return true;
}

encapsulation::BColor encapsulation::BModel::getColor() const noexcept
{
    return this->_color;
}

Vector3T<float> encapsulation::BModel::getPos() const noexcept
{
    return this->_pos;
}

//----------------------------

//SETTER
void encapsulation::BModel::load(const std::string &filepath)
{
    if (isLoad())
        this->unload();
    this->_model = LoadModel(filepath.c_str());
    if (!isLoad())
        throw std::runtime_error("Model : Loading failed");
}

void encapsulation::BModel::unload() noexcept
{
    if (!isLoad())
        return;
    UnloadModel(this->_model);
    this->resetObj();
}

void encapsulation::BModel::unloadKeepMesh() noexcept
{
    if (!isLoad())
        return;
    UnloadModelKeepMeshes(this->_model);
}

void encapsulation::BModel::setPos(const Vector3T<float> &pos) noexcept
{
    this->_pos = pos;
}

void encapsulation::BModel::setColor(const BColor &color) noexcept
{
    this->_color = color;
}

void encapsulation::BModel::setTexture(int material_idx, int maps_idx,
                const BTexture2D &texture) noexcept
{
    _model.materials[material_idx].maps[maps_idx].texture = texture.getObj();              // Set map diffuse texture
}

//-------------------------

//DRAW

void encapsulation::BModel::draw() const noexcept
{
    Vector3 vec = {_pos._x , _pos._y, _pos._z};

    DrawModel(this->_model, vec, _scale, _color.getObj());
}

//---------------------

//PRIVATE FUNCTION

void encapsulation::BModel::resetObj() noexcept
{
    this->_model.materials = nullptr;
}
