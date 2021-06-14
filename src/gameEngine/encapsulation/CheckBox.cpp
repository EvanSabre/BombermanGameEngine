/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** CheckBox
*/

#include "CheckBox.hpp"

using namespace gameEngine::encapsulation;

CheckBox::CheckBox(const Vector<float> &size,
                    const Vector<float> &pos,
                    const BText &content,
                    bool initState,
                    const BColor &color,
                    const BColor &selectColor,
                    const std::string &textureFile,
                    float rotation, int nbFrames
                )
    : Button(size, pos, content, color, selectColor, textureFile, rotation, nbFrames)
{
    _checkState = initState;
}

CheckBox::~CheckBox()
{
}

CheckBox::CheckBox(const std::shared_ptr<BTexture2D> &text, const std::shared_ptr<BRectangle> &rect, const std::shared_ptr<BText> &content)
    : Button(text, rect, content)
{
}


//getter

bool CheckBox::getState() const noexcept
{
    return _checkState;
}

void CheckBox::draw() noexcept
{
    if (_checkState)
        (*_content).setColor(GREEN);
    else
        (*_content).setColor(RED);
    this->Button::drawButton();
}