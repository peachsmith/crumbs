#ifndef JEP_CRUMBS_SDL_H
#define JEP_CRUMBS_SDL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

/**
 * Keyboard scancodes.
 */
typedef SDL_Scancode cr_scancode;

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

#endif