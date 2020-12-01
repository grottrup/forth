#include "dictionary.h"
#include "operations.h"
#include <assert.h>
#include <stdlib.h>

#define WORDS 1 // remember to increase when adding a command

dictionary* initialize_built_in_dict(void)
{
    dictionary* dict = malloc(sizeof(dictionary));
    dict->length = WORDS;
    dict->command = calloc(WORDS, sizeof(command));
    dict->command[0] = (command){"+", add};
    // dict->word[1] = (word){"-", minus, 2, true};
    // dict->word[2] = (word){"*", mult, 2, true};
    // dict->word[3] = (word){"/", divide, 2, true};
    // dict->word[4] = (word){"~", uniminus, 1, true}; // change sign
    // dict->word[6] = (word){".", dot, 1, false};
    // dict->word[5] = (word){"EMIT", emit, 2, false};
    // dict->word[7] = (word){"CR", cr, 2, false};
    // dict->word[8] = (word){"\"", qmark, 2, false};

    /* Verify initialization */
    for (int i = 0; i < WORDS; i++)
    {
        assert(dict->command[i].word!= 0 && dict->command[i].execute != 0);
    }

    return dict;
}