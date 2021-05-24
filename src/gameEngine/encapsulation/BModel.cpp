/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BModel
*/

#include "BModel.hpp"

using namespace gameEngine;

encapsulation::BModel::BModel(const std::string &filepath)
{
    try
    {
        this->load(filepath);
    }
    catch(const std::exception& e)
    {
        throw e;
    }
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
    if (!this->_model.materials)
        return false;
    return true;
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
    this->_model = {0};
}

void encapsulation::BModel::unloadKeepMesh() noexcept
{
    if (!isLoad())
        return;
    UnloadModelKeepMeshes(this->_model);
}

//-------------------------

//DRAW

void encapsulation::BModel::draw(int x, int y, int z, float scale, const BColor &color) const noexcept
{
    Vector3 vec = {x, y, z};

    DrawModel(this->_model, vec, scale, color.getObj());
}



