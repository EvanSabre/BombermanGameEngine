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
    if (!IsAudioDeviceReady())
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

void AudioManager::unloadSoundStream()
{
    _sound->unload();
}

void AudioManager::playSound()
{
    if (_sound->isLoad())
        _sound->play();
}

void AudioManager::pauseSound()
{
    if (_sound->isLoad())
        _sound->pause();
}

void AudioManager::resumeSound()
{
    if (_sound->isLoad())
        _sound->resume();
}

void AudioManager::stopSound()
{
    if (_sound->isLoad())
        _sound->stop();
}

void AudioManager::setSoundVolume(float volume)
{
    _soundVolume = volume;
    _sound->setVolume(volume);
}

void AudioManager::loadMusicStreamFromFile(const char *filepath)
{
    _music = std::make_unique<BMusic>(filepath);
}

void AudioManager::unloadMusicStream()
{
    _music->unload();
}

void AudioManager::updateMusicStream()
{
    if (_music->isLoad())
        _music->updateStream();
}

void AudioManager::playMusic()
{
    if (_music->isLoad())
        _music->play();
}

void AudioManager::pauseMusic()
{
    if (_music->isLoad())
        _music->pause();
}

void AudioManager::resumeMusic()
{
    if (_music->isLoad())
        _music->resume();
}

void AudioManager::stopMusic()
{
    if (_music->isLoad())
        _music->stop();
}

void AudioManager::setMusicVolume(float volume)
{
    _musicVolume = volume;
    _music->setVolume(volume);
}

float AudioManager::getCurrentSoundVolume() const
{
    return _soundVolume;
}

float AudioManager::getCurrentMusicVolume() const
{
    return _musicVolume;
}
