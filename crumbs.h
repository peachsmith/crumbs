#ifndef JEP_CRUMBS_H
#define JEP_CRUMBS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "collection.h"

// resource types
#define CR_RESOURCE_TEXTURE 1
#define CR_RESOURCE_FONT    2
#define CR_RESOURCE_SOUND   3

typedef struct cr_resource cr_resource;
typedef enum cr_input cr_input;
typedef struct cr_glyph cr_glyph;
typedef struct cr_input_handler cr_input_handler;
typedef struct cr_context cr_context;
typedef void(*cr_function)(cr_context*, void*);

// input types
#define CR_KEYBOARD 1

// total number of inputs
#define CR_INPUT_COUNT 63

// input actuation flags
enum cr_input {
    CR_KEY_ESCAPE,
    CR_KEY_LEFT,
    CR_KEY_UP,
    CR_KEY_RIGHT,
    CR_KEY_DOWN,
    CR_KEY_A,
    CR_KEY_B,
    CR_KEY_C,
    CR_KEY_D,
    CR_KEY_E,
    CR_KEY_F,
    CR_KEY_G,
    CR_KEY_H,
    CR_KEY_I,
    CR_KEY_J,
    CR_KEY_K,
    CR_KEY_L,
    CR_KEY_M,
    CR_KEY_N,
    CR_KEY_O,
    CR_KEY_P,
    CR_KEY_Q,
    CR_KEY_R,
    CR_KEY_S,
    CR_KEY_T,
    CR_KEY_U,
    CR_KEY_V,
    CR_KEY_W,
    CR_KEY_X,
    CR_KEY_Y,
    CR_KEY_Z,
    CR_KEY_0,
    CR_KEY_1,
    CR_KEY_2,
    CR_KEY_3,
    CR_KEY_4,
    CR_KEY_5,
    CR_KEY_6,
    CR_KEY_7,
    CR_KEY_8,
    CR_KEY_9,
    CR_KEY_MINUS,
    CR_KEY_EQUALS,
    CR_KEY_BACKTICK,
    CR_KEY_COMMA,
    CR_KEY_PERIOD,
    CR_KEY_SEMICOLON,
    CR_KEY_APOSTROPHE,
    CR_KEY_LEFT_BRACKET,
    CR_KEY_RIGHT_BRACKET,
    CR_KEY_BACKSPACE,
    CR_KEY_SPACE,
    CR_KEY_SLASH,
    CR_KEY_BACKSLASH,
    CR_KEY_TAB,
    CR_KEY_CAPS,
    CR_KEY_LSHIFT,
    CR_KEY_RSHIFT,
    CR_KEY_LALT,
    CR_KEY_RALT,
    CR_KEY_LCTRL,
    CR_KEY_RCTRL,

    // limit of keys
    CR_KEY_MAX
};

struct cr_resource {

    int type;

    // SDL fields
    union
    {
        SDL_Texture* texture;
        TTF_Font* font;
        Mix_Chunk* sound;
        Mix_Music* music;
    } data;
};

// An image of a single text character
struct cr_glyph {
    int w;
    int h;
    cr_resource* img;
};

struct cr_input_handler {
    cr_function handle;
};

/**
 * A context contains the state of the application.
 * Only one context should be created for an application.
 */
struct cr_context {

    // SDL fields
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;
    Uint32 ticks;
    const Uint8* key_states;

    size_t inputs[CR_INPUT_COUNT];
    jep_node* input_handlers;
    int done;
};

// scancodes
#define CR_SC_A SDL_SCANCODE_A
#define CR_SC_B SDL_SCANCODE_B
#define CR_SC_C SDL_SCANCODE_C
#define CR_SC_D SDL_SCANCODE_D
#define CR_SC_E SDL_SCANCODE_E
#define CR_SC_F SDL_SCANCODE_F
#define CR_SC_G SDL_SCANCODE_G
#define CR_SC_H SDL_SCANCODE_H
#define CR_SC_I SDL_SCANCODE_I
#define CR_SC_J SDL_SCANCODE_J
#define CR_SC_K SDL_SCANCODE_K
#define CR_SC_L SDL_SCANCODE_L
#define CR_SC_M SDL_SCANCODE_M
#define CR_SC_N SDL_SCANCODE_N
#define CR_SC_O SDL_SCANCODE_O
#define CR_SC_P SDL_SCANCODE_P
#define CR_SC_Q SDL_SCANCODE_Q
#define CR_SC_R SDL_SCANCODE_R
#define CR_SC_S SDL_SCANCODE_S
#define CR_SC_T SDL_SCANCODE_T
#define CR_SC_U SDL_SCANCODE_U
#define CR_SC_V SDL_SCANCODE_V
#define CR_SC_W SDL_SCANCODE_W
#define CR_SC_X SDL_SCANCODE_X
#define CR_SC_Y SDL_SCANCODE_Y
#define CR_SC_Z SDL_SCANCODE_Z
#define CR_SC_0 SDL_SCANCODE_0
#define CR_SC_1 SDL_SCANCODE_1
#define CR_SC_2 SDL_SCANCODE_2
#define CR_SC_3 SDL_SCANCODE_3
#define CR_SC_4 SDL_SCANCODE_4
#define CR_SC_5 SDL_SCANCODE_5
#define CR_SC_6 SDL_SCANCODE_6
#define CR_SC_7 SDL_SCANCODE_7
#define CR_SC_8 SDL_SCANCODE_8
#define CR_SC_9 SDL_SCANCODE_9

#define CR_SC_MINUS         SDL_SCANCODE_MINUS
#define CR_SC_EQUALS        SDL_SCANCODE_EQUALS
#define CR_SC_COMMA         SDL_SCANCODE_COMMA
#define CR_SC_PERIOD        SDL_SCANCODE_PERIOD
#define CR_SC_SEMICOLON     SDL_SCANCODE_SEMICOLON
#define CR_SC_APOSTROPHE    SDL_SCANCODE_APOSTROPHE
#define CR_SC_LEFT_BRACKET  SDL_SCANCODE_LEFTBRACKET
#define CR_SC_RIGHT_BRACKET SDL_SCANCODE_RIGHTBRACKET
#define CR_SC_SLASH         SDL_SCANCODE_SLASH
#define CR_SC_BACKSLASH     SDL_SCANCODE_BACKSLASH
#define CR_SC_BACKTICK      SDL_SCANCODE_GRAVE
#define CR_SC_SPACE         SDL_SCANCODE_SPACE

#define CR_SC_TAB       SDL_SCANCODE_TAB
#define CR_SC_CAPS      SDL_SCANCODE_CAPSLOCK
#define CR_SC_BACKSPACE SDL_SCANCODE_BACKSPACE
#define CR_SC_ESCAPE    SDL_SCANCODE_ESCAPE
#define CR_SC_LCTRL     SDL_SCANCODE_LCTRL
#define CR_SC_RCTRL     SDL_SCANCODE_RCTRL
#define CR_SC_LALT      SDL_SCANCODE_LALT
#define CR_SC_RALT      SDL_SCANCODE_RALT
#define CR_SC_LSHIFT    SDL_SCANCODE_LSHIFT
#define CR_SC_RSHIFT    SDL_SCANCODE_RSHIFT


#define CR_SC_LEFT  SDL_SCANCODE_LEFT
#define CR_SC_UP    SDL_SCANCODE_UP
#define CR_SC_RIGHT SDL_SCANCODE_RIGHT
#define CR_SC_DOWN  SDL_SCANCODE_DOWN

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
 * Populates a context with everything it needs to run.
 *
 * Params:
 *   cr_context* - the application context
 */
void cr_configure_context(cr_context*);

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