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
                                : ADrawable()
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
    this->_position = pos;
    this->_scale = scale;
    this->_filePath = filepath;
}

encapsulation::BModel::~BModel()
{
    if (isLoad())
        this->unload();
}

encapsulation::BModel::BModel(const encapsulation::BModel &ref)
{
    this->resetObj();
    try {
        this->load(ref.getFilePath());
    } catch (const std::exception &e) {
        throw e;
    }
    this->_color = ref.getColor();
    this->_position = ref.getPosition();
    this->_scale = ref.getScale();
}

encapsulation::BModel &encapsulation::BModel::BModel::operator=(const encapsulation::BModel &ref)
{
    if (this == &ref)
        return *this;
    if (this->isLoad())
        this->unload();
    try {
        this->load(ref.getFilePath());
    } catch (const std::exception &e) {
        throw e;
    }
    this->_color = ref.getColor();
    this->_position = ref.getPosition();
    this->_scale = ref.getScale();
    return *this;
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

std::string encapsulation::BModel::getFilePath() const noexcept
{
    return this->_filePath;
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

void encapsulation::BModel::setTexture(int material_idx, int maps_idx,
                const BTexture2D &texture) noexcept
{
    _model.materials[material_idx].maps[maps_idx].texture = texture.getObj();              // Set map diffuse texture
}
//-------------------------

//DRAW

void encapsulation::BModel::draw() const noexcept
{
    Vector3 vec = {_position._x , _position._y, _position._z};

    DrawModel(this->_model, vec, _scale, _color.getObj());
}

//---------------------

//PRIVATE FUNCTION

void encapsulation::BModel::resetObj() noexcept
{
    this->_model.materials = nullptr;
}
