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
                IWindowManager();
                ~IWindowManager();

                virtual bool createWindow(std::string name, int height, int width);
                virtual void deleteWindow(void);
                virtual void *getWindow(void) const;
                virtual void resizeWindow(int height, int width);

                virtual void setFullScreen(void);
                virtual void setBackgroundColor(Color color);
                virtual void set3DMode(camera camera);
                virtual void set2DMode(camera camera);
        };
    }
}

#endif /* !IWINDOWMANAGER_HPP_ */
