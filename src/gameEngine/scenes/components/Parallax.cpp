/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** Parallax
*/

#include "Parallax.hpp"

using namespace gameEngine::scenes;

#define SCALE 2

Parallax::Parallax()
{
    scrollingBack = 0;
    scrollingMid = 0;
    scrollingFront = 0;
}

Parallax::~Parallax()
{
}

void Parallax::initParallax(const std::string &backPath, const std::string &midPath, const std::string &forePath)
{
    _background = std::make_shared<gameEngine::encapsulation::BTexture2D>(backPath);
    _midground = std::make_shared<gameEngine::encapsulation::BTexture2D>(midPath);
    _foreground = std::make_shared<gameEngine::encapsulation::BTexture2D>(forePath);
}

void Parallax::calculateParallax(float back, float mid, float fore)
{
    scrollingBack -= back;
    scrollingMid -= mid;
    scrollingFront -= fore;
    if (scrollingBack <= -_background->getSize()._x * 2)
        scrollingBack = 0;
    if (scrollingMid <= -_midground->getSize()._x * 2)
        scrollingMid = 0;
    if (scrollingFront <= -_foreground->getSize()._x * 2)
        scrollingFront = 0;

    _background->setPos({scrollingBack, 0});
    _midground->setPos({scrollingMid, 0});
    _foreground->setPos({scrollingFront, 70});
}

void Parallax::drawParallax()
{

    _background->drawEx(SCALE);
    _background->setPos({_background->getSize()._x * 2 + scrollingBack, 0});
    _background->drawEx(SCALE);
    _background->setPos({scrollingBack, 20});

    _midground->drawEx(SCALE);
    _midground->setPos({_midground->getSize()._x * 2 + scrollingMid, 0});
    _midground->drawEx(SCALE);
    _midground->setPos({scrollingMid, 20});

    _foreground->drawEx(SCALE);
    _foreground->setPos({_foreground->getSize()._x * 2 + scrollingFront, 70});
    _foreground->drawEx(SCALE);
    _foreground->setPos({scrollingFront, 70});
}
