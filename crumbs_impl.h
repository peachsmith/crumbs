#ifndef JEP_CRUMBS_IMPL
#define JEP_CRUMBS_IMPL

#include "crumbs.h"
#include "crumbs_sdl.h"
#include "collection.h"

// input types
#define CR_KEYBOARD 1

// total number of inputs
#define CR_INPUT_COUNT 63

// key indices
typedef enum cr_input {
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
} cr_input;


/**
 * A glyph represents a single text character that can be rendered on
 * the screen.
 */
typedef struct cr_glyph {
    int w;
    int h;
    cr_texture* img;
}cr_glyph;

/**
 * cr_context implementation
 */
struct cr_context {

    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;
    Uint32 ticks;

    const Uint8* key_states;

    size_t inputs[CR_INPUT_COUNT];

    jep_node* input_handlers;

    int done;
};

/**
 * A callback function.
 * The caller of this function must know the correct
 * data type of the second argument.
 */
typedef void(*cr_function)(cr_context*, void*);

/**
 * input_handler implementation
 */
struct input_handler {
    cr_function handle;
};

#endif