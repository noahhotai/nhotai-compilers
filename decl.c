#include "decl.h"
#include <stdlib.h>

struct decl * decl_create( char *name, struct type *type, struct expr* value, struct stmt *code, struct decl *next ){
    struct decl * d = malloc(sizeof(struct decl));
    d->name = name; 
    d->type = type;
    d->value = value;
    d->code = code;
    d->next = next;
    return d;
}

void decl_print(struct decl *d, int indents){
    extern void indent(int indents);
    if (!d) return;

    ident(indents);
    fprintf(stdout, "%s: ", d->name);
    type_print(d->type);

    if (d->value){
        fprintf(stdout, " = ");
        expr_print(d->value);
    }

    if (d->code){
        fprintf(stdout, " = {\n}");
        stmt_print(d->code, indents + 1 );
        ident(indents);
        fprintf(stdout, ";\n");
    }
    else{
        fprintf(stdout, ";\n");
    }

    if (d->next){
        decl_print(d->next, indents);
    }
    

}