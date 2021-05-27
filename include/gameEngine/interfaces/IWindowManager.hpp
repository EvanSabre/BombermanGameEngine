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
#include "BColor.hpp"
#include "BCamera.hpp"
#include "BCamera2D.hpp"

namespace gameEngine {
    namespace Interfaces {
        class IWindowManager {
            public:
                virtual ~IWindowManager() = default;

                virtual bool createWindow(std::string name, Vector<int> size) = 0;
                virtual void deleteWindow(void) = 0;
                virtual void resizeWindow(const Vector<int> &size) = 0;

                virtual void setFullScreen(void) = 0;
                virtual void setBackgroundColor(const encapsulation::BColor &color) = 0;
                virtual void set3DMode(const encapsulation::BCamera &camera) = 0;
                virtual void set2DMode(const encapsulation::BCamera2D &camera) = 0;

                virtual Vector<int> getWindowSize() const = 0;
        };
    }
}

#endif /* !IWINDOWMANAGER_HPP_ */
