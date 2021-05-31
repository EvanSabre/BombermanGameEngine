/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BModelAnimation
*/

#ifndef BMODELANIMATION_HPP_
#define BMODELANIMATION_HPP_

#include "raylib.h"
#include <string>

namespace gameEngine {
    namespace encapsulation {
        class BModelAnimation {
            public:
                BModelAnimation(const std::string &filePath);
                ~BModelAnimation();

                int getAnimFrameCount() const noexcept;
                ModelAnimation getModelAnimation() const noexcept;

                void loadNewAnimation(const std::string &filePath);
            private:
                void destroyAnim();
                ModelAnimation *_anims;
                int _animsCount;
        };
    }
}

#endif /* !BMODELANIMATION_HPP_ */
