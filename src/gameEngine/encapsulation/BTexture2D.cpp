/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BTexture2D
*/

#include "BTexture2D.hpp"

using namespace gameEngine;

encapsulation::BTexture2D::BTexture2D(const std::string &filePath)
{
    this->resetObj();
    this->loadFromFile(filePath);
    _filepath = filePath;
}

encapsulation::BTexture2D::BTexture2D()
{
    this->resetObj();
}

encapsulation::BTexture2D::BTexture2D(const std::string &filePath, const encapsulation::BText &content)
{
    this->resetObj();
    this->addTextToTexture(content, filePath);
    _filepath = filePath;
}

encapsulation::BTexture2D::BTexture2D(const BTexture2D &ref)
{
    this->resetObj();
    this->loadFromFile(ref.getFilePath());
    this->_filepath = ref._filepath;
}


encapsulation::BTexture2D::~BTexture2D()
{
    this->unload();
}

//-----------------------

//GETTER

Texture2D encapsulation::BTexture2D::getObj() const noexcept
{
    return this->_texture;
}

bool encapsulation::BTexture2D::isLoad() const noexcept
{
    if (this->_texture.format < 0 && _texture.width == -1 && _texture.height == -1)
        return false;
    return true;
}

encapsulation::BColor encapsulation::BTexture2D::getColor() const noexcept
{
    return this->_color;
}

Vector<int> encapsulation::BTexture2D::getPos() const noexcept
{
    return this->_pos;
}

Vector<int> encapsulation::BTexture2D::getSize() const noexcept
{
    Vector<int> size(getObj().width, getObj().height);

    return size;
}

std::string encapsulation::BTexture2D::getFilePath() const noexcept
{
    return this->_filepath;
}

//setter
void encapsulation::BTexture2D::setPos(const Vector<int> &pos) noexcept
{
    this->_pos = pos;
}

void encapsulation::BTexture2D::setColor(const BColor &color) noexcept
{
    this->_color = color;
}

//trhrow runtime error if img is not load
void encapsulation::BTexture2D::loadFromImg(const BImage &img)
{
    if (!img.isLoad())
        throw std::runtime_error("Texture : Loading from image not load");
    this->_texture = LoadTextureFromImage(img.getObj());
    std::cout << "TEXTURE :" << _texture.width << " " << _texture.height << " " << _texture.format << std::endl;
    if (!this->isLoad())
        throw std::runtime_error("Texture test : loading failed");
}

void encapsulation::BTexture2D::loadFromImgRelRect(const std::string &path, const BRectangle &rect)
{
    BImage img(path);
    Vector<float> size = rect.getRectSize();

    img.resize(Vector<int>(size._x, size._y));
    this->loadFromImg(img);
}

void encapsulation::BTexture2D::loadFromFile(const std::string &filepath)
{
    this->_texture = LoadTexture(filepath.c_str());
    if (!this->isLoad())
        throw std::runtime_error("Texture : Loading failedd");
}

void encapsulation::BTexture2D::addTextToTexture(const BText &text, const std::string &filePath)
{
    BImage img(filePath);

    img.drawText(text, text.getTextPosition());
    loadFromImg(img);
}

void encapsulation::BTexture2D::unload() noexcept
{
    if (!isLoad())
        return;
    UnloadTexture(this->_texture);
    this->resetObj();
}

//------------------

//DRAW

void encapsulation::BTexture2D::draw() const noexcept
{
    if (isLoad())
        DrawTexture(this->_texture, _pos._x, _pos._y, _color.getObj());
}

void encapsulation::BTexture2D::drawEx(int scale) const noexcept
{
    if (isLoad())
        DrawTextureEx(this->_texture, (Vector2){_pos._x, _pos._y}, 0.0f, (float)scale, WHITE);
}

void encapsulation::BTexture2D::drawRect(const encapsulation::BRectangle &rect, Vector<float> pos) const noexcept
{
    if (isLoad()) {
        DrawTextureRec(this->_texture, rect.getObj(), (Vector2) {pos._x, pos._y}, _color.getObj());
    }
}

//-----------------

//PRIVATE METHOD

void encapsulation::BTexture2D::resetObj() noexcept
{
    _texture.id = 0;
    _texture.width = -1;
    _texture.height = -1;
    _texture.mipmaps = 0;
    _texture.format = -1;
}
