#include "dictionary.h"
#include "operations.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h> //atoi


void test_init(void)
{
    {
        dictionary* dict = initialize_built_in_dict();
        assert(dict->length > 0);
        free(dict);
    }
    {
        dictionary* dict = initialize_built_in_dict();
        assert(dict->length >= 9); // update when the dictionary is expanded
        free(dict);
    }
}

void test_arithmetics(void)
{
    {
        stack s = initialize_stack(); // whoops not so unifor implementation
        push(&s, 1);
        push(&s, 2);
        dictionary* dict = initialize_built_in_dict();
        for (int i = 0; i < dict->length; i++)
        {
            if(dict->word[i].operator = "+" )
            {
                printf("index(%d)\n", i);
                word w = dict->word[i];
                execute_command(&s, &w);
                assert(pop(&s) == 3 );
                return;
            }
        }
        // free stack
        free(dict);
    }
}

int main()
{
    test_init();
    test_arithmetics();
    printf("📖\n");
    return 0;
}