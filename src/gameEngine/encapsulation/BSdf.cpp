/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** BSdf
*/

#include "BSdf.hpp"

using namespace gameEngine::encapsulation;

BSdf::BSdf(const std::string &msg, const int &textSize, const BColor &color, const Vector3T<float> &pos, const std::string &filePath,
        const int &fontSize, const int &charsCount) :
        _filePath(filePath), _msg(msg)
{
    unsigned int fileSize = 0;
    unsigned char *fileData = LoadFileData(filePath.c_str(), &fileSize);
    _fontSize = textSize;
    _font.baseSize = fontSize;
    _font.charsCount = charsCount;
    _font.chars = LoadFontData(fileData, fileSize, fontSize, 0, 0, FONT_SDF);
    Image atlas = GenImageFontAtlas(_font.chars, &_font.recs, charsCount, fontSize, 0, 1);
    _font.texture = LoadTextureFromImage(atlas);
    UnloadImage(atlas);
    UnloadFileData(fileData);
    _sdfShader = LoadShader(0, TextFormat(SHADER_PATH, GLSL_VERSION));
    SetTextureFilter(_font.texture, FILTER_BILINEAR);
    this->setTransform().setPosition(pos);
    _color = color;
}

BSdf::~BSdf()
{
    UnloadShader(_sdfShader);
    UnloadFont(_font);
}

void BSdf::draw()
{
    Vector2 vec;

    vec.x = this->getTransform()._position._x;
    vec.y = this->getTransform()._position._y;
    BeginShaderMode(_sdfShader);
    DrawTextEx(_font, _msg.c_str(), vec, _fontSize, 0, _color.getObj());
    EndShaderMode();
}

std::string BSdf::getContent() const noexcept
{
    return _msg;
}
