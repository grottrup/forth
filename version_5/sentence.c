#include "sentence.h"
#include <stdio.h>

// Creates a node
word_node* new_node(const char* word, word_node* next) {
    word_node* node = malloc(sizeof(word_node));
    node->word = word;
    node->next_word = next;
    return node;
}

// Turn a string with whitespace into a linked list of words. When calling, saveptr should be NULL; it's used for recursive calls.
word_node* string_to_sentence(const char* src, char* saveptr) {
    char* src_cpy = malloc(strlen(src));
    strcpy(src_cpy, src);
    word_node* node;
    char* token;

    if (saveptr == NULL)
        token = strtok_r(src_cpy, " ", &saveptr);
    else
        token = strtok_r(NULL, " ", &saveptr);


    if (token == NULL) {
        node = NULL;
    } else {
        // token is the same as src_copy, so it also has allocated memory for 
        // the full lenght of the source string. 
        // This allocates only the space needed for the token.
        char* token_copy = malloc(strlen(token));
        strcpy(token_copy, token);

        // Make a node with the token, and make the next pointer using recursion.
        node = new_node(
            token_copy,
            string_to_sentence(src_cpy, saveptr)
        );
    }

    free(src_cpy);
    return node;
}

// Remove and free all nodes in a list
void destroy_sentence(word_node* list) {
    if (list == NULL) {
        // Shouldn't happen, but adding this case, just to be safe.
        return;
    } else if (list->next_word == NULL) {
        // Free the neccessary values in the struct
        free((void*) list->word);
    } else {
        // Recursively free the list
        destroy_sentence(list->next_word);
        free(list->next_word);
    }
}

// Returns the last non-NULL pointer in the list
word_node* last_node(word_node* list) {
    if (list == NULL) {
        // Shouldn't happen, but adding this case, just to be safe.
        return NULL;
    } else if (list->next_word == NULL) {
        return list;
    } else {
        return last_node(list->next_word);
    }
}


// Returns a pointer to the node of the first occurrance. Null if no match.
word_node* find_in_sentence(const char* search_term, word_node* list) {
    if (list == NULL) {
        return NULL;
    } else if (strcmp(list->word, search_term) == 0) {
        return list;
    } else {
        return find_in_sentence(search_term, list->next_word);
    }
}

void print_list(word_node* list) {
    if (list != NULL) {
        printf("%s\n", list->word);
        print_list(list->next_word);
    }
}
