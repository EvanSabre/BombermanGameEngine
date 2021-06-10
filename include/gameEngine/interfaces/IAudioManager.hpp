/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** IAudioManager
*/

#ifndef IAUDIOMANAGER_HPP_
#define IAUDIOMANAGER_HPP_

#include <string>
#include <unordered_map>
#include <vector>

#include <AAudioObject.hpp>
#include <BSound.hpp>
#include <BMusic.hpp>

using namespace gameEngine::encapsulation;

namespace gameEngine
{
    namespace Interfaces {
        class IAudioManager {
            public:
                virtual ~IAudioManager() = default;

                virtual void loadSoundFromFile(const char *filepath) = 0;

                virtual void playSound() = 0;
                virtual void pauseSound() = 0;
                virtual void resumeSound() = 0;
                virtual void stopSound() = 0;
                virtual void setSoundVolume(float volume) = 0;

                virtual void loadMusicStreamFromFile(const char *filepath) = 0;
                virtual void updateMusicStream() = 0;

                virtual void playMusic() = 0;
                virtual void pauseMusic() = 0;
                virtual void resumeMusic() = 0;
                virtual void stopMusic() = 0;
                virtual void setMusicVolume(float volume) = 0;

                virtual float getCurrentSoundVolume() const = 0;
                virtual float getCurrentMusicVolume() const = 0;
        };
    }
}

#endif /* !IAUDIOMANAGER_HPP_ */
