#include "input.h"
#include <stdlib.h>

input_handler* cr_create_input_handler(void(*handle)(cr_context*))
{
    input_handler* input = (input_handler*)malloc(sizeof(input_handler));

    if (input == NULL)
    {
        return NULL;
    }

    input->handle = handle;

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
