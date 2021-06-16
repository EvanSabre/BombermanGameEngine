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
        std::cout << "### adding text to texture" << std::endl;
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
    *_rectangle = *ref._rectangle;
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
    _frameRec->setTransform()._scale._x = size._x;
    _frameRec->setTransform()._scale._y = size._y;
}

//CHECKERS
void Button::update()
{
    updateState();
}

//DRAW
void Button::draw()
{
    Vector<float> pos(
        _rectangle->getTransform().getPosition()._x,
        _rectangle->getTransform().getPosition()._y);

    if (_texture->isLoad()) {
        _texture->setPos(Vector<int>((int)pos._x, (int)pos._y));
        if (_texture->getSize()._x >= _rectangle->getWidth()) {
            _texture->drawEx(_rectangle->getWidth() / _texture->getSize()._x);
        } else if (_texture->getSize()._y > _rectangle->getHeight()) {
            _texture->drawEx(_rectangle->getHeight() / _texture->getSize()._y);
        } else {
            _texture->drawRect(*_frameRec, pos);
        }
    } else {
        drawButtonRect();
    }
    drawOutline();
}
