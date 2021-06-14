/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BFont
*/

#include "BFont.hpp"

using namespace gameEngine::encapsulation;

BFont::BFont()
{
    this->resetObj();
}

BFont::BFont(const BFont &ref)
{
    try
    {
        this->loadFromFile(ref._filepath);
    }
    catch(const LoadingError &e)
    {
        throw e;
    }
}

BFont &BFont::operator=(const BFont &ref)
{
    if (this == &ref)
        return *this;
    this->unload();
    if (ref.isLoad()) {
        this->loadFromFile(ref._filepath);
    }
    return *this;
}

BFont::~BFont()
{
}

//GETTER

Font BFont::getObj() const noexcept
{
    return *_font;
}

bool BFont::isLoad() const noexcept
{
    if (_font == nullptr)
        return false;
    return true;
}

//SETTER

void BFont::loadFromFile(const std::string &filepath)
{
    if (this->isLoad())
        this->unload();
    _font = std::make_unique<Font>();
    *_font = LoadFont(filepath.c_str());
    if (!this->isLoad())
        throw LoadingError(filepath, "Loading Failed : ", "FONCT");
    this->_filepath = filepath;
}

void BFont::unload() noexcept
{
    if (!this->isLoad())
        return;
    UnloadFont(*_font);
    this->resetObj();
}

void BFont::resetObj() noexcept
{
    this->_font = nullptr;
    this->_font = nullptr;
    this->_filepath.clear();
}
