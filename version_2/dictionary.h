#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_

#include "stack.h"
#include <stdbool.h>

typedef struct command
{
    char* word;
    void (*execute)(stack*);
} command;

typedef struct dictionary
{
    command(*command);
    int length;
} dictionary;

dictionary* initialize_built_in_dict(void);

#endif