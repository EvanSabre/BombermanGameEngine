/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BMusic
*/

#include "BMusic.hpp"

using namespace gameEngine::encapsulation;

BMusic::BMusic(const std::string &filepath)
{
    try {
        this->load(filepath);
    } catch(const LoadingError &e) {
        throw e;
    }
}

BMusic::~BMusic()
{
    if (this->isLoad())
        this->unload();
}


//GETTER
Music BMusic::getObj() const noexcept
{
    return this->_music;
}

bool BMusic::isLoad() const noexcept
{
    return this->_load;
}


bool BMusic::isPlaying() const noexcept
{
    if (!this->isLoad())
        return false;

    return IsMusicStreamPlaying(this->_music);
}

float BMusic::getTimeLength() const noexcept
{
    return GetMusicTimeLength(this->_music);
}

float BMusic::getTimePlayed() const noexcept
{
    return GetMusicTimePlayed(this->_music);
}


//SETTTER
void BMusic::load(const std::string &filepath)
{
    if (this->isLoad())
        this->unload();
    this->_music = LoadMusicStream(filepath.c_str());
    if (this->_music.ctxType <= 0)
        throw LoadingError(filepath, "Loading Failed : ", "MUSIC");
    this->_load =  true;
}

void BMusic::unload() noexcept
{
    Music buf;
    buf.ctxData = nullptr;

    if (!this->isLoad())
        return;
    UnloadMusicStream(this->_music);
    this->_music = buf;
    this->_load = false;
}

//Transform
void BMusic::play()
{
    if (!isLoad())
        throw std::runtime_error("Music [PLAY]: no music load");
    PlayMusicStream(this->_music);
}

void BMusic::updateStream()
{
    if (!isLoad())
        throw engineError("update unload stream", "MUSIC");
    UpdateMusicStream(this->_music);
}

void BMusic::stop()
{
    if (!isLoad())
        throw engineError("Play unload Music", "MUSIC");
    StopMusicStream(this->_music);
}

void BMusic::pause()
{
    if (!isLoad())
        throw engineError("Pause unload Music", "MUSIC");
    PauseMusicStream(this->_music);
}

void BMusic::resume()
{
    if (!isLoad())
        throw engineError("Resume unload Music", "MUSIC");
    ResumeMusicStream(this->_music);
}

void BMusic::setVolume(float volume)
{
    if (!isLoad())
        throw engineError("Set volume on unload Music", "MUSIC");
    if (volume > 1.0f)
        volume = 1.0f;
    else if (volume < 0.0f)
        volume = 0.0f;
    SetMusicVolume(this->_music, volume);
    _volume = volume;
}

//base is 1.à
void BMusic::setPitch(float pitch)
{
    if (!isLoad())
        throw engineError("Set pitch on unload Music", "MUSIC");
    if (pitch < 0)
        pitch = 0;
    SetMusicPitch(this->_music, pitch);
    _pitch = pitch;
}
