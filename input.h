#ifndef JEP_INPUT_H
#define JEP_INPUT_H

#include "crumbs_impl.h"

/**
 * Converts a keyboard scancode to an input index.
 *
 * Params:
 *   cr_scancode - a keyboard scancode
 *
 * Returns:
 *   cr_input - the index of an input actuation flag
 */
cr_input cr_sc_to_input(cr_scancode sc);

/**
 * Converts an input index to a keyboard scancode.
 *
 * Params:
 *   cr_input - a key index
 *
 * Returns:
 *   cr_scancode - a keyboard scancode
 */
cr_scancode cr_input_to_sc(cr_input key);

/**
 * Creates a new input handler.
 *
 * Params:
 *   cr_function - a function to handle input
 *
 * Returns:
 *   input_handler* - a new input handler object
 */
input_handler* cr_create_input_handler(cr_function f);

/**
 * Frees the resources allocated for an input handler.
 *
 * Params:
 *   input_handler* - an input handler to destroy
 */
void cr_destroy_input_handler(input_handler* handler);

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