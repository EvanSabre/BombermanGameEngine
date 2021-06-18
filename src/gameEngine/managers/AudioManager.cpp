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
: _musicVolume(100), _soundVolume(100)
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

void AudioManager::loadSoundFromFile(const char *filepath, std::string name)
{
    std::pair<std::string, std::shared_ptr<BSound>> pair = std::make_pair(name, std::make_shared<BSound>(filepath));
    _sounds.insert(pair);
}

void AudioManager::unloadSoundStream(std::string sound)
{
    _sounds.find(sound)->second->unload();
}

void AudioManager::playSound(std::string sound)
{
    if (_sounds.find(sound)->second->isLoad()) {
        _sounds.find(sound)->second->play();
        std::cout << "SOUND PLAYEEEDDDDD" << std::endl;
    }
}

void AudioManager::pauseSound(std::string sound)
{
    if (_sounds.find(sound)->second->isLoad())
        _sounds.find(sound)->second->pause();
}

void AudioManager::resumeSound(std::string sound)
{
    if (_sounds.find(sound)->second->isLoad())
        _sounds.find(sound)->second->resume();
}

void AudioManager::stopSound(std::string sound)
{
    if (_sounds.find(sound)->second->isLoad())
        _sounds.find(sound)->second->stop();
}

void AudioManager::setSoundVolume(float volume)
{
    _soundVolume = volume;
    for (std::pair<std::string, std::shared_ptr<BSound>> sound : _sounds)
    {
        sound.second->setVolume(volume);
    }
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
