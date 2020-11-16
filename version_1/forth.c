/// @version 1.0
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h> //atoi
#include "stack.h"

 #define EXIT 'q'

//! At the meeting get tips to:
//  * Good ways to refactor in C dealing with ASCII in an elegant way
//  * Using libraries in big projects
// VS Code C extentions screenshot. list of issues to figure out debugging across multiple files
bool is_number(char *x)
{
    //-1 dealing with negative numbers as well
    //look at every character
    //for loop dealing with a string of digits
    if (x[0] >= '0' && x[0] <= '9')
    {
        return true;
    }
    return false;
}

bool is_operator(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
    {
        return true;
    }
    return false;
}

void calculate(stack *s, char operator)
{
    int a, b, result;// 
    a = pop(s);
    b = pop(s);
    switch (operator)
    {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a * b;
        break;
    case '/':
        result = a / b;
        break;
    default:
        break;
    }
    push(s, result);
}

int main(void)
{
    printf("Welcome to forth🍀\n");
    stack _stack = initialize_stack(); // rewrite to just be a top node that represents the stack
    char *_input;
    bool should_continue;

    should_continue = true;
    while (should_continue)
    {
        scanf("%s", _input);
        if (is_number(_input))
        {
            push(&_stack, atoi(_input));
        }
        else
        {
            char symbol = _input[0];
            if (is_operator(symbol))
            {
                calculate(&_stack, symbol);
            }
            else
            {
                if (symbol == EXIT)
                {
                    should_continue = false;
                }
            }
        }
        print_stack(&_stack);
    }
    return 0;
}