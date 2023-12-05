#include "penut.h"

int main()
{
    if (!cr_initialize())
    {
        return 1;
    }

    float scale = 1;
    cr_config config = {
        .scale = scale,
        .scale_mode = CR_SCALE_FIXED,
        .title = "PEnut",
        .window_width = 640,
        .window_height = 480};

    cr_configure(&config);

    cr_app *app = cr_create_app();
    if (app == NULL)
    {
        cr_terminate();
        return 1;
    }

    if (!penut_init_app(app))
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