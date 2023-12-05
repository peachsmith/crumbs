#include "penut.h"
#include "entity_types.h"
#include "draw.h"
#include "input.h"

#include <windows.h>

static cr_entity entities[PENUT_MAX_ENTITIES];
static cr_func input_handlers[PENUT_MAX_INPUT_HANDLERS];
static cr_entity *menus[PENUT_MAX_MENUS];
static cr_entity *dialogs[PENUT_MAX_DIALOGS];
static cr_entity *overlays[PENUT_MAX_OVERLAYS];
static cr_texture *textures[PENUT_MAX_TEXTURES];
static cr_font *fonts[PENUT_MAX_FONTS];
static cr_sound *sounds[PENUT_MAX_SOUNDS];
static cr_entity_type entity_types[ENTITY_TYPE_MAX];

// static cr_entity *entity_handles[PENUT_MAX_ENTITY_HANDLES];
// static cr_extension extension;

static int default_get_x_vel(cr_entity *e)
{
    return e->x_vel;
}

static int default_get_y_vel(cr_entity *e)
{
    return e->y_vel;
}

static int should_update(cr_app *app, cr_entity *ent)
{
    cr_entity_func update = app->entity_types[ent->type].update;
    int pause_flag = cr_check_flag(ent, ENTITY_FLAG_PAUSE);
    int menu_flag = cr_check_flag(ent, ENTITY_FLAG_MENU);

    if (!ent->present || update == NULL)
        return 0;

    if (app->pause)
        return pause_flag && !menu_flag;

    return !pause_flag;
}

static int should_render(cr_app *app, cr_entity *ent)
{
    cr_entity_func render = app->entity_types[ent->type].render;
    int pause_flag = cr_check_flag(ent, ENTITY_FLAG_PAUSE);
    int menu_flag = cr_check_flag(ent, ENTITY_FLAG_MENU);

    if (!ent->present || render == NULL)
        return 0;

    if (app->pause)
        return !menu_flag;

    return !pause_flag && !menu_flag;
}

static void update(cr_app *app)
{
    if (app->time == TIMING_DELTA)
    {
        if (app->frame_check < 1)
        {
            return;
        }
    }

    app->ticks++;

    // Handle input.
    if (app->input != NULL && app->input_count > 0)
    {
        app->input[app->input_count - 1](app);
    }

    // update dialogs
    if (app->dialog_count > 0)
    {
        cr_entity *d = app->dialogs[app->dialog_count - 1];
        app->entity_types[d->type].update(app, d);
    }

    // update menus
    if (app->menu_count > 0)
    {
        cr_entity *m = app->menus[app->menu_count - 1];
        app->entity_types[m->type].update(app, m);
    }

    // update overlays
    if (app->overlay_count > 0)
    {
        cr_entity *o = app->overlays[app->overlay_count - 1];
        app->entity_types[o->type].update(app, o);
    }

    // no collision detection necessary
    // handle collisions
    // if (!app->pause)
    // {
    //     common_handle_collisions(app);
    // }

    // main update loop
    for (int i = 0; i < app->entity_cap; i++)
    {
        cr_entity *ent = &(app->entities[i]);
        cr_entity_type t = app->entity_types[ent->type];
        if (should_update(app, ent))
        {
            t.update(app, ent);
        }
    }
}

static void draw(cr_app *app)
{
    if (app->time == TIMING_DELTA)
    {
        if (app->frame_check < 1)
        {
            return;
        }
    }

    draw_background(app);

    for (int i = 0; i < app->entity_cap; i++)
    {
        cr_entity *ent = &(app->entities[i]);
        cr_entity_type t = app->entity_types[ent->type];
        if (should_render(app, ent))
        {
            t.render(app, ent);
        }
    }

    cr_draw_text(
        app,
        app->fonts[PENUT_FONT_DEFAULT],
        "This is where we would render the contents of a PE file.",
        10,
        10);
}

FILE *open_file(const char *name, const char *mode)
{
    FILE *f;

#if (defined(__STDC_LIB_EXT1__) && __STDC_WANT_LIB_EXT1__ == 1) || \
    (defined(_WIN32) && !defined(_CRT_SECURE_NO_WARNINGS))
    if (fopen_s(&f, name, mode))
    {
        return NULL;
    }
#else
    f = fopen(name, mode);
    if (f == NULL)
    {
        return NULL;
    }
#endif

    return f;
}

int penut_init_app(cr_app *app)
{
    for (int i = 0; i < ENTITY_TYPE_MAX; i++)
    {
        entity_types[i].id = 0;
        entity_types[i].width = 0;
        entity_types[i].height = 0;
        entity_types[i].render = NULL;
        entity_types[i].update = NULL;
        entity_types[i].advance = NULL;
        entity_types[i].collide = NULL;
        entity_types[i].get_x_vel = default_get_x_vel;
        entity_types[i].get_y_vel = default_get_y_vel;
        entity_types[i].interactable = 0;
        entity_types[i].interact = NULL;
        entity_types[i].control = 0;
        entity_types[i].spur = 0;
        entity_types[i].move = 0;
        entity_types[i].slope = 0;
    }

    for (int i = 0; i < PENUT_MAX_ENTITIES; i++)
    {
        entities[i].present = 0;
        entities[i].type = 0;
        entities[i].x_pos = 0;
        entities[i].y_pos = 0;
        entities[i].x_vel = 0;
        entities[i].y_vel = 0;
        entities[i].x_acc = 0;
        entities[i].y_acc = 0;
        entities[i].x_t = 0;
        entities[i].y_t = 0;
        entities[i].flags = 0;
        entities[i].data = 0;
        entities[i].animation_ticks = 0;
        entities[i].ticks = 0;
        entities[i].iframes = 0;
        entities[i].carrier = NULL;
        entities[i].text = NULL;
        entities[i].text_len = 0;
        entities[i].tick_limit = 0;
        entities[i].result = 0;
        entities[i].cursor_x = 0;
        entities[i].cursor_y = 0;
        entities[i].scroll_x = 0;
        entities[i].scroll_y = 0;
    }

    app->entity_cap = PENUT_MAX_ENTITIES;
    app->entities = entities;
    app->input = &(input_handlers[0]);
    app->menus = &(menus[0]);
    app->dialogs = &(dialogs[0]);
    app->overlays = &(overlays[0]);
    app->textures = &(textures[0]);
    app->fonts = &(fonts[0]);
    app->sounds = &(sounds[0]);
    app->entity_types = entity_types;
    app->update = update;
    app->draw = draw;

    if (cr_load_font(app, "assets/fonts/JetBrainsMonoNL-Regular.ttf", 14) == NULL)
    {
        fprintf(stderr, "failed to load font\n");
        return 0;
    }

    cr_push_input_handler(app, penut_root_input);

    printf("opening PE file\n");
    FILE *pe_file = open_file("hello.exe", "rb");
    if (pe_file == NULL)
    {
        fprintf(stderr, "failed to open executable file\n");
        return 0;
    }

    // PE sections:
    // MS-DOS Stub
    //   A small program inserted by the linker
    //   At location 0x3C, the stub contains the location of the signature
    //
    // Signature
    //   Located at the offset specified at 0x3C.
    //   Four bytes "PE\0\0"
    //
    // COFF File Header
    //   Immediately after the signature
    //   Offset Size   Field Description
    //   0      2      Machine
    //   2      2      NumberOfSections
    //   4      4      TimeDateStamp
    //   8      4      PointerToSymbolTable
    //   12     4      NumberOfSymbols
    //   16     2      SizeOfOptionalHeader
    //   18     2      Characteristics
    //
    LONG sigLoc;
    char sig[4];

    // signature location
    fseek(pe_file, 0x3C, SEEK_SET);
    fread(&sigLoc, sizeof(LONG), 1, pe_file);
    printf("signature offset: %ld\n", sigLoc);

    // signature
    fseek(pe_file, sigLoc, SEEK_SET);
    fread(sig, sizeof(char), 4, pe_file);
    if (sig[0] != 'P' || sig[1] != 'E' || sig[2] != '\0' || sig[3] != '\0')
    {
        fprintf(stderr, "failed to read PE signature\n");
        fclose(pe_file);
        return 1;
    }
    printf("signature: %s\n", sig);

    // COFF header
    unsigned char coff[20];
    fread(coff, sizeof(unsigned char), 20, pe_file);
    unsigned int machine_type = (((int)(coff[1]) << 8) | coff[0]);
    unsigned int num_sections = (((int)(coff[3]) << 8) | coff[2]);
    unsigned int time_date_stamp = (((int)(coff[7]) << 24) | ((int)(coff[6]) << 16) | ((int)(coff[5]) << 8) | coff[4]);
    unsigned int symbol_pointer = (((int)(coff[11]) << 24) | ((int)(coff[10]) << 16) | ((int)(coff[9]) << 8) | coff[8]);
    unsigned int num_symbols = (((int)(coff[15]) << 24) | ((int)(coff[14]) << 16) | ((int)(coff[13]) << 8) | coff[12]);
    unsigned int opt_header_size = (((int)(coff[17]) << 8) | coff[16]);
    unsigned int characteristics = (((int)(coff[19]) << 8) | coff[18]);

    printf("Machine: %X\n", machine_type);
    printf("NumberOfSections: %X\n", num_sections);
    printf("TimeDateStamp: %u\n", time_date_stamp);
    printf("PointerToSymbolTable: %u\n", symbol_pointer); // should be 0 because COFF debugging information is deprecated
    printf("NumberOfSymbols: %u\n", num_symbols);         // should be 0 because COFF debugging information is deprecated
    printf("SizeOfOptionalHeader: %u\n", opt_header_size);
    printf("Executable: %s\n", characteristics & IMAGE_FILE_EXECUTABLE_IMAGE ? "yes" : "no");
    printf("DLL: %s\n", characteristics & IMAGE_FILE_DLL ? "yes" : "no");

    printf("finished reading PE file\n");
    printf("closing PE file\n");
    fclose(pe_file);

    return 1;
}
