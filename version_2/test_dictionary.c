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
    // {
    //     dictionary* dict = initialize_built_in_dict();
    //     assert(dict->length >= 9); // update when the dictionary is expanded
    //     free(dict);
    // }
}

void test_arithmetics(void) // white box
{
    {
        stack s = initialize_stack(); // whoops not so unifor implementation
        push(&s, 1);
        push(&s, 2);
        command w = (command){"+", Add};
        w.execute(&s);
        assert(pop(&s) == 3 );
        assert(stack_is_empty(&s));
        // free stack
    }
    {
        stack s = initialize_stack(); // whoops not so unifor implementation
        push(&s, 10);
        push(&s, 2);
        command w = (command){"/", Divide};
        w.execute(&s);
        assert(pop(&s) == 5 );
        assert(stack_is_empty(&s));
        // free stack
    }
}

void user_word()
{
    {
        // command w = (command){":", DefineStart};
    }
    {
        stack s = initialize_stack(); // whoops not so unifor implementation
        // command w = (command){";", DefineEnd};
    }
}

// void test_arithmetics2(void) // black box
// {
//     {
//         stack s = initialize_stack(); // whoops not so unifor implementation
//         push(&s, 1);
//         push(&s, 2);
//         dictionary* dict = initialize_built_in_dict();
//         for (int i = 0; i < dict->length; i++)
//         {
//             if(dict->command[i].word = "+" )
//             {
//                 printf("index(%d)\n", i);
//                 command w = dict->command[i];
//                 execute_command(&s, &w);
//                 assert(pop(&s) == 3 );
//                 return;
//             }
//         }
//         // free stack
//         free(dict);
//     }
// }

int main()
{
    test_init();
    test_arithmetics();
    printf("📖\n");
    return 0;
}