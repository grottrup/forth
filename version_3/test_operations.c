#include "dictionary.h"
#include "operations.h"
#include "test_project.h"
#include <stdlib.h> //atoi

void test_arithmetics(void) // white box
{
    {
        stack s = initialize_stack(); // whoops not so unifor implementation
        push(&s, 1);
        push(&s, 2);
        command w = (command){"+", Add};
        w.execute(&s);
        assert(pop(&s) == 3 );
        assert(stack_is_empty(&s));
        // free stack
    }
    {
        stack s = initialize_stack(); // whoops not so unifor implementation
        push(&s, 10);
        push(&s, 2);
        command w = (command){"/", Divide};
        w.execute(&s);
        assert(pop(&s) == 5 );
        assert(stack_is_empty(&s));
        // free stack
    }
}

bool test_operations(void)
{
    test_arithmetics();
    return true;
}