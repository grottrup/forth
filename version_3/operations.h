#ifndef _OPERATIONS_H_
#define _OPERATIONS_H_
#include "stack.h"

/* Arithmetics */
void Add(stack* s);
void Minus(stack* s);
void Mult(stack* s);
void Divide(stack* s);

/* Output */
void Emit(stack* s);
void CR(stack* s);
void Dot(stack* s);
void Qmark(stack* s);

/* Data Stack */
void Dup(stack* s);
void Drop(stack* s);
void Swap(stack* s);
void Over(stack* s);
void Rot(stack* s);

#endif
