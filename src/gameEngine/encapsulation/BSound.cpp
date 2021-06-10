/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BSound
*/

#include "BSound.hpp"

using namespace gameEngine;

encapsulation::BSound::BSound(const std::string &filepath)
{
    try {
        this->load(filepath);
    } catch(const std::exception& e) {
        throw e;
    }
}

encapsulation::BSound::~BSound()
{
    if (this->isLoad())
        this->unload();
}

//GETTER
Sound encapsulation::BSound::getObj() const noexcept
{
    return this->_sound;
}

bool encapsulation::BSound::isLoad() const noexcept
{
    return this->_load;
}

bool encapsulation::BSound::isPlaying() const noexcept
{
    if (!this->isLoad())
        return false;
    return IsSoundPlaying(this->_sound);
}

//SETTTER
void encapsulation::BSound::load(const std::string &filepath)
{
    if (this->isLoad())
        this->unload();
    this->_sound = LoadSound(filepath.c_str());
    if (!this->_sound.stream.buffer)
        throw std::runtime_error("Sound : Loading failed");
    this->_load = true;
}

void encapsulation::BSound::unload() noexcept
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
void encapsulation::BSound::play()
{
    if (!isLoad())
        throw std::runtime_error("Sound [PLAY]: no Sound load");
    PlaySound(this->_sound);
}

void encapsulation::BSound::stop()
{
    if (!isLoad())
        throw std::runtime_error("Sound [STOP]: no Sound load");
    StopSound(this->_sound);
}

void encapsulation::BSound::pause()
{
    if (!isLoad())
        throw std::runtime_error("Sound [PAUSE]: no Sound load");
    PauseSound(this->_sound);
}

void encapsulation::BSound::resume()
{
    if (!isLoad())
        throw std::runtime_error("Sound [RESUME]: no Sound load");
    ResumeSound(this->_sound);
}

void encapsulation::BSound::setVolume(float volume)
{
    if (!isLoad())
        throw std::runtime_error("Sound [SET_VOLUME]: no Sound load");
    if (volume > 1.0f)
        volume = 1.0f;
    else if (volume < 0.0f)
        volume = 0.0f;
    SetSoundVolume(this->_sound, volume);
}

//base is 1.à
void encapsulation::BSound::setPitch(float pitch)
{
    if (!isLoad())
        throw std::runtime_error("Sound [SET_PITCH]: no Sound load");
    if (pitch < 0)
        pitch = 0;
    SetSoundPitch(this->_sound, pitch);
}