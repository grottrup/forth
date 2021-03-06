#include "parser.h"

//#define LOOKUP_COMPARE_FUNCTION strcmp // Case sensitive
#define LOOKUP_COMPARE_FUNCTION strcasecmp // Case insensitive

typedef enum parse_type
{
    UNKNOWN,
    NUMBER,
    COMMAND,
    USER_COMMAND,
    DEFINITION,
    UNDEFINITION,
    IF_STATEMENT,
    COMMAND_QMARK, // remember to refactor
} parse_t;

bool is_number(const char* str)
{
    int i;
    char c;

    // atoi tries to convert the string to an int. If it fails, it returns 0
    i = atoi(str);

    if (i != 0)
        return true;
    else
    {
        // The string might be one or more zeroes, e.g. "0" or "0000000", or it's an invalid int.
        // Return false if any char is not a '0'.
        c = str[0];
        for (size_t j = 1; c != 0; j++)
        {
            if (c != '0')
                return false;
            c = str[j];
        }
        return true;
    }
}

parse_t get_parse_type(const char* word, sys_dict_entry* sys_dict, user_dict_entry* user_dict)
{
    if(is_number(word))
        return NUMBER;
    else if(sys_dict_entry_exists(word, sys_dict))
        return COMMAND;
    else if(user_dict_entry_exists(word, user_dict))
        return USER_COMMAND;
    else if(LOOKUP_COMPARE_FUNCTION(word, ":") == 0)
        return DEFINITION;
    else if (LOOKUP_COMPARE_FUNCTION(word, "-:") == 0)
        return UNDEFINITION;
    else if(LOOKUP_COMPARE_FUNCTION(word, ";") == 0)
        return COMMAND_QMARK;
    else if(LOOKUP_COMPARE_FUNCTION(word, "IF") == 0)
        return IF_STATEMENT;
    else
        return UNKNOWN;
}


bool is_command(const char* str, sys_dict_entry* sys_dict)
{
    return sys_dict_entry_exists(str, sys_dict);
}

bool is_user_word(const char* str, user_dict_entry* user_dict)
{
    return user_dict_entry_exists(str, user_dict);
}

/**
 * @brief Get the body object
 * 
 * @param t 
 * @param str 
 * @return char* returns NULL if it fails
 */
char* get_body(parse_t t, const char* str)
{
    switch (t)
    {
    case IF_STATEMENT:
        return strsep(str, "THEN"); // strsep cannont use multi-char delimiter... :(
    case DEFINITION:
        return strsep(str, ";");
    case COMMAND_QMARK:
        return strsep(str, "\"");
    default:
        return NULL;
    }
}

void parse2(const char* input, stack* num_stack, sys_dict_entry* sys_dict, user_dict_entry* user_dict)
{
    char* remaining_to_read; // The remainder of the input string
    char* word;              // THe current word in the loop

    remaining_to_read = strdup(input);
    // strsep(&str, " ") returns the part of the string before the first space, and removes it from
    // the original string. Returns NULL if no spaces found
    while ((word = strsep(&remaining_to_read, " ")) != NULL)
    {
        parse_t parse_type = get_parse_type(word, sys_dict, user_dict);
        switch (parse_type)
        {
        case NUMBER:
            push(num_stack, atoi(word));
            break;
        case COMMAND:
        case USER_COMMAND:
        case UNDEFINITION:
            //do simple stuff
            break;
        case IF_STATEMENT:
        case DEFINITION:
        case COMMAND_QMARK:
            char* body = get_body(parse_type, remaining_to_read);
            if(body != NULL)
                // do some more stuff
            break;
        default:
            break;
        }
    }
}

void parse(const char* input, stack* num_stack, sys_dict_entry* sys_dict,
           user_dict_entry* user_dict)
{
    /*  for each word in input:
            if word is_number:
                push number to stack
            if word is_command:
                run command
            if word is_user_word:
                parse word entry in user dictionary
    */

    char* remaining_to_read; // The remainder of the input string
    char* word;              // THe current word in the loop

    remaining_to_read = strdup(input);
    // strsep(&str, " ") returns the part of the string before the first space, and removes it from
    // the original string. Returns NULL if no spaces found
    while ((word = strsep(&remaining_to_read, " ")) != NULL)
    {
        if ((*word == 0))
        {
            // This happens if there's a double space or a trailing space.
        }

        else if (is_number(word))
        {
            push(num_stack, atoi(word));
        }

        else if (is_command(word, sys_dict))
        {
            sys_dict_execute(word, sys_dict, num_stack);
        }
        else if (is_user_word(word, user_dict))
        {
            parse(user_dict_get_entry(word, user_dict), num_stack, sys_dict, user_dict);
        }

        else if (LOOKUP_COMPARE_FUNCTION(word, ".\"") == 0)
        {
            // Cannot use current sys dict implementation to print strings through that
            printf("%s", strsep(&remaining_to_read, "\""));
        }

        else if (LOOKUP_COMPARE_FUNCTION(word, ":") == 0)
        {
            char* keyword;
            char* definition;
            if ((keyword = strsep(&remaining_to_read, " ")) != NULL)
            {
                if ((definition = strsep(&remaining_to_read, ";")) != NULL)
                {
                    user_dict_assign(keyword, definition, user_dict);
                }
            }
        }
        else if (LOOKUP_COMPARE_FUNCTION(word, "-:") == 0)
        {
            char* keyword;
            if ((keyword = strsep(&remaining_to_read, " ")) != NULL)
            {
                user_dict_unassign(keyword, user_dict);
            }
        }
        else if (LOOKUP_COMPARE_FUNCTION(word, "IF") == 0)
        {
            char* body;
            if ((body = strsep(&remaining_to_read, "THEN")) != NULL)
            {
            }
        }
        else
        {
            printf("%s ?\n", word);
        }
    }
}
