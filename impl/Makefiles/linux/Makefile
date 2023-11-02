#=============================================================================
# Makefile for Linux
#=============================================================================

CC=gcc

# libcrumbs.so.1.0.0
MAJOR_VERSION=1
MINOR_VERSION=0
PATCH_VERSION=0
LIB_NAME=crumbs
LIB_SONAME=lib$(LIB_NAME).so.$(MAJOR_VERSION)
LIB_REALNAME=$(LIB_SONAME).$(MINOR_VERSION).$(PATCH_VERSION)
LIB_DEPENDENCIES=-lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer
CFLAGS=-Wall -Werror -fPIC -shared -Wl,-soname,$(LIB_SONAME)
INCLUDE_DIR=-I../.. -I../../..
SRC=../../../impl/*.c
INSTALL_DIR=/usr/local/lib

all:
	$(CC) $(CFLAGS)    $(SRC) -DCRUMBS_EXPORTS -o $(LIB_REALNAME) $(INCLUDE_DIR) $(LIB_DEPENDENCIES)

debug:
	$(CC) $(CFLAGS) -g $(SRC) -DCRUMBS_EXPORTS -o $(LIB_REALNAME) $(INCLUDE_DIR) $(LIB_DEPENDENCIES)
