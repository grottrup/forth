#include "dictionary.h"
#include "operations.h"
#include "test_project.h"
#include <stdlib.h> //atoi

void test_arithmetics(void)
{
    {
        stack s = init_stack();
        push(&s, 1);
        push(&s, 2);
        command w = (command){"+", Add};
        w.execute(&s);
        assert(pop(&s) == 3 );
        assert(stack_is_empty(&s));
        free_stack(&s);
    }    
    {
        stack s = init_stack();
        push(&s, 2);
        push(&s, 2);
        command w = (command){"-", Minus};
        w.execute(&s);
        assert(pop(&s) == 0 );
        assert(stack_is_empty(&s));
        free_stack(&s);
    }    
    {
        stack s = init_stack(); 
        push(&s, 2);
        push(&s, 2);
        command w = (command){"*", Mult};
        w.execute(&s);
        assert(pop(&s) == 4 );
        assert(stack_is_empty(&s));
        free_stack(&s);
    }
    {
        stack s = init_stack();
        push(&s, 10);
        push(&s, 2);
        command w = (command){"/", Divide};
        w.execute(&s);
        assert(pop(&s) == 5 );
        assert(stack_is_empty(&s));
        free_stack(&s);
    }
}

void test_output(void)
{
    /* We cannot test what it prints in the commandline, but we can test the changes that are made to the stack */
    {
        stack s = init_stack();
        push(&s, 42);
        assert(!stack_is_empty(&s));
        command w = (command){".", Dot};
        w.execute(&s);
        assert(stack_is_empty(&s));
        free_stack(&s);
    }
}
//void Emit(stack* s);
//void CR(stack* s);
//void Dot(stack* s);
//void Qmark(stack* s);

/* Data Stack */
//void Dup(stack* s);
//void Drop(stack* s);
//void Swap(stack* s);
//void Over(stack* s);
//void Rot(stack* s);

bool test_operations(void)
{
    test_arithmetics();
    return true;
}
