/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BImage
*/

#include "include/gameEngine/encapsulation/BImage.hpp"

using namespace gameEngine;

encapsulation::BImage::BImage(const std::string &filepaht)
{
    this->_img = LoadImage(filepaht.c_str());
    if (!this->_img.data)
        throw std::runtime_error("Image: Loading failed");
}

encapsulation::BImage::BImage(const BImage &ref)
{
    Image img_buf = {0};

    if (ref.isLoad()) {
        this->_img = ImageCopy(ref.getObj());
        if (!this->_img.data)
            throw std::runtime_error("Image : Copy failed");
    } else
        this->_img = img_buf;
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

void encapsulation::BImage::setImage(const Image &img) noexcept
{
    if (this->isLoad())
        this->unload();
    this->_img = img;
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

