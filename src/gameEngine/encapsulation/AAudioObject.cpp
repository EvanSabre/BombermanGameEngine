/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** AAudioObject
*/

#include "AAudioObject.hpp"

using namespace gameEngine;

encapsulation::AAudioObject::AAudioObject()
{
}

encapsulation::AAudioObject::~AAudioObject()
{
}

//max is
float encapsulation::AAudioObject::getVolume() const noexcept
{
    return this->_volume;
}

void encapsulation::AAudioObject::setVolume(float volume)
{
    this->_volume = volume;
}

//---------------------

void encapsulation::AAudioObject::play()
{}

void encapsulation::AAudioObject::stop()
{}

void encapsulation::AAudioObject::pause()
{}

void encapsulation::AAudioObject::resume()
{}

bool encapsulation::AAudioObject::isPlaying() const
{
    return false;
}

//base is 1.0
float encapsulation::AAudioObject::getPitch() const noexcept
{
    return this->_pitch;
}

void encapsulation::AAudioObject::setPitch(float pitch)
{
    this->_pitch = pitch;
}

