/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** windowManager
*/

#ifndef WINDOWMANAGER_HPP_
#define WINDOWMANAGER_HPP_

#include "gameEngine/interfaces/IWindowManager.hpp"
#include "Vector.hpp"
#include <string>
#include <vector>

namespace game {
    namespace Managers {
        class WindowManager : public gameEngine::Interfaces::IWindowManager {
            public:
                WindowManager();
                ~WindowManager();

                bool createWindow(std::string name, Vector<int> size) final;
                void deleteWindow(void) final;
                void resizeWindow(int height, int width) final;

                void setFullScreen(void) final;
                void setBackgroundColor(Color color) final;
                void set3DMode(camera camera) final;
                void set2DMode(camera camera) final;

                Vector<int> getWindowSize() const final;

                // set icon image ??
                // get Monitor size for windows max width/height ?

            private:
                std::string _windowName;
                Vector<int> _size;
                bool is3D;
                bool is2D;
        };
    }
}

#endif /* !WINDOWMANAGER_HPP_ */
