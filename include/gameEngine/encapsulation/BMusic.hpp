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
#include "raylib.h"

namespace gameEngine
{
    namespace encapsulation
    {
        class BMusic
        {
        public:
            BMusic(const std::string &filepath);
            BMusic(const BMusic &ref) = delete;
            BMusic &operator=(const BMusic &ref) = delete;
            ~BMusic();

            //getter
                [[nodiscard]] Music getObj() const noexcept;
                [[nodiscard]] bool isLoad() const noexcept;
                [[nodiscard]] bool isPlaying() const noexcept;
                [[nodiscard]] float getTimeLength() const noexcept;
                [[nodiscard]] float getTimePlayed() const noexcept;

            //setter
            // Load image from file into CPU memory (RAM)
                void load(const std::string &filpath);

                void unload() noexcept;

            //transform
            //throw runtime_error if no music is loaded
                void play();
                void updateStream();
                void stop();
                void pause();
                void resumeStream();

                //max is 1.00
                void setVolume(float volume);
                //base is 1.à
                void setPitch(float pitch);

        protected:
        private:
            Music _music = {0};
            bool _load;
        };
    }
}

#endif /* !BMUSIC_HPP_ */
