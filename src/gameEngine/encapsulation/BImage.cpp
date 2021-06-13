/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BImage
*/

#include "BImage.hpp"

using namespace gameEngine::encapsulation;

BImage::BImage(const std::string &filepaht, const Vector<int> &pos)
{
    this->_img = LoadImage(filepaht.c_str());
    if (!this->_img.data)
        throw LoadingError(filepaht, "Loading Failed", "IMAGE");
    this->_pos = pos;
}

BImage::BImage(const BImage &ref)
{
    if (ref.isLoad()) {
        this->_img = ImageCopy(ref.getObj());
        if (!this->_img.data)
            throw IndeeError("Copy failed", "IMAGE");
    }
    this->_pos = ref._pos;
}

BImage &BImage::operator=(const BImage &ref)
{
    if (this == &ref)
        return *this;
    if (this->isLoad())
        this->unload();
    this->_img = ImageCopy(ref.getObj());
    if (!this->_img.data)
        throw IndeeError("Copy Failed", "IMAGE");
    return *this;
}

BImage::~BImage()
{
    if (this->isLoad())
        this->unload();
}

//GETTER
Image BImage::getObj() const noexcept
{
    return this->_img;
}

bool BImage::isLoad() const noexcept
{
    if (this->_img.data)
        return true;
    return false;
}

int BImage::getWidth() const noexcept
{
    return this->_img.width;
}

int BImage::getHeight() const noexcept
{
    return this->_img.height;
}

Vector<int> BImage::getSize() const noexcept
{
    Vector<int> vec{this->_img.width, this->_img.height};
    return vec;
}

Vector<int> BImage::getPosition() const noexcept
{
    return this->_pos;
}

//setter
//Load image from file into CPU memory (RAM)
void BImage::load(const std::string &filepath)
{
    if (this->isLoad())
        this->unload();
    this->_img = LoadImage(filepath.c_str());
    if (!this->_img.data)
        throw LoadingError(filepath, "Loading Failed", "IMAGE");
}

void BImage::unload() noexcept
{
    if (!this->isLoad())
        return;
    UnloadImage(this->_img);
    this->_img.width = 0;
    this->_img.height = 0;
    this->_img.data = nullptr;
}

void BImage::setImage(const Image &img) noexcept
{
    if (this->isLoad())
        this->unload();
    this->_img = img;
}

void BImage::setImage(const Image &img, const Vector<int> &pos) noexcept
{
    this->setImage(img);
    this->setPosition(pos);
}

void BImage::setPosition(const Vector<int> &pos) noexcept
{
    this->_pos = pos;
}

void BImage::resize(const Vector<int> &newSize) noexcept
{
    if (this->isLoad())
        ImageResize(&this->_img, newSize._x, newSize._y);
}

//------------------------------------

//TRANSFORM

void BImage::scale(const float &scale) noexcept
{
    if (!this->isLoad())
        return;
    Vector<int> new_size = {this->_img.width, this->_img.height};
    new_size._x *= scale;
    new_size._y *= scale;
    this->resize(new_size);
}


void BImage::rotateRight() noexcept
{
    ImageRotateCW(&this->_img);
}

void BImage::rotateLeft() noexcept
{
    ImageRotateCCW(&this->_img);
}

void BImage::flipV() noexcept
{
    ImageFlipVertical(&this->_img);
}

void BImage::flipH() noexcept
{
    ImageFlipHorizontal(&this->_img);
}

void BImage::clearBackground(const BColor &color) noexcept
{
    if (!isLoad())
        return;
    ImageClearBackground(&this->_img, color.getObj());
}

void BImage::drawPixel(const Vector<int> &pos, const BColor &color) noexcept
{
    if (!isLoad())
        return;
    ImageDrawPixel(&this->_img, pos._x, pos._y, color.getObj());
}

void BImage::drawLine(const Vector<float> &start, const Vector<float> &end, const BColor &color) noexcept
{
    if (!isLoad())
        return;
    Vector2 from = {start._x, start._y};
    Vector2 to = {end._x, end._y};
    ImageDrawLineV(&this->_img, from, to, color.getObj());
}

void BImage::drawCircle(const Vector<float> &center, int radius, const BColor &color) noexcept
{
    if (!isLoad())
        return;
    Vector2 middle = {center._x, center._y};
    ImageDrawCircleV(&this->_img, middle, radius, color.getObj());
}

void BImage::drawRectangle(const BRectangle &rec) noexcept
{
    if (!isLoad())

    ImageDrawRectangleRec(&this->_img, rec.getObj(), rec.getColor().getObj());
}

void BImage::drawText(BText text, const Vector<float> &pos) noexcept
{
    if (!isLoad())
        return;
    BFont font = text.getFont();
    if (font.isLoad()) {
        Vector2 vec = {pos._x, pos._y};

        ImageDrawTextEx(&_img, font.getObj(), text.getStr().c_str(),
            vec, text.getTextSize(), text.getSpacing(), text.getColor().getObj());
    } else {
        ImageDrawText(&this->_img, text.getStr().c_str(), pos._x, pos._y,
                text.getTextSize(), text.getColor().getObj());
    }
}
