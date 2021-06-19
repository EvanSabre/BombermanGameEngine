/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** display player Gui
*/

#ifndef GUI_HPP_
#define GUI_HPP_

#include "BTexture2D.hpp"
#include "BText.hpp"
#include "Character.hpp"
#include "BRectangle.hpp"
#include "BText.hpp"
#include <memory>
#include "Clock.hpp"
namespace game
{
    class Gui {
    public:
        typedef enum e_corner {
            TOP_LEFT,
            TOP_RIGHT,
            BOTTOM_LEFT,
            BOTTOM_RIGHT
        } corner_e;

        Gui();
        ~Gui();

        void draw(const game::objects::Character &charac, const Vector<float> &basePose);
        void draw(const game::objects::Character &charac, corner_e corner);
        void drawElt(int nb, std::shared_ptr<gameEngine::encapsulation::BTexture2D> texture,
            Vector<float> scale, float spacing = 30) noexcept;
        void drawEltStr(const std::string &str, std::shared_ptr<gameEngine::encapsulation::BTexture2D> texture,
            Vector<float> scale, float spacing = 30) noexcept;
        void drawLabel(const std::string &str, const Vector<float> &pos) noexcept;

    private:
        std::shared_ptr<gameEngine::encapsulation::BTexture2D> _heartTexture;
        std::shared_ptr<gameEngine::encapsulation::BTexture2D> _bombTexture;
        gameEngine::encapsulation::BText _text;
    };
} // namespace game



#endif /* !GUI_HPP_ */
