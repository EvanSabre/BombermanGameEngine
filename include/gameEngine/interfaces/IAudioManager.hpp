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

namespace gameEngine {
    namespace Interfaces {
        class IAudioManager {
            public:
                virtual ~IAudioManager() = default;

                virtual Sound loadSoundromFile(char *filepath) = 0;

                virtual void playSound(Sound sound) = 0;
                virtual void pauseSound(Sound sound) = 0;
                virtual void resumeSound(Sound sound) = 0;
                virtual void stopSound(Sound sound) = 0;
                virtual void setSoundVolume(Sound sound, float volume) = 0;

                virtual Music loadMusicStreamFromFile(char *filepath) = 0;

                virtual void playMusic(Music music) = 0;
                virtual void pauseMusic(Music music) = 0;
                virtual void resumeMusic(Music music) = 0;
                virtual void stopMusic(Music music) = 0;
                virtual void setMusicVolume(Music music, float volume) = 0;

                virtual float getCurrentSoundVolume() const = 0;
                virtual float getCurrentMusicVolume() const = 0;
        };
    }
}

#endif /* !IAUDIOMANAGER_HPP_ */
