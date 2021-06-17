/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BTexture2D
*/

#include "BTexture2D.hpp"

using namespace gameEngine::encapsulation;

BTexture2D::BTexture2D(const std::string &filePath)
{
    this->resetObj();
    this->loadFromFile(filePath);
    _filepath = filePath;
}

BTexture2D::BTexture2D()
{
    this->resetObj();
}

BTexture2D::BTexture2D(const std::string &filePath, const encapsulation::BText &content)
{
    this->resetObj();
    encapsulation::BText t(content);
    this->addTextToTexture(t, filePath);
    _filepath = filePath;
}

BTexture2D::BTexture2D(const BTexture2D &ref)
{
    this->resetObj();
    this->loadFromFile(ref.getFilePath());
    this->_filepath = ref._filepath;
}


BTexture2D::~BTexture2D()
{
    if (isLoad())
        this->unload();
}

//-----------------------

//GETTER

Texture2D BTexture2D::getObj() const noexcept
{
    return this->_texture;
}

bool BTexture2D::isLoad() const noexcept
{
    if (this->_texture.format < 0 && _texture.width == -1 && _texture.height == -1)
        return false;
    return true;
}

BColor BTexture2D::getColor() const noexcept
{
    return this->_color;
}

Vector<int> BTexture2D::getPos() const noexcept
{
    return this->_pos;
}

Vector<int> BTexture2D::getSize() const noexcept
{
    Vector<int> size(getObj().width, getObj().height);

    return size;
}

std::string BTexture2D::getFilePath() const noexcept
{
    return this->_filepath;
}

bool BTexture2D::getEnabled() const noexcept
{
    return this->_enabled;
}

//setter
void BTexture2D::setPos(const Vector<int> &pos) noexcept
{
    this->_pos = pos;
}

void BTexture2D::setColor(const BColor &color) noexcept
{
    this->_color = color;
}

void BTexture2D::setEnabled(bool enable) noexcept
{
    this->_enabled = enable;
}

//trhrow runtime error if img is not load
void BTexture2D::loadFromImg(const BImage &img)
{
    if (!img.isLoad())
        throw LoadingError("Bimage", "Loading fromm unloaded : ", "TEXTURE2D");
    this->_texture = LoadTextureFromImage(img.getObj());
    if (!this->isLoad())
        throw LoadingError("Bimage", "Loading from : ", "TEXTURE2D");
}

void BTexture2D::loadFromImgRelRect(const std::string &path, const Vector<float> &size)
{
    BImage img(path);

    this->resetObj();
    img.resize(Vector<int>(size._x, size._y));
    img.setPosition(Vector<int>(0, 0));
    this->loadFromImg(img);
    _filepath = path;
}

void BTexture2D::loadFromFile(const std::string &filepath)
{
    this->_texture = LoadTexture(filepath.c_str());
    if (!this->isLoad())
        throw LoadingError(filepath, "Loading from : ", "TEXTURE2D");
}

void BTexture2D::addTextToTexture(BText &text, const std::string &filePath)
{
    BImage img(filePath);

    img.drawText(text, text.getTextPosition());
    loadFromImg(img);
}

void BTexture2D::unload() noexcept
{
    if (!isLoad())
        return;
    UnloadTexture(this->_texture);
    // this->resetObj();
}

//------------------

//DRAW

void BTexture2D::draw() const noexcept
{
    if (isLoad() && _enabled == true)
        DrawTexture(this->_texture, _pos._x, _pos._y, _color.getObj());
}

void BTexture2D::drawEx(const Vector<float> &scale) const noexcept
{
    Rectangle source = {0.0f, 0.0f, (float)_texture.width, (float)_texture.height};
    Rectangle dest = {(float)_pos._x, (float)_pos._y, (float)_texture.width * scale._x, (float)_texture.height * scale._y};
    Vector2 origin = {0.0f, 0.0f};

    if (isLoad() && _enabled == true)
        DrawTexturePro(this->_texture, source, dest, origin, 0.0f, _color.getObj());
}

void BTexture2D::drawRect(const encapsulation::BRectangle &rect, Vector<float> pos) const noexcept
{
    Vector2 vec;

    vec.x = pos._x;
    vec.y = pos._y;
    if (isLoad() && _enabled == true) {
        DrawTextureRec(this->_texture, rect.getObj(), vec, _color.getObj());
    }
}

//-----------------

//PRIVATE METHOD

void BTexture2D::resetObj() noexcept
{
    _texture.id = 0;
    _texture.width = -1;
    _texture.height = -1;
    _texture.mipmaps = 0;
    _texture.format = -1;
}
