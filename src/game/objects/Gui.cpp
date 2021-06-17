/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Gui
*/

#include "Gui.hpp"

Gui::Gui()
{
    _heartTexture = std::make_shared<gameEngine::encapsulation::BTexture2D>();
    _heartTexture->loadFromFile("./heart_icon.png");
    _heartTexture->setEnabled(true);

    _bombTexture = std::make_shared<gameEngine::encapsulation::BTexture2D>();
    _bombTexture->loadFromFile("./bomb_icon.png");
    _bombTexture->setEnabled(true);
}

Gui::~Gui()
{
}

void Gui::draw()
{
    _heartTexture->setPos({0, 100});
    _bombTexture->setPos({0, 140});
    drawElt(2, _heartTexture, Vector<float>(0.05, 0.05), 50);
    drawElt(2, _bombTexture, Vector<float>(0.1, 0.1));
}

void Gui::drawElt(int nbElt, std::shared_ptr<gameEngine::encapsulation::BTexture2D> texture,
    Vector<float> scale, float spacing) noexcept
{
    Vector<int> bufPos = texture->getPos();
    Vector<float> newPos = {bufPos._x, bufPos._y};

    for (int i = 0; i < nbElt; i++) {
        texture->setPos({newPos._x, newPos._y});
        texture->drawEx(scale);
        newPos._x += spacing;
    }
    texture->setPos(bufPos);
}
