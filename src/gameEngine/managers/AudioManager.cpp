/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** AudioManager
*/

#include "gameEngine/managers/AudioManager.hpp"

using namespace gameEngine::managers;

AudioManager::AudioManager()
{
    InitAudioDevice();
    SetMasterVolume(100);
}

AudioManager::~AudioManager()
{
    if (IsAudioDeviceReady)
        CloseAudioDevice();
}

Sound AudioManager::loadSoundromFile(char *filepath)
{
    Sound sound;

    if (!filepath)
        return NULL;

    sound = LoadSound(filepath);
    return sound;
}

void AudioManager::playSound(Sound sound)
{
    PlaySound(sound);
}

void AudioManager::pauseSound(Sound sound)
{
    PauseSound(sound);
}

void AudioManager::resumeSound(Sound sound)
{
    ResumeSound(sound);
}

void AudioManager::stopSound(Sound sound)
{
    StopSound(sound);
}

void AudioManager::setSoundVolume(Sound sound, float volume)
{
    _soundVolume = volume;
    SetSoundVolume(sound, volume);
}

Music AudioManager::loadMusicStreamFromFile(char *filepath)
{
    Music music;

    if (!filepath)
        return NULL;

    music = LoadMusicStream(filepath);
    return music;
}

void AudioManager::playMusic(Music music)
{
    PlayMusicStream(music);
}

void AudioManager::pauseMusic(Music music)
{
    PauseMusicStream(music);
}

void AudioManager::resumeMusic(Music music)
{
    ResumeMusicStream(music);
}

void AudioManager::stopMusic(Music music)
{
    StopMusicStream(music);
}

void game::managers::AudioManager::setMusicVolume(Music music, float volume)
{
    _musicVolume = volume;
    SetMusicVolume(music, volume);
}

float game::managers::AudioManager::getCurrentSoundVolume() const
{
    return _soundVolume;
}

float game::managers::AudioManager::getCurrentMusicVolume() const
{
    return _musicVolume;
}