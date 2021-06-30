#include "crumbs.h"
#include <stdlib.h>
#include <string.h>

int cr_init()
{
    // Initialize SDL.
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
    {
        return 0;
    }

    // On Linux, the X11 does some weird graphical stuff by
    // bypassing something called a "compositor", so we
    // disable the bypass here.
#if defined linux && SDL_VERSION_ATLEAST(2, 0, 8)
    if (!SDL_SetHint(SDL_HINT_VIDEO_X11_NET_WM_BYPASS_COMPOSITOR, "0"))
    {
        fprintf(stderr, "failed to disable compositor bypass\n");
        return 0;
    }
#endif

    // Initialize SDL_mixer for audio.
    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 16) < 0)
    {
        fprintf(stderr, "failed to initialize SDL2_mixer. %s\n", SDL_GetError());
        SDL_Quit();
        return 0;
    }

    // Enable OGG file loading.
    if (!(Mix_Init(MIX_INIT_OGG) & MIX_INIT_OGG))
    {
        fprintf(stderr, "failed to enable ogg loading. %s\n", SDL_GetError());
        Mix_CloseAudio();
        SDL_Quit();
        return 0;
    }

    // Initialize SDL_image for loading PNG files.
    if (!IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)
    {
        fprintf(stderr, "failed to initialize SDL2_image. %s\n", SDL_GetError());
        Mix_Quit();
        Mix_CloseAudio();
        SDL_Quit();
        return 0;
    }

    // Initialize SDL_ttf for text rendering.
    if (TTF_Init() < 0)
    {
        fprintf(stderr, "failed to initialize SDL2_ttf. %s\n", SDL_GetError());
        IMG_Quit();
        Mix_Quit();
        Mix_CloseAudio();
        SDL_Quit();
        return 0;
    }

    return 1;
}

void cr_terminate()
{
    TTF_Quit();
    IMG_Quit();
    Mix_Quit();
    Mix_CloseAudio();
    SDL_Quit();
}

/**
 * Creates a new crumbs context.
 *
 * Returns:
 *   cr_context* - a pointer to a crumbs context, or NULL on failure.
 */
cr_context* cr_create_context()
{
    cr_context* ctx = NULL;

    ctx = (cr_context*)malloc(sizeof(cr_context));

    if (!ctx)
    {
        return NULL;
    }

    // Create a window.
    ctx->window = SDL_CreateWindow("Crumbs Demo",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        240,
        160,
        0
    );

    if (ctx->window == NULL)
    {
        free(ctx);
        return NULL;
    }

    ctx->renderer = SDL_CreateRenderer(ctx->window,
        -1,
        SDL_RENDERER_ACCELERATED
    );

    if (ctx->renderer == NULL)
    {
        SDL_DestroyWindow(ctx->window);
        free(ctx);
        return NULL;
    }

    ctx->key_states = SDL_GetKeyboardState(NULL);

    ctx->done = 0;

    return ctx;
}

void cr_destroy_context(cr_context* ctx)
{
    if (ctx == NULL)
    {
        return;
    }

    SDL_DestroyRenderer(ctx->renderer);
    SDL_DestroyWindow(ctx->window);
    free(ctx);
}

const char* cr_get_error()
{
    return SDL_GetError();
}

cr_texture* cr_load_image(cr_context* ctx, const char* path)
{
    // Load the image. The IMG_Load returns a pointer to an SDL_Surface
    // which we will need to convert into a texture.
    SDL_Surface* surface = IMG_Load(path);

    if (!surface)
    {
        return NULL;
    }

    // Convert the SDL_Surface into an SDL_Texture.
    SDL_Texture* texture = SDL_CreateTextureFromSurface(ctx->renderer, surface);

    // Destroy the SDL_Surface since it's no longer needed.
    // This should be done regardless of whether or not the texture
    // creation succeeded.
    SDL_FreeSurface(surface);

    if (!texture)
    {
        fprintf(stderr, "failed to create texture. %s\n", SDL_GetError());
        return NULL;
    }

    return texture;
}

void cr_destroy_image(cr_texture* img)
{
    SDL_DestroyTexture(img);
}

cr_font* cr_load_font(const char* path, int point_size)
{
    TTF_Font* font = TTF_OpenFont(path, point_size);
    if (!font)
    {
        return NULL;
    }

    return font;
}

void cr_destroy_font(cr_font* font)
{
    TTF_CloseFont(font);
}

int cr_create_glyph_image(cr_context* ctx, cr_font* font, char c, cr_glyph* g)
{
    SDL_Surface* sur;

    SDL_Color color = { 250, 250, 250 };
    // TTF_RenderGlyph_Shaded for foreground and background colors.
    sur = TTF_RenderGlyph_Blended(font, (Uint16)c, color);

    if (!sur)
    {
        return 0;
    }

    SDL_Texture* tex = SDL_CreateTextureFromSurface(ctx->renderer, sur);

    if (!tex)
    {
        SDL_FreeSurface(sur);
        return 0;
    }

    g->w = sur->w;
    g->h = sur->h;
    g->img = tex;

    SDL_FreeSurface(sur);

    return 1;
}

void cr_destroy_glyph(cr_glyph* glyph)
{
    cr_destroy_image(glyph->img);
    free(glyph);
}

cr_glyph* cr_create_font_atlas(cr_context* ctx, cr_font* font)
{
    // Allocate spac efor 95 characters.
    // The range 32 to 126 or ' ' to '~'.
    cr_glyph* atlas = (cr_glyph*)malloc(sizeof(cr_glyph) * 95);

    if (!atlas)
    {
        return NULL;
    }

    for (int i = 0; i < 95; i++)
    {
        int g = cr_create_glyph_image(ctx, font, (char)(i + 32), &(atlas[i]));
        if (!g)
        {
            for (int j = 0; j < i; j++)
            {
                cr_destroy_image(atlas[j].img);
            }

            free(atlas);

            return NULL;
        }
    }

    return atlas;
}

void cr_destroy_font_atlas(cr_glyph* atlas)
{
    for (int i = 0; i < 95; i++)
    {
        SDL_DestroyTexture(atlas[i].img);
    }

    free(atlas);
}

void cr_render_text(cr_context* ctx, cr_glyph* atlas, const char* text, int x, int y)
{
    SDL_Rect r;
    r.x = x;
    r.y = y;

    size_t len = strlen(text);

    for (size_t i = 0; i < len; i++)
    {
        int c = (int)(text[i]);
        if (c >= 32 && c <= 126)
        {
            cr_glyph g = atlas[c - 32];

            // Update the width and height of the rectangle.
            r.w = g.w;
            r.h = g.h;

            // Render the glyph.
            SDL_RenderCopy(ctx->renderer, g.img, NULL, &r);

            // Advance the x position based on the width of the
            // the current glyph.
            r.x += (g.w + 1);
        }
    }
}
