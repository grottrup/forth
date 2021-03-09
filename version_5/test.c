#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "dict.h"
#include "parser.h"
#include "dict.h"
#include "operations.h"
#include "sentence.h"

#define INP_MAX 80

#define _SHOW_AUTO_TESTS true

void test_arithmetics(void)
{
    stack s;
    {
        init_stack(&s);
        push(&s, 1);
        push(&s, 2);
        command w = (command){"+", Add};
        w.execute(&s);
        assert(pop(&s) == 3 );
        assert(stack_is_empty(&s));
    }    
    {
        init_stack(&s);
        push(&s, 2);
        push(&s, 2);
        command w = (command){"-", Minus};
        w.execute(&s);
        assert(pop(&s) == 0 );
        assert(stack_is_empty(&s));
    }    
    {
        init_stack(&s);
        push(&s, 2);
        push(&s, 2);
        command w = (command){"*", Mult};
        w.execute(&s);
        assert(pop(&s) == 4 );
        assert(stack_is_empty(&s));
    }
    {
        init_stack(&s);
        push(&s, 10);
        push(&s, 2);
        command w = (command){"/", Divide};
        w.execute(&s);
        assert(pop(&s) == 5 );
        assert(stack_is_empty(&s));
    }
    free_stack(&s);
}

void test_dictionary(void)
{
    user_dict* ud = user_dict_initialize();
    sys_dict* sd = sys_dict_initialize();
    stack si;
    init_stack(&si);
    stack* s = &si;

    /// ADD A USER ENTRY
    if (_SHOW_AUTO_TESTS) printf("~ ADD ~\n");
    user_dict_assign("test", "1 2 3 + -", ud);
    assert(user_dict_entry_exists("test", ud));

    const char* body = user_dict_get_entry("test", ud);

    if (_SHOW_AUTO_TESTS) printf("User dict test entry body: %s\n", body);


    /// TEST EXECUTION OF SYSTEM ENTRY
    if (_SHOW_AUTO_TESTS) printf("~ EXEC ~\n");
    push(s, 5);
    push(s, 7);
    if (_SHOW_AUTO_TESTS) print_stack(s);
    if (_SHOW_AUTO_TESTS) printf("+\n");
    sys_dict_execute("+", sd, s);
    if (_SHOW_AUTO_TESTS) print_stack(s);
    assert(pop(s) == 12);

    push(s, 5);
    push(s, 7);
    if (_SHOW_AUTO_TESTS) print_stack(s);
    if (_SHOW_AUTO_TESTS) printf("-\n");
    sys_dict_execute("-", sd, s);
    if (_SHOW_AUTO_TESTS) print_stack(s);
    assert(pop(s) == -2);


    /// TEST PARSER ON USER ENTRY
    if (_SHOW_AUTO_TESTS) printf("~ PARSE ~\n");
    if (_SHOW_AUTO_TESTS) printf("Parser input: %s\n", body);
    parse(body, s, sd, ud);
    if (_SHOW_AUTO_TESTS) print_stack(s);
    assert(pop(s) == -4);


    /// REMOVE USER ENTRY
    // if (_SHOW_AUTO_TESTS) printf("~ REMOVE ~\n");
    // user_dict_unassign("test", ud);
    // assert(!user_dict_entry_exists("test", ud));
}

void test_sentence() {
    const char* str = "Hello World. What a nice day.";
    word_node* list = string_to_sentence(str, NULL);

    print_list(list);

    print_list(find_in_sentence("What", list));

    print_list(last_node(list));

    destroy_sentence(list);
}

void auto_test() {
    if (_SHOW_AUTO_TESTS) printf("~ INIT ~\n");
    test_arithmetics(); // temporary placement. clean up other tests...
    test_dictionary();
    test_sentence();
}

void manual_test() {
    user_dict* ud = user_dict_initialize();
    user_dict_assign("test", "1 2 3 + -", ud); // remove
    sys_dict* sd = sys_dict_initialize();
    stack si;
    init_stack(&si);
    stack* s = &si;

    char inp[INP_MAX+2];

    while (strcmp(inp,"exit") != 0)
    {
        // https://stackoverflow.com/questions/1247989/how-do-you-allow-spaces-to-be-entered-using-scanf
        if(!fgets(inp, sizeof(inp), stdin))
        {
            fputs("io error\n", stderr);
            return;
        }

        // Remove the newline
        for (int i = 0; i < INP_MAX+1; i++) {
            if (inp[i] == '\n')
                inp[i] = 0x0;
        }
        //printf("\"%s\"\n",inp);

        parse((const char*) &inp, s, sd, ud);
        printf("\n");
        print_stack(s);
    }
}

int main(int argc, char *argv[])
{
    auto_test();
    if (_SHOW_AUTO_TESTS) printf("Success!\n");
    if(argc > 1)
        manual_test(); // commented out to see whether the automatic tests work
    return 0;
}