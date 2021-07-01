#ifndef JEP_CRUMBS_H
#define JEP_CRUMBS_H

/**
 * A context contains the state of the application.
 * Only one context should be created for an application.
 */
typedef struct cr_context cr_context;

/**
 * Initializes the crumbs framework.
 * This should be called once per application before calling any other
 * functions in the framework.
 *
 * Returns:
 *   int - 1 on success or 0 on failure.
 */
int cr_initialize();

/**
 * Terminates the crumbs framework.
 * This should be called once per application after all other resources
 * are freed.
 */
void cr_terminate();

/**
 * Creates a new crumbs context.
 *
 * Returns:
 *   cr_context* - a pointer to a crumbs context, or NULL on failure.
 */
cr_context* cr_create_context();

/**
 * Frees the resources allocated for a crumbs context.
 *
 * Params:
 *   cr_context - a pointer to the context to destroy
 */
void cr_destroy_context(cr_context* ctx);

/**
 * Determines if the main loop should be concluded.
 *
 * Params:
 *   cr_context* - the context of the application
 *
 * Returns:
 *   int - 1 if the loop should be exited, or 0 if it should continue
 */
int cr_is_done(cr_context* ctx);

/**
 * Begins an iteration of the main loop.
 * This should be called once at the start of the main loop
 * of the application.
 *
 * Params:
 *   cr_context* - the context of the application
 */
void cr_begin_frame(cr_context* ctx);

/**
 * Handles events like messages from a window management system.
 *
 * Params:
 *   cr_context* - the context of the application
 */
void cr_handle_events(cr_context* ctx);

/**
 * Handles user input.
 *
 * Params:
 *   cr_context* - the context of the application
 */
void cr_handle_input(cr_context* ctx);

/**
 * Updates the state of the application.
 * This is where we handle things like collision detection and advancing
 * the frames of an animation.
 *
 * Params:
 *   cr_context* - the context of the application
 */
void cr_update(cr_context* ctx);

/**
 * Renders graphical data to the screen based on the current
 * state of the application.
 *
 * Params:
 *   cr_context* - the context of the application
 */
void cr_render(cr_context* ctx);

/**
 * Concludes an iteration of the main loop.
 * This should be called once at the end of each iteration of the main loop.
 *
 * Params:
 *   cr_context* - the context of the application
 */
void cr_end_frame(cr_context* ctx);

#endif
