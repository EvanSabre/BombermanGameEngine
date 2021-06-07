/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** AAudioObject
*/

#ifndef AAUDIOOBJECT_HPP_
#define AAUDIOOBJECT_HPP_

#include "IAudioObject.hpp"

namespace gameEngine
{
    namespace encapsulation
    {
        class AAudioObject : public gameEngine::interfaces::IAudioObject
        {
        public:
            AAudioObject();
            ~AAudioObject();

            virtual void play() override;
            virtual void stop() override;
            virtual void pause() override;
            virtual void resume() override;

            virtual bool isPlaying() const override;

            //max is
            float getVolume() const noexcept final;
            virtual void setVolume(float volume) override;

            //base is 1.0
            float getPitch() const noexcept final;
            virtual void setPitch(float pitch) override;

        protected:
            float _pitch;
            float _volume;

        private:
        };
    } // namespace encapsulation

} // namespace gameEngine




#endif /* !AAUDIOOBJECT_HPP_ */
