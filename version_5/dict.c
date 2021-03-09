#include "dict.h"

//#define LOOKUP_COMPARE_FUNCTION strcmp // Case sensitive
#define LOOKUP_COMPARE_FUNCTION strcasecmp // Case insensitive

user_dict_entry* user_dict_initialize(void) {
    user_dict_entry* d = malloc(sizeof(user_dict_entry));
    d->keyword = "";
    d->definition = "";
    d->next_entry = NULL;
    return d;
}

void user_dict_assign(const char* keyword, const char* definition, user_dict_entry* dict){
    user_dict_entry* entry = dict;
    user_dict_entry* new_entry = malloc(sizeof(user_dict_entry));

    new_entry->keyword = keyword; //
    new_entry->definition = definition;
    new_entry->next_entry = NULL;

    if (dict == NULL)
        return; // TOO DEEP
    else if (dict->next_entry == NULL) 
        // ADD ENTRY
        dict->next_entry = new_entry;
    else if (LOOKUP_COMPARE_FUNCTION(dict->keyword, keyword) == 0)
        dict->definition = definition; // Overwrites existing entry
    else
        user_dict_assign(keyword, definition, dict->next_entry);
}

void user_dict_unassign(const char* keyword, user_dict_entry* dict){
    user_dict_entry* entry = dict;
    if (entry == NULL || LOOKUP_COMPARE_FUNCTION(entry->keyword, keyword) == 0)
        return; // TOO DEEP
    else if (LOOKUP_COMPARE_FUNCTION(entry->next_entry->keyword, keyword) == 0) {
        user_dict_entry* entry_to_remove = entry->next_entry;
        user_dict_entry* following_entry = entry_to_remove->next_entry;

        free(entry_to_remove);
        entry->next_entry = following_entry;
    }
    else 
        user_dict_unassign(keyword, entry->next_entry);
}

bool user_dict_entry_exists(const char* keyword, user_dict_entry* dict){
    if (dict == NULL)
        return false;
    else if (LOOKUP_COMPARE_FUNCTION(dict->keyword, keyword) == 0)
        return true;
    else
        return user_dict_entry_exists(keyword, dict->next_entry);
}

const char* user_dict_get_entry(const char* keyword, user_dict_entry* dict){
    if (dict == NULL)
        return "";
    else if (LOOKUP_COMPARE_FUNCTION(dict->keyword, keyword) == 0)
        return dict->definition;
    else
        return user_dict_get_entry(keyword, dict->next_entry);
}



void sys_dict_add_entry(const char* keyword, void (*execute)(stack*), sys_dict_entry* dict) {
    sys_dict_entry* entry = dict;
    sys_dict_entry* new_entry = malloc(sizeof(sys_dict_entry));

    new_entry->entry.keyword = keyword;
    new_entry->entry.execute = execute;
    new_entry->next_entry = NULL;

    if (dict == NULL)
        return; // TOO DEEP
    else if (dict->next_entry == NULL) 
        // ADD ENTRY
        dict->next_entry = new_entry;
    else
        sys_dict_add_entry(keyword, execute, dict->next_entry);
}

sys_dict_entry* sys_dict_initialize(void){
    sys_dict_entry* d = malloc(sizeof(sys_dict_entry));
    d->entry.keyword = "";
    d->entry.execute = NULL;
    d->next_entry = NULL;

    // Arithmetics
    sys_dict_add_entry("+", Add, d);
    sys_dict_add_entry("-", Minus, d);
    sys_dict_add_entry("*", Mult, d);
    sys_dict_add_entry("/", Divide, d);

    // Output
    sys_dict_add_entry(".", Dot, d);
    sys_dict_add_entry("EMIT", Emit, d);
    sys_dict_add_entry("CR", CR, d);
    //sys_dict_add_entry(".\"", Qmark, d); //."

    // Data stack
    sys_dict_add_entry("DROP", Drop, d);
    sys_dict_add_entry("DUP", Dup, d);
    sys_dict_add_entry("SWAP", Swap, d);
    sys_dict_add_entry("OVER", Over, d);
    sys_dict_add_entry("ROT", Rot, d);
    
    // Comparisons
    sys_dict_add_entry("=", Equals, d);
    sys_dict_add_entry("<", LessThan, d);
    sys_dict_add_entry(">", GreaterThan, d);
    sys_dict_add_entry("AND", And, d);
    sys_dict_add_entry("OR", Or, d);
    sys_dict_add_entry("NOT", Not, d);

    return d;
}

void sys_dict_execute(const char* keyword, sys_dict_entry* dict, stack* s) {
    if (dict == NULL)
        return;
    else if (LOOKUP_COMPARE_FUNCTION(dict->entry.keyword, keyword) == 0)
        dict->entry.execute(s);
    else
        sys_dict_execute(keyword, dict->next_entry, s);
}

bool sys_dict_entry_exists(const char* keyword, sys_dict_entry* dict){
    if (dict == NULL)
        return false;
    else if (LOOKUP_COMPARE_FUNCTION(dict->entry.keyword, keyword) == 0)
        return true;
    else
        return sys_dict_entry_exists(keyword, dict->next_entry);
}
