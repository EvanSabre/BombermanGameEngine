/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** ExplosionAnimation
*/

#ifndef EXPLOSIONANIMATION_HPP_
#define EXPLOSIONANIMATION_HPP_

#include "memory"
#include "BModel.hpp"
#include "Clock.hpp"

namespace game::objects {
    class ExplosionAnimation {
        public:
            ExplosionAnimation(
                const std::shared_ptr<gameEngine::encapsulation::BModel> &modH,
                const Vector3T<float> &posH,
                const Vector3T<float> &scaleH,
                const std::shared_ptr<gameEngine::encapsulation::BModel> &modV,
                const Vector3T<float> &posV,
                const Vector3T<float> &scaleV);
            ~ExplosionAnimation();

            std::shared_ptr<gameEngine::encapsulation::BModel> _modelH;
            Vector3T<float> _posH;
            Vector3T<float> _scaleH;
            std::shared_ptr<gameEngine::encapsulation::BModel> _modelV;
            Vector3T<float> _posV;
            Vector3T<float> _scaleV;
            std::unique_ptr<gameEngine::component::Clock> _clock;
        protected:
        private:
    };
}

#endif /* !EXPLOSIONANIMATION_HPP_ */
