/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Button
*/

#include "Button.hpp"
using namespace gameEngine;

Button::Button(const std::string &content)
{
    _buttonPressed = false;
    _content = content;
}

Button::~Button()
{
}
