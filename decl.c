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
        expr_print(d->value);

    }

    if (d->code){
        fprintf(stdout, " = ");
        stmt_print(d->code, indents);
    }
    else{
        fprintf(stdout, ";");
    }
    
    printf("\n");
    if (d->next){
        decl_print(d->next, indents);
    }
    
}

void decl_resolve( struct decl *d ){

    extern int resolve_error;

    if(!d) return;

    symbol_t kind;

    if (scope_level() > 1) {
        kind = SYMBOL_LOCAL;
    } 
    else {
        kind = SYMBOL_GLOBAL;
    }


    the_stack->top->count++;
    if (d->code){
        d->symbol = symbol_create(kind, d->type, d->name, 1, the_stack->top->count);

    }
    else{
        d->symbol = symbol_create(kind, d->type, d->name, 0, the_stack->top->count);
    }

    expr_resolve(d->value);
    
    // checking if theres's already a function declared
    if (d->type->kind == TYPE_FUNCTION){

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

        scope_bind(d->name,d->symbol); 
    }

    decl_resolve(d->next);

}
void decl_typecheck( struct decl *d ){
    // printf("top\n\n\n\n\n");
    extern int typecheck_error;
    if(!d) return;

    // extern int typecheck_error;
    if (d->value){
        // printf("here\n\n\n\n");
        struct type * expr_type = expr_typecheck(d->value);
        // expr_print(d->value);
        // printf("%s: %d", d->name, expr_type->kind);
        if (expr_type->kind == TYPE_ARRAY){
            if (d->symbol->kind != SYMBOL_GLOBAL){
                typecheck_error = 1;
                printf("type error: cannot assign declare array non-globally (%s)\n", d->name);
            }
            else{
                if (array_content_check(d->type, d->value)){
                    typecheck_error = 1;
                    printf("type error: cannot assign ");
                    printf(" (");
                    expr_print(d->value);
                    printf(") to type ");
                    type_print(d->type);
                    printf(" (%s).\n", d->name);
                }
            }
            // printf("gerdfsdf");
            // expr_list_check(e->left, lt);
        }
        else if (!type_check(expr_type, d->type)){
                typecheck_error = 1;
                printf("type error: cannot assign type ");
                type_print(expr_type);
                printf(" (");
                expr_print(d->value);
                printf(") to type ");
                type_print(d->type);
                printf(" (%s).\n", d->name);
                // expr_print(d->ident);
                // printf(").\n");
            // printf("type error: cannot assign declared ");
        }
    }
    else if (d->type->kind == TYPE_ARRAY){
        if (!d->type->array_size){
            // type error: declaration of array (a) must have a fixed size
            typecheck_error = 1;
            printf("type error: declaration of array (%s) must have a fixed size", d->name);
        }
        
    }
    else if (d->code){
        // printf("d->code");
        if (d->type->subtype->kind == TYPE_ARRAY){
            typecheck_error = 1;
            printf("type error: function cannot have return type ");
            type_print_error(d->type);
            printf(".\n");
        }
        else if (d->type->subtype->kind == TYPE_FUNCTION){
            typecheck_error = 1;
            printf("type error: function cannot have return type ");
            type_print_error(d->type->subtype);
            printf(".\n");
        }
        

        stmt_typecheck(d->code, d->type->subtype, 0, d->name);
        
    }

    decl_typecheck(d->next);

}


// void decl_typecheck( struct decl *d ){

//     extern int typecheck_error;

//     if(!d) return;

//     symbol_t kind;

//     if (scope_level() > 1) {
//         kind = SYMBOL_LOCAL;
//     } 
//     else {
//         kind = SYMBOL_GLOBAL;
//     }


//     the_stack->top->count++;
//     if (d->code){
//         d->symbol = symbol_create(kind, d->type, d->name, 1, the_stack->top->count);
//     }
//     else{
//         d->symbol = symbol_create(kind, d->type, d->name, 0, the_stack->top->count);
//     }



//     // checking if theres's already a function declared
//     if (d->type->kind == TYPE_FUNCTION){

//         struct symbol* lookup_symbol = hash_table_lookup(the_stack->top->ht, d->name);

//         if (!lookup_symbol){
//             scope_bind(d->name,d->symbol); 
//         }
//         else if (lookup_symbol->type->kind == TYPE_FUNCTION){
//             if (lookup_symbol->has_code == 1 && d->symbol->has_code == 1){

//                 resolve_error = 1;
//                 printf("error: redeclaration of function code\n");
//             }
//             else if (!type_check(lookup_symbol->type, d->type)){ 
//                 resolve_error = 1;
//                 printf("error: type differences\n");
//             }
//             else if (!param_check(lookup_symbol->type->params, d->type->params)){//make sure the parameters are the same
//                 resolve_error = 1;
//                  printf("error: function paramaters are different\n");
//             }

//             if (d->code){
//                 lookup_symbol->has_code = 1;
//             }
//         }
//         else {
//             resolve_error = 1;
//             printf("error: redeclaration\n");
//         }

//         scope_enter();
//         param_list_resolve(d->type->params);
        
//         if(d->code) {
//             stmt_resolve(d->code);
//         }
//         scope_exit();
//     }   
//     else {
//         scope_bind(d->name,d->symbol); 
//         if (d->value){
//             if (!type_check(expr_typecheck(d->value), d->symbol->type)){
//                 printf("declaration doesn't match value");
//             }
//         }
//     }

//     decl_type_check(d->next);

// }
