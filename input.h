#ifndef JEP_INPUT_H
#define JEP_INPUT_H

#include "crumbs.h"

/**
 * Creates a new input handler.
 *
 * Params:
 *   cr_function - a function to handle input
 *
 * Returns:
 *   input_handler* - a new input handler object
 */
cr_input_handler* cr_create_input_handler(cr_function f);

/**
 * Frees the resources allocated for an input handler.
 *
 * Params:
 *   cr_input_handler* - an input handler to destroy
 */
void cr_destroy_input_handler(cr_input_handler* handler);

/**
 * Checks the current actuation state of an input.
 * This function does NOT modify the state of the input.
 * As long as the specified input is actuated, this function should
 * return 1.
 *
 * Params:
 *   cr_context* - the context of the application
 *   int - the type of the input
 *   int - the input value
 *
 * Returns:
 *   int - 1 if the input is actuated, otherwise 0
 */
int cr_peek_input(cr_context*, int type, int val);

/**
 * Checks the current actuation state of an input.
 * This function DOES modify the state of the input.
 * If the input is actuated, a flag is set to indicate that the input
 * has been consumed. Calling this function twice immediately after
 * actuating an input will result in the first call returning 1 and
 * the second call returning 0.
 *
 * Params:
 *   cr_context* - the context of the application
 *   int - the type of the input
 *   int - the input value
 *
 * Returns:
 *   int - 1 if the input is actuated, otherwise 0
 */
int cr_consume_input(cr_context*, int type, int val);

#endif