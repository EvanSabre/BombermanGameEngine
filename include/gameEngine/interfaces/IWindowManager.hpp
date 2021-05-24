/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** IWindowManager
*/

#ifndef IWINDOWMANAGER_HPP_
#define IWINDOWMANAGER_HPP_

#include <string>
#include <unordered_map>
#include <vector>

namespace gameEngine {
    namespace Interfaces {
        class IWindowManager {
            public:
                virtual ~IWindowManager() = default;

                virtual bool createWindow(std::string name, Vector<int> size) = 0;
                virtual void deleteWindow(void) = 0;
                virtual void resizeWindow(int height, int width) = 0;

                virtual void setFullScreen(void) = 0;
                virtual void setBackgroundColor(Color color) = 0;
                virtual void set3DMode(camera camera) = 0;
                virtual void set2DMode(camera camera) = 0;

                virtual Vector<int> getWindowSize() const = 0;
        };
    }
}

#endif /* !IWINDOWMANAGER_HPP_ */
