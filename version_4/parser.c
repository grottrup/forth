#include "parser.h"

bool is_number(const char* str) {
    int i;
    char c;

    // atoi tries to convert the string to an int. If it fails, it returns 0
    i = atoi(str);

    if (i != 0)
        return true;
    else {
        // The string might be one or more zeroes, e.g. "0" or "0000000", or it's an invalid int. Return false if any char is not a '0'.
        c = str[0];
        for (size_t j = 1; c != 0; j++) {
            if (c != '0')
                return false;
            c = str[0];
        }
        return true;
    }
}

bool is_command(const char* str, sys_dict_entry* sys_dict) {
    return sys_dict_entry_exists(str, sys_dict);  
}

bool is_user_word(const char* str, user_dict_entry* user_dict) {
    return user_dict_entry_exists(str, user_dict);
}

void parse(const char* input, stack* num_stack, sys_dict_entry* sys_dict, user_dict_entry* user_dict) {
    /*  for each word in input:
            if word is_number:
                push number to stack
            if word is_command:
                run command
            if word is_user_word:
                parse word entry in user dictionary
    */
   
   char* str;  // The remainder of the input string
   char* word; // THe current word in the loop

   str = strdup(input); 
   //strsep(&str, " ") returns the part of the string before the first space, and removes it from the original string. Returns NULL if no spaces found
   while ( (word = strsep(&str, " ")) != NULL )
   {
        if ((*word == 0)) {
            // This happens if there's a double space or a trailing space. 
        } 
        else if (is_number(word)) {
            push(num_stack, atoi(word));
        }
        else if (is_command(word, sys_dict)) {
            sys_dict_execute(word, sys_dict, num_stack);
        }
        else if (is_user_word(word, user_dict)) {
            parse(user_dict_get_entry(word, user_dict), num_stack, sys_dict, user_dict);
        }
   }
}