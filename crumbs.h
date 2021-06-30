#ifndef JEP_CRUMBS_H
#define JEP_CRUMBS_H

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
 * A context contains the state of the application.
 * Only one context should be created for an application.
 */
typedef struct cr_context {
    SDL_Window* window;
    SDL_Renderer* renderer;
    const char* key_states;
    SDL_Event event;
    Uint32 ticks;
    int done;

    // temporary debugging fields
    SDL_Rect* tmp_rect;
    cr_texture* tmp_entity;
    cr_glyph* tmp_atlas;
} cr_context;

/**
 * Initializes the crumbs framework.
 * This should be called once per application before calling any other
 * functions in the framework.
 *
 * Returns:
 *   int - 1 on success or 0 on failure.
 */
int cr_init();

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
 * Retrieves an error message.
 *
 * Returns:
 *   char* - a string containing an error message
 */
const char* cr_get_error();

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
 * Detects events like window management.
 * 
 * Params:
 *   cr_context* - the context of the application
 */
void cr_handle_events(cr_context* ctx);

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

/**
 * Loads an image from a file.
 *
 * Params:
 *   cr_context* - the current context
 *   char* - the path of the file to load
 *
 * Returns:
 *   cr_texture* - a new texture, or NULL on failure
 */
cr_texture* cr_load_image(cr_context* ctx, const char* path);

/**
 * Frees the resources allocated for a texture.
 *
 * Params:
 *   cr_texture* a texture to free
 */
void cr_destroy_image(cr_texture* img);

/**
 * Loads a font from a font file.
 *
 * Params:
 *   const char* - the file path of the font to load
 *   int - the point size of the font
 *
 * Returns:
 *   cr_font* - a font object
 */
cr_font* cr_load_font(const char* path, int point_size);

/**
 * Frees the resources allocated for a font object.
 *
 * Params:
 *   cr_font* - a font to free
 */
void cr_destroy_font(cr_font* font);

/**
 * Creates a texture for a single character.
 *
 * Params:
 *   cr_context* - the context
 *   cr_font* - the font on which the texture data is based
 *   char - the character to convert to a texture
 *   cr_glyph* - a reference to a glyph object to receive the data
 *
 * Returns:
 *   int - 1 on success or 0 on failure
 */
int cr_create_glyph_image(cr_context* ctx, cr_font* font, char c, cr_glyph* g);

/**
 * Creates a font atlas for a given font.
 * A font atlas is a collection of texture data for individual characters.
 * This can be used for dynamic strings of text that may change based on
 * some events.
 *
 * Params:
 *   cr_context* - the context
 *   cr_font* - the font to use
 *
 * Returns:
 *   cr_glyph* - an array of glyph data
 */
cr_glyph* cr_create_font_atlas(cr_context* ctx, cr_font* font);

/**
 * Frees the resources allocated for a font atlas.
 *
 * Params:
 *   cr_glyph* - a font atlas
 */
void cr_destroy_font_atlas(cr_glyph* atlas);

/**
 * Renders a string of text to the screen.
 *
 * Params:
 *   cr_context* - the context
 *   cr_glyph* - the font atlas
 *   const char* - a string of text to render
 *   int - the x coordinate on the screen
 *   int - the y coordinate on the screen
 */
void cr_render_text(cr_context* ctx, cr_glyph* atlas, const char* text, int x, int y);

#endif
