/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BImage
*/

#include "BImage.hpp"

using namespace gameEngine;

encapsulation::BImage::BImage(const std::string &filepaht, const Vector<int> &pos)
{
    this->_img = LoadImage(filepaht.c_str());
    if (!this->_img.data)
        throw std::runtime_error("Image: Loading failed");
    this->_pos = pos;
}

encapsulation::BImage::BImage(const BImage &ref)
{
    Image img_buf;

    if (ref.isLoad()) {
        this->_img = ImageCopy(ref.getObj());
        if (!this->_img.data)
            throw std::runtime_error("Image : Copy failed");
    } else
        this->_img = img_buf;
    this->_pos = ref._pos;
}

encapsulation::BImage &encapsulation::BImage::operator=(const BImage &ref)
{
    if (this == &ref)
        return *this;
    if (this->isLoad())
        this->unload();
    this->_img = ImageCopy(ref.getObj());
    if (!this->_img.data)
        throw std::runtime_error("Image : Copy failed");
    return *this;
}

encapsulation::BImage::~BImage()
{
    if (this->isLoad())
        this->unload();
}

//GETTER
Image encapsulation::BImage::getObj() const noexcept
{
    return this->_img;
}

bool encapsulation::BImage::isLoad() const noexcept
{
    if (this->_img.data)
        return true;
    return false;
}

int encapsulation::BImage::getWidth() const noexcept
{
    return this->_img.width;
}

int encapsulation::BImage::getHeight() const noexcept
{
    return this->_img.height;
}

Vector<int> encapsulation::BImage::getSize() const noexcept
{
    Vector<int> vec{this->_img.width, this->_img.height};
    return vec;
}

Vector<int> encapsulation::BImage::getPosition() const noexcept
{
    return this->_pos;
}

//setter
//Load image from file into CPU memory (RAM)
void encapsulation::BImage::load(const std::string &filepath)
{
    if (this->isLoad())
        this->unload();
    this->_img = LoadImage(filepath.c_str());
    if (!this->_img.data)
        throw std::runtime_error("Image : Loading failed");
}

void encapsulation::BImage::unload() noexcept
{
    if (!this->isLoad())
        return;
    UnloadImage(this->_img);
    this->_img.width = 0;
    this->_img.height = 0;
    this->_img.data = nullptr;
}

void encapsulation::BImage::setImage(const Image &img) noexcept
{
    if (this->isLoad())
        this->unload();
    this->_img = img;
}

void encapsulation::BImage::setImage(const Image &img, const Vector<int> &pos) noexcept
{
    this->setImage(img);
    this->setPosition(pos);
}

void encapsulation::BImage::setPosition(const Vector<int> &pos) noexcept
{
    this->_pos = pos;
}

void encapsulation::BImage::resize(const Vector<int> &newSize) noexcept
{
    if (this->isLoad())
        ImageResize(&this->_img, newSize._x, newSize._y);
}

//------------------------------------

//TRANSFORM

void encapsulation::BImage::scale(const float &scale) noexcept
{
    if (!this->isLoad())
        return;
    Vector<int> new_size = {this->_img.width, this->_img.height};
    new_size._x *= scale;
    new_size._y *= scale;
    this->resize(new_size);
}


void encapsulation::BImage::rotateRight() noexcept
{
    ImageRotateCW(&this->_img);
}

void encapsulation::BImage::rotateLeft() noexcept
{
    ImageRotateCCW(&this->_img);
}

void encapsulation::BImage::flipV() noexcept
{
    ImageFlipVertical(&this->_img);
}

void encapsulation::BImage::flipH() noexcept
{
    ImageFlipHorizontal(&this->_img);
}
