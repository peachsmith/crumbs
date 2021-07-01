#ifndef JEP_INPUT_H
#define JEP_INPUT_H

#include "crumbs.h"

typedef void(*handler_function)(cr_context*);

typedef struct input_handler {
    handler_function handle;
} input_handler;

input_handler* cr_create_input_handler(handler_function f);

void cr_destroy_input_handler(input_handler* handler);

#endif