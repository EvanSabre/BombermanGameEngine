/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** BSdf
*/

#ifndef BSDF_HPP_
#define BSDF_HPP_

#include "ADrawable.hpp"
#include "BFont.hpp"
#include "Vector.hpp"
#include "BColor.hpp"

#if defined(PLATFORM_DESKTOP)
    #define GLSL_VERSION            330
#else   // PLATFORM_RPI, PLATFORM_ANDROID, PLATFORM_WEB
    #define GLSL_VERSION            100
#endif
#define DEFAULT_FONT "./assets/Fonts/anonymous_pro_bold.ttf"
#define SHADER_PATH "./assets/Shaders/glsl%i/sdf.fs"

namespace gameEngine {
    namespace encapsulation {
        class BSdf : public gameEngine::encapsulation::ADrawable {
            public:
                BSdf(const std::string &msg, const int &textSize, const BColor &color = WHITE, const Vector3T<float> &pos = {0, 0, 0},
                const std::string &filePath = DEFAULT_FONT, const int &fontSize = 16, const int &charsCount = 95);
                ~BSdf();


                void draw();
                std::string getContent() const noexcept;
            protected:
                Font _font = { 0 };
                BColor _color;
                Shader _sdfShader;
                int _fontSize;
                std::string _filePath;
                std::string _msg;
            private:
        };
    }
}

#endif /* !BSDF_HPP_ */
