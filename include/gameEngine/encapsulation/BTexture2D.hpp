/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BTexture
*/

#ifndef BTEXTURE2D_HPP_
#define BTEXTURE2D_HPP_

#include "raylib.h"
#include "BImage.hpp"
#include "Vector.hpp"
#include "BColor.hpp"
#include "Errors.hpp"
#include "ADrawable.hpp"

namespace gameEngine
{
    namespace encapsulation
    {
        class BTexture2D : public gameEngine::encapsulation::ADrawable
        {
        public:
            BTexture2D(const std::string &filePath);
            BTexture2D(const std::string &filePath, const BText &content);
            BTexture2D(const BTexture2D &ref);
            BTexture2D();
            BTexture2D &operator=(const BTexture2D &ref);
            BTexture2D(const std::string &filepath, const std::string &content);
            ~BTexture2D();

            void update() override;

        //getter
            [[nodiscard]] Texture2D getObj() const noexcept;
            [[nodiscard]] bool isLoad() const noexcept;
            //[[nodiscard]] BColor getColor() const noexcept;
            [[nodiscard]] Vector<int> getPos() const noexcept;
            [[nodiscard]] Vector<int> getSize() const noexcept;
            [[nodiscard]] std::string getFilePath() const noexcept;
            [[nodiscard]] bool getEnabled() const noexcept;
            std::string getContent() const noexcept override;
            void setContent(std::string &content) noexcept;
        //setter
            void setPos(const Vector<int> &pos) noexcept;
            //void setColor(const BColor &color) noexcept;
            void setEnabled(bool enabled) noexcept;

            //trhrow runtime error if img is not load
            void loadFromImg(const BImage &img);
            void loadFromImgRelRect(const std::string &path, const Vector<float> &size);

            void loadFromFile(const std::string &filepath);
            void unload() noexcept;

        //draw
            void draw() override;
            void drawEx(const Vector<float> &scale) const noexcept;
            void drawRect(const BRectangle &rect, Vector<float> pos) const noexcept;

        //utils
            void addTextToTexture(BText &text, const std::string &filePath);
        private:
            bool _enabled = true;
            Texture2D _texture;
            std::string _filepath;
            std::string _content;
            Vector<int> _pos{0, 0};
            BColor _color{WHITE};

        private:
            void resetObj() noexcept;
        };

    } // namespace encapsulation

} // namespace gameEngine


#endif /* !BTEXTURE2D_HPP_ */
