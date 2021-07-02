#include "input.h"
#include <stdlib.h>

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
