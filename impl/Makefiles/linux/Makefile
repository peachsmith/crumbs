#=============================================================================
# Makefile for Linux
#=============================================================================

CC=gcc
LIB_OUTPUT=libcrumbs.so

INCLUDE_DIR=-I../.. -I../../..

CFLAGS=-Wall -Werror
LIBS=-lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer

SRC=../../../impl/*.c

all:
	$(CC) $(CFLAGS) -fPIC -shared $(SRC) -DCRUMBS_EXPORTS -o $(LIB_OUTPUT) $(INCLUDE_DIR) $(LINK_DIR) $(LIBS)

debug:
	$(CC) $(CFLAGS) -g -fPIC -shared $(SRC) -DCRUMBS_EXPORTS -o $(LIB_OUTPUT) $(INCLUDE_DIR) $(LINK_DIR) $(LIBS)
