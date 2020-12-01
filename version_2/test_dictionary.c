#include "dictionary.h"

void test_init(void)
{
    {
        built_in_word_dict* dict = initialize_built_in_dict();
        assert(c1->getTime() >= 0);
        delete c1;
    }
    {
        int initTime = 10;
        Clock* c2 = new Clock(initTime);
        assert(c2->getTime() >= initTime);
        delete c2;
    }
}

int main()
{
    
    test_init();
    return 0;
}