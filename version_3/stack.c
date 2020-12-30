/// @file stack.c
/// @author Simon
/// @date 2020-10-17
///
/// (2) (PC-2.1.1) Stacks are containers where items are retrieved according
/// to the order of insertion, independent of content. Stacks maintain last-in, first-out
/// order (LIFO). The abstract operations on a stack include:
///
/// @li @c Push(x,s) - Insert item x at the top of stack @c s
/// @li @c Pop(s) – Return (and remove) the top item of stack @c s.
/// @li @c Initialize(s) – Create an empty stack.
/// @li @c Empty(s) – Test whether the stack can accept more pushes or pops, respectively.
/// Note that there is no element search operation defined on standard stacks and queues.
/// Stacks naturally model piles of objects, such as dinner plates. After a new plate is
/// washed, it is pushed on the top of the stack. When someone is hungry, a clean plate
/// is popped off the top.
/// *Remark: Stack order is important in processing any properly nested structure. This*
/// *includes parenthesised formulas (push on a “(”, pop on “)”), recursive program*
/// *calls (push on a procedure entry, pop on a procedure exit and depth-first traversals of graphs*
/// *(push on discovering a vertex, pop on leaving it for the last time).*

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "stack.h"

stack* construct_stack(void)
{
    stack* s = malloc(sizeof(stack));
    s->link_below = NULL;
    s->item = 0;
    return s;
}

/**
 * @brief Push a value to the top of the stack
 * @param x 
 * @param s 
 */
void push(stack* s, int x)
{
    stack* old_top = malloc(sizeof(stack));
    old_top->link_below = s->link_below; 
    old_top->item = s->item; 
    s->item = x;
    s->link_below = old_top;
}

/**
 * @brief Pop the top stack element and clean the heap
 * @param s 
 * @return int 
 */
int pop(stack* s)
{
    assert(!stack_is_empty(s));
    int result = s->item;
    s->item = 0;
    if(!stack_is_empty(s))
    {
        s->item = s->link_below->item;
        s->link_below = s->link_below->link_below;
    }
    return result;
}

/**
 * @brief Check whether there are any elements left in the stack
 * @param s 
 * @return true 
 * @return false 
 */
bool stack_is_empty(stack* s)
{
    return s->item == 0 && s->link_below == NULL;
}