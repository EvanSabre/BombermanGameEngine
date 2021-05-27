/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BMusic
*/

#include "BMusic.hpp"

using namespace gameEngine;

encapsulation::BMusic::BMusic(const std::string &filepath)
{
    try {
        this->load(filepath);
    } catch(const std::exception& e) {
        throw e;
    }
}

encapsulation::BMusic::~BMusic()
{
    if (this->isLoad())
        this->unload();
}


//GETTER
Music encapsulation::BMusic::getObj() const noexcept
{
    return this->_music;
}

bool encapsulation::BMusic::isLoad() const noexcept
{
    return this->_load;
}


bool encapsulation::BMusic::isPlaying() const noexcept
{
    if (!this->isLoad())
        return false;
    return IsMusicPlaying(this->_music);
}

float encapsulation::BMusic::getTimeLength() const noexcept
{
    return GetMusicTimeLength(this->_music);
}

float encapsulation::BMusic::getTimePlayed() const noexcept
{
    return GetMusicTimePlayed(this->_music);
}


//SETTTER
void encapsulation::BMusic::load(const std::string &filepath)
{
    if (this->isLoad())
        this->unload();
    this->_music = LoadMusicStream(filepath.c_str());
    if (this->_music.ctxType <= 0)
        throw std::runtime_error("Music : Loading failed");
    this->_load =  true;
}

void encapsulation::BMusic::unload() noexcept
{
    Music buf = {0};

    if (!this->isLoad())
        return;
    UnloadMusicStream(this->_music);
    this->_music = buf;
    this->_load = false;
}

//Transform
void encapsulation::BMusic::play()
{
    if (!isLoad())
        throw std::runtime_error("Music [PLAY]: no music load");
    PlayMusicStream(this->_music);
}

void encapsulation::BMusic::updateStream()
{
    if (!isLoad())
        throw std::runtime_error("Music [UPDATE_STREAM]: no music load");
    UpdateMusicStream(this->_music);
}

void encapsulation::BMusic::stop()
{
    if (!isLoad())
        throw std::runtime_error("Music [STOP]: no music load");
    StopMusicStream(this->_music);
}

void encapsulation::BMusic::pause()
{
    if (!isLoad())
        throw std::runtime_error("Music [PAUSE]: no music load");
    PauseMusicStream(this->_music);
}

void encapsulation::BMusic::resumeStream()
{
    if (!isLoad())
        throw std::runtime_error("Music [RESUME]: no music load");
    ResumeMusicStream(this->_music);
}

void encapsulation::BMusic::setVolume(float volume)
{
    if (!isLoad())
        throw std::runtime_error("Music [SET_VOLUME]: no music load");
    if (volume > 1.0f)
        volume = 1.0f;
    else if (volume < 0.0f)
        volume = 0.0f;
    SetMusicVolume(this->_music, volume);
}

//base is 1.à
void encapsulation::BMusic::setPitch(float pitch)
{
    if (!isLoad())
        throw std::runtime_error("Music [SET_PITCH]: no music load");
    if (pitch < 0)
        pitch = 0;
    SetMusicPitch(this->_music, pitch);
}
