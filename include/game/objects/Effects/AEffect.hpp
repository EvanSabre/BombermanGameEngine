/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** AEffect
*/

#ifndef AEFFECT_HPP_
#define AEFFECT_HPP_

#include "IEffect.hpp"

namespace game
{
    namespace objects
    {
        class AEffect : public game::interfaces::IEffect
        {
        public:
            AEffect(const std::string &type);
            ~AEffect();

            std::string getType() const noexcept;

            int getLife() const noexcept final;
            int getMaxLife() const noexcept final;
            int getNbBomb() const noexcept final;
            int getBlastPower() const noexcept final;
            int getBombPass() const noexcept final;
            Vector3T<float> getSpeed() const noexcept final;

        protected:
            int _extraLife = 0;
            int _maxLife = 0;
            int _nbBomb = 0;
            int _blastPower = 0;
            int _bombPass = 0;
            Vector3T<float> _speed{0, 0, 0};

        private:
            std::string _type;
        };
    } // namespace name
} // namespace game

#endif /* !AEFFECT_HPP_ */
