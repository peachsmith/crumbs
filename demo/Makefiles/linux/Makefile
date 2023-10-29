#=============================================================================
# Makefile for Linux
#=============================================================================

CC=gcc

INCLUDE_DIR=-I../.. -I../../..
LINK_DIR=-L../../../impl/Makefiles/linux

CFLAGS=-Wall -Werror
LIBS=-lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer

# This is needed to get access to SDL's main function without having to
# include the SDL header file.
MAIN_DEF=-D_start=_SDL_main

D=../..
SRC=$(D)/*.c $(D)/common/*.c $(D)/entities/*.c $(D)/input/*.c $(D)/scenes/*.c $(D)/util/*.c

all:
	$(CC) $(MAIN_DEF) $(SRC) -o demo.out $(INCLUDE_DIR) $(LINK_DIR) $(LIBS) -lcrumbs

debug:
	$(CC) -g $(MAIN_DEF) $(SRC) -o demo.out $(INCLUDE_DIR) $(LINK_DIR) $(LIBS) -lcrumbs
