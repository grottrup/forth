#include "stack.h"
#include "test_project.h"

bool test_stack(void)
{
    stack* s = construct_stack();
    assert(stack_is_empty(s));
    
    int x = 5;
    push(s, x);
    assert(!stack_is_empty(s));
    int y = pop(s);
    assert(stack_is_empty(s));
    assert(x == y);

    int x0 = 7;
    int x1 = 9;
    push(s, x0);
    push(s, x1);

    int y0 = pop(s);
    int y1 = pop(s);
    assert(stack_is_empty(s));
    assert(x0 == y1);
    assert(x1 == y0);
    free_stack(s);
    printf("🔥\n");
    return true;
}

int main(void)
{
    test_stack();
    return 0;
}