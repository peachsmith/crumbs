#include "draw.h"

void draw_background(cr_app *app)
{
    cr_rect r = {
        .x = 0,
        .y = 0,
        .w = app->screen_width,
        .h = app->screen_height,
    };
    cr_set_color(app, 0xFF333333);
    cr_draw_rect(app, &r, 1);
}