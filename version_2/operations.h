#ifndef _OPERATIONS_H_
#define _OPERATIONS_H_
#include "stack.h"

void Add(stack* s);
void Minus(stack* s);
void Mult(stack* s);
void Divide(stack* s);
void uniminus(stack* s);
void Emit(stack* s);
void CR(stack* s);
void Dot(stack* s);
void Qmark(stack* s);
void Dup(stack* s);
void Drop(stack* s);
void Swap(stack* s);
void Over(stack* s);
void Rot(stack* s);
void And(stack* s);
void Or(stack* s);
void Not(stack* s);
void If(stack* s);
void Else(stack* s);
void Then(stack* s);

#endif