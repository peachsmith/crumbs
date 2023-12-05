#include "input.h"

void penut_root_input(cr_app *app)
{
    if (cr_consume_input(app, CR_KEYCODE_ESCAPE))
    {
        app->done = 1;
    }
}