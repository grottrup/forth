#include "dict.h"

//#define LOOKUP_COMPARE_FUNCTION strcmp // Case sensitive
#define LOOKUP_COMPARE_FUNCTION strcasecmp // Case insensitive

user_dict_entry* user_dict_initialize() {
    user_dict_entry* d = malloc(sizeof(user_dict_entry));
    d->name = "";
    d->body = "";
    d->next_entry = NULL;
    return d;
}

void user_dict_assign(const char* name, const char* body, user_dict_entry* dict){
    user_dict_entry* entry = dict;
    user_dict_entry* new_entry = malloc(sizeof(user_dict_entry));

    new_entry->name = name;
    new_entry->body = body;
    new_entry->next_entry = NULL;

    if (dict == NULL)
        return; // TOO DEEP
    else if (dict->next_entry == NULL) 
        // ADD ENTRY
        dict->next_entry = new_entry;
    else if (LOOKUP_COMPARE_FUNCTION(dict->name, name) == 0)
        dict->body = body; // Overwrites existing entry
    else
        user_dict_assign(name, body, dict->next_entry);
}

void user_dict_unassign(const char* name, user_dict_entry* dict){
    user_dict_entry* entry = dict;
    if (entry == NULL || LOOKUP_COMPARE_FUNCTION(entry->name, name) == 0)
        return; // TOO DEEP
    else if (LOOKUP_COMPARE_FUNCTION(entry->next_entry->name, name) == 0) {
        user_dict_entry* entry_to_remove = entry->next_entry;
        user_dict_entry* following_entry = entry_to_remove->next_entry;

        free(entry_to_remove);
        entry->next_entry = following_entry;
    }
    else 
        user_dict_unassign(name, entry->next_entry);
}

bool user_dict_entry_exists(const char* name, user_dict_entry* dict){
    if (dict == NULL)
        return false;
    else if (LOOKUP_COMPARE_FUNCTION(dict->name, name) == 0)
        return true;
    else
        user_dict_entry_exists(name, dict->next_entry);
}

const char* user_dict_get_entry(const char* name, user_dict_entry* dict){
    if (dict == NULL)
        return "";
    else if (LOOKUP_COMPARE_FUNCTION(dict->name, name) == 0)
        return dict->body;
    else
        user_dict_get_entry(name, dict->next_entry);
}



void sys_dict_add_entry(const char* name, void (*execute)(stack*), sys_dict_entry* dict) {
    sys_dict_entry* entry = dict;
    sys_dict_entry* new_entry = malloc(sizeof(sys_dict_entry));

    new_entry->name = name;
    new_entry->execute = execute;
    new_entry->next_entry = NULL;

    if (dict == NULL)
        return; // TOO DEEP
    else if (dict->next_entry == NULL) 
        // ADD ENTRY
        dict->next_entry = new_entry;
    else
        sys_dict_add_entry(name, execute, dict->next_entry);
}

sys_dict_entry* sys_dict_initialize(){
    sys_dict_entry* d = malloc(sizeof(sys_dict_entry));
    d->name = "";
    d->execute = NULL;
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
    //sys_dict_add_entry(".\"", Qmark, d);

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

void sys_dict_execute(const char* name, sys_dict_entry* dict, stack* s) {
    if (dict == NULL)
        return;
    else if (LOOKUP_COMPARE_FUNCTION(dict->name, name) == 0)
        dict->execute(s);
    else
        sys_dict_execute(name, dict->next_entry, s);
}

bool sys_dict_entry_exists(const char* name, sys_dict_entry* dict){
    if (dict == NULL)
        return false;
    else if (LOOKUP_COMPARE_FUNCTION(dict->name, name) == 0)
        return true;
    else
        sys_dict_entry_exists(name, dict->next_entry);
}
