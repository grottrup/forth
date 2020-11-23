/// @version 1.0
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h> //atoi
#include "stack.h"

#define EXIT 'q'
#define WORDS 5

/**
 * @brief 
 * 
 * 
 */
 typedef struct built_in_word{
     char operator; // which operator to execute
     int(*get_result)(int*); // use an array of arguments to execute the operator on
     int para_count; // how many arguments does the operator take
 }built_in_word;

typedef struct built_in_word_dict
{
    built_in_word* word;
    int length;
} built_in_word_dict;


int add(int* arr){
    return arr[0]+arr[1];
}
int minus(int* arr){
    return arr[0]-arr[1];
}
int mult(int* arr){
    return arr[0]*arr[1];
}
int divide(int* arr){
    return arr[0]/arr[1];
}
int uniminus(int* arr){
    return -arr[0];
}

built_in_word_dict* initialize_built_in_dict(void) {
    built_in_word_dict* dict = malloc(sizeof(built_in_word_dict));
    dict->length = WORDS;
    dict->word = calloc(WORDS, sizeof(built_in_word));
    dict->word[0] = {'+', add, 2};
    dict->word[1] = {'-', minus, 2};
    dict->word[2] = {'*', mult, 2};
    dict->word[3] = {'/', divide,2};
    dict->word[4] = {'~', uniminus, 1};

    /* Verify initialization */
    for (int i = 0; i < WORDS; i++) {
        assert(dict->word[i] != 0);
    }

    return dict;
}


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

void calculate(stack *s, char operator, built_in_word* w, int len)
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


int main(void)
{
    printf("Welcome to forth🍀\n");
    stack _stack = initialize_stack(); // rewrite to just be a top node that represents the stack
    char *_input;
    bool should_continue;

    built_in_word_dict* dict = initialize_built_in_dict();

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
                calculate(&_stack, symbol, dict->word, dict->length);
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