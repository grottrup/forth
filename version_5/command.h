#ifndef _COMMAND_H_
#define _COMMAND_H_
#include "stack.h"
typedef struct command
{
    const char* keyword;
    void (*execute)(stack*);
} command;

/* @summary
    A linked list of words
    It contains
        - word : a string with no whitespace
        - next_word : a pointer to the next word in the list
*/
typedef struct word_node
{
    const char* word;
    struct word_node* next_word;
} word_node;

typedef struct user_command
{
    const char* keyword;
    word_node* definition;
} user_command;

#endif // !_COMMAND_H_