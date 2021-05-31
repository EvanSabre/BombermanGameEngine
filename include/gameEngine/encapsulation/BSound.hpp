/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BSound
*/

#ifndef BSOUND_HPP_
#define BSOUND_HPP_

#include <string>
#include <stdexcept>
#include "raylib.h"


namespace gameEngine
{
    namespace encapsulation
    {
        class BSound
        {
        public:
            BSound(const std::string &filepath);
            BSound(const BSound &ref) = delete;
            BSound &operator=(const BSound &ref) = delete;
            ~BSound();

            //getter
                [[nodiscard]] Sound getObj() const noexcept;
                [[nodiscard]] bool isLoad() const noexcept;
                [[nodiscard]] bool isPlaying() const noexcept;

            //setter
            // Load image from file into CPU memory (RAM)
                void load(const std::string &filpath);

                void unload() noexcept;

            //transform
            //throw runtime_error if no Sound is loaded
                void play();
                void stop();
                void pause();
                void resumeStream();

                //max is 1.00
                void setVolume(float volume);
                //base is 1.à
                void setPitch(float pitch);

        protected:
        private:
            Sound _sound = {0};
            bool _load;
        };
    }
}

#endif /* !BSOUND_HPP_ */
