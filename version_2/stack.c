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

/**
 * @brief 
 * @return stack 
 */
stack initialize_stack(void)
{
  stack s = {malloc(sizeof(stack))};
  s.top-> link_below = NULL; // or sentinal
  return NULL; //rewrite
}

/**
 * @brief Push a value to the top of the stack
 * @param x 
 * @param s 
 */
void push(stack* s, int x)
{
    node* next_top = malloc(sizeof(node));
    next_top->item = x;
    next_top->link_below = s->top;
    s->top = next_top;
}

/**
 * @brief Pop the top stack element and clean the heap
 * @param s 
 * @return int 
 */
int pop(stack* s)
{
    assert(!stack_is_empty(s));
    int result = s->top->item;
    node* temp = s->top;
    s->top = s->top->link_below;
    free(temp);
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
    if (s->top-> link_below == NULL)
    {
        return true;
    }
    return false;
}

/**
 * @brief Prints tail of the node, then the node itself, resulting in the bottom to the left
 * @param n
 */
void print_node(node* n) {
    node* next = n->link_below;
    
    if (next != NULL) {
        print_node(next);
        
        int value = n->item;
        printf("%d ", value);
    }
}

// https://1scyem2bunjw1ghzsf1cjwwn-wpengine.netdna-ssl.com/wp-content/uploads/2018/01/Starting-FORTH.pdf

/**
 * @brief Prints the stack with the top as the first element
 * @param s 
 */
void print_stack(stack* s) {
    node* current_node = s->top;

    if (current_node == NULL) {
        printf("Stack empty\n");
        return;
    }
    printf("Stack: ");
    /* while (current_node->link_below != NULL) {
        int value = current_node->item;
        printf("%d ", value);
        current_node = current_node->link_below;
    } */
    print_node(current_node);
    printf("<- Top\n");
}

// the 
