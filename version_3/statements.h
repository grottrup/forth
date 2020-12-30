#ifndef _STATEMENTS_H_
#define _STATEMENTS_H_
#include "stack.h"

void And(stack* s);
void Or(stack* s);
void Not(stack* s);

void If(stack* s);
void Else(stack* s);
void Then(stack* s);

void Equals(stack* s);
void LessThan(stack* s);
void GreaterThan(stack* s);

#endif
