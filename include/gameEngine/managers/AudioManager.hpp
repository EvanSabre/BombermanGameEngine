/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** AudioManager
*/

#ifndef AUDIOMANAGER_HPP_
#define AUDIOMANAGER_HPP_

#include "IAudioManager.hpp"

namespace gameEngine {
    namespace managers {
        class AudioManager : public gameEngine::Interfaces::IAudioManager {
            public:
                AudioManager();
                ~AudioManager();

                Sound loadSoundromFile(char *filepath);

                void playSound(Sound sound);
                void pauseSound(Sound sound);
                void resumeSound(Sound sound);
                void stopSound(Sound sound);
                void setSoundVolume(Sound sound, float volume);

                Music loadMusicStreamFromFile(char *filepath);

                void playMusic(Music music);
                void pauseMusic(Music music);
                void resumeMusic(Music music);
                void stopMusic(Music music);
                void setMusicVolume(Music music, float volume);

                float getCurrentSoundVolume() const;
                float getCurrentMusicVolume() const;

            private:
                float _soundVolume;
                float _musicVolume;
        };
    }
}

#endif /* !AUDIOMANAGER_HPP_ */
