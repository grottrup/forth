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
    assert(b != 0); // could possibly be handled later with our own error messages
    int a = pop(s);
    push(s,a/b);
}

void Emit(stack* s){
    int a = pop(s); // the con... too much work
    printf("%d", a);
    push(s,a);
    // another option: extend the stack to have a read head fucntion
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

void Over(stack* s)
{
    // 1 2 3 -> 1 2 3 2
    // - a b -> - a b a
    
}

void Rot(stack* s)
{
    // 1 2 3 -> 2 3 1
    // a b c -> b c a
    int c = pop(s); //3
    int b = pop(s); //2
    int a = pop(s); //1
    push(s,b);
    push(s,c); 
    push(s,a);
}

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




// int uniminus(int* arr){
//     return -arr[0];
// }

