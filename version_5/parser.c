#include "parser.h"

//#define LOOKUP_COMPARE_FUNCTION strcmp // Case sensitive
#define LOOKUP_COMPARE_FUNCTION strcasecmp // Case insensitive

typedef enum parse_type
{
    UNKNOWN,
    NUMBER,
    COMMAND,
    USER_COMMAND,
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

parse_t get_parse_type(const char* word, sys_dict* sys_dict, user_dict* user_dict)
{
    if(is_number(word))
        return NUMBER;
    else if(sys_dict_entry_exists(word, sys_dict))
        return COMMAND;
    else if(user_dict_entry_exists(word, user_dict))
        return USER_COMMAND;
    else
        return UNKNOWN;
}


bool is_command(const char* str, sys_dict* sys_dict)
{
    return sys_dict_entry_exists(str, sys_dict);
}

bool is_user_word(const char* str, user_dict* user_dict)
{
    return user_dict_entry_exists(str, user_dict);
}

void parse_helper(parse_t t, char* word, stack* num_stack, sys_dict* sys_dict,
           user_dict* user_dict)
{
    switch (t)
    {
    case NUMBER:
        push(num_stack, atoi(word));
        break;
    case COMMAND:
        sys_dict_execute(word, sys_dict, num_stack);
        break;
    case USER_COMMAND:
        parse(user_dict_get_entry(word, user_dict), num_stack, sys_dict, user_dict);
        break;
    default:
        break;
    }
}

void parse(word_node* input, stack* num_stack, sys_dict* sys_dict,
           user_dict* user_dict)
{
    word_node* ite = input;
    while (input != NULL)
    {
        char* word = (char*)input->word;
        parse_t parse_type = get_parse_type(word,sys_dict,user_dict);
        if(parse_type != UNKNOWN) // refactor code below until there are no unknown
        {
            parse_helper(parse_type, word, num_stack, sys_dict,user_dict);
        }
        else if (LOOKUP_COMPARE_FUNCTION(word, ".\"") == 0)
        {
            word_node* printstr = ite;
            while (LOOKUP_COMPARE_FUNCTION(printstr->next_word->word, "\"") == 0)
            {
                printf("%s ", printstr->word);
                printstr = printstr->next_word;
            }
            printf("\n");
        }

        // else if (LOOKUP_COMPARE_FUNCTION(word, ":") == 0)
        // {
        //     char* keyword;
        //     char* definition;
        //     if ((keyword = strsep(&remaining_to_read, " ")) != NULL)
        //     {
        //         if ((definition = strsep(&remaining_to_read, ";")) != NULL)
        //         {
        //             user_dict_assign(keyword, definition, user_dict);
        //         }
        //     }
        // }
        // else if (LOOKUP_COMPARE_FUNCTION(word, "-:") == 0)
        // {
        //     char* keyword;
        //     if ((keyword = strsep(&remaining_to_read, " ")) != NULL)
        //     {
        //         user_dict_unassign(keyword, user_dict);
        //     }
        // }
        // else if (LOOKUP_COMPARE_FUNCTION(word, "IF") == 0)
        // {
        //     char* body;
        //     if ((body = strsep(&remaining_to_read, "THEN")) != NULL)
        //     {
        //     }
        // }
        else
        {
            printf("%s ?\n", word);
        }
    }
}
