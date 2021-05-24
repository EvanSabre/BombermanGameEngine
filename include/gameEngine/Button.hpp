/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Button
*/

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include "Vector.hpp"
#include <string>


namespace gameEngine {
    class Button {

        enum State {
            NORMAL,
            MOUSE_HOVER,
            PRESSED
        };

        public:
            Button(Vector<double> pos, Vector<double> size, const std::string &content);
            ~Button();

            Vector<double> getPos() const;
            Vector<double> getSize() const;
            std::string getContent() const;
        private:
            Vector<double> _pos;
            Vector<double> _size;
            std::string _content;
            bool _buttonPressed;
            //gameEngine::Texture _texture;
            //gameEngine::Rectangle _rectangle
            
    };
}

#endif /* !BUTTON_HPP_ */
