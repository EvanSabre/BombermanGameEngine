/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** render Gui
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

void Gui::draw(int charac, corner_e corner)
{
    switch (corner)
    {
    case Gui::TOP_LEFT:
        draw(charac, {0, 30});
        break;
    case Gui::TOP_RIGHT:
        draw(charac, {1600, 30});
        break;
    case Gui::BOTTOM_LEFT:
        draw(charac, {0, 1000});
        break;
    case Gui::BOTTOM_RIGHT:
        draw(charac, {100, 1000});
        break;
    default:
        draw(charac, {0, 0});
        break;
    }
}

void Gui::draw(int charac, const Vector<float> &basePose)
{
    _heartTexture->setPos({basePose._x - 12, basePose._y});
    _bombTexture->setPos({basePose._x, basePose._y + 40});
    drawElt(charac, _heartTexture, Vector<float>(0.05, 0.05), 50);
    drawElt(charac, _bombTexture, Vector<float>(0.1, 0.1));
}

void Gui::draw(const game::objects::Character &charac)
{
    _heartTexture->setPos({0, 0});
    _bombTexture->setPos({0, 0});
    drawElt(charac.getLives(), _heartTexture, Vector<float>(0.05, 0.05), 50);
    drawElt(charac.getNbBomb(), _bombTexture, Vector<float>(0.1, 0.1));
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
