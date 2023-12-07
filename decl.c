#include "decl.h"


extern FILE* file;

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

void decl_print_error(struct decl *d){
    extern void indent(int indents);

    if (!d) {
        return;
    } 

    fprintf(stdout, "%s: ", d->name);

    type_print(d->type);

}




void decl_resolve( struct decl *d ){

    extern int resolve_error;
    extern int func_local_count;
    extern int global_count;
    if(!d) return;

    // determining kind before creating symbol
    symbol_t kind;
    if (scope_level() > 1) {
        func_local_count++;
        kind = SYMBOL_LOCAL;
    } 
    else {
        global_count++;
        // printf("here\n");
        // decl_print_error(d);
        // printf("\n");
        kind = SYMBOL_GLOBAL;
    }

    // determining code status before symbol creation
    if (d->code){
        func_local_count = -1;
        d->symbol = symbol_create(kind, d->type, d->name, 1, global_count);
    }
    else{
        if (kind == SYMBOL_GLOBAL){
            d->symbol = symbol_create(kind, d->type, d->name, 0, global_count);
        }
        else {
            d->symbol = symbol_create(kind, d->type, d->name, 0, func_local_count);
        }
    }

    expr_resolve(d->value);
    if (d->symbol->type->array_size) expr_resolve(d->type->array_size);
    
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



void decl_typecheck(struct decl *d ){
    if (!d) return;
    extern int typecheck_error;
    int is_global = 0;
    if (d->symbol->kind == SYMBOL_GLOBAL){
        // expr_typecheck_global(d->value);
        is_global = 1;
    }
    struct type* expr_type;
    switch (d->type->kind){
        case(TYPE_FUNCTION):
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

            if (d->code){
                stmt_typecheck(d->code, d->type->subtype, 0, d->name);
            }
            break;
        case(TYPE_ARRAY):
            // if (array_size_check){
            //     return 
            // }
            if (d->value){
                if (!is_global){
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
            }
            if (!is_global){
                if (!d->type->array_size){
                    printf("type error: no array size given to %s\n", d->name);
                
                }
                
                else if (expr_typecheck(d->type->array_size)->kind != TYPE_INTEGER){
                    typecheck_error = 1;
                    printf("type error: array size initializer must be of type intger (");
                    decl_print_error(d);
                    printf(")\n");
                }
            }
            else{
                if (!d->type->array_size){
                    printf("type error: no array size given to %s\n", d->name);
                }
                else if (expr_typecheck_global(d->type->array_size)->kind != TYPE_INTEGER){
                    typecheck_error = 1;
                    printf("type error: array size initializer must be of type intger (");
                    decl_print_error(d);
                    printf(")\n");
                }
            }
            break;

        default: 
            if (d->value){
                if(is_global){
                    expr_type = expr_typecheck_global(d->value);
                }
                else{
                    expr_type = expr_typecheck(d->value);
                }

            if (!type_check(expr_type, d->type)){
                typecheck_error = 1;
                printf("type error: cannot assign type ");
                type_print(expr_type);
                printf(" (");
                expr_print(d->value);
                printf(") to type ");
                type_print(d->type);
                printf(" (%s).\n", d->name);
            }
            }
            break; // Add this break statement

    } // Close the switch statement
    decl_typecheck(d->next);
}


void global_array_hander(struct expr * e){
    if (!e) return;
    if ((e->kind == EXPR_ARRAY_BRACES) || (e->kind == EXPR_LIST)){
        e = e->right;
    }
    if (e->right){
        fprintf(file, "%d, ", e->int_literal);
        e = e->right;
    }
    fprintf(file, "%d\n", e->int_literal);

}

void global_decl_hander(struct decl * d){
    switch (d->type->kind){
        case TYPE_INTEGER:
            if (d->value){
                fprintf(file, ".quad %d\n", d->value->int_literal);
            }
            else{
                fprintf(file, ".quad 0\n");
            }
            break;
        case TYPE_CHAR:
            if (d->value){
                fprintf(file, ".quad '%c'\n", char_decode2(d->value->string_literal));
            }
            else{
                fprintf(file, ".quad 0\n");
            }
            break;
        case TYPE_ARRAY:
            if (d->type->subtype->kind != TYPE_INTEGER){
                fprintf(file, "codegen error: array subtype must be integer\n");
                return;
            }
            global_array_hander(d->value->right);
            break;
        case TYPE_BOOLEAN:
            if (d->value){
                fprintf(file, ".quad %d\n", d->value->bool_literal);
            }
            else{
                fprintf(file, ".quad 0\n");
            }
            break;
        case TYPE_STRING:
            fprintf(file, ".string %s\n", d->value->string_literal);
            break;
        case TYPE_FLOAT:
            fprintf(file, "codegen error: floating not supported\n");
            break;
        default:
            break;

    }

}



void func_preamble(){
    //changing stack pointer and base pointer
    fprintf(file, "PUSHQ %%rbp\n");
    fprintf(file, "MOVQ %%rsp, %%rbp\n");

    //pushing function arguments onto stack 
    fprintf(file, "PUSHQ %%rdi\n");
    fprintf(file, "PUSHQ %%rsi\n");
    fprintf(file, "PUSHQ %%rdx\n");
    fprintf(file, "PUSHQ %%rcx\n");
    fprintf(file, "PUSHQ %%r8\n");
    fprintf(file, "PUSHQ %%r9\n");

}


void func_postamble(){
    //changing stack pointer and base pointer

    //pushing function arguments onto stack 
    fprintf(file, "POPQ %%r9\n");
    fprintf(file, "POPQ %%r8\n");
    fprintf(file, "POPQ %%rcx\n");
    fprintf(file, "POPQ %%rdx\n");
    fprintf(file, "POPQ %%rsi\n");
    fprintf(file, "POPQ %%rdi\n");

    fprintf(file, "POPQ %%rbp\n");
    fprintf(file, "RET\n");

}


int global_func_counter_codegen = 0;
void decl_codegen(struct decl *d){

    if (!d) return;
    
    if (d->type->kind == TYPE_FUNCTION){
        global_func_counter_codegen = 0;
        fprintf(file, ".text\n");
        fprintf(file, ".global %s\n", d->name);
        fprintf(file, "%s:\n", d->name);
        func_preamble();
        stmt_codegen(d->code, d->name);

        fprintf(file, "SUBQ $%d, %%rsp\n", 8 *global_func_counter_codegen);
        
        func_postamble();
    }
    else if (d->symbol->kind == SYMBOL_GLOBAL){  
        fprintf(file, ".data\n");
        fprintf(file, "%s: \n", d->name);
        global_decl_hander(d);
    }
    else{
        if (d->type->kind != TYPE_ARRAY){
            global_func_counter_codegen += 1;
            if (d->value){
                expr_codegen(d->value, d->name);
                fprintf(file, "PUSHQ %s\n", scratch_name(d->value->reg));
            }
            else{
                fprintf(file, "SUBQ $8, %%rsp\n");
            }
        }
        else{
            fprintf(file, "cannot implement array locally\n");
        }
    }

    decl_codegen(d->next);
    
}