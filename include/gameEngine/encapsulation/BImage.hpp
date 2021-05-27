/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BImage
*/

#ifndef BIMAGE_HPP_
#define BIMAGE_HPP_

#include <iostream>
#include <string>
#include <stdexcept>
#include "Vector.hpp"
#include "BRectangle.hpp"
#include "BText.hpp"
#include "raylib.h"

namespace gameEngine
{
    namespace encapsulation
    {
        class BImage
        {
        public:
            BImage(const std::string &filepath, const Vector<int> &pos = {0, 0});
            BImage(const BImage &ref);
            BImage &operator=(const BImage &ref);
            ~BImage();

            //getter
                [[nodiscard]] Image getObj() const noexcept;
                [[nodiscard]] bool isLoad() const noexcept;
                [[nodiscard]] int getWidth() const noexcept;
                [[nodiscard]] int getHeight() const noexcept;
                [[nodiscard]] Vector<int> getSize() const noexcept;
                [[nodiscard]] Vector<int> getPosition() const noexcept;

            //setter
            // Load image from file into CPU memory (RAM)
                void load(const std::string &filpath);
                void unload() noexcept;

                void setImage(const Image &img) noexcept;
                void setImage(const Image &img, const Vector<int> &pos) noexcept;
                void setPosition(const Vector<int> &pos) noexcept;

            //transform
                void resize(const Vector<int> &newSize) noexcept;
                void scale(const float &scale) noexcept;
                void rotateRight() noexcept;
                void rotateLeft() noexcept;

                void clearBackground(const BColor &color) noexcept;
                void drawPixel(const Vector<int> &pos, const BColor &color) noexcept;
                void drawLine(const Vector<float> &start, const Vector<float> &end, const BColor &color) noexcept;
                void drawCircle(const Vector<float> &center, int radius, const BColor &color) noexcept;
                void drawRectangle(const BRectangle &rec) noexcept;
                void drawText(const BText &text, const Vector<int> &pos) noexcept;

                //flip vertically
                void flipV() noexcept;
                //flip horizontaly
                void flipH() noexcept;

        private:
            Image _img;
            Vector<int> _pos{0, 0};
        };
    } // namespace encapsulation

} // namespace gameEngine

// void ImageClearBackground(Image *dst, Color color);                                                // Clear image background with given color
// void ImageDrawPixel(Image *dst, int posX, int posY, Color color);                                  // Draw pixel within an image
// void ImageDrawPixelV(Image *dst, Vector2 position, Color color);                                   // Draw pixel within an image (Vector version)
// void ImageDrawLine(Image *dst, int startPosX, int startPosY, int endPosX, int endPosY, Color color); // Draw line within an image
// void ImageDrawLineV(Image *dst, Vector2 start, Vector2 end, Color color);                          // Draw line within an image (Vector version)
// void ImageDrawCircle(Image *dst, int centerX, int centerY, int radius, Color color);               // Draw circle within an image
// void ImageDrawCircleV(Image *dst, Vector2 center, int radius, Color color);                        // Draw circle within an image (Vector version)
// void ImageDrawRectangle(Image *dst, int posX, int posY, int width, int height, Color color);       // Draw rectangle within an image
// void ImageDrawRectangleV(Image *dst, Vector2 position, Vector2 size, Color color);                 // Draw rectangle within an image (Vector version)
// void ImageDrawRectangleRec(Image *dst, Rectangle rec, Color color);                                // Draw rectangle within an image
// void ImageDrawRectangleLines(Image *dst, Rectangle rec, int thick, Color color);                   // Draw rectangle lines within an image
// void ImageDraw(Image *dst, Image src, Rectangle srcRec, Rectangle dstRec, Color tint);             // Draw a source image within a destination image (tint applied to source)
// void ImageDrawText(Image *dst, const char *text, int posX, int posY, int fontSize, Color color);   // Draw text (using default font) within an image (destination)
// void ImageDrawTextEx(Image *dst, Font font, const char *text, Vector2 position, float fontSize, float spacing, Color tint); // Draw text (custom sprite font) within an image (destination)



#endif /* !BIMAGE_HPP_ */
