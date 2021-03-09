#ifndef _DICT_H_
#define _DICT_H_

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "operations.h"
#include "command.h"

/* @summary
    The dictionary of user defined words, implemented as a linked list.
    It contains
        - keyword : a string specifing the userdefined word
        - definition : a string of space seperated words to be parsed when called
*/
typedef struct user_dict
{
    user_command entry;
    struct user_dict* next;
} user_dict;

user_dict* user_dict_initialize(void);
/* The user makes their own word in the RIPL etc*/
void user_dict_assign(const char* keyword,word_node* definition, user_dict* dict);
void user_dict_unassign(const char* keyword, user_dict* dict);
bool user_dict_entry_exists(const char* keyword, user_dict* dict);
word_node* user_dict_get_entry(const char* keyword, user_dict* dict);

/* @summary
    The dictionary of the Forth language defined words. This version uses a linked structure. (Personally I think this is a violation of "seperation by concern", so I think we should later update this implementation)
    
    It contains
        - keyword : a string specifing the defined word
        - (*execute) : a function to execute the defined operator for the word
*/
typedef struct sys_dict
{
    command entry;
    struct sys_dict* next;
} sys_dict;

sys_dict* sys_dict_initialize(void);
void sys_dict_execute(const char* keyword, sys_dict* dict, stack* s);
bool sys_dict_entry_exists(const char* keyword, sys_dict* dict);


#endif
