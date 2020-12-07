#include "operations.h"

void add(stack* s){
    int b = pop(s);
    int a = pop(s);
    push(s,a+b);
}

void minus(stack* s){
    int b = pop(s);
    int a = pop(s);
    push(s,a-b);
}

void mult(stack* s){
    int b = pop(s);
    int a = pop(s);
    push(s,a*b);
}

void divide(stack* s){
    int b = pop(s);
    int a = pop(s);
    push(s,a/b);
}

// int uniminus(int* arr){
//     return -arr[0];
// }

// int emit(int* arr)
// {
//     return 0;
// }

// int dot(stack* s)
// {
//     return 0;
// }

// int cr(int* arr)
// {
//     return 0;
// }

// int qmark(int* arr)
// {
//     return 0;
// }