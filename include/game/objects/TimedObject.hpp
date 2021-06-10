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

namespace game
{
    namespace objects
    {
        class TimedObject : public gameEngine::objects::AGameObject
        {
        public:
            TimedObject(const std::string &id,
                const std::chrono::milliseconds &life_time
                );
            ~TimedObject();

            //getter
                std::chrono::milliseconds getLifeTime() const noexcept;
                std::chrono::milliseconds getRemainedTime() const noexcept;
                std::chrono::milliseconds getElapsedTime() const noexcept;
                bool isTimeOver() const noexcept;

            //setter
                void setModel(gameEngine::encapsulation::BModel *model) noexcept;


            void draw() const noexcept;

            virtual void onOverTime() = 0;

            //AGameObject overide
                virtual void OnCollisionEnter(const AGameObject &collision) override;
                virtual void OnCollisionExit(const AGameObject &collision) override;
                virtual void Update() override;

        protected:
            gameEngine::encapsulation::BModel *_model = nullptr;

        private:
            std::chrono::milliseconds _lifeTime;
            std::chrono::system_clock::time_point _startLifePoint = std::chrono::system_clock::now();
            std::chrono::system_clock::time_point _lastLifeTimeCheckPoint = std::chrono::system_clock::now();

        private:
            void updateLastTimeCheck() noexcept;

            //update _lastCheck adnd lauch onOvertime if neccessary
                void updateLifeTime() noexcept;

        };

    } // namespace systems
} // namespace gmae



#endif /* !TIMEDOBJECT_HPP_ */
