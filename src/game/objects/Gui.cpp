/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** render Gui
*/

#include "Gui.hpp"

using namespace game;

Gui::Gui()
{
    _heartTexture = std::make_shared<gameEngine::encapsulation::BTexture2D>();
    _heartTexture->loadFromFile("./heart_icon.png");
    _heartTexture->setEnabled(true);

    _bombTexture = std::make_shared<gameEngine::encapsulation::BTexture2D>();
    _bombTexture->loadFromFile("./bomb_icon.png");
    _bombTexture->setEnabled(true);

    _text.setTransform()._scale = Vector3T<float>(10, 3, 3);

}

Gui::~Gui()
{
}

void Gui::draw(const game::objects::Character &charac, corner_e corner)
{
    switch (corner)
    {
    case Gui::TOP_LEFT:
        draw(charac, {0, 60});
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

void Gui::draw(const game::objects::Character &charac, const Vector<float> &basePose)
{
    _heartTexture->setPos(Vector<int>(basePose._x - 12, basePose._y));
    _bombTexture->setPos(Vector<int>(basePose._x, basePose._y + 40));
    drawEltStr(std::to_string(charac.getLives()), _heartTexture, Vector<float>(0.05, 0.05), 50);
    drawElt(charac.getNbBomb(), _bombTexture, Vector<float>(0.1, 0.1));
}

void Gui::drawElt(int nbElt, std::shared_ptr<gameEngine::encapsulation::BTexture2D> texture,
    Vector<float> scale, float spacing) noexcept
{
    Vector<int> bufPos = texture->getPos();
    Vector<float> newPos(bufPos._x, bufPos._y);

    for (int i = 0; i < nbElt; i++) {
        texture->setPos(Vector<int>(newPos._x, newPos._y));
        texture->drawEx(scale);
        newPos._x += spacing;
    }
    texture->setPos(bufPos);
}

void Gui::drawEltStr(const std::string &str, std::shared_ptr<gameEngine::encapsulation::BTexture2D> texture,
            Vector<float> scale, float spacing) noexcept
{
    Vector<int> bufPos = texture->getPos();
    _text.setTransform()._position._x = bufPos._x + 30;
    _text.setTransform()._position._y = bufPos._y + 15;

    texture->drawEx(scale);
    _text.setStr(str);
    _text.setColor(BLACK);
    _text.draw();
}