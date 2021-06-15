/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** IInput
*/

#ifndef IINPUT_HPP_
#define IINPUT_HPP_

#include <stdlib.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>


namespace gameEngine
{
    enum Key
    {
        KEY_NULL            = 0,
        KEY_APOSTROPHE      = 39,
        KEY_COMMA           = 44,
        KEY_MINUS           = 45,
        KEY_PERIOD          = 46,
        KEY_SLASH           = 47,
        KEY_ZERO            = 48,
        KEY_ONE             = 49,
        KEY_TWO             = 50,
        KEY_THREE           = 51,
        KEY_FOUR            = 52,
        KEY_FIVE            = 53,
        KEY_SIX             = 54,
        KEY_SEVEN           = 55,
        KEY_EIGHT           = 56,
        KEY_NINE            = 57,
        KEY_SEMICOLON       = 59,
        KEY_EQUAL           = 61,
        KEY_A               = 65,
        KEY_B               = 66,
        KEY_C               = 67,
        KEY_D               = 68,
        KEY_E               = 69,
        KEY_F               = 70,
        KEY_G               = 71,
        KEY_H               = 72,
        KEY_I               = 73,
        KEY_J               = 74,
        KEY_K               = 75,
        KEY_L               = 76,
        KEY_M               = 77,
        KEY_N               = 78,
        KEY_O               = 79,
        KEY_P               = 80,
        KEY_Q               = 81,
        KEY_R               = 82,
        KEY_S               = 83,
        KEY_T               = 84,
        KEY_U               = 85,
        KEY_V               = 86,
        KEY_W               = 87,
        KEY_X               = 88,
        KEY_Y               = 89,
        KEY_Z               = 90,
        KEY_SPACE           = 32,
        KEY_ESCAPE          = 256,
        KEY_ENTER           = 257,
        KEY_TAB             = 258,
        KEY_BACKSPACE       = 259,
        KEY_INSERT          = 260,
        KEY_DELETE          = 261,
        KEY_RIGHT           = 262,
        KEY_LEFT            = 263,
        KEY_DOWN            = 264,
        KEY_UP              = 265,
        KEY_PAGE_UP         = 266,
        KEY_PAGE_DOWN       = 267,
        KEY_HOME            = 268,
        KEY_END             = 269,
        KEY_CAPS_LOCK       = 280,
        KEY_SCROLL_LOCK     = 281,
        KEY_NUM_LOCK        = 282,
        KEY_PRINT_SCREEN    = 283,
        KEY_PAUSE           = 284,
        KEY_F1              = 290,
        KEY_F2              = 291,
        KEY_F3              = 292,
        KEY_F4              = 293,
        KEY_F5              = 294,
        KEY_F6              = 295,
        KEY_F7              = 296,
        KEY_F8              = 297,
        KEY_F9              = 298,
        KEY_F10             = 299,
        KEY_F11             = 300,
        KEY_F12             = 301,
        KEY_LEFT_SHIFT      = 340,
        KEY_LEFT_CONTROL    = 341,
        KEY_LEFT_ALT        = 342,
        KEY_LEFT_SUPER      = 343,
        KEY_RIGHT_SHIFT     = 344,
        KEY_RIGHT_CONTROL   = 345,
        KEY_RIGHT_ALT       = 346,
        KEY_RIGHT_SUPER     = 347,
        KEY_KB_MENU         = 348,
        KEY_LEFT_BRACKET    = 91,
        KEY_BACKSLASH       = 92,
        KEY_RIGHT_BRACKET   = 93,
        KEY_GRAVE           = 96,
        KEY_KP_0            = 320,
        KEY_KP_1            = 321,
        KEY_KP_2            = 322,
        KEY_KP_3            = 323,
        KEY_KP_4            = 324,
        KEY_KP_5            = 325,
        KEY_KP_6            = 326,
        KEY_KP_7            = 327,
        KEY_KP_8            = 328,
        KEY_KP_9            = 329,
        KEY_KP_DECIMAL      = 330,
        KEY_KP_DIVIDE       = 331,
        KEY_KP_MULTIPLY     = 332,
        KEY_KP_SUBTRACT     = 333,
        KEY_KP_ADD          = 334,
        KEY_KP_ENTER        = 335,
        KEY_KP_EQUAL        = 336,
        KEY_BACK            = 4,
        KEY_MENU            = 82,
        KEY_VOLUME_UP       = 24,
        KEY_VOLUME_DOWN     = 25,
        //TODO: rajouter + 400 au get_key return du gamepad
        //TODO: enlever -400 au get_key return du gamepad
        GAMEPAD_BUTTON_LEFT_FACE_UP = 401,
        GAMEPAD_BUTTON_LEFT_FACE_RIGHT = 402,
        GAMEPAD_BUTTON_LEFT_FACE_DOWN = 403,
        GAMEPAD_BUTTON_LEFT_FACE_LEFT = 404,

        // This normally corresponds with PlayStation and Xbox controllers
        // XBOX: [Y,X,A,B]
        // PS3: [Triangle,Square,Cross,Circle]
        // No support for 6 button controllers though..
        GAMEPAD_BUTTON_RIGHT_FACE_UP = 405,
        GAMEPAD_BUTTON_RIGHT_FACE_RIGHT = 405,
        GAMEPAD_BUTTON_RIGHT_FACE_DOWN = 406,
        GAMEPAD_BUTTON_RIGHT_FACE_LEFT = 407,

        // Triggers
        GAMEPAD_BUTTON_LEFT_TRIGGER_1 = 408,
        GAMEPAD_BUTTON_LEFT_TRIGGER_2 = 409,
        GAMEPAD_BUTTON_RIGHT_TRIGGER_1 = 410,
        GAMEPAD_BUTTON_RIGHT_TRIGGER_2 = 411,

        // These are buttons in the center of the gamepad
        GAMEPAD_BUTTON_MIDDLE_LEFT = 412,     // PS3 Select
        GAMEPAD_BUTTON_MIDDLE = 413,          // PS Button/XBOX Button
        GAMEPAD_BUTTON_MIDDLE_RIGHT = 414,    // PS3 Start

        // These are the joystick press in buttons
        GAMEPAD_BUTTON_LEFT_THUMB = 415,
        GAMEPAD_BUTTON_RIGHT_THUMB = 416
    };


    namespace interfaces
    {
        class IInput
        {
            public:
                virtual ~IInput() = default;
                virtual bool isKeyPressed(int key) = 0;
                virtual bool isKeyDown(int key) = 0;
                virtual bool isKeyUp(int key) = 0;
                virtual bool isKeyReleased(int key) = 0;
                virtual const std::string getDeviceName() = 0;
                virtual bool isDeviceAvailable(void) = 0;
                virtual bool isDeviceName(const char *name) = 0;
                virtual int getKeyPressed(void) = 0;
                virtual int getDeviceID(void) = 0;

        };
    }
    typedef std::unordered_map<int, std::shared_ptr<gameEngine::interfaces::IInput>> UserInputs; // <id, Keyboard or Gamepad>
    typedef bool (gameEngine::interfaces::IInput::*InputFunc)(int);

    typedef std::pair<gameEngine::Key, gameEngine::Key> AttachedKeys;
    typedef std::pair<gameEngine::InputFunc, AttachedKeys> Controller;
}

#endif /* !IINPUT_HPP_ */
