#include "input_map.h"

cr_key cr_sc_to_input(SDL_Scancode sc)
{
    switch (sc)
    {
        // arrow keys
    case SDL_SCANCODE_LEFT:  return CR_KEY_LEFT;
    case SDL_SCANCODE_UP:    return CR_KEY_UP;
    case SDL_SCANCODE_RIGHT: return CR_KEY_RIGHT;
    case SDL_SCANCODE_DOWN:  return CR_KEY_DOWN;

        // alphanumeric keys
    case SDL_SCANCODE_A: return CR_KEY_A;
    case SDL_SCANCODE_B: return CR_KEY_B;
    case SDL_SCANCODE_C: return CR_KEY_C;
    case SDL_SCANCODE_D: return CR_KEY_D;
    case SDL_SCANCODE_E: return CR_KEY_E;
    case SDL_SCANCODE_F: return CR_KEY_F;
    case SDL_SCANCODE_G: return CR_KEY_G;
    case SDL_SCANCODE_H: return CR_KEY_H;
    case SDL_SCANCODE_I: return CR_KEY_I;
    case SDL_SCANCODE_J: return CR_KEY_J;
    case SDL_SCANCODE_K: return CR_KEY_K;
    case SDL_SCANCODE_L: return CR_KEY_L;
    case SDL_SCANCODE_M: return CR_KEY_M;
    case SDL_SCANCODE_N: return CR_KEY_N;
    case SDL_SCANCODE_O: return CR_KEY_O;
    case SDL_SCANCODE_P: return CR_KEY_P;
    case SDL_SCANCODE_Q: return CR_KEY_Q;
    case SDL_SCANCODE_R: return CR_KEY_R;
    case SDL_SCANCODE_S: return CR_KEY_S;
    case SDL_SCANCODE_T: return CR_KEY_T;
    case SDL_SCANCODE_U: return CR_KEY_U;
    case SDL_SCANCODE_V: return CR_KEY_V;
    case SDL_SCANCODE_W: return CR_KEY_W;
    case SDL_SCANCODE_X: return CR_KEY_X;
    case SDL_SCANCODE_Y: return CR_KEY_Y;
    case SDL_SCANCODE_Z: return CR_KEY_Z;
    case SDL_SCANCODE_0: return CR_KEY_0;
    case SDL_SCANCODE_1: return CR_KEY_1;
    case SDL_SCANCODE_2: return CR_KEY_2;
    case SDL_SCANCODE_3: return CR_KEY_3;
    case SDL_SCANCODE_4: return CR_KEY_4;
    case SDL_SCANCODE_5: return CR_KEY_5;
    case SDL_SCANCODE_6: return CR_KEY_6;
    case SDL_SCANCODE_7: return CR_KEY_7;
    case SDL_SCANCODE_8: return CR_KEY_8;
    case SDL_SCANCODE_9: return CR_KEY_9;

        // symbols
    case SDL_SCANCODE_MINUS:        return CR_KEY_ESCAPE;
    case SDL_SCANCODE_EQUALS:       return CR_KEY_EQUALS;
    case SDL_SCANCODE_COMMA:        return CR_KEY_COMMA;
    case SDL_SCANCODE_PERIOD:       return CR_KEY_PERIOD;
    case SDL_SCANCODE_SEMICOLON:    return CR_KEY_SEMICOLON;
    case SDL_SCANCODE_APOSTROPHE:   return CR_KEY_APOSTROPHE;
    case SDL_SCANCODE_LEFTBRACKET:  return CR_KEY_LEFT_BRACKET;
    case SDL_SCANCODE_RIGHTBRACKET: return CR_KEY_RIGHT_BRACKET;
    case SDL_SCANCODE_SLASH:        return CR_KEY_SLASH;
    case SDL_SCANCODE_BACKSLASH:    return CR_KEY_BACKSLASH;
    case SDL_SCANCODE_GRAVE:        return CR_KEY_BACKTICK;
    case SDL_SCANCODE_SPACE:        return CR_KEY_SPACE;

        // control keys
    case SDL_SCANCODE_LCTRL:    return CR_KEY_LCTRL;
    case SDL_SCANCODE_RCTRL:    return CR_KEY_RCTRL;
    case SDL_SCANCODE_LALT:     return CR_KEY_LALT;
    case SDL_SCANCODE_RALT:     return CR_KEY_RALT;
    case SDL_SCANCODE_LSHIFT:   return CR_KEY_LSHIFT;
    case SDL_SCANCODE_RSHIFT:   return CR_KEY_RSHIFT;
    case SDL_SCANCODE_TAB:      return CR_KEY_TAB;
    case SDL_SCANCODE_CAPSLOCK: return CR_KEY_CAPS;
    case SDL_SCANCODE_ESCAPE:   return CR_KEY_ESCAPE;

    default: return CR_KEY_MAX;
    }
}

SDL_Scancode cr_input_to_sc(cr_key key)
{
    switch (key)
    {
        // arrow keys
    case CR_KEY_LEFT:  return SDL_SCANCODE_LEFT;
    case CR_KEY_UP:    return SDL_SCANCODE_UP;
    case CR_KEY_RIGHT: return SDL_SCANCODE_RIGHT;
    case CR_KEY_DOWN:  return SDL_SCANCODE_DOWN;

        // alphanumeric keys
    case CR_KEY_A: return SDL_SCANCODE_A;
    case CR_KEY_B: return SDL_SCANCODE_B;
    case CR_KEY_C: return SDL_SCANCODE_C;
    case CR_KEY_D: return SDL_SCANCODE_D;
    case CR_KEY_E: return SDL_SCANCODE_E;
    case CR_KEY_F: return SDL_SCANCODE_F;
    case CR_KEY_G: return SDL_SCANCODE_G;
    case CR_KEY_H: return SDL_SCANCODE_H;
    case CR_KEY_I: return SDL_SCANCODE_I;
    case CR_KEY_J: return SDL_SCANCODE_J;
    case CR_KEY_K: return SDL_SCANCODE_K;
    case CR_KEY_L: return SDL_SCANCODE_L;
    case CR_KEY_M: return SDL_SCANCODE_M;
    case CR_KEY_N: return SDL_SCANCODE_N;
    case CR_KEY_O: return SDL_SCANCODE_O;
    case CR_KEY_P: return SDL_SCANCODE_P;
    case CR_KEY_Q: return SDL_SCANCODE_Q;
    case CR_KEY_R: return SDL_SCANCODE_R;
    case CR_KEY_S: return SDL_SCANCODE_S;
    case CR_KEY_T: return SDL_SCANCODE_T;
    case CR_KEY_U: return SDL_SCANCODE_U;
    case CR_KEY_V: return SDL_SCANCODE_V;
    case CR_KEY_W: return SDL_SCANCODE_W;
    case CR_KEY_X: return SDL_SCANCODE_X;
    case CR_KEY_Y: return SDL_SCANCODE_Y;
    case CR_KEY_Z: return SDL_SCANCODE_Z;
    case CR_KEY_0: return SDL_SCANCODE_0;
    case CR_KEY_1: return SDL_SCANCODE_1;
    case CR_KEY_2: return SDL_SCANCODE_2;
    case CR_KEY_3: return SDL_SCANCODE_3;
    case CR_KEY_4: return SDL_SCANCODE_4;
    case CR_KEY_5: return SDL_SCANCODE_5;
    case CR_KEY_6: return SDL_SCANCODE_6;
    case CR_KEY_7: return SDL_SCANCODE_7;
    case CR_KEY_8: return SDL_SCANCODE_8;
    case CR_KEY_9: return SDL_SCANCODE_9;

        // symbols
    case CR_KEY_MINUS:         return SDL_SCANCODE_MINUS;
    case CR_KEY_EQUALS:        return SDL_SCANCODE_EQUALS;
    case CR_KEY_COMMA:         return SDL_SCANCODE_COMMA;
    case CR_KEY_PERIOD:        return SDL_SCANCODE_PERIOD;
    case CR_KEY_SEMICOLON:     return SDL_SCANCODE_SEMICOLON;
    case CR_KEY_APOSTROPHE:    return SDL_SCANCODE_APOSTROPHE;
    case CR_KEY_LEFT_BRACKET:  return SDL_SCANCODE_LEFTBRACKET;
    case CR_KEY_RIGHT_BRACKET: return SDL_SCANCODE_RIGHTBRACKET;
    case CR_KEY_SLASH:         return SDL_SCANCODE_SLASH;
    case CR_KEY_BACKSLASH:     return SDL_SCANCODE_BACKSLASH;
    case CR_KEY_BACKTICK:      return SDL_SCANCODE_GRAVE;
    case CR_KEY_SPACE:         return SDL_SCANCODE_SPACE;

        // control keys
    case CR_KEY_LCTRL:  return SDL_SCANCODE_LCTRL;
    case CR_KEY_RCTRL:  return SDL_SCANCODE_RCTRL;
    case CR_KEY_LALT:   return SDL_SCANCODE_LALT;
    case CR_KEY_RALT:   return SDL_SCANCODE_RALT;
    case CR_KEY_LSHIFT: return SDL_SCANCODE_LSHIFT;
    case CR_KEY_RSHIFT: return SDL_SCANCODE_RSHIFT;
    case CR_KEY_TAB:    return SDL_SCANCODE_TAB;
    case CR_KEY_CAPS:   return SDL_SCANCODE_CAPSLOCK;
    case CR_KEY_ESCAPE: return SDL_SCANCODE_ESCAPE;

    default: return SDL_NUM_SCANCODES;
    }
}
