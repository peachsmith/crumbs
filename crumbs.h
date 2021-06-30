#ifndef JEP_CRUMBS_H
#define JEP_CRUMBS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

// texture
typedef SDL_Texture cr_texture;

// font
typedef TTF_Font cr_font;

// sound effect
typedef Mix_Chunk cr_sound;

// music
typedef Mix_Chunk cr_music;

typedef struct cr_glyph {
    int w;
    int h;
    cr_texture* img;
}cr_glyph;

// contains the state of the application
typedef struct cr_context {
    SDL_Window* window;
    SDL_Renderer* renderer;
    const char* key_states;
    int done;
} cr_context;

/**
 * Initializes the crumbs framework,
 *
 * Returns:
 *   int - 1 on success or 0 on failure.
 */
int cr_init();

/**
 * Terminates the crumbs framework.
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

const char* cr_get_error();

cr_texture* cr_load_image(cr_context* ctx, const char* path);

void cr_destroy_image(cr_texture* img);

cr_font* cr_load_font(const char* path, int point_size);

void cr_destroy_font(cr_font* font);

int cr_create_glyph_image(cr_context* ctx, cr_font* font, char c, cr_glyph* g);

void cr_destroy_glyph(cr_glyph* glyph);

cr_glyph* cr_create_font_atlas(cr_context* ctx, cr_font* font);

void cr_destroy_font_atlas(cr_glyph* atlas);

void cr_render_text(cr_context* ctx, cr_glyph* atlas, const char* text, int x, int y);

#endif
