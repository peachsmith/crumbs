CC=gcc

# Dependency directory
DEPS=/home/john/Documents/crumbs

# SDL installation directories
SDL=$(DEPS)/build-sdl
SDL_IMAGE=$(DEPS)/build-sdl-image
SDL_TTF=$(DEPS)/build-sdl-ttf
SDL_MIXER=$(DEPS)/build-sdl-mixer

INC=-I$(SDL)/include

LIB=-L$(SDL)/lib   \
-L$(SDL_IMAGE)/lib \
-L$(SDL_TTF)/lib   \
-L$(SDL_MIXER)/lib

SRC=main.c crumbs.c

LNK=-lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

all:
	$(CC) $(LIB) $(INC) $(SRC) -o crumbs $(LNK)

