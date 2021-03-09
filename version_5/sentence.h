#ifndef _SENTENCE_AS_LINKED_LIST_
#define _SENTENCE_AS_LINKED_LIST_

#include <string.h>  // strdup, strsep
#include <stdlib.h>

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

word_node* string_to_sentence(const char* src, char* saveptr); // Turn a string with whitespace into a linked list of words. When calling, saveptr should be NULL; it's used for recursive calls.
void destroy_sentence(word_node* list); // Remove and free all nodes in a list
word_node* last_node(word_node* list); // Returns the last non-NULL pointer in the list

word_node* find_in_sentence(const char* search_term, word_node* list); // Returns a pointer to the node of the first occurrance. Null if no match.

#endif