#ifndef PENUT_H
#define PENUT_H

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>

#include "crumbs.h"

// font resources
#define PENUT_FONT_DEFAULT 0

// limits
#define PENUT_MAX_ENTITIES 256
#define PENUT_MAX_INPUT_HANDLERS 20
#define PENUT_MAX_MENUS 10
#define PENUT_MAX_DIALOGS 10
#define PENUT_MAX_OVERLAYS 10
#define PENUT_MAX_TEXTURES 10
#define PENUT_MAX_FONTS 10
#define PENUT_MAX_SOUNDS 10

// entity flags
#define ENTITY_FLAG_GROUND 0
#define ENTITY_FLAG_JUMP 1
#define ENTITY_FLAG_DOWN 2
#define ENTITY_FLAG_MOVE 3
#define ENTITY_FLAG_UPDATE 4
#define ENTITY_FLAG_SLOPE 5
#define ENTITY_FLAG_MIRROR 6
#define ENTITY_FLAG_INVINCIBLE 7
#define ENTITY_FLAG_PAUSE 8
#define ENTITY_FLAG_MENU 9
#define ENTITY_FLAG_10 10
#define ENTITY_FLAG_11 11
#define ENTITY_FLAG_12 12
#define ENTITY_FLAG_13 13
#define ENTITY_FLAG_14 14
#define ENTITY_FLAG_15 15

// entity types
#define ENTITY_TYPE_SECTION 0
#define ENTITY_TYPE_BLOCK 1

// total number of entity types
#define ENTITY_TYPE_MAX 2

int penut_init_app(cr_app *);

#endif