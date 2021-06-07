/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Animation
*/

#ifndef ANIMATION_HPP_
#define ANIMATION_HPP_

#include "raylib.h"
#include <stdio.h>
#include <string>
#include "BModel.hpp"
#include "BTexture2D.hpp"
#include "BModelAnimation.hpp"

namespace gameEngine {
    class Animation {
        public:
            Animation(const encapsulation::BModel &model, const encapsulation::BModelAnimation &anim);
            Animation(const std::string &modelPath, const std::string &animPath, const std::string &texturePath);
            ~Animation();

            void updateModelAnimation();
            void refresh();
        private:
            encapsulation::BModel _model;
            encapsulation::BModelAnimation _anim;
            encapsulation::BTexture2D _texture;
            int _frameCounter;
    };
}

#endif /* !ANIMATION_HPP_ */
