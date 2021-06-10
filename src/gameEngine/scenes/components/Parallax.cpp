/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** Parallax
*/

#include "Parallax.hpp"

using namespace gameEngine::scenes;

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

    _background->setPos({scrollingBack, 20});
    _midground->setPos({scrollingMid, 20});
    _foreground->setPos({scrollingFront, 70});
}

void Parallax::drawParallax()
{

    _background->drawEx(2);
    // _background->setPos({_background->getSize()._x * 2 + scrollingBack, 20});
    // _background->draw();
    // _background->setPos({scrollingBack, 20});

    _midground->drawEx(2);
    // _midground->setPos({_midground->getSize()._x * 2 + scrollingMid, 20});
    // _midground->draw();
    // _midground->setPos({scrollingMid, 20});

    _foreground->drawEx(2);
    // _foreground->setPos({_foreground->getSize()._x * 2 + scrollingFront, 70});
    // _foreground->draw();
    // _foreground->setPos({scrollingFront, 70});
}
