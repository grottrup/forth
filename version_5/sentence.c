#include "sentence.h"
#include <stdio.h>

word_node* word_node_ctor(const char* word, word_node* next)
{
    word_node* node = malloc(sizeof(word_node));
    node->word = word;
    node->next_word = next;
    return node;
}

word_node* _break_string_into_tokens(const char* src_cpy, char* saveptr)
{
    word_node* node;
    char* token;

    if (saveptr == NULL) // does this only happens the first time?
        token = strtok_r(src_cpy, " ", &saveptr);
    else
        token = strtok_r(NULL, " ", &saveptr);

    if (token == NULL)
    {
        node = NULL; //! base case: no more words.. add tail to list
    }
    else
    {
        // token is the same as src_copy, so it also has allocated memory for
        // the full lenght of the source string.
        // This allocates only the space needed for the token.
        char* token_copy = malloc(strlen(token));
        strcpy(token_copy, token);

        // Make a node with the token, and make the next pointer using recursion.
        node = word_node_ctor(token_copy, _break_string_into_tokens(src_cpy, saveptr));
    }

    return node;
}

/**
 * @brief
 * Turn a string with whitespace into a linked list of words.
 * @param src original string
 * @return word_node* a word/token with a link to the next word
 */
word_node* break_string_into_tokens(const char* src)
{
    char* src_cpy = malloc(strlen(src));
    strcpy(src_cpy, src);
    word_node* tokens = _break_string_into_tokens(src, NULL);
    free(src_cpy);
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
