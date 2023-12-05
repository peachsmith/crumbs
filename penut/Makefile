#=============================================================================
# Makefile for MinGW-w64
#=============================================================================

CC=gcc

INCLUDE_DIR=-I..
LINK_DIR=-L.

CFLAGS=-Wall -Werror
LIBS=-lmingw32 -lcrumbs -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer

# This is needed to get access to SDL's main function without having to
# include the SDL header file.
MAIN_DEF=-Dmain=SDL_main
SRC=*.c

all:
	$(CC) $(CFLAGS) $(MAIN_DEF) $(SRC) -o penut.exe $(INCLUDE_DIR) -mwindows $(LINK_DIR) $(LIBS)

debug:
	$(CC) $(CFLAGS) -g -O0 $(MAIN_DEF) $(SRC) -o penut.exe $(INCLUDE_DIR) $(LINK_DIR) $(LIBS)
