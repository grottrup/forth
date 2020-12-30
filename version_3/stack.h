#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h> 
#include <stdbool.h> 

typedef struct node
{
  struct node*  link_below;
  int  item;
} node;

typedef struct stack
{
  node*  top;
} stack;

void init_stack(stack* s);
void push(stack* s, int x);
int pop(stack* s);
bool stack_is_empty(stack* s);
void free_stack(stack* s);
void print_stack(stack* s);

#endif