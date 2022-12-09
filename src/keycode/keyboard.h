#pragma once

#include <TinyUSB_Mouse_and_Keyboard.h>

#include "../common.h"

using keypad::Operation;

namespace {
    const int SHIFT = 0x80;

    enum class KeyCode : char {
        KEY_SPACE = ' ',
        KEY_EXCLAMATION = '!',
        KEY_DOUBLE_QUOTE = '"',
        KEY_HASH = '#',
        KEY_DOLLAR = '$',
        KEY_PERCENT = '%',
        KEY_AMPERSAND = '&',
        KEY_SINGLE_QUOTE = '\'',
        KEY_LEFT_PAREN = '(',
        KEY_RIGHT_PAREN = ')',
        KEY_ASTERISK = '*',
        KEY_PLUS = '+',
        KEY_COMMA = ',',
        KEY_MINUS = '-',
        KEY_DOT = '.',
        KEY_SLASH = '/',
        KEY_0 = '0',
        KEY_1 = '1',
        KEY_2 = '2',
        KEY_3 = '3',
        KEY_4 = '4',
        KEY_5 = '5',
        KEY_6 = '6',
        KEY_7 = '7',
        KEY_8 = '8',
        KEY_9 = '9',
        KEY_COLON = ':',
        KEY_SEMICOLON = ';',
        KEY_LESS_THEN = '<',
        KEY_EQUAL = '=',
        KEY_GREATER_THEN = '>',
        KEY_QUESTON = '?',
        KEY_AT = '@',
        KEY_LEFT_BRACKET = '[',
        KEY_BACK_SLASH = '\\',
        KEY_RIGHT_BRACKET = ']',
        KEY_KC_CIRCUMFLEX = '^',
        KEY_UNDER_SCORE = '_',
        KEY_GRAVE = '`',
        KEY_A = 'a',
        KEY_B = 'b',
        KEY_C = 'c',
        KEY_D = 'd',
        KEY_E = 'e',
        KEY_F = 'f',
        KEY_G = 'g',
        KEY_H = 'h',
        KEY_I = 'i',
        KEY_J = 'j',
        KEY_K = 'k',
        KEY_L = 'l',
        KEY_M = 'm',
        KEY_N = 'n',
        KEY_O = 'o',
        KEY_P = 'p',
        KEY_Q = 'q',
        KEY_R = 'r',
        KEY_S = 's',
        KEY_T = 't',
        KEY_U = 'u',
        KEY_V = 'v',
        KEY_W = 'w',
        KEY_X = 'x',
        KEY_Y = 'y',
        KEY_Z = 'z',
        KEY_LEFT_BRACE = '{',
        KEY_PIPE = '|',
        KEY_RIGHT_BRACE = '}',
        KEY_TILDE = '~',
    };
}

// -----------------------------------------------------------------------------

#define PR_KEY_LEFT_CTRL \
    { Operation::PRESS, KEY_LEFT_CTRL }
#define PR_KEY_LEFT_SHIFT \
    { Operation::PRESS, KEY_LEFT_SHIFT }
#define PR_KEY_LEFT_ALT \
    { Operation::PRESS, KEY_LEFT_ALT }
#define PR_KEY_LEFT_GUI \
    { Operation::PRESS, KEY_LEFT_GUI }
#define PR_KEY_RIGHT_CTRL \
    { Operation::PRESS, KEY_RIGHT_CTRL }
#define PR_KEY_RIGHT_SHIFT \
    { Operation::PRESS, KEY_RIGHT_SHIFT }
#define PR_KEY_RIGHT_ALT \
    { Operation::PRESS, KEY_RIGHT_ALT }
#define PR_KEY_RIGHT_GUI \
    { Operation::PRESS, KEY_RIGHT_GUI }

#define PR_KEY_UP_ARROW \
    { Operation::PRESS, KEY_UP_ARROW }
#define PR_KEY_DOWN_ARROW \
    { Operation::PRESS, KEY_DOWN_ARROW }
#define PR_KEY_LEFT_ARROW \
    { Operation::PRESS, KEY_LEFT_ARROW }
#define PR_KEY_RIGHT_ARROW \
    { Operation::PRESS, KEY_RIGHT_ARROW }
#define PR_KEY_BACKSPACE \
    { Operation::PRESS, KEY_BACKSPACE }
#define PR_KEY_TAB \
    { Operation::PRESS, KEY_TAB }
#define PR_KEY_RETURN \
    { Operation::PRESS, KEY_RETURN }
#define PR_KEY_ESC \
    { Operation::PRESS, KEY_ESC }
#define PR_KEY_INSERT \
    { Operation::PRESS, KEY_INSERT }
#define PR_KEY_DELETE \
    { Operation::PRESS, KEY_DELETE }
#define PR_KEY_PAGE_UP \
    { Operation::PRESS, KEY_PAGE_UP }
#define PR_KEY_PAGE_DOWN \
    { Operation::PRESS, KEY_PAGE_DOWN }
#define PR_KEY_HOME \
    { Operation::PRESS, KEY_HOME }
#define PR_KEY_END \
    { Operation::PRESS, KEY_END }
#define PR_KEY_CAPS_LOCK \
    { Operation::PRESS, KEY_CAPS_LOCK }
#define PR_KEY_F1 \
    { Operation::PRESS, KEY_F1 }
#define PR_KEY_F2 \
    { Operation::PRESS, KEY_F2 }
#define PR_KEY_F3 \
    { Operation::PRESS, KEY_F3 }
#define PR_KEY_F4 \
    { Operation::PRESS, KEY_F4 }
#define PR_KEY_F5 \
    { Operation::PRESS, KEY_F5 }
#define PR_KEY_F6 \
    { Operation::PRESS, KEY_F6 }
#define PR_KEY_F7 \
    { Operation::PRESS, KEY_F7 }
#define PR_KEY_F8 \
    { Operation::PRESS, KEY_F8 }
#define PR_KEY_F9 \
    { Operation::PRESS, KEY_F9 }
#define PR_KEY_F10 \
    { Operation::PRESS, KEY_F10 }
#define PR_KEY_F11 \
    { Operation::PRESS, KEY_F11 }
#define PR_KEY_F12 \
    { Operation::PRESS, KEY_F12 }
#define PR_KEY_F13 \
    { Operation::PRESS, KEY_F13 }
#define PR_KEY_F14 \
    { Operation::PRESS, KEY_F14 }
#define PR_KEY_F15 \
    { Operation::PRESS, KEY_F15 }
#define PR_KEY_F16 \
    { Operation::PRESS, KEY_F16 }
#define PR_KEY_F17 \
    { Operation::PRESS, KEY_F17 }
#define PR_KEY_F18 \
    { Operation::PRESS, KEY_F18 }
#define PR_KEY_F19 \
    { Operation::PRESS, KEY_F19 }
#define PR_KEY_F20 \
    { Operation::PRESS, KEY_F20 }
#define PR_KEY_F21 \
    { Operation::PRESS, KEY_F21 }
#define PR_KEY_F22 \
    { Operation::PRESS, KEY_F22 }
#define PR_KEY_F23 \
    { Operation::PRESS, KEY_F23 }
#define PR_KEY_F24 \
    { Operation::PRESS, KEY_F2 }

#define PR_KEY_SPACE \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_SPACE }
#define PR_KEY_EXCLAMATION \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_EXCLAMATION }
#define PR_KEY_DOUBLE_QUOTE \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_DOUBLE_QUOTE }
#define PR_KEY_HASH \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_HASH }
#define PR_KEY_DOLLAR \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_DOLLAR }
#define PR_KEY_PERCENT \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_PERCENT }
#define PR_KEY_AMPERSAND \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_AMPERSAND }
#define PR_KEY_SINGLE_QUOTE \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_SINGLE_QUOTE }
#define PR_KEY_LEFT_PAREN \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_LEFT_PAREN }
#define PR_KEY_RIGHT_PAREN \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_RIGHT_PAREN }
#define PR_KEY_ASTERISK \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_ASTERISK }
#define PR_KEY_PLUS \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_PLUS }
#define PR_KEY_COMMA \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_COMMA }
#define PR_KEY_MINUS \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_MINUS }
#define PR_KEY_DOT \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_DOT }
#define PR_KEY_SLASH \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_SLASH }
#define PR_KEY_0 \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_0 }
#define PR_KEY_1 \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_1 }
#define PR_KEY_1 \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_1 }
#define PR_KEY_3 \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_3 }
#define PR_KEY_4 \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_4 }
#define PR_KEY_5 \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_5 }
#define PR_KEY_6 \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_6 }
#define PR_KEY_7 \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_7 }
#define PR_KEY_8 \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_8 }
#define PR_KEY_9 \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_9 }
#define PR_KEY_COLON \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_COLON }
#define PR_KEY_SEMICOLON \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_SEMICOLON }
#define PR_KEY_LESS_THEN \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_LESS_THEN }
#define PR_KEY_EQUAL \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_EQUAL }
#define PR_KEY_GREATER_THEN \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_GREATER_THEN }
#define PR_KEY_QUESTON \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_QUESTON }
#define PR_KEY_AT \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_AT }
#define PR_KEY_LEFT_BRACKET \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_LEFT_BRACKET }
#define PR_KEY_BACK_SLASH \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_BACK_SLASH }
#define PR_KEY_RIGHT_BRACKET \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_RIGHT_BRACKET }
#define PR_KEY_KC_CIRCUMFLEX \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_KC_CIRCUMFLEX }
#define PR_KEY_UNDER_SCORE \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_UNDER_SCORE }
#define PR_KEY_GRAVE \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_GRAVE }
#define PR_KEY_A \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_A }
#define PR_KEY_B \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_B }
#define PR_KEY_C \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_C }
#define PR_KEY_D \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_D }
#define PR_KEY_E \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_E }
#define PR_KEY_F \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_F }
#define PR_KEY_G \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_G }
#define PR_KEY_H \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_H }
#define PR_KEY_I \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_I }
#define PR_KEY_J \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_J }
#define PR_KEY_K \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_K }
#define PR_KEY_L \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_L }
#define PR_KEY_M \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_M }
#define PR_KEY_N \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_N }
#define PR_KEY_O \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_O }
#define PR_KEY_P \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_P }
#define PR_KEY_Q \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_Q }
#define PR_KEY_R \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_R }
#define PR_KEY_S \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_S }
#define PR_KEY_T \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_T }
#define PR_KEY_U \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_U }
#define PR_KEY_V \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_V }
#define PR_KEY_W \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_W }
#define PR_KEY_X \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_X }
#define PR_KEY_Y \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_Y }
#define PR_KEY_Z \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_Z }
#define PR_KEY_LEFT_BRACE \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_LEFT_BRACE }
#define PR_KEY_PIPE \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_PIPE }
#define PR_KEY_RIGHT_BRACE \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_RIGHT_BRACE }
#define PR_KEY_TILDE \
    { Operation::PRESS, (unsigned long)KeyCode::KEY_TILDE }

// -----------------------------------------------------------------------------

#define RE_KEY_LEFT_CTRL \
    { Operation::RELEASE, KEY_LEFT_CTRL }
#define RE_KEY_LEFT_SHIFT \
    { Operation::RELEASE, KEY_LEFT_SHIFT }
#define RE_KEY_LEFT_ALT \
    { Operation::RELEASE, KEY_LEFT_ALT }
#define RE_KEY_LEFT_GUI \
    { Operation::RELEASE, KEY_LEFT_GUI }
#define RE_KEY_RIGHT_CTRL \
    { Operation::RELEASE, KEY_RIGHT_CTRL }
#define RE_KEY_RIGHT_SHIFT \
    { Operation::RELEASE, KEY_RIGHT_SHIFT }
#define RE_KEY_RIGHT_ALT \
    { Operation::RELEASE, KEY_RIGHT_ALT }
#define RE_KEY_RIGHT_GUI \
    { Operation::RELEASE, KEY_RIGHT_GUI }

#define RE_KEY_UP_ARROW \
    { Operation::RELEASE, KEY_UP_ARROW }
#define RE_KEY_DOWN_ARROW \
    { Operation::RELEASE, KEY_DOWN_ARROW }
#define RE_KEY_LEFT_ARROW \
    { Operation::RELEASE, KEY_LEFT_ARROW }
#define RE_KEY_RIGHT_ARROW \
    { Operation::RELEASE, KEY_RIGHT_ARROW }
#define RE_KEY_BACKSPACE \
    { Operation::RELEASE, KEY_BACKSPACE }
#define RE_KEY_TAB \
    { Operation::RELEASE, KEY_TAB }
#define RE_KEY_RETURN \
    { Operation::RELEASE, KEY_RETURN }
#define RE_KEY_ESC \
    { Operation::RELEASE, KEY_ESC }
#define RE_KEY_INSERT \
    { Operation::RELEASE, KEY_INSERT }
#define RE_KEY_DELETE \
    { Operation::RELEASE, KEY_DELETE }
#define RE_KEY_PAGE_UP \
    { Operation::RELEASE, KEY_PAGE_UP }
#define RE_KEY_PAGE_DOWN \
    { Operation::RELEASE, KEY_PAGE_DOWN }
#define RE_KEY_HOME \
    { Operation::RELEASE, KEY_HOME }
#define RE_KEY_END \
    { Operation::RELEASE, KEY_END }
#define RE_KEY_CAPS_LOCK \
    { Operation::RELEASE, KEY_CAPS_LOCK }
#define RE_KEY_F1 \
    { Operation::RELEASE, KEY_F1 }
#define RE_KEY_F2 \
    { Operation::RELEASE, KEY_F2 }
#define RE_KEY_F3 \
    { Operation::RELEASE, KEY_F3 }
#define RE_KEY_F4 \
    { Operation::RELEASE, KEY_F4 }
#define RE_KEY_F5 \
    { Operation::RELEASE, KEY_F5 }
#define RE_KEY_F6 \
    { Operation::RELEASE, KEY_F6 }
#define RE_KEY_F7 \
    { Operation::RELEASE, KEY_F7 }
#define RE_KEY_F8 \
    { Operation::RELEASE, KEY_F8 }
#define RE_KEY_F9 \
    { Operation::RELEASE, KEY_F9 }
#define RE_KEY_F10 \
    { Operation::RELEASE, KEY_F10 }
#define RE_KEY_F11 \
    { Operation::RELEASE, KEY_F11 }
#define RE_KEY_F12 \
    { Operation::RELEASE, KEY_F12 }
#define RE_KEY_F13 \
    { Operation::RELEASE, KEY_F13 }
#define RE_KEY_F14 \
    { Operation::RELEASE, KEY_F14 }
#define RE_KEY_F15 \
    { Operation::RELEASE, KEY_F15 }
#define RE_KEY_F16 \
    { Operation::RELEASE, KEY_F16 }
#define RE_KEY_F17 \
    { Operation::RELEASE, KEY_F17 }
#define RE_KEY_F18 \
    { Operation::RELEASE, KEY_F18 }
#define RE_KEY_F19 \
    { Operation::RELEASE, KEY_F19 }
#define RE_KEY_F20 \
    { Operation::RELEASE, KEY_F20 }
#define RE_KEY_F21 \
    { Operation::RELEASE, KEY_F21 }
#define RE_KEY_F22 \
    { Operation::RELEASE, KEY_F22 }
#define RE_KEY_F23 \
    { Operation::RELEASE, KEY_F23 }
#define RE_KEY_F24 \
    { Operation::RELEASE, KEY_F2 }

#define RE_KEY_SPACE \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_SPACE }
#define RE_KEY_EXCLAMATION \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_EXCLAMATION }
#define RE_KEY_DOUBLE_QUOTE \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_DOUBLE_QUOTE }
#define RE_KEY_HASH \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_HASH }
#define RE_KEY_DOLLAR \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_DOLLAR }
#define RE_KEY_PERCENT \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_PERCENT }
#define RE_KEY_AMPERSAND \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_AMPERSAND }
#define RE_KEY_SINGLE_QUOTE \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_SINGLE_QUOTE }
#define RE_KEY_LEFT_PAREN \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_LEFT_PAREN }
#define RE_KEY_RIGHT_PAREN \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_RIGHT_PAREN }
#define RE_KEY_ASTERISK \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_ASTERISK }
#define RE_KEY_PLUS \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_PLUS }
#define RE_KEY_COMMA \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_COMMA }
#define RE_KEY_MINUS \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_MINUS }
#define RE_KEY_DOT \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_DOT }
#define RE_KEY_SLASH \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_SLASH }
#define RE_KEY_0 \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_0 }
#define RE_KEY_1 \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_1 }
#define RE_KEY_1 \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_1 }
#define RE_KEY_3 \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_3 }
#define RE_KEY_4 \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_4 }
#define RE_KEY_5 \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_5 }
#define RE_KEY_6 \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_6 }
#define RE_KEY_7 \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_7 }
#define RE_KEY_8 \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_8 }
#define RE_KEY_9 \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_9 }
#define RE_KEY_COLON \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_COLON }
#define RE_KEY_SEMICOLON \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_SEMICOLON }
#define RE_KEY_LESS_THEN \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_LESS_THEN }
#define RE_KEY_EQUAL \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_EQUAL }
#define RE_KEY_GREATER_THEN \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_GREATER_THEN }
#define RE_KEY_QUESTON \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_QUESTON }
#define RE_KEY_AT \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_AT }
#define RE_KEY_LEFT_BRACKET \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_LEFT_BRACKET }
#define RE_KEY_BACK_SLASH \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_BACK_SLASH }
#define RE_KEY_RIGHT_BRACKET \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_RIGHT_BRACKET }
#define RE_KEY_KC_CIRCUMFLEX \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_KC_CIRCUMFLEX }
#define RE_KEY_UNDER_SCORE \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_UNDER_SCORE }
#define RE_KEY_GRAVE \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_GRAVE }
#define RE_KEY_A \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_A }
#define RE_KEY_B \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_B }
#define RE_KEY_C \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_C }
#define RE_KEY_D \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_D }
#define RE_KEY_E \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_E }
#define RE_KEY_F \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_F }
#define RE_KEY_G \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_G }
#define RE_KEY_H \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_H }
#define RE_KEY_I \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_I }
#define RE_KEY_J \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_J }
#define RE_KEY_K \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_K }
#define RE_KEY_L \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_L }
#define RE_KEY_M \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_M }
#define RE_KEY_N \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_N }
#define RE_KEY_O \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_O }
#define RE_KEY_P \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_P }
#define RE_KEY_Q \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_Q }
#define RE_KEY_R \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_R }
#define RE_KEY_S \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_S }
#define RE_KEY_T \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_T }
#define RE_KEY_U \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_U }
#define RE_KEY_V \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_V }
#define RE_KEY_W \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_W }
#define RE_KEY_X \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_X }
#define RE_KEY_Y \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_Y }
#define RE_KEY_Z \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_Z }
#define RE_KEY_LEFT_BRACE \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_LEFT_BRACE }
#define RE_KEY_PIPE \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_PIPE }
#define RE_KEY_RIGHT_BRACE \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_RIGHT_BRACE }
#define RE_KEY_TILDE \
    { Operation::RELEASE, (unsigned long)KeyCode::KEY_TILDE }
#define RE_KEY_DEL \

// -----------------------------------------------------------------------------

#define CL_KEY_LEFT_CTRL \
    { Operation::CLICK, KEY_LEFT_CTRL }
#define CL_KEY_LEFT_SHIFT \
    { Operation::CLICK, KEY_LEFT_SHIFT }
#define CL_KEY_LEFT_ALT \
    { Operation::CLICK, KEY_LEFT_ALT }
#define CL_KEY_LEFT_GUI \
    { Operation::CLICK, KEY_LEFT_GUI }
#define CL_KEY_RIGHT_CTRL \
    { Operation::CLICK, KEY_RIGHT_CTRL }
#define CL_KEY_RIGHT_SHIFT \
    { Operation::CLICK, KEY_RIGHT_SHIFT }
#define CL_KEY_RIGHT_ALT \
    { Operation::CLICK, KEY_RIGHT_ALT }
#define CL_KEY_RIGHT_GUI \
    { Operation::CLICK, KEY_RIGHT_GUI }

#define CL_KEY_UP_ARROW \
    { Operation::CLICK, KEY_UP_ARROW }
#define CL_KEY_DOWN_ARROW \
    { Operation::CLICK, KEY_DOWN_ARROW }
#define CL_KEY_LEFT_ARROW \
    { Operation::CLICK, KEY_LEFT_ARROW }
#define CL_KEY_RIGHT_ARROW \
    { Operation::CLICK, KEY_RIGHT_ARROW }
#define CL_KEY_BACKSPACE \
    { Operation::CLICK, KEY_BACKSPACE }
#define CL_KEY_TAB \
    { Operation::CLICK, KEY_TAB }
#define CL_KEY_RETURN \
    { Operation::CLICK, KEY_RETURN }
#define CL_KEY_ESC \
    { Operation::CLICK, KEY_ESC }
#define CL_KEY_INSERT \
    { Operation::CLICK, KEY_INSERT }
#define CL_KEY_DELETE \
    { Operation::CLICK, KEY_DELETE }
#define CL_KEY_PAGE_UP \
    { Operation::CLICK, KEY_PAGE_UP }
#define CL_KEY_PAGE_DOWN \
    { Operation::CLICK, KEY_PAGE_DOWN }
#define CL_KEY_HOME \
    { Operation::CLICK, KEY_HOME }
#define CL_KEY_END \
    { Operation::CLICK, KEY_END }
#define CL_KEY_CAPS_LOCK \
    { Operation::CLICK, KEY_CAPS_LOCK }
#define CL_KEY_F1 \
    { Operation::CLICK, KEY_F1 }
#define CL_KEY_F2 \
    { Operation::CLICK, KEY_F2 }
#define CL_KEY_F3 \
    { Operation::CLICK, KEY_F3 }
#define CL_KEY_F4 \
    { Operation::CLICK, KEY_F4 }
#define CL_KEY_F5 \
    { Operation::CLICK, KEY_F5 }
#define CL_KEY_F6 \
    { Operation::CLICK, KEY_F6 }
#define CL_KEY_F7 \
    { Operation::CLICK, KEY_F7 }
#define CL_KEY_F8 \
    { Operation::CLICK, KEY_F8 }
#define CL_KEY_F9 \
    { Operation::CLICK, KEY_F9 }
#define CL_KEY_F10 \
    { Operation::CLICK, KEY_F10 }
#define CL_KEY_F11 \
    { Operation::CLICK, KEY_F11 }
#define CL_KEY_F12 \
    { Operation::CLICK, KEY_F12 }
#define CL_KEY_F13 \
    { Operation::CLICK, KEY_F13 }
#define CL_KEY_F14 \
    { Operation::CLICK, KEY_F14 }
#define CL_KEY_F15 \
    { Operation::CLICK, KEY_F15 }
#define CL_KEY_F16 \
    { Operation::CLICK, KEY_F16 }
#define CL_KEY_F17 \
    { Operation::CLICK, KEY_F17 }
#define CL_KEY_F18 \
    { Operation::CLICK, KEY_F18 }
#define CL_KEY_F19 \
    { Operation::CLICK, KEY_F19 }
#define CL_KEY_F20 \
    { Operation::CLICK, KEY_F20 }
#define CL_KEY_F21 \
    { Operation::CLICK, KEY_F21 }
#define CL_KEY_F22 \
    { Operation::CLICK, KEY_F22 }
#define CL_KEY_F23 \
    { Operation::CLICK, KEY_F23 }
#define CL_KEY_F24 \
    { Operation::CLICK, KEY_F2 }

#define CL_KEY_SPACE \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_SPACE }
#define CL_KEY_EXCLAMATION \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_EXCLAMATION }
#define CL_KEY_DOUBLE_QUOTE \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_DOUBLE_QUOTE }
#define CL_KEY_HASH \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_HASH }
#define CL_KEY_DOLLAR \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_DOLLAR }
#define CL_KEY_PERCENT \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_PERCENT }
#define CL_KEY_AMPERSAND \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_AMPERSAND }
#define CL_KEY_SINGLE_QUOTE \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_SINGLE_QUOTE }
#define CL_KEY_LEFT_PAREN \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_LEFT_PAREN }
#define CL_KEY_RIGHT_PAREN \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_RIGHT_PAREN }
#define CL_KEY_ASTERISK \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_ASTERISK }
#define CL_KEY_PLUS \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_PLUS }
#define CL_KEY_COMMA \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_COMMA }
#define CL_KEY_MINUS \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_MINUS }
#define CL_KEY_DOT \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_DOT }
#define CL_KEY_SLASH \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_SLASH }
#define CL_KEY_0 \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_0 }
#define CL_KEY_1 \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_1 }
#define CL_KEY_1 \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_1 }
#define CL_KEY_3 \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_3 }
#define CL_KEY_4 \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_4 }
#define CL_KEY_5 \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_5 }
#define CL_KEY_6 \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_6 }
#define CL_KEY_7 \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_7 }
#define CL_KEY_8 \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_8 }
#define CL_KEY_9 \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_9 }
#define CL_KEY_COLON \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_COLON }
#define CL_KEY_SEMICOLON \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_SEMICOLON }
#define CL_KEY_LESS_THEN \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_LESS_THEN }
#define CL_KEY_EQUAL \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_EQUAL }
#define CL_KEY_GREATER_THEN \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_GREATER_THEN }
#define CL_KEY_QUESTON \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_QUESTON }
#define CL_KEY_AT \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_AT }
#define CL_KEY_LEFT_BRACKET \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_LEFT_BRACKET }
#define CL_KEY_BACK_SLASH \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_BACK_SLASH }
#define CL_KEY_RIGHT_BRACKET \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_RIGHT_BRACKET }
#define CL_KEY_KC_CIRCUMFLEX \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_KC_CIRCUMFLEX }
#define CL_KEY_UNDER_SCORE \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_UNDER_SCORE }
#define CL_KEY_GRAVE \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_GRAVE }
#define CL_KEY_A \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_A }
#define CL_KEY_B \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_B }
#define CL_KEY_C \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_C }
#define CL_KEY_D \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_D }
#define CL_KEY_E \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_E }
#define CL_KEY_F \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_F }
#define CL_KEY_G \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_G }
#define CL_KEY_H \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_H }
#define CL_KEY_I \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_I }
#define CL_KEY_J \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_J }
#define CL_KEY_K \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_K }
#define CL_KEY_L \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_L }
#define CL_KEY_M \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_M }
#define CL_KEY_N \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_N }
#define CL_KEY_O \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_O }
#define CL_KEY_P \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_P }
#define CL_KEY_Q \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_Q }
#define CL_KEY_R \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_R }
#define CL_KEY_S \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_S }
#define CL_KEY_T \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_T }
#define CL_KEY_U \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_U }
#define CL_KEY_V \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_V }
#define CL_KEY_W \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_W }
#define CL_KEY_X \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_X }
#define CL_KEY_Y \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_Y }
#define CL_KEY_Z \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_Z }
#define CL_KEY_LEFT_BRACE \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_LEFT_BRACE }
#define CL_KEY_PIPE \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_PIPE }
#define CL_KEY_RIGHT_BRACE \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_RIGHT_BRACE }
#define CL_KEY_TILDE \
    { Operation::CLICK, (unsigned long)KeyCode::KEY_TILDE }
