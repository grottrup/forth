#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include "dict.h"
#include "parser.h"

void test() {
    printf("~ INIT ~\n");
    user_dict_entry* ud = user_dict_initialize();
    sys_dict_entry* sd = sys_dict_initialize();
    stack si;
    init_stack(&si);
    stack* s = &si;


    /// ADD A USER ENTRY
    printf("~ ADD ~\n");
    user_dict_assign("test", "1 2 3 + -", ud);
    assert(user_dict_entry_exists("test", ud));

    const char* body = user_dict_get_entry("test", ud);

    printf("User dict test entry body: %s\n", body);


    /// TEST EXECUTION OF SYSTEM ENTRY
    printf("~ EXEC ~\n");
    push(s, 5);
    push(s, 7);
    print_stack(s);
    printf("+\n");
    sys_dict_execute("+", sd, s);
    print_stack(s);
    assert(pop(s) == 12);

    push(s, 5);
    push(s, 7);
    print_stack(s);
    printf("-\n");
    sys_dict_execute("-", sd, s);
    print_stack(s);
    assert(pop(s) == -2);


    /// TEST PARSER ON USER ENTRY
    printf("~ PARSE ~\n");
    printf("Parser input: %s\n", body);
    parse(body, s, sd, ud);
    print_stack(s);
    assert(pop(s) == -4);


    /// REMOVE USER ENTRY
    printf("~ REMOVE ~\n");
    user_dict_unassign("test", ud);
    assert(!user_dict_entry_exists("test", ud));
}

void main() {
    test();
    printf("Success!\n");
}
