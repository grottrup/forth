#include "sentence.h"
#include <stdio.h>

word_node* word_node_ctor(const char* word, word_node* next)
{
    word_node* node = malloc(sizeof(word_node));
    node->word = word;
    node->next_word = next;
    return node;
}

word_node* _break_string_into_tokens(char* src_cpy, char* saveptr, char* token)
{
    word_node* node = NULL;
    char* dest_token = (char *)malloc(64); // malloc(strlen(token));
    if(token != NULL) 
    {
        strcpy(dest_token, token); // This allocates only the space needed for the token.
        token = strtok_r(NULL, " ", &saveptr); // TODO: token causes "degeneration"
        if (token == NULL) return node;
        word_node* next = _break_string_into_tokens(src_cpy, saveptr, token);
        node = word_node_ctor(dest_token, next);
    }
    return node;
}

/**
 * @brief
 * Turn a string with whitespace into a linked list of words.
 * @param src original string
 * @return word_node* a word/token with a link to the next word
 */
word_node* break_string_into_tokens(char* src)
{
    word_node* tokens = NULL;
    char* dest = (char *)malloc(3000); //malloc(strlen(src)); //+1
    if(dest)
    {
        strcpy(dest, src);
        char* saveptr;
        char* token = strtok_r(dest, " ", &saveptr);
        tokens = _break_string_into_tokens(dest, saveptr, token);
        free(dest);
    }
    return tokens;
}

// Remove and free all nodes in a list
void destroy_sentence(word_node* list)
{
    if (list == NULL)
    {
        // Shouldn't happen, but adding this case, just to be safe.
        return;
    }
    else if (list->next_word == NULL)
    {
        // Free the neccessary values in the struct
        free((void*)list->word);
    }
    else
    {
        // Recursively free the list
        destroy_sentence(list->next_word);
        free(list->next_word);
    }
}

// Returns the last non-NULL pointer in the list
word_node* last_node(word_node* list)
{ //! might not be needed
    if (list == NULL)
    {
        // Shouldn't happen, but adding this case, just to be safe.
        return NULL;
    }
    else if (list->next_word == NULL)
    {
        return list;
    }
    else
    {
        return last_node(list->next_word);
    }
}

//! useful for if else then.... stop at else and parse till then
// Returns a pointer to the node of the first occurrance. Null if no match.
word_node* find_in_sentence(const char* search_term, word_node* list)
{
    if (list == NULL)
    {
        return NULL;
    }
    else if (strcmp(list->word, search_term) == 0)
    {
        return list;
    }
    else
    {
        return find_in_sentence(search_term, list->next_word);
    }
}

void print_list(word_node* list)
{
    if (list != NULL)
    {
        printf("%s\n", list->word);
        print_list(list->next_word);
    }
}
