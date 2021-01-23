#include "dict.h"

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
    else if (strcmp(dict->name, name) == 0)
        dict->body = body; // Overwrites existing entry
    else
        user_dict_assign(name, body, dict->next_entry);
}

void user_dict_unassign(const char* name, user_dict_entry* dict){
    user_dict_entry* entry = dict;
    if (entry == NULL || strcmp(entry->name, name) == 0)
        return; // TOO DEEP
    else if (strcmp(entry->next_entry->name, name) == 0) {
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
    else if (strcmp(dict->name, name) == 0)
        return true;
    else
        user_dict_entry_exists(name, dict->next_entry);
}

const char* user_dict_get_entry(const char* name, user_dict_entry* dict){
    if (dict == NULL)
        return "";
    else if (strcmp(dict->name, name) == 0)
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

    sys_dict_add_entry("+", Add, d);
    sys_dict_add_entry("-",Minus, d);

    return d;
}

void sys_dict_execute(const char* name, sys_dict_entry* dict, stack* s) {
    if (dict == NULL)
        return;
    else if (strcmp(dict->name, name) == 0)
        dict->execute(s);
    else
        sys_dict_execute(name, dict->next_entry, s);
}

bool sys_dict_entry_exists(const char* name, sys_dict_entry* dict){
    if (dict == NULL)
        return false;
    else if (strcmp(dict->name, name) == 0)
        return true;
    else
        sys_dict_entry_exists(name, dict->next_entry);
}
