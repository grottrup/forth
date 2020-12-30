#include <assert.h>
#include "statements.h"

void Equals (stack* s) {
    int b = pop(s);
    int a = pop(s);

    int ret = (a == b) ? -1 : 0;
    push(s, ret);

    // Alternatives:
    //
    // if(a == b) 
    //     push(s, -1);
    // else
    //     push(s, 0);
    //
    // (a == b)? push(s, -1) : push(s, 0);
    //
    // push(s, (a == b) * -1)
}

void LessThan (stack* s);
void GreaterThan (stack* s);

void And(stack* s)
{
    int b = pop(s);
    assert(b == -1 || b == 0);
    int a = pop(s);
    assert(a == -1 || a == 0);
    if (a == -1 && b == -1)
         push(s, -1);
    else 
        push(s, 0);
}

void Or(stack* s);

void Not(stack* s)
{
    int a = pop(s);
    assert(a == -1 || a == 0);
    if (a == -1)
         push(s, 0);
    else 
        push(s, -1);
}

void If(stack* s)
{

}

void Else(stack* s);
void Then(stack* s);