 typedef struct built_in_word{
     char* operator; // which operator to execute
     int(*get_result)(int*); // use an array of arguments to execute the operator on
     int para_count; // how many arguments does the operator take
 }built_in_word;

typedef struct built_in_word_dict
{
    built_in_word (* word);
    int length;
} built_in_word_dict;