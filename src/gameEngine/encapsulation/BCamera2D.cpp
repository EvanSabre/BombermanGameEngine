/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BCamera2D
*/

#include "BCamera2D.hpp"

using namespace gameEngine;

encapsulation::BCamera2D::BCamera2D()
{
    this->resetObj();
}

encapsulation::BCamera2D::~BCamera2D()
{
}

encapsulation::BCamera2D::BCamera2D(const BCamera2D &ref)
{
    this->_camera = ref.getObj();
}

encapsulation::BCamera2D &encapsulation::BCamera2D::operator=(const BCamera2D &ref)
{
    if (this == &ref)
        return *this;
    this->_camera = ref.getObj();
    return *this;
}

//--------------------------

//GETTER

Camera2D encapsulation::BCamera2D::getObj() const noexcept
{
    return this->_camera;
}

Vector<float> encapsulation::BCamera2D::getOffset() const noexcept
{
    Vector<float> vec{_camera.offset.x, _camera.offset.y};
    return vec;
}

Vector<float> encapsulation::BCamera2D::getTarget() const noexcept
{
    Vector<float> vec{_camera.target.x, _camera.target.y};
    return vec;
}

float encapsulation::BCamera2D::getRotation() const noexcept
{
    return _camera.rotation;
}

float encapsulation::BCamera2D::getZoom() const noexcept
{
    return _camera.zoom;
}

//---------------------------

//SETTER

void encapsulation::BCamera2D::setOffset(const Vector<float> &offset) noexcept
{
    Vector2 vec = {offset._x, offset._y};
    _camera.offset = vec;
}

void encapsulation::BCamera2D::setTarget(const Vector<float> &target) noexcept
{
    Vector2 vec = {target._x, target._y};
    _camera.target = vec;
}

void encapsulation::BCamera2D::setRotation(float rotation) noexcept
{
    _camera.rotation = rotation;
}

void encapsulation::BCamera2D::rotateLeft(float value) noexcept
{
    _camera.rotation -= value;
}

void encapsulation::BCamera2D::rotateRight(float value) noexcept
{
    _camera.rotation += value;
}

void encapsulation::BCamera2D::setZoom(float zoom) noexcept
{
    _camera.zoom = zoom;
}

void encapsulation::BCamera2D::unzoom(float value) noexcept
{
    _camera.zoom -= value;
}

void encapsulation::BCamera2D::zoom(float value) noexcept
{
    _camera.zoom += value;
}

void encapsulation::BCamera2D::resetObj() noexcept
{
    _camera.target = {0, 0};
    _camera.offset = {0, 0};
    _camera.zoom = 1.0f;
    _camera.rotation = 0.0f;
}

//--------------------

//DRAW

void encapsulation::BCamera2D::beginMode() const noexcept
{
    BeginMode2D(_camera);
}

void encapsulation::BCamera2D::endMode() const noexcept
{
    EndMode2D();
}
