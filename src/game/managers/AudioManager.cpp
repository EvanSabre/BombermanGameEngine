/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** AudioManager
*/

#include "game/managers/AudioManager.hpp"

game::managers::AudioManager::AudioManager()
{
    InitAudioDevice();
    SetMasterVolume(100);
}

game::managers::AudioManager::~AudioManager()
{
    if (IsAudioDeviceReady)
        CloseAudioDevice();
}

Sound game::managers::AudioManager::loadSoundromFile(char *filepath)
{
    Sound sound;

    if (!filepath)
        return NULL;

    sound = LoadSound(filepath);
    return sound;
}

void game::managers::AudioManager::playSound(Sound sound)
{
    PlaySound(sound);
}

void game::managers::AudioManager::pauseSound(Sound sound)
{
    PauseSound(sound);
}

void game::managers::AudioManager::resumeSound(Sound sound)
{
    ResumeSound(sound);
}

void game::managers::AudioManager::stopSound(Sound sound)
{
    StopSound(sound);
}

void game::managers::AudioManager::setSoundVolume(Sound sound, float volume)
{
    _soundVolume = volume;
    SetSoundVolume(sound, volume);
}

Music game::managers::AudioManager::loadMusicStreamFromFile(char *filepath)
{
    Music music;

    if (!filepath)
        return NULL;

    music = LoadMusicStream(filepath);
    return music;
}

void game::managers::AudioManager::playMusic(Music music)
{
    PlayMusicStream(music);
}

void game::managers::AudioManager::pauseMusic(Music music)
{
    PauseMusicStream(music);
}

void game::managers::AudioManager::resumeMusic(Music music)
{
    ResumeMusicStream(music);
}

void game::managers::AudioManager::stopMusic(Music music)
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