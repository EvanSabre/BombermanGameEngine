/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BMusic
*/

#ifndef BMUSIC_HPP_
#define BMUSIC_HPP_

#include <iostream>
#include <string>
#include <stdexcept>
#include "AAudioObject.hpp"
#include "raylib.h"
#include "Errors.hpp"

namespace gameEngine
{
    namespace encapsulation
    {
        class BMusic : gameEngine::encapsulation::AAudioObject
        {
        public:
            BMusic(const std::string &filepath);
            BMusic(const BMusic &ref) = delete;
            BMusic &operator=(const BMusic &ref) = delete;
            ~BMusic();

            //getter
                [[nodiscard]] Music getObj() const noexcept;
                [[nodiscard]] bool isLoad() const noexcept;
                [[nodiscard]] float getTimeLength() const noexcept;
                [[nodiscard]] float getTimePlayed() const noexcept;
                [[nodiscard]] bool isPlaying() const noexcept override;

            //setter
            // Load image from file into CPU memory (RAM)
                void load(const std::string &filpath);
                void unload() noexcept;

            //transform
            //throw runtime_error if no music is loaded
                void updateStream();
                void play() override;
                void stop() override;
                void pause() override;
                void resume() override;

                //max is
                    void setVolume(float volume) override;

                //base is 1.0
                    void setPitch(float pitch) override;

        private:
            Music _music;
            bool _load = false;
        };
    }
}

#endif /* !BMUSIC_HPP_ */
