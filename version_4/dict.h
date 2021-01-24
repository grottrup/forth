#ifndef _DICT_H_
#define _DICT_H_

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "operations.h"

/* @summary
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

user_dict_entry* user_dict_initialize(void);
/* The user makes their own word in the RIPL etc*/
void user_dict_assign(const char* name, const char* body, user_dict_entry* dict);
void user_dict_unassign(const char* name, user_dict_entry* dict);
bool user_dict_entry_exists(const char* name, user_dict_entry* dict);
const char* user_dict_get_entry(const char* name, user_dict_entry* dict);

/* @summary
    The dictionary of the Forth language defined words. This version uses a linked structure. (Personally I think this is a violation of "seperation by concern", so I think we should later update this implementation)
    
    It contains
        - name : a string specifing the defined word
        - (*execute) : a function to execute the defined operator for the word
*/
typedef struct sys_dict_entry
{
    const char* name; 
    void (*execute)(stack*);
    struct sys_dict_entry* next_entry;
} sys_dict_entry;

sys_dict_entry* sys_dict_initialize(void);
void sys_dict_execute(const char* name, sys_dict_entry* dict, stack* s);
bool sys_dict_entry_exists(const char* name, sys_dict_entry* dict);


#endif
