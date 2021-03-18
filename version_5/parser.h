#ifndef _PARSE_H_
#define _PARSE_H_

#include <stdbool.h> //Bools
#include <stdlib.h>  // atoi
#include <string.h>  // strdup, strsep
#include "dict.h"
#include "stack.h"
#include "sentence.h"

void parse(word_node* input, stack* num_stack, sys_dict* sys_dict, user_dict* user_dict); // Parse forth input, whitespace seperated list of words

#endif