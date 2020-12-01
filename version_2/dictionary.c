#include "dictionary.h"
#include "operations.h"
#define WORDS 5

built_in_word_dict* initialize_built_in_dict(void) {
    built_in_word_dict* dict = malloc(sizeof(built_in_word_dict));
    dict->length = WORDS;
    dict->word = calloc(WORDS, sizeof(built_in_word));
    dict->word[0] = (built_in_word){"+", add, 2};
    dict->word[1] = (built_in_word){"-", minus, 2};
    dict->word[2] = (built_in_word){"*", mult, 2};
    dict->word[3] = (built_in_word){"/", divide,2};
    dict->word[4] = (built_in_word){"~", uniminus, 1};
    // dict->word[0] = (built_in_word){"EMIT", emit, 2};
    // dict->word[0] = (built_in_word){'.', dot, 2};
    // dict->word[0] = (built_in_word){"CR", cr, 2};
    // dict->word[0] = (built_in_word){'\"', qmark, 2};
    /* Verify initialization */
    // for (int i = 0; i < WORDS; i++) {
    //     assert(dict->word[i].operator != 0 && dict->word[i].get_result != 0);
    // }

    return dict;
}