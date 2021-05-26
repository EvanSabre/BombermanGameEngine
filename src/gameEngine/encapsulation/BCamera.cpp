/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BCamera
*/

#include "BCamera.hpp"

using namespace gameEngine;

encapsulation::BCamera::BCamera()
{
}

encapsulation::BCamera::BCamera(const BCamera &ref)
{
    this->_camera = ref.getObj();
}

encapsulation::BCamera &encapsulation::BCamera::operator=(const BCamera &ref)
{
    if (this == &ref)
        return *this;
    this->_camera = ref.getObj();
    return *this;
}

encapsulation::BCamera::~BCamera()
{
}

//-----------------

//GETTER

Camera encapsulation::BCamera::getObj() const noexcept
{
    return this->_camera;
}

//------------------

//SETTER

void encapsulation::BCamera::setPosition(const Vector3T<float> &pos) noexcept
{
   Vector3 vec = {pos._x, pos._y, pos._z};

   this->_camera.position = vec;
}

void encapsulation::BCamera::setTarget(const Vector3T<float> &target) noexcept
{
   Vector3 vec = {target._x, target._y, target._z};

   this->_camera.target = vec;
}

void encapsulation::BCamera::setUp(const Vector3T<float> &up) noexcept
{
    Vector3 vec = {up._x, up._y, up._z};

    this->_camera.up = vec;
}

void encapsulation::BCamera::setFovy(float fov) noexcept
{
    this->_camera.fovy = fov;
}

void encapsulation::BCamera::setProjection(CameraProjection projection) noexcept
{
    this->_camera.projection = projection;
}

void encapsulation::BCamera::update() noexcept
{
    UpdateCamera(&this->_camera);
}

void encapsulation::BCamera::setMode(CameraMode mode) noexcept
{
    SetCameraMode(this->_camera, mode);
}

//----------------------------

//DRAW

void encapsulation::BCamera::beginMode()
{
    BeginMode3D(this->_camera);
}

void encapsulation::BCamera::endMode()
{
    EndMode3D();
}
