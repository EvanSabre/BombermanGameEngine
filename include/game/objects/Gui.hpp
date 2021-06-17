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
#include <memory>

class Gui {
public:
    Gui();
    ~Gui();

    void draw();
    void drawElt(int nb, std::shared_ptr<gameEngine::encapsulation::BTexture2D> texture,
        Vector<float> scale, float spacing = 30) noexcept;

private:
    std::shared_ptr<gameEngine::encapsulation::BTexture2D> _heartTexture;
    std::shared_ptr<gameEngine::encapsulation::BTexture2D> _bombTexture;
};

#endif /* !GUI_HPP_ */
