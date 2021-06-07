/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** IAudioObject
*/

#ifndef IAUDIOOBJECT_HPP_
#define IAUDIOOBJECT_HPP_

namespace gameEngine
{
    namespace interfaces
    {
        class IAudioObject {
        public:
            virtual ~IAudioObject() = default;

            virtual void play() = 0;
            virtual void stop() = 0;
            virtual void pause() = 0;
            virtual void resume() = 0;

            virtual bool isPlaying() const = 0;

            //max is
            virtual float getVolume() const noexcept = 0;
            virtual void setVolume(float volume) = 0;
            //base is 1.0
            virtual float getPitch() const noexcept = 0;
            virtual void setPitch(float pitch) = 0;

        };
    } // namespace interfaces


} // namespace gameEngine

#endif /* !IAUDIOOBJECT_HPP_ */
