/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BAudio
*/

#include "BAudio.hpp"

using namespace gameEngine;

void encapsulation::BAudio::init()
{
    InitAudioDevice();
    if (!BAudio::isReady())
        throw std::runtime_error("BAudio: Init Failed");
}

void encapsulation::BAudio::close() noexcept
{
    CloseAudioDevice();
}

bool encapsulation::BAudio::isReady() noexcept
{
    return IsAudioDeviceReady();
}


//TODO: check max and min values
void encapsulation::BAudio::setVolume(float volume) noexcept
{
    if (volume < 0)
        volume = 0;
    else if (volume > 100)
        volume = 100;
    SetMasterVolume(volume);
}
