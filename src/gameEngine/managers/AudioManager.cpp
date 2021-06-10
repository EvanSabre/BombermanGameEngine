/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** AudioManager
*/

#include "AudioManager.hpp"

using namespace gameEngine::encapsulation;
using namespace gameEngine::managers;

AudioManager::AudioManager()
{
    InitAudioDevice();
    SetMasterVolume(100);
}

AudioManager::~AudioManager()
{
    if (IsAudioDeviceReady())
        CloseAudioDevice();
}

void AudioManager::loadSoundFromFile(const char *filepath)
{
    _sound = std::make_unique<BSound>(filepath);
}

void AudioManager::playSound()
{
    if (_sound->isLoad())
        PlaySound(_sound->getObj());
}

void AudioManager::pauseSound()
{
    if (_sound->isLoad())
        PauseSound(_sound->getObj());
}

void AudioManager::resumeSound()
{
    if (_sound->isLoad())
        ResumeSound(_sound->getObj());
}

void AudioManager::stopSound()
{
    if (_sound->isLoad())
        StopSound(_sound->getObj());
}

void AudioManager::setSoundVolume(float volume)
{
    _soundVolume = volume;
    SetSoundVolume(_sound->getObj(), volume);
}

void AudioManager::loadMusicStreamFromFile(const char *filepath)
{
    _music = std::make_unique<BMusic>(filepath);
}

void AudioManager::updateMusicStream()
{
    UpdateMusicStream(_music->getObj());
}

void AudioManager::playMusic()
{
    if (_music->isLoad())
        PlayMusicStream(_music->getObj());
}

void AudioManager::pauseMusic()
{
    if (_music->isLoad())
        PauseMusicStream(_music->getObj());
}

void AudioManager::resumeMusic()
{
    if (_music->isLoad())
        ResumeMusicStream(_music->getObj());
}

void AudioManager::stopMusic()
{
    if (_music->isLoad())
        StopMusicStream(_music->getObj());
}

void AudioManager::setMusicVolume(float volume)
{
    _musicVolume = volume;
    SetMusicVolume(_music->getObj(), volume);
}

float AudioManager::getCurrentSoundVolume() const
{
    return _soundVolume;
}

float AudioManager::getCurrentMusicVolume() const
{
    return _musicVolume;
}