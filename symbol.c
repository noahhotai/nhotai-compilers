
#include "symbol.h"
#include <stdio.h>


struct symbol * symbol_create( symbol_t kind, struct type *type, char *name, int has_code, int num ) { 
    struct symbol *s = malloc(sizeof(*s));
    s->kind = kind;
    s->type = type;
    s->name = name;
    s->has_code = has_code;
    s->which = num;
    return s;
}

char* symbol_codegen(struct symbol * sym){
    if (sym->kind == SYMBOL_GLOBAL){
        return sym->name;
    }
}