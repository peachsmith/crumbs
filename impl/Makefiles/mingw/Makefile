#=============================================================================
# Makefile for MinGW-w64
#=============================================================================

CC=gcc
CFLAGS=-Wall -Werror
LIBS=-lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

INCLUDE_DIR=-I../.. -I../../..

SRC=../../../impl/*.c

all:
	$(CC) -fPIC -shared  $(SRC) -DCRUMBS_EXPORTS -o libcrumbs.dll $(INCLUDE_DIR) -mwindows $(LIBS)

debug:
	$(CC) -g -O0 -fPIC -shared $(SRC) -DCRUMBS_EXPORTS -DCR_DEBUG -o libcrumbs.dll $(INCLUDE_DIR) $(LIBS)

dist:
	mkdir -p mingw/include/crumbs
	mkdir -p mingw/lib
	cp libcrumbs.dll mingw/lib
	cp ../../../crumbs.h mingw/include/crumbs
