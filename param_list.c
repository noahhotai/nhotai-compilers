#include "param_list.h"

struct param_list * param_list_create( char *name, struct type *type, struct param_list *next ){
    struct param_list * d = calloc(1, sizeof(struct param_list));
    d->name = name;
    d->type = type;
    d->next = next;
    return d;
}
void param_list_print( struct param_list *a ){
    while(a){
        printf("%s", a->name);
        printf(" : ");
        type_print(a->type);
        if (a->next){
            printf(", ");
        }
        a = a->next;
    }
}

void param_list_resolve( struct param_list *a ){
    extern int resolve_error;
    while(a){
        if (scope_lookup_current( a->name)){
            resolve_error = 1;
            printf("resolve error: %s already declared in this scope\n", a->name);
        }
        else{
            the_stack->top->count++;
            struct symbol* new_symbol = symbol_create(SYMBOL_PARAM, a->type, a->name, 0, the_stack->top->count);
            scope_bind(a->name, new_symbol);
        }
        a = a->next;
    }
}

int param_check(struct param_list* param_1, struct param_list* param_2){

    if (!param_1 && !param_2){
        return 1;
    }
    else if (!param_1 || !param_2){
        return 0;
    }
    else{
        if (type_check(param_1->type, param_2->type) && !strcmp(param_1->name, param_1->name)){
            return param_check(param_1->next, param_2->next);
        }
        else{
            return 0;
        }
    }
}

void param_delete(struct param_list* param){

    struct param_list* temp;
    while (param){
        temp = param->next;
        free(param);
        param = temp;
    }
}