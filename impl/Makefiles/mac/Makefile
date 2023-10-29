#=============================================================================
# Makefile for MacOS
#=============================================================================

CC=clang
LIB_OUTPUT=libcrumbs.dylib

INCLUDE_DIR=-I/Library/Frameworks/SDL2.framework/Headers -I../.. -I../../..
LINK_DIR=-F/Library/Frameworks -L.

CFLAGS=-Wall -Werror
LIBS=-framework SDL2 -framework SDL2_image -framework SDL2_ttf -framework SDL2_mixer

SRC=../../../impl/*.c

all:
	$(CC) $(CFLAGS) -fPIC -shared $(SRC) -DCRUMBS_EXPORTS -o $(LIB_OUTPUT) $(INCLUDE_DIR) $(LINK_DIR) $(LIBS)

debug:
	$(CC) $(CFLAGS) -g -fPIC -shared $(SRC) -DCRUMBS_EXPORTS -o $(LIB_OUTPUT) $(INCLUDE_DIR) $(LINK_DIR) $(LIBS)
