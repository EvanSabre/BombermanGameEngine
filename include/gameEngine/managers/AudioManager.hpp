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
#include <unordered_map>

using namespace gameEngine::encapsulation;

namespace gameEngine {
    namespace managers {
        class AudioManager : public gameEngine::Interfaces::IAudioManager {
            public:
                AudioManager();
                ~AudioManager();

                void loadSoundFromFile(const char *filepath, std::string name);
                void unloadSoundStream(std::string name);

                void playSound(std::string name);
                void pauseSound(std::string name);
                void resumeSound(std::string name);
                void stopSound(std::string name);
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
                std::unordered_map<std::string, std::shared_ptr<BSound>> _sounds;
                std::unique_ptr<BMusic> _music;
                float _musicVolume;
                float _soundVolume;
        };
    }
}

#endif /* !AUDIOMANAGER_HPP_ */
