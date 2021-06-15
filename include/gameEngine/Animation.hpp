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
#include <vector>

#define ANIMIDLE 0
#define ANIMWALK 1

namespace gameEngine {
    class Animation {
        public:
            Animation(const encapsulation::BModel &, const encapsulation::BModelAnimation &, const encapsulation::BModelAnimation &);
            Animation(const std::string &modelPath, const std::string &animWalkPath, const std::string &animIdlePath, const std::string &texturePath);
            ~Animation();

            void updateModelAnimation();
            void refresh();

            encapsulation::BModel &getModel();
        private:
            encapsulation::BModel _model;
            encapsulation::BModelAnimation _animWalk;
            encapsulation::BModelAnimation _animIdle;
            encapsulation::BModelAnimation _anim;
            encapsulation::BTexture2D _texture;
            int _frameCounter;
            int _state;
    };
}

#endif /* !ANIMATION_HPP_ */
