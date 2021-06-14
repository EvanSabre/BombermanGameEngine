/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** ADrawable
*/

#include "ADrawable.hpp"

using namespace gameEngine;

encapsulation::ADrawable::ADrawable()
    : gameEngine::objects::AGameObject("")
{
}

encapsulation::ADrawable::~ADrawable()
{
}

//-----------------------

//MEMBER FUNCTIONS

void gameEngine::encapsulation::ADrawable::OnCollisionEnter(const AGameObject &collision)
{
}

void gameEngine::encapsulation::ADrawable::OnCollisionExit(const AGameObject &collision)
{
}

void gameEngine::encapsulation::ADrawable::Update()
{
}

//GETTER

gameEngine::encapsulation::BColor encapsulation::ADrawable::getColor() const noexcept
{
    return this->_color;
}

//---------------------
//SETTER

void encapsulation::ADrawable::setColor(const gameEngine::encapsulation::BColor &color) noexcept
{
    this->_color = color;
}

//-----------------------
//DRAW
void encapsulation::ADrawable::draw() const noexcept
{
}
