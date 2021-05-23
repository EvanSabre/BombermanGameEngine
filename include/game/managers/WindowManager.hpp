/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** windowManager
*/

#ifndef WINDOWMANAGER_HPP_
#define WINDOWMANAGER_HPP_

#include "gameEngine/interfaces/IWindowManager.hpp"
#include <string>
#include <vector>

namespace game {
    namespace Managers {
        class WindowManager : public gameEngine::Interfaces::IWindowManager {
            public:
                WindowManager();
                ~WindowManager();

                bool createWindow(std::string name, int height, int width) final;
                void deleteWindow(void) final;
                void *getWindow(void) const;
                void resizeWindow(int height, int width);

                void setFullScreen(void);
                void setBackgroundColor(Color color);
                void set3DMode(camera camera);
                void set2DMode(camera camera);

            private:
                std::string _windowName;
                int _height;
                int _width;
                bool is3D;
                bool is2D;
        };
    }
}

#endif /* !WINDOWMANAGER_HPP_ */
