#include <stdbool.h>
#include <stdio.h>

/// @version 0.0
/// next version should use structs and calloc

#define STACK_SIZE 4
#define PLUS '+'

int main(void)
{ 
    int stack[STACK_SIZE] = {0};
    int x;
    int i;
    bool should_continue;

    should_continue = true;
    x = 0; 
    i = 0;
    while (should_continue && i < STACK_SIZE)
    {
        scanf("%d", &x);
        stack[i] = x;
        if(x<0)
        {
            should_continue = false;
        }
        i++;
    }
    return 0;
}