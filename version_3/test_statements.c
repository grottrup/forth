#include "dictionary.h"
#include "statements.h"
#include "test_project.h"
#include <stdlib.h> //atoi

void Comparisons(void)
{
    {
        stack s = initialize_stack(); // whoops not so unifor implementation
        push(&s, 1);
        push(&s, 1);
        command w = (command){"=", Equals};
        w.execute(&s);
        assert(pop(&s) == -1 );
    }
}

void Logic(void)
{
    {
        stack s = initialize_stack(); // whoops not so unifor implementation
        push(&s, 1);
        push(&s, 1);
        command w = (command){"=", And};
        w.execute(&s);
        assert(pop(&s) == -1 );
    }
}

bool test_statements(void)
{
    Comparisons();
    Logic();
    return true;
}