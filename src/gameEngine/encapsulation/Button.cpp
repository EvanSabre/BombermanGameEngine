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
                const BText &content, const BColor &color, const std::string &textureFile,
                float rotation, int nbFrames) :
_rectangle(size, pos, color, rotation), _frameRec(size, {0, 0}, color, rotation),
_content(content.getStr(), content.getPosition(), content.getColor(), content.getSize())
{
    if (textureFile != "" && content.getStr() != "") {
            BImage img(textureFile);
            img.drawText(content, content.getPosition());
            _texture.loadFromImg(img);
    } else if (textureFile != "")
        _texture.loadFromFile(textureFile);
    _state = NORMAL;
    _nbFrames = nbFrames;
    _buttonPressed = false;
}

Button::Button(const BTexture2D &text, const BRectangle &rect, const BText &content) :
    _rectangle(rect), _frameRec(rect.getSize(), {0, 0}, rect.getColor(), rect.getRotation()),
    _content(content)
{

    _state = NORMAL;
    _nbFrames = 1;
    _buttonPressed = false;
    _texture = text;
    _rectangle = rect;
    _content = content;
}

Button::~Button()
{}

Button &Button::operator=(const Button &ref)
{
    if (this == &ref)
        return *this;
    _content = ref.getContent();
    _texture = ref.getTexture();
    _nbFrames = ref.getNbFrames();
    _state = ref.getState();
    _buttonPressed = ref.getButtonPressed();
    _rectangle = ref.getRect();
    _frameRec = ref.getFrameRect();    
    return *this;
}

//GETTERS
Vector<float> Button::getPos() const
{
    return _rectangle.getPos();
}

Vector<float> Button::getSize() const
{
    return _rectangle.getSize();
}

BText Button::getContent() const
{
    return _content;
}

Button::State Button::getState() const
{
    return _state;
}

bool Button::getButtonPressed() const
{
    return _buttonPressed;
}

BTexture2D Button::getTexture() const
{
    return _texture;
}

BRectangle Button::getRect() const
{
    return _rectangle;
}

BRectangle Button::getFrameRect() const
{
    return _frameRec;
}

int Button::getNbFrames() const
{
    _nbFrames;
}

//SETTERS
void Button::setPos(const Vector<float> &pos)
{
    _rectangle.setPos(pos);
}

void Button::setRotation(const float &rotation)
{
    _rectangle.setRotation(rotation);
}

void Button::setSize(const Vector<float> &size)
{
    _rectangle.setSize(size);
}

void Button::setColor(const BColor &color)
{
    _rectangle.setColor(color);
}

void Button::setNbFrames(const int &nb)
{
    _nbFrames = nb;
}

void Button::setContentStr(const std::string &str)
{
    _content.setStr(str);
}

void Button::setFrameRect(const BRectangle &rect)
{
    _frameRec = rect;
}

void Button::setFrameRectSize(const Vector<float> &size)
{
    _frameRec.setSize(size);
}

//CHECKERS
bool Button::isInsideButton(const Vector<float> &point)
{
    if (_rectangle.checkPointInside(point)) {
        _state = MOUSE_HOVER;
        return true;
    }
    _state = NORMAL;
    return false;
}

bool Button::isButtonPressed(Vector<float> mousePos)
{
    if (isInsideButton(mousePos) && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        _state = PRESSED;
        return true;
    }
    return false;
}

bool Button::isButtonReleased()
{
    if (_state == PRESSED && IsMouseButtonReleased(MOUSE_BUTTON_RIGHT)) {
        _buttonPressed = true;
        return true;
    }
    return false;
}


//DRAW
void Button::drawButton()
{
    if (_texture.isLoad())
        _texture.drawRect(_frameRec, _rectangle.getPos());
    else {
        _rectangle.draw();
        _content.draw();
    }
}