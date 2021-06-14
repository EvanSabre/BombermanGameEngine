/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Button
*/

#include "Button.hpp"

using namespace gameEngine::encapsulation;
using namespace gameEngine;

Button::Button(const Vector<float> &size, const Vector<float> &pos,
                const BText &content, const BColor &color, const BColor &selectColor, const std::string &textureFile,
                float rotation, int nbFrames) : AButton(size, pos, content, color, selectColor, rotation)
{
    _frameRec = std::make_shared<BRectangle>(size, Vector<float>(0, 0), color, rotation);
    _texture = std::make_shared<BTexture2D>();
    if (textureFile != "" && content.getStr() != "") {
        _texture->addTextToTexture(content, textureFile);
    } else if (textureFile != "")
        _texture->loadFromFile(textureFile);
    _nbFrames = nbFrames;
    _buttonPressed = false;
}

Button::Button(const std::shared_ptr<BTexture2D> &text, const std::shared_ptr<BRectangle> &rect, const std::shared_ptr<BText> &content)
: AButton(rect, content)
{
    _texture = text;
    _rectangle = rect;
    _content = content;
    _frameRec = std::make_shared<BRectangle>(*rect);
    _frameRec->setRectPosition(Vector<float>(0, 0));
    _state = NORMAL;
    _nbFrames = 1;
    _buttonPressed = false;
}

Button::~Button()
{}

Button &Button::operator=(const Button &ref)
{
    if (this == &ref)
        return *this;
    *_content = ref.getContent();
    *_texture = ref.getTexture();
    _nbFrames = ref.getNbFrames();
    _state = ref.getState();
    _buttonPressed = ref.getButtonPressed();
    *_rectangle = ref.getRect();
    *_frameRec = ref.getFrameRect();
    return *this;
}

//GETTER
bool Button::getButtonPressed() const
{
    return _buttonPressed;
}

BTexture2D Button::getTexture() const
{
    return *_texture;
}

BRectangle Button::getRect() const
{
    return *_rectangle;
}

BRectangle Button::getFrameRect() const
{
    return *_frameRec;
}

int Button::getNbFrames() const
{
    return _nbFrames;
}

//SETTERS
void Button::setNbFrames(const int &nb)
{
    _nbFrames = nb;
}

void Button::setFrameRect(const BRectangle &rect)
{
    *_frameRec = rect;
}

void Button::setFrameRectSize(const Vector<float> &size)
{
    _frameRec->setRectSize(size);
}

//CHECKERS
void Button::update()
{
}

//DRAW
void Button::draw()
{
    if (_texture->isLoad()) {
       _texture->drawRect(*_frameRec, _rectangle->getRectPosition());
    } else {
        drawButtonRect();
    }
    drawOutline();
}
