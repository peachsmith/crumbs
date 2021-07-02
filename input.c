#include "input.h"
#include <stdlib.h>

cr_input cr_sc_to_input(cr_scancode sc)
{
    switch (sc)
    {
        // arrow keys
    case CR_SC_LEFT:  return CR_KEY_LEFT;
    case CR_SC_UP:    return CR_KEY_UP;
    case CR_SC_RIGHT: return CR_KEY_RIGHT;
    case CR_SC_DOWN:  return CR_KEY_DOWN;

        // alphanumeric keys
    case CR_SC_A: return CR_KEY_A;
    case CR_SC_B: return CR_KEY_B;
    case CR_SC_C: return CR_KEY_C;
    case CR_SC_D: return CR_KEY_D;
    case CR_SC_E: return CR_KEY_E;
    case CR_SC_F: return CR_KEY_F;
    case CR_SC_G: return CR_KEY_G;
    case CR_SC_H: return CR_KEY_H;
    case CR_SC_I: return CR_KEY_I;
    case CR_SC_J: return CR_KEY_J;
    case CR_SC_K: return CR_KEY_K;
    case CR_SC_L: return CR_KEY_L;
    case CR_SC_M: return CR_KEY_M;
    case CR_SC_N: return CR_KEY_N;
    case CR_SC_O: return CR_KEY_O;
    case CR_SC_P: return CR_KEY_P;
    case CR_SC_Q: return CR_KEY_Q;
    case CR_SC_R: return CR_KEY_R;
    case CR_SC_S: return CR_KEY_S;
    case CR_SC_T: return CR_KEY_T;
    case CR_SC_U: return CR_KEY_U;
    case CR_SC_V: return CR_KEY_V;
    case CR_SC_W: return CR_KEY_W;
    case CR_SC_X: return CR_KEY_X;
    case CR_SC_Y: return CR_KEY_Y;
    case CR_SC_Z: return CR_KEY_Z;
    case CR_SC_0: return CR_KEY_0;
    case CR_SC_1: return CR_KEY_1;
    case CR_SC_2: return CR_KEY_2;
    case CR_SC_3: return CR_KEY_3;
    case CR_SC_4: return CR_KEY_4;
    case CR_SC_5: return CR_KEY_5;
    case CR_SC_6: return CR_KEY_6;
    case CR_SC_7: return CR_KEY_7;
    case CR_SC_8: return CR_KEY_8;
    case CR_SC_9: return CR_KEY_9;

        // symbols
    case CR_SC_MINUS:         return CR_KEY_ESCAPE;
    case CR_SC_EQUALS:        return CR_KEY_EQUALS;
    case CR_SC_COMMA:         return CR_KEY_COMMA;
    case CR_SC_PERIOD:        return CR_KEY_PERIOD;
    case CR_SC_SEMICOLON:     return CR_KEY_SEMICOLON;
    case CR_SC_APOSTROPHE:    return CR_KEY_APOSTROPHE;
    case CR_SC_LEFT_BRACKET:  return CR_KEY_LEFT_BRACKET;
    case CR_SC_RIGHT_BRACKET: return CR_KEY_RIGHT_BRACKET;
    case CR_SC_SLASH:         return CR_KEY_SLASH;
    case CR_SC_BACKSLASH:     return CR_KEY_BACKSLASH;
    case CR_SC_BACKTICK:      return CR_KEY_BACKTICK;
    case CR_SC_SPACE:         return CR_KEY_SPACE;

        // control keys
    case CR_SC_LCTRL:    return CR_KEY_LCTRL;
    case CR_SC_RCTRL:    return CR_KEY_RCTRL;
    case CR_SC_LALT:     return CR_KEY_LALT;
    case CR_SC_RALT:     return CR_KEY_RALT;
    case CR_SC_LSHIFT:   return CR_KEY_LSHIFT;
    case CR_SC_RSHIFT:   return CR_KEY_RSHIFT;
    case CR_SC_TAB:      return CR_KEY_TAB;
    case CR_SC_CAPS:     return CR_KEY_CAPS;
    case CR_SC_ESCAPE:   return CR_KEY_ESCAPE;

    default: return CR_KEY_MAX;
    }
}

cr_scancode cr_input_to_sc(cr_input key)
{
    switch (key)
    {
        // arrow keys
    case CR_KEY_LEFT:  return CR_SC_LEFT;
    case CR_KEY_UP:    return CR_SC_UP;
    case CR_KEY_RIGHT: return CR_SC_RIGHT;
    case CR_KEY_DOWN:  return CR_SC_DOWN;

        // alphanumeric keys
    case CR_KEY_A: return CR_SC_A;
    case CR_KEY_B: return CR_SC_B;
    case CR_KEY_C: return CR_SC_C;
    case CR_KEY_D: return CR_SC_D;
    case CR_KEY_E: return CR_SC_E;
    case CR_KEY_F: return CR_SC_F;
    case CR_KEY_G: return CR_SC_G;
    case CR_KEY_H: return CR_SC_H;
    case CR_KEY_I: return CR_SC_I;
    case CR_KEY_J: return CR_SC_J;
    case CR_KEY_K: return CR_SC_K;
    case CR_KEY_L: return CR_SC_L;
    case CR_KEY_M: return CR_SC_M;
    case CR_KEY_N: return CR_SC_N;
    case CR_KEY_O: return CR_SC_O;
    case CR_KEY_P: return CR_SC_P;
    case CR_KEY_Q: return CR_SC_Q;
    case CR_KEY_R: return CR_SC_R;
    case CR_KEY_S: return CR_SC_S;
    case CR_KEY_T: return CR_SC_T;
    case CR_KEY_U: return CR_SC_U;
    case CR_KEY_V: return CR_SC_V;
    case CR_KEY_W: return CR_SC_W;
    case CR_KEY_X: return CR_SC_X;
    case CR_KEY_Y: return CR_SC_Y;
    case CR_KEY_Z: return CR_SC_Z;
    case CR_KEY_0: return CR_SC_0;
    case CR_KEY_1: return CR_SC_1;
    case CR_KEY_2: return CR_SC_2;
    case CR_KEY_3: return CR_SC_3;
    case CR_KEY_4: return CR_SC_4;
    case CR_KEY_5: return CR_SC_5;
    case CR_KEY_6: return CR_SC_6;
    case CR_KEY_7: return CR_SC_7;
    case CR_KEY_8: return CR_SC_8;
    case CR_KEY_9: return CR_SC_9;

        // symbols
    case CR_KEY_MINUS:         return CR_SC_MINUS;
    case CR_KEY_EQUALS:        return CR_SC_EQUALS;
    case CR_KEY_COMMA:         return CR_SC_COMMA;
    case CR_KEY_PERIOD:        return CR_SC_PERIOD;
    case CR_KEY_SEMICOLON:     return CR_SC_SEMICOLON;
    case CR_KEY_APOSTROPHE:    return CR_SC_APOSTROPHE;
    case CR_KEY_LEFT_BRACKET:  return CR_SC_LEFT_BRACKET;
    case CR_KEY_RIGHT_BRACKET: return CR_SC_RIGHT_BRACKET;
    case CR_KEY_SLASH:         return CR_SC_SLASH;
    case CR_KEY_BACKSLASH:     return CR_SC_BACKSLASH;
    case CR_KEY_BACKTICK:      return CR_SC_BACKTICK;
    case CR_KEY_SPACE:         return CR_SC_SPACE;

        // control keys
    case CR_KEY_LCTRL:  return CR_SC_LCTRL;
    case CR_KEY_RCTRL:  return CR_SC_RCTRL;
    case CR_KEY_LALT:   return CR_SC_LALT;
    case CR_KEY_RALT:   return CR_SC_RALT;
    case CR_KEY_LSHIFT: return CR_SC_LSHIFT;
    case CR_KEY_RSHIFT: return CR_SC_RSHIFT;
    case CR_KEY_TAB:    return CR_SC_TAB;
    case CR_KEY_CAPS:   return CR_SC_CAPS;
    case CR_KEY_ESCAPE: return CR_SC_ESCAPE;

    default: return SDL_NUM_SCANCODES;
    }
}

input_handler* cr_create_input_handler(cr_function f)
{
    input_handler* input = (input_handler*)malloc(sizeof(input_handler));

    if (input == NULL)
    {
        return NULL;
    }

    input->handle = f;

    return input;
}

void cr_destroy_input_handler(input_handler* handler)
{
    if (handler == NULL)
    {
        return;
    }

    free(handler);
}

int cr_peek_input(cr_context* ctx, int type, int val)
{
    if (type == CR_KEYBOARD && val < CR_KEY_MAX)
    {
        // Return the current state of the key.
        SDL_Scancode sc = cr_input_to_sc(val);
        return ctx->key_states[sc];
    }

    return 0;
}

int cr_consume_input(cr_context* ctx, int type, int val)
{
    if (type == CR_KEYBOARD && val < CR_KEY_MAX)
    {
        SDL_Scancode sc = cr_input_to_sc(val);
        if (ctx->key_states[sc])
        {
            // If the actuation flags is not set,
            // then set it to 1.
            if (!(ctx->inputs[val]))
            {
                ctx->inputs[val] = 1;
                return 1;
            }

            // If the key is pressed, but the actuation
            // flag is already set, simply return 0.
            return 0;
        }

        // If the key is not pressed, but the actuation flag
        // is set, clear the actuation flag.
        if (ctx->inputs[val])
        {
            ctx->inputs[val] = 0;
        }
    }

    return 0;
}
