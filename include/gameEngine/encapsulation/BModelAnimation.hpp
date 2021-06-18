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
                BModelAnimation(const BModelAnimation &ref);
                ~BModelAnimation();

                int getAnimFrameCount() const noexcept;
                ModelAnimation *getModelAnimation() const noexcept;
                std::string getFilePath() const noexcept;

                bool isLoad();
                void loadNewAnimation(const std::string &filePath);
                void destroyAnim();
            private:
                std::string _filePath;
                ModelAnimation *_anims;
                int _animsCount;
                bool _loaded;
        };
    }
}

#endif /* !BMODELANIMATION_HPP_ */
