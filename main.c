#include <stdio.h>
#include "crumbs.h"

int main(int argc, char** argv)
{
    printf("Hello, World!\n");

    if (!cr_init())
    {
        fprintf(stderr, "failed to initialize crumbs\n");
        return 1;
    }

    cr_context* ctx = cr_create_context();

    if (!ctx)
    {
        fprintf(stderr, "failed to create crumbs context\n");
        cr_terminate();
        return 1;
    }

    SDL_Rect rect;
    rect.w = 32;
    rect.h = 32;
    rect.x = 32;
    rect.y = 32;

    // NOTE: for movement, typically use key states
    // SDL_GetKeyboardState(NULL);

    // TODO:
    // regulate framerate

    cr_texture* person_tex = cr_load_image(ctx, "character.png");
    if (!person_tex)
    {
        fprintf(stderr, "failed to load image. %s\n", cr_get_error());
        cr_destroy_context(ctx);
        cr_terminate();
        return 1;
    }

    cr_font* font = cr_load_font("DroidSansMono.ttf", 12);
    if (!font)
    {
        fprintf(stderr, "failed to load font. %s\n", cr_get_error());
        cr_destroy_image(person_tex);
        cr_destroy_context(ctx);
        cr_terminate();
        return 1;
    }

    cr_glyph* atlas = cr_create_font_atlas(ctx, font);
    if (!atlas)
    {
        fprintf(stderr, "failed to create font atlas. %s\n", cr_get_error());
        cr_destroy_image(person_tex);
        cr_destroy_font(font);
        cr_destroy_context(ctx);
        cr_terminate();
        return 1;
    }

    // Loada sound effect.
    // Mix_Chunk* pop_sound = Mix_LoadWAV("uh.ogg");
    // Mix_Chunk* pop2_sound = Mix_LoadWAV("pop2.ogg");
    // Mix_Chunk* pop3_sound = Mix_LoadWAV("pop3.ogg");
    // if (!pop_sound)
    // {
    //     fprintf(stderr, "failed to load sound effect. %s\n", SDL_GetError());
    //     cr_destroy_image(person_tex);
    //     cr_terminate();
    //     return 1;
    // }

    // int m_pressed = 0;
    // int n_pressed = 0;
    // int b_pressed = 0;

    int left_pressed = 0;
    int right_pressed = 0;
    int down_pressed = 0;
    int up_pressed = 0;

    printf("entering main loop\n");

    // main loop
    while (!ctx->done)
    {
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                ctx->done = 1;
            }
        }

        if (ctx->key_states[SDL_SCANCODE_ESCAPE])
        {
            ctx->done = 1;
        }

        // Handle left arrow key,
        if (ctx->key_states[SDL_SCANCODE_LEFT])
        {
            rect.x--;
            if (!left_pressed)
            {
                left_pressed = 1;
                printf("left pressed\n");
            }
        }
        else if (left_pressed)
        {
            left_pressed = 0;
            printf("left released\n");
        }

        // Handle right arrow key,
        if (ctx->key_states[SDL_SCANCODE_RIGHT])
        {
            rect.x++;
            if (!right_pressed)
            {
                right_pressed = 1;
                printf("right pressed\n");
            }
        }
        else if (right_pressed)
        {
            right_pressed = 0;
            printf("right released\n");
        }

        if (ctx->key_states[SDL_SCANCODE_UP])
        {
            rect.y--;
            if (!up_pressed)
            {
                up_pressed = 1;
                printf("up pressed\n");
            }
        }
        else if (up_pressed)
        {
            up_pressed = 0;
            printf("up released\n");
        }

        if (ctx->key_states[SDL_SCANCODE_DOWN])
        {
            rect.y++;
            if (!down_pressed)
            {
                down_pressed = 1;
                printf("down pressed\n");
            }
        }
        else if (down_pressed)
        {
            down_pressed = 0;
            printf("down released\n");
        }



        // if (ctx->key_states[SDL_SCANCODE_M])
        // {
        //     if (!m_pressed)
        //     {
        //         m_pressed = 1;
        //         printf("playing sound\n");
        //         Mix_PlayChannel(1, pop_sound, 0);
        //         printf("done playing sound\n");
        //     }
        // }
        // else if (m_pressed)
        // {
        //     m_pressed = 0;
        // }

        // if (ctx->key_states[SDL_SCANCODE_N])
        // {
        //     if (!n_pressed)
        //     {
        //         n_pressed = 1;
        //         printf("playing sound\n");
        //         Mix_PlayChannel(1, pop2_sound, 0);
        //         printf("done playing sound\n");
        //     }
        // }
        // else if (n_pressed)
        // {
        //     n_pressed = 0;
        // }

        // if (ctx->key_states[SDL_SCANCODE_B])
        // {
        //     if (!b_pressed)
        //     {
        //         b_pressed = 1;
        //         printf("playing sound\n");
        //         Mix_PlayChannel(1, pop3_sound, 0);
        //         printf("done playing sound\n");
        //     }
        // }
        // else if (b_pressed)
        // {
        //     b_pressed = 0;
        // }

        SDL_SetRenderDrawColor(ctx->renderer, 0, 0, 0, 255);
        SDL_RenderClear(ctx->renderer);

        SDL_RenderCopy(ctx->renderer, person_tex, NULL, &rect);

        cr_render_text(ctx, atlas, "Hello, World!", 2, 2);

        // SDL_SetRenderDrawColor(renderer, 40, 200, 120, 255);
        // SDL_RenderFillRect(renderer, &rect);

        SDL_RenderPresent(ctx->renderer);
        SDL_Delay(1);
    }

    printf("done with main loop\n");

    cr_destroy_font_atlas(atlas);

    // Mix_FreeChunk(pop_sound);
    // Mix_FreeChunk(pop2_sound);
    // Mix_FreeChunk(pop3_sound);
    TTF_CloseFont(font);
    cr_destroy_image(person_tex);
    // SDL_DestroyTexture(text_tex);

    cr_destroy_context(ctx);
    cr_terminate();

    return 0;
}
