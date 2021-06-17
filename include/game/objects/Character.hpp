/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Chraracter
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <string>
#include <deque>
#include "Moveable.hpp"
#include "BModel.hpp"
#include "IEffect.hpp"
#include "EffectFactory.hpp"
#include "BModelAnimation.hpp"
#include "SettingConf.hpp"
#include "Bomb.hpp"
// #include "Animation.hpp"

#define ANIMIDLE 0
#define ANIMWALK 1
#define TILESIZE 10

namespace game
{
    namespace objects
    {
        class Character : public gameEngine::objects::Moveable
        {
        public:
            Character(
                        const std::string &id,
                        const std::string &name,
                        const std::string &texturePath,
                        const std::string &model,
                        const std::string &animWalk,
                        const std::string &animIdle,
                        const Vector3T<float> &pos = {0, 0, 0}
                        );
            ~Character();

            //getter
                std::string getName() const noexcept;
                size_t getScore() const noexcept;
                int getState() const noexcept;
                void setCurrentEvent(game::Event Event) noexcept;
                game::Event getCurrentEvent() const noexcept;

            //setter
                void setCollider() noexcept;
                void setState(const int &) noexcept;
                void addScore(const size_t value) noexcept;
                void subScore(const size_t value) noexcept;
                void setModel(std::shared_ptr<gameEngine::encapsulation::BModel> model) noexcept;
                void setIsMoving(bool isMoving) noexcept;

            //action
            std::shared_ptr<game::objects::AExplosif> &getNextBomb();
            void dropBomb(std::size_t tick) noexcept;
            void draw() const noexcept;
            //tmp for test : to delete
                void onCollisionEnter(const AGameObject &collision);
                void onCollisionExit(const AGameObject &collision);
                void update();
                void updateAnim();
                void updateModelAnimation();
               game::Tag_e getTag() const noexcept override;

        protected:
            size_t _score = 0;
            int _nbBomb = 1;
            int _bombRange = 1;
            int _health = 1;
            int _lives = 1;
            game::Event _currentEvent;
            bool _isMoving;

        private:
            std::string _name;
            std::shared_ptr<gameEngine::encapsulation::BModel> _model = nullptr;
            std::shared_ptr<gameEngine::encapsulation::BTexture2D> _texture = nullptr;
            // std::shared_ptr<gameEngine::Animation> _animation = nullptr;
            std::shared_ptr<gameEngine::encapsulation::BModelAnimation> _animWalk;
            std::shared_ptr<gameEngine::encapsulation::BModelAnimation> _animIdle;
            std::shared_ptr<gameEngine::encapsulation::BModelAnimation> _anim;
            int _frameCounter;
            int _state;
            game::objects::Bomb _bombRef;
            std::deque<std::shared_ptr<game::objects::AExplosif>> _bombQueue;

        private:
            void addPowerUpEffec(const game::interfaces::IEffect *efx) noexcept;
        };
    } // namespace objects
} // namespace game

#endif /* !CHARACTER_HPP_ */
