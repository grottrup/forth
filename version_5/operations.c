#include <assert.h>
#include "operations.h"
#include "parser.h" // possibly seperate dependents into a seperate file

// Arithmetics
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

// Output
void Emit(stack* s){
    // print the char with the ASCII value of the top item in the stack
    int a = pop(s); // the con... too much work
    printf("%c", a);
    // another option: extend the stack to have a read head fucntion
}

void CR(stack* s) {
    // Carriage return
    printf("\n");
}

void Dot(stack* s) {
    // Print the number from the top of the stack
    int a = pop(s);
    printf("%d", a);
}

void Qmark(stack* s) {
    // Print string. e.g. (lines with '>' is user input)
    //    > : say-hello ."Hello World!" ;
    //    > say-hello
    //    Hello World!

    // User defined words likely has to be implemented first.
}


// Stack manipulation
void Dup(stack* s) {
    // Duplicate the top item in the stack
    int a = pop(s);
    push(s,a);
    push(s,a);
}

void Drop(stack* s)
{
    // Pop the stack with no output
    pop(s);
}

void Swap(stack* s)
{
    // x 1 2 -> 2 1
    // - a b -> b a 
    int b = pop(s);
    int a = pop(s);
    push(s,b);
    push(s,a);
}

void Over(stack* s)
{
    // 1 2 3 -> 1 2 3 2
    // - a b -> - a b a
    int b = pop(s);
    int a = pop(s);
    push(s,a);
    push(s,b);
    push(s,a);
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


// Comparisons

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

void LessThan (stack* s) {
    int b = pop(s);
    int a = pop(s);
    push(s, a < b ? -1: 0);
}

void GreaterThan (stack* s) {
    int b = pop(s);
    int a = pop(s);
    push(s, a > b ? -1: 0);
}

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

void Or(stack* s) {
    int b = pop(s);
    int a = pop(s);
    push(s, a == -1 || b == -1 ? -1: 0);
}

void Not(stack* s)
{
    int a = pop(s);
    assert(a == -1 || a == 0);
    if (a == -1)
         push(s, 0);
    else 
        push(s, -1);
}


// Conditionals

void If(stack* s, char* body)
{
    // : TEST  IF ." NON-ZERO " ELSE ." ZERO " THEN ;
    //      TEST            -- WORD
    //      ." NON-ZERO "   -- TRUE STRING
    //      ." ZERO "       -- FALSE STRING
    //
    //      body should contain
    //           ." NON-ZERO " ELSE ." ZERO " THEN ;
    // If false, parse from ELSE to THEN
    // If true, parse from IF to ELSE

    // char* true_body;
    // char* false_body;

    // true_body = strsep(&body, "ELSE");
    // false_body = strsep(&body, "THEN");
    
    // int a = pop(s);
    
    // if (a == 0) {
    //     body = return_str;
    // } else {
    //     body = return_str;
    // }
}

void Else(stack* s);
void Then(stack* s);




// int uniminus(int* arr){
//     return -arr[0];
// }

