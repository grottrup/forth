#ifndef _DICT_H_
#define _DICT_H_

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "operations.h"

/*
    The dictionary of user defined words, implemented as a linked list.
    It contains
        - name : a string specifing the userdefined word
        - body : a string of space seperated words to be parsed when called
*/

typedef struct user_dict_entry
{
    const char* name;
    const char* body;
    struct user_dict_entry* next_entry;
} user_dict_entry;

user_dict_entry* user_dict_initialize();
void user_dict_assign(const char* name, const char* body, user_dict_entry* dict);
void user_dict_unassign(const char* name, user_dict_entry* dict);
bool user_dict_entry_exists(const char* name, user_dict_entry* dict);
const char* user_dict_get_entry(const char* name, user_dict_entry* dict);


typedef struct sys_dict_entry
{
    const char* name;
    void (*execute)(stack*);
    struct sys_dict_entry* next_entry;
} sys_dict_entry;

sys_dict_entry* sys_dict_initialize();
void sys_dict_execute(const char* name, sys_dict_entry* dict, stack* s);
bool sys_dict_entry_exists(const char* name, sys_dict_entry* dict);


#endif