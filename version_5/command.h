#ifndef _COMMAND_H_
#define _COMMAND_H_
#include "stack.h"

typedef struct command
{
    const char* keyword;
    void (*execute)(stack*);
} command;

#endif // !_COMMAND_H_