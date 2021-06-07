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
#include "AAudioObject.hpp"
#include "raylib.h"

namespace gameEngine
{
    namespace encapsulation
    {
        class BSound : public gameEngine::encapsulation::AAudioObject
        {
        public:
            BSound(const std::string &filepath);
            BSound(const BSound &ref) = delete;
            BSound &operator=(const BSound &ref) = delete;
            ~BSound();

            //getter
                [[nodiscard]] Sound getObj() const noexcept;
                [[nodiscard]] bool isLoad() const noexcept;
                [[nodiscard]] bool isPlaying() const noexcept override;

            //setter
            // Load image from file into CPU memory (RAM)
                void load(const std::string &filpath);
                void unload() noexcept;

            //transform
            //throw runtime_error if no Sound is loaded
                void play() override;
                void stop() override;
                void pause() override;
                void resume() override;

                //max is
                    void setVolume(float volume) override;

                //base is 1.0
                    void setPitch(float pitch) override;

        private:
            Sound _sound;
            bool _load;
        };
    }
}

#endif /* !BSOUND_HPP_ */
