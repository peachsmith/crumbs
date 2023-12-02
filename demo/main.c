#include "demo.h"

int main(int argc, char **argv)
{
    printf("crumbs version: %s\n", cr_version());

    if (!cr_initialize())
    {
        return 1;
    }

    float scale = 2;
    cr_config config = {
        .scale = scale,
        .scale_mode = CR_SCALE_ASPECT_RATIO,
        .title = "Crumbs Demo",
        .window_width = CR_DEFAULT_SCREEN_WIDTH * scale,
        .window_height = CR_DEFAULT_SCREEN_HEIGHT * scale};

    cr_configure(&config);

    cr_app *app = cr_create_app();
    if (app == NULL)
    {
        cr_terminate();
        return 1;
    }

    if (!demo_init_app(app))
    {
        cr_destroy_app(app);
        cr_terminate();
        return 1;
    }

    while (!app->done)
    {
        cr_begin_frame(app);
        app->update(app);
        app->draw(app);
        cr_end_frame(app);
    }

    cr_destroy_app(app);
    cr_terminate();

    return 0;
}
