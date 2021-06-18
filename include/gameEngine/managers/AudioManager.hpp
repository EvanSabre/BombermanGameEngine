/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** AudioManager
*/

#ifndef AUDIOMANAGER_HPP_
#define AUDIOMANAGER_HPP_

#include "IAudioManager.hpp"
#include <memory>

using namespace gameEngine::encapsulation;

namespace gameEngine {
    namespace managers {
        class AudioManager : public gameEngine::Interfaces::IAudioManager {
            public:
                AudioManager();
                ~AudioManager();

                void loadSoundFromFile(const char *filepath);
                void unloadSoundStream();

                void playSound();
                void pauseSound();
                void resumeSound();
                void stopSound();
                void setSoundVolume(float volume);

                void loadMusicStreamFromFile(const std::string &filepath);
                void unloadMusicStream();
                void updateMusicStream();

                void playMusic();
                void pauseMusic();
                void resumeMusic();
                void stopMusic();
                void setMusicVolume(float volume);

                float getCurrentSoundVolume() const;
                float getCurrentMusicVolume() const;

            private:
                std::unique_ptr<BSound> _sound;
                std::unique_ptr<BMusic> _music;
                float _soundVolume;
                float _musicVolume;
        };
    }
}

#endif /* !AUDIOMANAGER_HPP_ */
