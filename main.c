#include <stdio.h>

#include "crumbs.h"

int main(int argc, char** argv)
{
    // Initialize the framework.
    if (!cr_initialize())
    {
        fprintf(stderr, "failed to initialize crumbs\n");
        return 1;
    }

    // Create the application context.
    cr_context* ctx = cr_create_context();
    if (!ctx)
    {
        fprintf(stderr, "failed to create crumbs context\n");
        cr_terminate();
        return 1;
    }

    printf("entering main loop\n");

    // main loop
    while (!cr_is_done(ctx))
    {
        cr_begin_frame(ctx);
        cr_handle_events(ctx);
        cr_handle_input(ctx);
        cr_update(ctx);
        cr_render(ctx);
        cr_end_frame(ctx);
    }

    printf("done with main loop\n");

    // Dispose of the context and its resources.
    cr_destroy_context(ctx);

    // Terminate the framework.
    cr_terminate();

    return 0;
}
