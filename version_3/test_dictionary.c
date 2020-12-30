#include "dictionary.h"
#include "operations.h"
#include "test_project.h"
#include <stdlib.h> //atoi

void test_init(void)
{
    {
        dictionary* dict = initialize_built_in_dict();
        assert(dict->length > 0);
        free(dict);
    }
}

bool test_dictionary(void)
{
    test_init();
    printf("📖\n");
    return true;
}