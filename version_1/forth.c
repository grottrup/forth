/// @version 1.0
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h> //atoi
#include "stack.h"

 #define EXIT 'q'

/**
 * @brief 
 * 
 * 
 */
 typedef struct build_in_word{
     char operator; // which operator to execute
     int(*get_result)(int*); // use an array of arguments to execute the operator on
     int para_count; // how many arguments does the operator take
 }build_in_word;










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

void calculate(stack *s, char operator, build_in_word* w, int len)
{
    int result;
    for(int i = 0; i<len; i++)
    {
        // which command to execute
        if(w[i].operator == operator)
        {
            int* arr = calloc(w[i].para_count, sizeof(int));
            // extract parameters
            for (int j = 0; j < w[i].para_count; j++)
            {
                arr[j] = pop(s);
            }
            result = w[i].get_result(arr);
        }
    }
    push(s, result);
}

int add(int* arr){
    return arr[0]+arr[1];
}
int minus(int x, int y){
    return x-y;
}
int mult(int x, int y){
    return x*y;
}
int divide(int x, int y){
    return x/y;
}

int uniminus(int x){
    return -x;
}

int main(void)
{
    printf("Welcome to forth🍀\n");
    stack _stack = initialize_stack(); // rewrite to just be a top node that represents the stack
    char *_input;
    bool should_continue;

    build_in_word w[4] = {{'+', add, 2}, {'-', minus, 2},{'*', mult, 2}, {'/', divide,2}, {'~', uniminus, 1} };

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