#=============================================================================
# Makefile for Linux
#=============================================================================

CC=gcc

INCLUDE_DIR=-I../..
# LINK_DIR=-L../../../impl/Makefiles/linux

CFLAGS=-Wall -Werror
LIBS=-lcrumbs -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer

# This is needed to get access to SDL's main function without having to
# include the SDL header file.
MAIN_DEF=-D_start=_SDL_main

D=../..
SRC=$(D)/*.c $(D)/common/*.c $(D)/entities/*.c $(D)/input/*.c $(D)/scenes/*.c $(D)/util/*.c

all:
	$(CC) $(MAIN_DEF) $(SRC) -o demo.out $(INCLUDE_DIR) $(LIBS)

debug:
	$(CC) -g -O0 -DDEBUG $(MAIN_DEF) $(SRC) -o demo.out $(INCLUDE_DIR) $(LIBS)
