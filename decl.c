#include "decl.h"


struct decl * decl_create( char *name, struct type *type, struct expr* value, struct stmt *code, struct decl *next ){
    struct decl * d = calloc(1, sizeof(struct decl));
    d->name = name; 
    d->type = type;
    d->value = value;
    d->code = code;
    d->next = next;
    return d;
}

void decl_print(struct decl *d, int indents){
    extern void indent(int indents);


    if (!d) {
        return;
    } 

    fprintf(stdout, "%s: ", d->name);

    type_print(d->type);
    
    if (d->value){
        fprintf(stdout, " = ");
        if (d->value->kind == EXPR_LIST || d->value->kind == EXPR_NESTED_BRACES){
            fprintf(stdout, "{");
            expr_print(d->value);
            fprintf(stdout, "}");
        }
        else{
            expr_print(d->value);
        }
        
    }

    if (d->code){
        // printf("heyyyyyy");
        fprintf(stdout, " = ");
        stmt_print(d->code, indents);
        // indent(indents);
    }
    else{
        fprintf(stdout, ";");
    }
    
    printf("\n");
    // printf("BKHBKHB");
    if (d->next){
        // printf("d->next");
        decl_print(d->next, indents);
    }

    
}


void decl_resolve( struct decl *d ){
    extern int resolve_error;
    if(!d) return;

    symbol_t kind;
    // printf("decl_resolve\n");
    if (scope_level() > 1) {
        kind = SYMBOL_LOCAL;
    } 
    else {
        kind = SYMBOL_GLOBAL;
    }
    // printf("decl_resolve\n");
    // creating symbol for decl
    the_stack->top->count++;
    if (d->code){
        d->symbol = symbol_create(kind, d->type, d->name, 1, the_stack->top->count);
    }
    else{
        d->symbol = symbol_create(kind, d->type, d->name, 0, the_stack->top->count);
    }
    expr_resolve(d->value);
    
    // printf("decl_resolve\n");
    // checking if theres's already a function declared
    if (d->type->kind == TYPE_FUNCTION){
        // printf("first_if\n");

        struct symbol* lookup_symbol = hash_table_lookup(the_stack->top->ht, d->name);
        if (!lookup_symbol){
            scope_bind(d->name,d->symbol); 
        }
        else if (lookup_symbol->type->kind == TYPE_FUNCTION){
            if (lookup_symbol->has_code == 1 && d->symbol->has_code == 1){

                resolve_error = 1;
                printf("error: redeclaration of function code\n");
            }
            else if (!type_check(lookup_symbol->type, d->type)){ 
                resolve_error = 1;
                printf("error: type differences\n");
            }
            else if (!param_check(lookup_symbol->type->params, d->type->params)){//make sure the parameters are the same
                resolve_error = 1;
                 printf("error: function paramaters are different\n");
            }
            else{
                // scope_enter();
                // param_list_resolve(d->type->params);
                // scope_bind(d->name,d->symbol); 

            }
            if (d->code){
                lookup_symbol->has_code = 1;
            }
        }
        else {
            resolve_error = 1;
            printf("error: redeclaration\n");
        }

        scope_enter();
        param_list_resolve(d->type->params);
        
        if(d->code) {
            stmt_resolve(d->code);
        }
        scope_exit();
    }   
    else {
        // printf("second_if\n");
        scope_bind(d->name,d->symbol); 
    }


    decl_resolve(d->next);

}
