/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BSound
*/

#include "BSound.hpp"

using namespace gameEngine::encapsulation;

BSound::BSound(const std::string &filepath)
    : _load(false)
{
    try {
        this->load(filepath);
    } catch(const LoadingError &e) {
        throw e;
    }
}

BSound::~BSound()
{
    if (this->isLoad())
        this->unload();
}

//GETTER
Sound BSound::getObj() const noexcept
{
    return this->_sound;
}

bool BSound::isLoad() const noexcept
{
    return this->_load;
}

bool BSound::isPlaying() const noexcept
{
    if (!this->isLoad())
        return false;
    return IsSoundPlaying(this->_sound);
}

//SETTTER
void BSound::load(const std::string &filepath)
{
    if (this->isLoad())
        this->unload();
    this->_sound = LoadSound(filepath.c_str());
    if (!this->_sound.stream.buffer)
        throw LoadingError(filepath, "Loading Failed : ", "SOUND");
    this->_load = true;
}

void BSound::unload() noexcept
{
    Sound buf;
    buf.stream.buffer = nullptr;

    if (!this->isLoad())
        return;
    UnloadSound(this->_sound);
    this->_sound = buf;
    this->_load = false;
}

//Transform
void BSound::play()
{
    if (!isLoad())
        throw engineError("Play unload Sound", "SOUND");
    PlaySound(this->_sound);
}

void BSound::stop()
{
    if (!isLoad())
        throw engineError("Stop unload Sound", "SOUND");
    StopSound(this->_sound);
}

void BSound::pause()
{
    if (!isLoad())
        throw engineError("Pause unload Sound", "SOUND");
    PauseSound(this->_sound);
}

void BSound::resume()
{
    if (!isLoad())
        throw engineError("Resume unload Sound", "SOUND");
    ResumeSound(this->_sound);
}

void BSound::setVolume(float volume)
{
    std::cout << "AVANT" << std::endl;
    if (!isLoad())
        throw engineError("Volume set on unload Sound", "SOUND");
    if (volume > 1.0f)
        volume = 1.0f;
    else if (volume < 0.0f)
        volume = 0.0f;
    SetSoundVolume(this->_sound, volume);
    std::cout << "APRES" << std::endl;
}

//base is 1.à
void BSound::setPitch(float pitch)
{
    if (!isLoad())
        throw engineError("Pitch set on unload Sound", "SOUND");
    if (pitch < 0)
        pitch = 0;
    SetSoundPitch(this->_sound, pitch);
}
