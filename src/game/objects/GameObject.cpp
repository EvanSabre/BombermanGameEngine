/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** GameObject
*/

#include "GameObject.hpp"

game::objects::GameObject::GameObject()
{
}

game::objects::GameObject::~GameObject()
{
}

// getters
std::size_t game::objects::GameObject::getId() const
{
    return _id;
}

// setters
void game::objects::GameObject::setId(const std::size_t &id)
{
    _id = id;
}
