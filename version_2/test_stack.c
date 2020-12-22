#include <assert.h>
#include "stack.h"

int stack_test()
{
    stack s = initialize_stack();
    assert(stack_is_empty(&s));
    
    int x = 5;
    push(&s, x);
    int y = pop(&s);
    assert(stack_is_empty(&s));
    assert(x == y);

    int x0 = 7;
    int x1 = 9;
    push(&s, x0);
    push(&s, x1);
    print_stack(&s);

    int y0 = pop(&s);
    int y1 = pop(&s);
    assert(stack_is_empty(&s));
    assert(x0 == y1);
    assert(x1 == y0);
    printf("🔥\n");
    return 0;
}
