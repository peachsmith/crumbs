#include "crumbs_impl.h"
#include "input.h"

void second_input_handler(cr_context* ctx, void* target)
{
    if (cr_consume_input(ctx, CR_KEYBOARD, CR_KEY_A))
    {
        printf("This is the second input handler.\n");
    }

    if (cr_consume_input(ctx, CR_KEYBOARD, CR_KEY_ESCAPE))
    {
        printf("Popping the second input handler off the stack.\n");
        jep_node* n = jep_pop_node(ctx->input_handlers);
        cr_destroy_input_handler((input_handler*)(n->data));
        free(n);
    }
}

/**
 * An example implementation of a root input handler.
 */
void root_input_handler(cr_context* ctx, void* target)
{
    if (cr_consume_input(ctx, CR_KEYBOARD, CR_KEY_LEFT))
    {
        printf("left was pressed\n");
    }

    if (cr_peek_input(ctx, CR_KEYBOARD, CR_KEY_RIGHT))
    {
        printf("right is pressed\n");
    }

    if (cr_consume_input(ctx, CR_KEYBOARD, CR_KEY_A))
    {
        printf("This is the root input handler\n");
    }

    if (cr_consume_input(ctx, CR_KEYBOARD, CR_KEY_S))
    {
        printf("Pushing the second input handler onto the stack.\n");
        input_handler* ih = cr_create_input_handler(second_input_handler);
        jep_node* n = jep_create_node((void*)ih);
        jep_push_node(ctx->input_handlers, n);
    }

    if (cr_consume_input(ctx, CR_KEYBOARD, CR_KEY_ESCAPE))
    {
        ctx->done = 1;
    }
}

/**
 * Example implementation of the cr_configure_context function.
 */
void cr_configure_context(cr_context* ctx)
{
    input_handler* root = cr_create_input_handler(root_input_handler);
    jep_node* col = jep_create_node((void*)root);

    ctx->input_handlers = col;
}
