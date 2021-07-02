#ifndef JEP_CRUMBS_IMPL
#define JEP_CRUMBS_IMPL

#include "crumbs.h"
#include "input_map.h"
#include "collection.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

/**
 * A texture represents graphical data that can be rendered on the screen.
 */
typedef SDL_Texture cr_texture;

/**
 * A font is data that allows the creation of text.
 */
typedef TTF_Font cr_font;

/**
 * A sound is a short segment of sound whose playback duration is usually
 * a few seconds.
 */
typedef Mix_Chunk cr_sound;

/**
 * Music is sound data that is intented to play for an extended period
 * of time.
 */
typedef Mix_Chunk cr_music;

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