/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** render Gui
*/

#include "Gui.hpp"

using namespace game;

#define HEART_ICON "./assets/Gui/heart_icon_2.png"
#define BOMB_ICON "./assets/Gui/bomb_icon.png"

Gui::Gui()
{
    _heartTexture = std::make_shared<gameEngine::encapsulation::BTexture2D>();
    _heartTexture->loadFromFile(HEART_ICON);
    _heartTexture->setEnabled(true);

    _bombTexture = std::make_shared<gameEngine::encapsulation::BTexture2D>();
    _bombTexture->loadFromFile(BOMB_ICON);
    _bombTexture->setEnabled(true);

    _text.setTransform()._scale._x = 20;
    _text.setColor(BLACK);
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
        draw(charac, {1750, 60});
        break;
    case Gui::BOTTOM_LEFT:
        draw(charac, {0, 800});
        break;
    case Gui::BOTTOM_RIGHT:
        draw(charac, {1750, 800});
        break;
    default:
        draw(charac, {0, 0});
        std::cout << "default"<< std::endl;
        break;
    }
}

void Gui::draw(const game::objects::Character &charac, const Vector<float> &basePose)
{
    std::cout << "draw gui" << std::endl;
    _heartTexture->setPos(Vector<int>(basePose._x, basePose._y + 80));
    _bombTexture->setPos(Vector<int>(basePose._x, basePose._y + 120));

    drawLabel(charac.getName(), Vector<float>(basePose._x - 20, basePose._y));
    drawLabel(std::string("Score : ") + std::to_string(charac.getScore()), Vector<float>(basePose._x - 20, basePose._y + 40));
    drawElt(charac.getLives(), _heartTexture, Vector<float>(0.05, 0.05), 50);
    drawEltStr(std::to_string(charac.getNbBomb()), _bombTexture, Vector<float>(0.1, 0.1), 50);
    drawLabel(std::string("Spedd: ") + std::to_string((int)(charac.getSpeed()._x * 10)), Vector<float>(basePose._x - 20, basePose._y + 160));
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
    _text.setTransform()._position._x = bufPos._x + spacing;
    _text.setTransform()._position._y = bufPos._y + 15;

    texture->drawEx(scale);
    _text.setStr(str);
    _text.draw();
}

void Gui::drawLabel(const std::string &str, const Vector<float> &pos) noexcept
{
    _text.setTransform()._position._x = pos._x + 30;
    _text.setTransform()._position._y = pos._y + 15;

    _text.setStr(str);
    _text.draw();
}
