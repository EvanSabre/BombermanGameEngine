/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** Parallax
*/

#ifndef PARALLAX_HPP_
#define PARALLAX_HPP_

#include "BTexture2D.hpp"
#include <memory>

namespace gameEngine {
    namespace scenes {
        class Parallax {
            public:
                Parallax();
                ~Parallax();

                void drawParallax();
                void calculateParallax(float back, float mid, float fore);
                void initParallax(const std::string &backPath, const std::string &midPath, const std::string &forePath);
            protected:
                std::shared_ptr<gameEngine::encapsulation::BTexture2D> _background;
                std::shared_ptr<gameEngine::encapsulation::BTexture2D> _midground;
                std::shared_ptr<gameEngine::encapsulation::BTexture2D> _foreground;
                int scrollingBack;
                int scrollingMid;
                int scrollingFront;
            private:
        };
    }
}

#endif /* !PARALLAX_HPP_ */
