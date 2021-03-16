#ifndef _SENTENCE_AS_LINKED_LIST_
#define _SENTENCE_AS_LINKED_LIST_

#include <string.h>  // strdup, strsep
#include <stdlib.h>
#include "command.h"

word_node* break_string_into_tokens(const char* src); // Turn a string with whitespace into a linked list of words. When calling, saveptr should be NULL; it's used for recursive calls.
void destroy_sentence(word_node* list); // Remove and free all nodes in a list
word_node* last_node(word_node* list); // Returns the last non-NULL pointer in the list

word_node* find_in_sentence(const char* search_term, word_node* list); // Returns a pointer to the node of the first occurrance. Null if no match.
void print_list(word_node* list);
#endif