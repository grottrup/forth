#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "dict.h"
#include "parser.h"

#define INP_MAX 80

#define _VIS_AUT_TEST false

void test() {
    if (_VIS_AUT_TEST) printf("~ INIT ~\n");
    user_dict_entry* ud = user_dict_initialize();
    sys_dict_entry* sd = sys_dict_initialize();
    stack si;
    init_stack(&si);
    stack* s = &si;


    /// ADD A USER ENTRY
    if (_VIS_AUT_TEST) printf("~ ADD ~\n");
    user_dict_assign("test", "1 2 3 + -", ud);
    assert(user_dict_entry_exists("test", ud));

    const char* body = user_dict_get_entry("test", ud);

    if (_VIS_AUT_TEST) printf("User dict test entry body: %s\n", body);


    /// TEST EXECUTION OF SYSTEM ENTRY
    if (_VIS_AUT_TEST) printf("~ EXEC ~\n");
    push(s, 5);
    push(s, 7);
    if (_VIS_AUT_TEST) print_stack(s);
    if (_VIS_AUT_TEST) printf("+\n");
    sys_dict_execute("+", sd, s);
    if (_VIS_AUT_TEST) print_stack(s);
    assert(pop(s) == 12);

    push(s, 5);
    push(s, 7);
    if (_VIS_AUT_TEST) print_stack(s);
    if (_VIS_AUT_TEST) printf("-\n");
    sys_dict_execute("-", sd, s);
    if (_VIS_AUT_TEST) print_stack(s);
    assert(pop(s) == -2);


    /// TEST PARSER ON USER ENTRY
    if (_VIS_AUT_TEST) printf("~ PARSE ~\n");
    if (_VIS_AUT_TEST) printf("Parser input: %s\n", body);
    parse(body, s, sd, ud);
    if (_VIS_AUT_TEST) print_stack(s);
    assert(pop(s) == -4);


    /// REMOVE USER ENTRY
    if (_VIS_AUT_TEST) printf("~ REMOVE ~\n");
    user_dict_unassign("test", ud);
    assert(!user_dict_entry_exists("test", ud));
}

void manual_test() {
    user_dict_entry* ud = user_dict_initialize();
    sys_dict_entry* sd = sys_dict_initialize();
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

void main() {
    test();
    if (_VIS_AUT_TEST) printf("Success!\n");
    manual_test();
}
