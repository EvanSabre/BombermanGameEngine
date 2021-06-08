/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** TimedObject
*/

#ifndef TIMEDOBJECT_HPP_
#define TIMEDOBJECT_HPP_

#include "AGameObject.hpp"
#include <chrono>
#include "BModel.hpp"

namespace gmae
{
    namespace objects
    {
        class TimedObject : public gameEngine::objects::AGameObject
        {
        public:
            TimedObject(const std::string &id,
                const std::chrono::microseconds &life_time
                );
            ~TimedObject();

            //getter
                std::chrono::microseconds getLifeTime() const noexcept;
                std::chrono::microseconds getRemainedTime() const noexcept;
                std::chrono::microseconds getElapsedTime() const noexcept;
                bool isTimeOver() const noexcept;

            //setter
                void setModel(gameEngine::encapsulation::BModel *model) noexcept;

            void draw() const noexcept;

            void updateElapsedTime() noexcept;

            virtual void onOverTime() = 0;

            //AGameObject overide
                virtual void OnCollisionEnter(const AGameObject &collision) override;
                virtual void OnCollisionExit(const AGameObject &collision) override;
                virtual void Update() override;

        protected:
            gameEngine::encapsulation::BModel *_model;

        private:
            std::chrono::microseconds _lifeTime;
            std::chrono::system_clock::time_point _startLifePoint = std::chrono::system_clock::now();
            std::chrono::system_clock::time_point _lastLifeTimeCheckPoint = std::chrono::system_clock::now();
        };

    } // namespace systems
} // namespace gmae



#endif /* !TIMEDOBJECT_HPP_ */
