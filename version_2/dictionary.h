#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_

#include <stdbool.h>
#include "stack.h"
#include <stdlib.h> //atoi

 typedef struct word{
     char* operator; // which operator to execute
     int(*get_result)(int*); // use an array of arguments to execute the operator on
     int operator_args; // how many arguments does the operator take
     bool should_push;
 }word;

typedef struct dictionary
{
    word (* word);
    int length;
} dictionary;

dictionary* initialize_built_in_dict(void);
void execute_command(stack *s, word* w);

#endif