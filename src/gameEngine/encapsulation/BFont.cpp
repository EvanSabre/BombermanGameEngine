/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BFont
*/

#include "BFont.hpp"

using namespace gameEngine;

encapsulation::BFont::BFont()
{
    this->resetObj();
}

encapsulation::BFont::BFont(const BFont &ref)
{
    try
    {
        this->loadFromFile(ref._filepath);
    }
    catch(const std::exception& e)
    {
        throw e;
    }
}

encapsulation::BFont &encapsulation::BFont::operator=(const BFont &ref)
{
    if (this == &ref)
        return *this;
    this->unload();
    if (ref.isLoad()) {
        this->loadFromFile(ref._filepath);
    }
    return *this;
}

encapsulation::BFont::~BFont()
{
}

//GETTER

Font encapsulation::BFont::getObj() const noexcept
{
    return *_font;
}

bool encapsulation::BFont::isLoad() const noexcept
{
    if (_font == nullptr)
        return false;
    return true;
}

//SETTER

void encapsulation::BFont::loadFromFile(const std::string &filepath)
{
    if (this->isLoad())
        this->unload();
    _font = std::make_unique<Font>();
    *_font = LoadFont(filepath.c_str());
    if (!this->isLoad())
        throw std::runtime_error("Font : Loading failed");
    this->_filepath = filepath;
}

void encapsulation::BFont::unload() noexcept
{
    if (!this->isLoad())
        return;
    UnloadFont(*_font);
    this->resetObj();
}

void encapsulation::BFont::resetObj() noexcept
{
    this->_font = nullptr;
    this->_font = nullptr;
    this->_filepath.clear();
}
