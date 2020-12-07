#include "operations.h"

void Add(stack* s){
    int b = pop(s);
    int a = pop(s);
    push(s,a+b);
}

void Minus(stack* s){
    int b = pop(s);
    int a = pop(s);
    push(s,a-b);
}

void Mult(stack* s){
    int b = pop(s);
    int a = pop(s);
    push(s,a*b);
}

void Divide(stack* s){
    int b = pop(s);
    int a = pop(s);
    push(s,a/b);
}

void Emit(stack* s){

}

void CR(stack* s);

void Dot(stack* s) {
    int a = pop(s);
    printf("%d", a);
}

void Qmark(stack* s);
void Dup(stack* s);

void Drop(stack* s)
{
    pop(s);
}
void Swap(stack* s)
{
    int b = pop(s);
    int a = pop(s);
    push(s,b);
    push(s,a);
}

void Over(stack* s);
void Rot(stack* s);
void And(stack* s);
void Or(stack* s);
void Not(stack* s);
void If(stack* s);
void Else(stack* s);
void Then(stack* s);




// int uniminus(int* arr){
//     return -arr[0];
// }

