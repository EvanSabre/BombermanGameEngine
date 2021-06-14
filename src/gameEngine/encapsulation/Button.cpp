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
                float rotation, int nbFrames)
{
    _rectangle = std::make_shared<BRectangle>(size, pos, color, rotation);
    _frameRec = std::make_shared<BRectangle>(size, Vector<float>(0, 0), color, rotation);
    _content = std::make_shared<BText>(content);
    _texture = std::make_shared<BTexture2D>();
    if (textureFile != "" && content.getStr() != "") {
        _texture->addTextToTexture(content, textureFile);
    } else if (textureFile != "")
        _texture->loadFromFile(textureFile);
    _state = NORMAL;
    _nbFrames = nbFrames;
    _buttonPressed = false;
}

Button::Button(const std::shared_ptr<BTexture2D> &text, const std::shared_ptr<BRectangle> &rect, const std::shared_ptr<BText> &content)
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
    *_rectangle = ref.getRect();
    *_frameRec = ref.getFrameRect();
    return *this;
}

//GETTERS
Vector<float> Button::getPos() const
{
    Vector3T<float> pos(_rectangle->getTransform().getPosition());

    return Vector<float>(pos._x, pos._y);
}

Vector<float> Button::getSize() const
{
    Vector3T<float> scale(_rectangle->getTransform().getScale());

    return Vector<float>(scale._x, scale._y);
}

BText Button::getContent() const
{
    return *_content;
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
void Button::setPos(const Vector<float> &pos)
{
    _rectangle->setTransform()._position._x = pos._x;
    _rectangle->setTransform()._position._y = pos._y;
}

void Button::setRotation(const float &rotation)
{
    _rectangle->setTransform()._rotation._x = rotation;
}

void Button::setSize(const Vector<float> &size)
{
    _rectangle->setTransform()._scale._x = size._x;
    _rectangle->setTransform()._scale._y = size._y;
}

void Button::setColor(const BColor &color)
{
    _rectangle->setColor(color);
}

void Button::setNbFrames(const int &nb)
{
    _nbFrames = nb;
}

void Button::setContentStr(const std::string &str)
{
    _content->setStr(str);
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
bool Button::isInsideButton(const Vector<float> &point)
{
    if (_rectangle->checkPointInside(point)) {
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

void Button::update()
{
    Vector2 tmp = GetMousePosition();
    Vector<float> vec(tmp.x, tmp.y);

    isButtonPressed(vec);
    isButtonReleased();
}

//DRAW
void Button::drawButton()
{
    Vector<float> pos(
        _rectangle->getTransform().getPosition()._x,
        _rectangle->getTransform().getPosition()._y);

    if (_texture->isLoad()) {
       _texture->drawRect(*_frameRec, pos);
    } else {
        _rectangle->draw();
        _content->draw();
    }
}
