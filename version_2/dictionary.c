#include "dictionary.h"
#include "operations.h"
#include <assert.h>
#define WORDS 9 // remember to increase when adding a command

dictionary* initialize_built_in_dict(void)
{
    dictionary* dict = malloc(sizeof(dictionary));
    dict->length = WORDS;
    dict->word = calloc(WORDS, sizeof(word));
    dict->word[0] = (word){"+", add, 2, true};
    dict->word[1] = (word){"-", minus, 2, true};
    dict->word[2] = (word){"*", mult, 2, true};
    dict->word[3] = (word){"/", divide, 2, true};
    dict->word[4] = (word){"~", uniminus, 1, true};
    dict->word[6] = (word){".", dot, 1, false};
    dict->word[5] = (word){"EMIT", emit, 2, false};
    dict->word[7] = (word){"CR", cr, 2, false};
    dict->word[8] = (word){"\"", qmark, 2, false};

    /* Verify initialization */
    for (int i = 0; i < WORDS; i++)
    {
        assert(dict->word[i].operator!= 0 && dict->word[i].get_result != 0);
    }

    return dict;
}

void execute_command(stack* s, word* w)
{
    int* arr = calloc(w->operator_args, sizeof(int));
    // extract parameters
    for (int j = 0; j < w->operator_args; j++)
    {
        arr[j] = pop(s);
    }
    if(w->should_push)
    {
        int result = w->get_result(arr);
        push(s, result);
    }
}