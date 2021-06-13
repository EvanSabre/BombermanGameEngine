/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** windowManager
*/

#ifndef WINDOWMANAGER_HPP_
#define WINDOWMANAGER_HPP_

#include <string>
#include <vector>
#include <iostream>
#include "Vector.hpp"
#include "IWindowManager.hpp"
#include "BColor.hpp"

namespace gameEngine {
    namespace managers {
        class WindowManager : public gameEngine::interfaces::IWindowManager {
            public:
                WindowManager();
                ~WindowManager();

                bool createWindow(std::string name, Vector<int> size) final;
                void deleteWindow(void) final;
                void resizeWindow(const Vector<int> &size) final;
                bool isRunning() const noexcept final;

                void BeginDraw() final;
                void EndDraw() final;
                void setFullScreen(void) final;
                void clear() noexcept;
                void clear(const gameEngine::encapsulation::BColor &color) final;
                void setBackgroundColor(const gameEngine::encapsulation::BColor &color) final;
                void set3DMode(const gameEngine::encapsulation::BCamera &camera) final;
                void set2DMode(const gameEngine::encapsulation::BCamera2D &camera) final;

                Vector<int> getWindowSize() const final;

                // set icon image ??
                // get Monitor size for windows max width/height ?

            private:
                std::string _windowName;
                Vector<int> _size{0, 0};
                gameEngine::encapsulation::BColor _color{{255, 255, 255, 255}};
                bool is3D;
                bool is2D;
        };
    }
}

#endif /* !WINDOWMANAGER_HPP_ */
