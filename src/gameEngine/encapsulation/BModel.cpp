/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BModel
*/

#include "BModel.hpp"

using namespace gameEngine::encapsulation;

BModel::BModel(const std::string &filepath, const Vector3T<float> &pos,
               const BColor &color, const Vector3T<float> &scale)
    : ADrawable()
{
    this->resetObj();
    try
    {
        this->load(filepath);
    }
    catch(const LoadingError &e)
    {
        throw e;
    }
    this->_color = color;
    this->_transform.setPosition(pos);
    this->_transform.setScale(scale);
    this->_filePath = filepath;
}

BModel::~BModel()
{
    if (isLoad())
        this->unload();
}

BModel::BModel(const encapsulation::BModel &ref)
{
    this->resetObj();
    try {
        this->load(ref.getFilePath());
    } catch (const LoadingError &e) {
        throw e;
    }
    this->_color = ref.getColor();
    this->_transform.setPosition(ref._transform.getPosition());
    this->_transform.setRotation(ref._transform.getRotation());
    this->_transform.setScale(ref._transform.getScale());
}

BModel &BModel::BModel::operator=(const encapsulation::BModel &ref)
{
    if (this == &ref)
        return *this;
    if (this->isLoad())
        this->unload();
    try {
        this->load(ref.getFilePath());
    } catch (const LoadingError &e) {
        throw e;
    }
    this->_color = ref.getColor();
    this->_transform.setPosition(ref._transform.getPosition());
    this->_transform.setRotation(ref._transform.getRotation());
    this->_transform.setScale(ref._transform.getScale());
    return *this;
}

void BModel::update()
{
}

//----------------------------

//GETTER

std::string BModel::getContent() const noexcept
{
    return "";
}

Model BModel::getObj() const noexcept
{
    return this->_model;
}

bool BModel::isLoad() const noexcept
{
    if (this->_model.materials == nullptr)
        return false;
    return true;
}

std::string BModel::getFilePath() const noexcept
{
    return this->_filePath;
}

//----------------------------

//SETTER
void BModel::load(const std::string &filepath)
{
    if (isLoad())
        this->unload();
    this->_model = LoadModel(filepath.c_str());
    if (!isLoad())
        throw LoadingError(filepath, "Loading failed : ", "MODEL");
}

void BModel::unload() noexcept
{
    if (!isLoad())
        return;
    UnloadModel(this->_model);
    this->resetObj();
}

void BModel::unloadKeepMesh() noexcept
{
    if (!isLoad())
        return;
    UnloadModelKeepMeshes(this->_model);
}

void BModel::setTexture(int material_idx, int maps_idx,
                const BTexture2D &texture) noexcept
{
    _model.materials[material_idx].maps[maps_idx].texture = texture.getObj();              // Set map diffuse texture
}
//-------------------------

//DRAW

void BModel::rotate()
{
    Vector3T<float> rota(this->_transform.getRotation());
    Vector3 vect = {
        DEG2RAD * rota._x,
        DEG2RAD * rota._y,
        DEG2RAD * rota._z};

    _model.transform = MatrixRotateXYZ(vect);
}

void BModel::draw()
{
    Vector3T<float> pos(this->_transform.getPosition());
    Vector3 vecPos = {pos._x, pos._y, pos._z};
    Vector3T<float> scale(this->_transform.getScale());
    Vector3 vecScale = {scale._x, scale._y, scale._z};

    DrawModel(this->_model, vecPos, scale._x, _color.getObj());
}

//---------------------

//PRIVATE FUNCTION

void BModel::resetObj() noexcept
{
    this->_model.materials = nullptr;
}
