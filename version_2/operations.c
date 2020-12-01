#include "operations.h"

void add(stack* s){
    int a = pop(s);
    int b = pop(s);
    push(s,a+b);
}

void minus(stack* s){
    int a = pop(s);
    int b = pop(s);
    push(s,a-b);
}

// int mult(int* arr){
//     return arr[1]*arr[0];
// }
// int divide(int* arr){
//     return arr[1]/arr[0];
// }
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