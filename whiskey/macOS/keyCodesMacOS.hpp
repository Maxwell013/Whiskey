// keyCodesMacOS.hpp
#pragma once

#include "../keyCodes.hpp"

namespace wsky {

    enum KeyCodesMacOS : unsigned short {

    // Character keys
    MACOS_KEY_SPACE              = 49,
    MACOS_KEY_APOSTROPHE         = 39,
    MACOS_KEY_COMMA              = 43,
    MACOS_KEY_MINUS              = 27,
    MACOS_KEY_PERIOD             = 47,
    MACOS_KEY_SLASH              = 44,
    MACOS_KEY_0                  = 29,
    MACOS_KEY_1                  = 18,
    MACOS_KEY_2                  = 19,
    MACOS_KEY_3                  = 20,
    MACOS_KEY_4                  = 21,
    MACOS_KEY_5                  = 23,
    MACOS_KEY_6                  = 22,
    MACOS_KEY_7                  = 26,
    MACOS_KEY_8                  = 28,
    MACOS_KEY_9                  = 25,
    MACOS_KEY_SEMICOLON          = 41,
    MACOS_KEY_EQUAL              = 24,
    MACOS_KEY_A                  = 0,
    MACOS_KEY_B                  = 11,
    MACOS_KEY_C                  = 8,
    MACOS_KEY_D                  = 2,
    MACOS_KEY_E                  = 14,
    MACOS_KEY_F                  = 3,
    MACOS_KEY_G                  = 5,
    MACOS_KEY_H                  = 4,
    MACOS_KEY_I                  = 34,
    MACOS_KEY_J                  = 38,
    MACOS_KEY_K                  = 40,
    MACOS_KEY_L                  = 37,
    MACOS_KEY_M                  = 46,
    MACOS_KEY_N                  = 45,
    MACOS_KEY_O                  = 31,
    MACOS_KEY_P                  = 35,
    MACOS_KEY_Q                  = 12,
    MACOS_KEY_R                  = 15,
    MACOS_KEY_S                  = 1,
    MACOS_KEY_T                  = 17,
    MACOS_KEY_U                  = 32,
    MACOS_KEY_V                  = 9,
    MACOS_KEY_W                  = 13,
    MACOS_KEY_X                  = 7,
    MACOS_KEY_Y                  = 16,
    MACOS_KEY_Z                  = 6,
    MACOS_KEY_LEFT_BRACKET       = 33,
    MACOS_KEY_BACKSLASH          = 42,
    MACOS_KEY_RIGHT_BRACKET      = 30,
    MACOS_KEY_GRAVE_ACCENT       = 50,

    // Function keys
    MACOS_KEY_ESCAPE             = 53,
    MACOS_KEY_ENTER              = 36,
    MACOS_KEY_TAB                = 48,
    MACOS_KEY_BACKSPACE          = 51,
    MACOS_KEY_INSERT             = 114,
    MACOS_KEY_DELETE             = 117,
    MACOS_KEY_RIGHT              = 124,
    MACOS_KEY_LEFT               = 123,
    MACOS_KEY_DOWN               = 125,
    MACOS_KEY_UP                 = 126,
    MACOS_KEY_PAGE_UP            = 116,
    MACOS_KEY_PAGE_DOWN          = 121,
    MACOS_KEY_HOME               = 115,
    MACOS_KEY_END                = 119,
    MACOS_KEY_CAPS_LOCK          = 57,
    MACOS_KEY_VOLUME_UP          = 72,
    MACOS_KEY_VOLUME_DOWN        = 73,
    MACOS_KEY_MUTE               = 74,
    MACOS_KEY_LINEFEED           = 52,
    MACOS_KEY_F1                 = 122,
    MACOS_KEY_F2                 = 120,
    MACOS_KEY_F3                 = 99,
    MACOS_KEY_F4                 = 118,
    MACOS_KEY_F5                 = 96,
    MACOS_KEY_F6                 = 97,
    MACOS_KEY_F7                 = 98,
    MACOS_KEY_F8                 = 100,
    MACOS_KEY_F9                 = 101,
    MACOS_KEY_F10                = 109,
    MACOS_KEY_F11                = 103,
    MACOS_KEY_F12                = 111,
    MACOS_KEY_F13                = 105,
    MACOS_KEY_F14                = 107,
    MACOS_KEY_F15                = 113,
    MACOS_KEY_F16                = 106,
    MACOS_KEY_F17                = 64,
    MACOS_KEY_F18                = 79,
    MACOS_KEY_F19                = 80,
    MACOS_KEY_F20                = 90,
    MACOS_KEY_KP_0               = 82,
    MACOS_KEY_KP_1               = 83,
    MACOS_KEY_KP_2               = 84,
    MACOS_KEY_KP_3               = 85,
    MACOS_KEY_KP_4               = 86,
    MACOS_KEY_KP_5               = 87,
    MACOS_KEY_KP_6               = 88,
    MACOS_KEY_KP_7               = 89,
    MACOS_KEY_KP_8               = 91,
    MACOS_KEY_KP_9               = 92,
    MACOS_KEY_KP_DECIMAL         = 65,
    MACOS_KEY_KP_DIVIDE          = 75,
    MACOS_KEY_KP_MULTIPLY        = 67,
    MACOS_KEY_KP_SUBTRACT        = 78,
    MACOS_KEY_KP_ADD             = 69,
    MACOS_KEY_KP_ENTER           = 76,
    MACOS_KEY_KP_EQUAL           = 81,
    MACOS_KEY_KP_CLEAR           = 71,

    // Modifier keys
    MACOS_KEY_LEFT_SHIFT         = 56,
    MACOS_KEY_LEFT_CONTROL       = 59,
    MACOS_KEY_LEFT_OPTION        = 58,
    MACOS_KEY_RIGHT_SHIFT        = 60,
    MACOS_KEY_RIGHT_CONTROL      = 62,
    MACOS_KEY_RIGHT_OPTION       = 61,
    MACOS_KEY_COMMAND            = 55,
    MACOS_KEY_FUNCTION           = 63,
    };

    inline constexpr unsigned short keyCodeConversionMacOS(const unsigned short p_keyCode) {
        switch (p_keyCode) {
            // Character keys
            case MACOS_KEY_SPACE:               return KEY_SPACE;
            case MACOS_KEY_APOSTROPHE:          return KEY_APOSTROPHE;
            case MACOS_KEY_COMMA:               return KEY_COMMA;
            case MACOS_KEY_MINUS:               return KEY_MINUS;
            case MACOS_KEY_PERIOD:              return KEY_PERIOD;
            case MACOS_KEY_SLASH:               return KEY_SLASH;
            case MACOS_KEY_0:                   return KEY_0;
            case MACOS_KEY_1:                   return KEY_1;
            case MACOS_KEY_2:                   return KEY_2;
            case MACOS_KEY_3:                   return KEY_3;
            case MACOS_KEY_4:                   return KEY_4;
            case MACOS_KEY_5:                   return KEY_5;
            case MACOS_KEY_6:                   return KEY_6;
            case MACOS_KEY_7:                   return KEY_7;
            case MACOS_KEY_8:                   return KEY_8;
            case MACOS_KEY_9:                   return KEY_9;
            case MACOS_KEY_SEMICOLON:           return KEY_SEMICOLON;
            case MACOS_KEY_EQUAL:               return KEY_EQUAL;
            case MACOS_KEY_A:                   return KEY_A;
            case MACOS_KEY_B:                   return KEY_B;
            case MACOS_KEY_C:                   return KEY_C;
            case MACOS_KEY_D:                   return KEY_D;
            case MACOS_KEY_E:                   return KEY_E;
            case MACOS_KEY_F:                   return KEY_F;
            case MACOS_KEY_G:                   return KEY_G;
            case MACOS_KEY_H:                   return KEY_H;
            case MACOS_KEY_I:                   return KEY_I;
            case MACOS_KEY_J:                   return KEY_J;
            case MACOS_KEY_K:                   return KEY_K;
            case MACOS_KEY_L:                   return KEY_L;
            case MACOS_KEY_M:                   return KEY_M;
            case MACOS_KEY_N:                   return KEY_N;
            case MACOS_KEY_O:                   return KEY_O;
            case MACOS_KEY_P:                   return KEY_P;
            case MACOS_KEY_Q:                   return KEY_Q;
            case MACOS_KEY_R:                   return KEY_R;
            case MACOS_KEY_S:                   return KEY_S;
            case MACOS_KEY_T:                   return KEY_T;
            case MACOS_KEY_U:                   return KEY_U;
            case MACOS_KEY_V:                   return KEY_V;
            case MACOS_KEY_W:                   return KEY_W;
            case MACOS_KEY_X:                   return KEY_X;
            case MACOS_KEY_Y:                   return KEY_Y;
            case MACOS_KEY_Z:                   return KEY_Z;
            case MACOS_KEY_LEFT_BRACKET:        return KEY_LEFT_BRACKET;
            case MACOS_KEY_BACKSLASH:           return KEY_BACKSLASH;
            case MACOS_KEY_RIGHT_BRACKET:       return KEY_RIGHT_BRACKET;
            case MACOS_KEY_GRAVE_ACCENT:        return KEY_GRAVE_ACCENT;
            case MACOS_KEY_FUNCTION:            return KEY_WORLD_1;

            // Function keys
            case MACOS_KEY_ESCAPE:              return KEY_ESCAPE;
            case MACOS_KEY_ENTER:               return KEY_ENTER;
            case MACOS_KEY_TAB:                 return KEY_TAB;
            case MACOS_KEY_BACKSPACE:           return KEY_BACKSPACE;
            case MACOS_KEY_INSERT:              return KEY_INSERT;
            case MACOS_KEY_DELETE:              return KEY_DELETE;
            case MACOS_KEY_RIGHT:               return KEY_RIGHT;
            case MACOS_KEY_LEFT:                return KEY_LEFT;
            case MACOS_KEY_DOWN:                return KEY_DOWN;
            case MACOS_KEY_UP:                  return KEY_UP;
            case MACOS_KEY_PAGE_UP:             return KEY_PAGE_UP;
            case MACOS_KEY_PAGE_DOWN:           return KEY_PAGE_DOWN;
            case MACOS_KEY_HOME:                return KEY_HOME;
            case MACOS_KEY_END:                 return KEY_END;
            case MACOS_KEY_CAPS_LOCK:           return KEY_CAPS_LOCK;
            case MACOS_KEY_F1:                  return KEY_F1;
            case MACOS_KEY_F2:                  return KEY_F2;
            case MACOS_KEY_F3:                  return KEY_F3;
            case MACOS_KEY_F4:                  return KEY_F4;
            case MACOS_KEY_F5:                  return KEY_F5;
            case MACOS_KEY_F6:                  return KEY_F6;
            case MACOS_KEY_F7:                  return KEY_F7;
            case MACOS_KEY_F8:                  return KEY_F8;
            case MACOS_KEY_F9:                  return KEY_F9;
            case MACOS_KEY_F10:                 return KEY_F10;
            case MACOS_KEY_F11:                 return KEY_F11;
            case MACOS_KEY_F12:                 return KEY_F12;
            case MACOS_KEY_F13:                 return KEY_F13;
            case MACOS_KEY_F14:                 return KEY_F14;
            case MACOS_KEY_F15:                 return KEY_F15;
            case MACOS_KEY_F16:                 return KEY_F16;
            case MACOS_KEY_F17:                 return KEY_F17;
            case MACOS_KEY_F18:                 return KEY_F18;
            case MACOS_KEY_F19:                 return KEY_F19;
            case MACOS_KEY_F20:                 return KEY_F20;
            case MACOS_KEY_KP_0:                return KEY_KP_0;
            case MACOS_KEY_KP_1:                return KEY_KP_1;
            case MACOS_KEY_KP_2:                return KEY_KP_2;
            case MACOS_KEY_KP_3:                return KEY_KP_3;
            case MACOS_KEY_KP_4:                return KEY_KP_4;
            case MACOS_KEY_KP_5:                return KEY_KP_5;
            case MACOS_KEY_KP_6:                return KEY_KP_6;
            case MACOS_KEY_KP_7:                return KEY_KP_7;
            case MACOS_KEY_KP_8:                return KEY_KP_8;
            case MACOS_KEY_KP_9:                return KEY_KP_9;
            case MACOS_KEY_KP_DECIMAL:          return KEY_KP_DECIMAL;
            case MACOS_KEY_KP_DIVIDE:           return KEY_KP_DIVIDE;
            case MACOS_KEY_KP_MULTIPLY:         return KEY_KP_MULTIPLY;
            case MACOS_KEY_KP_SUBTRACT:         return KEY_KP_SUBTRACT;
            case MACOS_KEY_KP_ADD:              return KEY_KP_ADD;
            case MACOS_KEY_KP_ENTER:            return KEY_KP_ENTER;
            case MACOS_KEY_KP_EQUAL:            return KEY_KP_EQUAL;

            // Modifier keys
            case MACOS_KEY_LEFT_SHIFT:          return KEY_LEFT_SHIFT;
            case MACOS_KEY_LEFT_CONTROL:        return KEY_LEFT_CONTROL;
            case MACOS_KEY_LEFT_OPTION:         return KEY_LEFT_ALT;
            case MACOS_KEY_RIGHT_SHIFT:         return KEY_RIGHT_SHIFT;
            case MACOS_KEY_RIGHT_CONTROL:       return KEY_RIGHT_CONTROL;
            case MACOS_KEY_RIGHT_OPTION:        return KEY_RIGHT_ALT;
            case MACOS_KEY_COMMAND:             return KEY_LEFT_SUPER;

            default:                            return KEY_UNKNOWN;
        }
    }
} // namespace wsky
