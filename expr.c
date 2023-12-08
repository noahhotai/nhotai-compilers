#include "expr.h"
#include <stdlib.h>
#include <string.h>
#include "type.h"
#include "codegen.h"

extern FILE* file;
char* arg_regs[6] = {"%rdi", "%rsi", "%rdx", "%rcx", "%r8", "%r9"};

struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right ){
    struct expr *d = calloc(1, sizeof(struct expr));
    d->kind = kind;
    d->left= left;
    d->right = right;
    return d;
}

struct expr * expr_create_ident( char *n ){
    struct expr* d = expr_create(EXPR_IDENT, 0, 0);
    d->ident = n;
    return d;
}

struct expr * expr_create_integer_literal( int c ){
    struct expr* d = expr_create(EXPR_INT, 0, 0);
    d->int_literal = c;
    return d;
}

struct expr * expr_create_float_literal( float c ){
    struct expr* d = expr_create(EXPR_FLOAT, 0, 0);
    d->float_literal = c;
    return d;
}

struct expr * expr_create_boolean_literal( int c ){
    struct expr* d = expr_create(EXPR_BOOL, 0, 0);
    d->bool_literal = c;
    return d;
}

struct expr * expr_create_char_literal(char *c ){
    struct expr* d = expr_create(EXPR_CHAR, 0, 0);
    d->string_literal = strdup(c);
    return d;
}

struct expr * expr_create_string_literal( char *str ){
    struct expr* d = expr_create(EXPR_STRING, 0, 0);
    d->string_literal = strdup(str);
    return d;
}
void func_call_args_reg_fixer(struct expr * e, int num){

    if (!e) return;
    if (e->kind == EXPR_LIST){
        func_call_args_reg_fixer(e->left, num);
        func_call_args_reg_fixer(e->right, num + 1);
    }
    else{
        if (num == 6){
            fprintf(file, "Too many arguments given.\n");
            return;
        }
        expr_codegen(e, 0);
        fprintf(file, "MOVQ %s, %s\n", scratch_name(e->reg), arg_regs[num]);
        scratch_free(e->reg);
        func_call_args_reg_fixer(e->right, num + 1);
    }
}


void expr_print(struct expr *e ){


    if (!e){
        return;
    }

    switch (e->kind) {
        case EXPR_ADD:
            expr_print(e->left);
            printf("+");
            expr_print(e->right);
            break;
        case EXPR_SUB:
            expr_print(e->left);
            printf("-");
            expr_print(e->right);
            break;
        case EXPR_MUL:
            expr_print(e->left);
            printf("*");
            expr_print(e->right);
            break;
        case EXPR_MOD:
            expr_print(e->left);
            printf("%%");
            expr_print(e->right);
            break;
        case EXPR_DIV:
            expr_print(e->left);
            printf("/");
            expr_print(e->right);
            break;
        case EXPR_EXP:
            expr_print(e->left);
            printf("^");
            expr_print(e->right);
            break;
        case EXPR_NEG:
            printf("-");
            expr_print(e->left);
            break;
        case EXPR_LTE:
            expr_print(e->left);
            printf("<=");
            expr_print(e->right);
            break;
        case EXPR_GTE:
            expr_print(e->left);
            printf(">=");
            expr_print(e->right);
            break;
        case EXPR_LT:
            expr_print(e->left);
            printf("<");
            expr_print(e->right);
            break;
        case EXPR_GT:
            expr_print(e->left);
            printf(">");
            expr_print(e->right);
            break;
        case EXPR_EQ:
            expr_print(e->left);
            printf("==");
            expr_print(e->right);
            break;
        case EXPR_NOT:
            printf("!");
            expr_print(e->left);
            expr_print(e->right);
            break;
        case EXPR_NOT_EQ:
            expr_print(e->left);
            printf("!=");
            expr_print(e->right);
            break;
        case EXPR_PAREN:
            printf("(");
            expr_print(e->left);
            printf(")");
            expr_print(e->right);
            break;
        case EXPR_ASSIGN:
            expr_print(e->left);
            printf("=");
            expr_print(e->right);
            break;
        case EXPR_AND:
            expr_print(e->left);
            printf("&&");
            expr_print(e->right);
            break;
        case EXPR_OR:
            expr_print(e->left);
            printf("||");
            expr_print(e->right);
            break;
        case EXPR_INT:
            printf("%d", e->int_literal);
            break;
        case EXPR_FLOAT:
            printf("%f", e->float_literal);
            break;
        case EXPR_BOOL:
            if (e->bool_literal){
                printf("true");
            }
            else{
                printf("false");
            }
            break;
        case EXPR_CHAR:
            printf("%s", e->string_literal);
            break;
        case EXPR_STRING:
            printf("%s", e->string_literal);
            break;
        case EXPR_IDENT:
            printf("%s", e->ident);
            break;
        case EXPR_ARRAY_ACCESS:
            expr_print(e->left);
            expr_print(e->right);
            break;
        case EXPR_FUNC_CALL:
            expr_print(e->left);
            printf("(");
            expr_print(e->right);
            printf(")");
            break;
        case EXPR_NESTED_ARRAY_ACCESS:
            printf("[");
            expr_print(e->left);
            printf("]");
            expr_print(e->right);
            break;
        case EXPR_LIST:
            expr_print(e->left);
            if (e->right){
                printf(", ");
                expr_print(e->right);
            }
            break;
        case EXPR_NESTED_BRACES:
            printf("{");
            expr_print(e->left);
            printf("}");
            if (e->right){
                printf(",");
                expr_print(e->right);
            }
            break;
        case EXPR_POS:
            printf("+");
            expr_print(e->left);
            break;
        case EXPR_INC:
            expr_print(e->left);
            printf("++");
            expr_print(e->right);
            break;
        case EXPR_DEC:
            expr_print(e->left);
            printf("--");
            expr_print(e->right);
            break;
        case EXPR_ARRAY_BRACES:
            printf("{");
            expr_print(e->left);
            printf("}");
        default:
            break;
    }


}

void expr_resolve( struct expr *e ){
    extern int resolve_error;
    if(!e) return;
    if( e->kind==EXPR_IDENT) {
        // printf("EXPR_IDENT");
        struct symbol* symbol_val = scope_lookup(e->ident);
        if (!symbol_val){
            printf("resolve error: %s is not defined\n", e->ident);
            resolve_error = 1;
        }
        else{
            if (symbol_val->kind == SYMBOL_GLOBAL){
                printf("%s resolves to global %d\n", symbol_val->name, symbol_val->which);
                // printf(" dfkldfjhskldjfkjsd.hf .\n");
            }
            else if (symbol_val->kind == SYMBOL_PARAM){
                printf("%s resolves to param %d\n", symbol_val->name, symbol_val->which);
            }
            else if (symbol_val->kind == SYMBOL_LOCAL) {
                printf("%s resolves to local %d\n", symbol_val->name, symbol_val->which);
            }
            e->symbol = symbol_val;

        }
    } 
    else {
        expr_resolve( e->left );
        expr_resolve( e->right );
    }
}


struct type * expr_typecheck( struct expr *e ){
    if(!e) return 0;
    extern int typecheck_error;
    struct type *lt = expr_typecheck(e->left);
    struct type *rt = expr_typecheck(e->right);
    struct type *result;
    switch (e->kind) {
        case EXPR_ADD:
            if ( lt->kind ==TYPE_INTEGER && rt->kind == TYPE_INTEGER){
                result = type_create(TYPE_INTEGER, 0, 0, 0);
            }
            else if (lt->kind==TYPE_FLOAT && rt->kind == TYPE_FLOAT){
                result = type_create(TYPE_FLOAT, 0, 0, 0 );
            }
            else{
                typecheck_error = 1;
                printf("type error: cannot add a ");
                type_print(lt);
                printf(" (");
                expr_print(e->left);
                printf(") by an ");
                type_print(rt);
                printf(" (");
                expr_print(e->right);
                printf(").\n");    
                result = type_create(TYPE_INTEGER, 0, 0, 0 );
            }
            break;
        case EXPR_SUB:
            if ( lt->kind ==TYPE_INTEGER && rt->kind == TYPE_INTEGER){
                result = type_create(TYPE_INTEGER, 0, 0, 0);
            }
            else if (lt->kind==TYPE_FLOAT && rt->kind == TYPE_FLOAT){
                result = type_create(TYPE_FLOAT, 0, 0, 0 );
            }
            else{
                typecheck_error = 1;
                printf("type error: cannot subtract a ");
                type_print(lt);
                printf(" (");
                expr_print(e->left);
                printf(") by an ");
                type_print(rt);
                printf(" (");
                expr_print(e->right);
                printf(").\n");    
                result = type_create(TYPE_INTEGER, 0, 0, 0 );
            }
            break;
        case EXPR_MUL:
            if ( lt->kind ==TYPE_INTEGER && rt->kind == TYPE_INTEGER){
                result = type_create(TYPE_INTEGER, 0, 0, 0);
            }
            else if (lt->kind==TYPE_FLOAT && rt->kind == TYPE_FLOAT){
                result = type_create(TYPE_FLOAT, 0, 0, 0 );
            }
            else{
                typecheck_error = 1;
                printf("type error: cannot multiply a ");
                type_print(lt);
                printf(" (");
                expr_print(e->left);
                printf(") by an ");
                type_print(rt);
                printf(" (");
                expr_print(e->right);
                printf(").\n");    
                result = type_create(TYPE_INTEGER, 0, 0, 0 );
            }
            break;
        case EXPR_MOD:
            if ( lt->kind ==TYPE_INTEGER && rt->kind == TYPE_INTEGER){
                result = type_create(TYPE_INTEGER, 0, 0, 0);
            }
            else if (lt->kind==TYPE_FLOAT && rt->kind == TYPE_FLOAT){
                result = type_create(TYPE_FLOAT, 0, 0, 0 );
            }
            else{
                typecheck_error = 1;
                printf("type error: cannot modulo a ");
                type_print(lt);
                printf(" (");
                expr_print(e->left);
                printf(") by an ");
                type_print(rt);
                printf(" (");
                expr_print(e->right);
                printf(").\n");    
                result = type_create(TYPE_INTEGER, 0, 0, 0 );
            }
            break;
        case EXPR_DIV:
            if ( lt->kind ==TYPE_INTEGER && rt->kind == TYPE_INTEGER){
                result = type_create(TYPE_INTEGER, 0, 0, 0);
            }
            else if (lt->kind==TYPE_FLOAT && rt->kind == TYPE_FLOAT){
                result = type_create(TYPE_FLOAT, 0, 0, 0 );
            }
            else{
                typecheck_error = 1;
                printf("type error: cannot divide a ");
                type_print(lt);
                printf(" (");
                expr_print(e->left);
                printf(") by an ");
                type_print(rt);
                printf(" (");
                expr_print(e->right);
                printf(").\n");    
                result = type_create(TYPE_INTEGER, 0, 0, 0 );
            }
            break;
        case EXPR_EXP:
            if ( lt->kind ==TYPE_INTEGER && rt->kind == TYPE_INTEGER){
                result = type_create(TYPE_INTEGER, 0, 0, 0);
            }
            else if (lt->kind==TYPE_FLOAT && rt->kind == TYPE_FLOAT){
                result = type_create(TYPE_FLOAT, 0, 0, 0 );
            }
            else{
                typecheck_error = 1;
                printf("type error: cannot exponentiate a ");
                type_print(lt);
                printf(" (");
                expr_print(e->left);
                printf(") by an ");
                type_print(rt);
                printf(" (");
                expr_print(e->right);
                printf(").\n");    
                result = type_create(TYPE_INTEGER, 0, 0, 0 );
            }
            break;
        case EXPR_NEG:
            if (lt->kind!=TYPE_INTEGER && lt->kind!=TYPE_FLOAT){
                typecheck_error = 1;
                printf("neg type error\n");
                result =  type_create(TYPE_INTEGER, 0, 0, 0);
            }
            else{
                result =  type_create(lt->kind, 0, 0, 0);
            }
            break;
        case EXPR_LTE:
            if (!(( lt->kind ==TYPE_INTEGER && rt->kind == TYPE_INTEGER) || (lt->kind==TYPE_FLOAT && rt->kind == TYPE_FLOAT))){
                typecheck_error = 1;
                printf("type error: cannot compare a ");
                type_print(lt);
                printf(" (");
                expr_print(e->left);
                printf(") with a ");
                type_print(rt);
                printf(" (");
                expr_print(e->right);
                printf(").\n");    
            }
            result = type_create(TYPE_BOOLEAN,0,0, 0);
            break;
        case EXPR_GTE:
            if (!(( lt->kind ==TYPE_INTEGER && rt->kind == TYPE_INTEGER) || (lt->kind==TYPE_FLOAT && rt->kind == TYPE_FLOAT))){
                // result = type_create(TYPE_INTEGER, 0, 0, 0);
                // type error: cannot add a string ("abc") to an integer (3+5) //      "%s") to an integer (3+5)", );
                typecheck_error = 1;
                printf("type error: cannot compare a ");
                type_print(lt);
                printf(" (");
                expr_print(e->left);
                printf(") with a ");
                type_print(rt);
                printf(" (");
                expr_print(e->right);
                printf(").\n");    
            }
            result = type_create(TYPE_BOOLEAN,0,0, 0);
            break;
        case EXPR_LT:
            if (!(( lt->kind == TYPE_INTEGER && rt->kind == TYPE_INTEGER) || (lt->kind==TYPE_FLOAT && rt->kind == TYPE_FLOAT))){
                typecheck_error = 1;
                printf("type error: cannot compare a ");
                type_print(lt);
                printf(" (");
                expr_print(e->left);
                printf(") with a ");
                type_print(rt);
                printf(" (");
                expr_print(e->right);
                printf(").\n");    
            }
            result = type_create(TYPE_BOOLEAN,0,0, 0);
            break;
        case EXPR_GT:
            if (!(( lt->kind ==TYPE_INTEGER && rt->kind == TYPE_INTEGER) || (lt->kind==TYPE_FLOAT && rt->kind == TYPE_FLOAT))){
                typecheck_error = 1;
                printf("type error: cannot compare a ");
                type_print(lt);
                printf(" (");
                expr_print(e->left);
                printf(") with a ");
                type_print(rt);
                printf(" (");
                expr_print(e->right);
                printf(").\n");    
            }
            result = type_create(TYPE_BOOLEAN,0,0, 0);
            break;
        case EXPR_EQ:
            if (!type_check(lt, rt)){
                typecheck_error = 1;
                printf("type error comparing different types\n");
            }
            if (lt->kind == TYPE_VOID || lt->kind == TYPE_FUNCTION || lt->kind == TYPE_ARRAY ){
                typecheck_error = 1;
                printf("type error: bad comparison\n");
            }
            result = type_create(TYPE_BOOLEAN, 0, 0, 0);
            break;
        case EXPR_NOT:
            if (lt->kind != TYPE_BOOLEAN){
                typecheck_error = 1;
                printf("type error: cannot use operation not with type ");
                type_print(lt);
                printf("(");
                expr_print(e);
                printf(").\n");

            }
            result = type_create(TYPE_BOOLEAN, 0, 0, 0);
            break;
        case EXPR_NOT_EQ:
            if (!type_check(lt, rt)){
                typecheck_error = 1;
                printf("type error comparing different types\n");
            }
            if (lt->kind == TYPE_VOID || lt->kind == TYPE_FUNCTION || lt->kind == TYPE_ARRAY ){
                typecheck_error = 1;
                printf("type error bad_comparison\n");
            }
            result = type_create(TYPE_BOOLEAN, 0, 0, 0);
            break;
        case EXPR_ASSIGN:
            if (!type_check(lt, rt)){
                typecheck_error = 1;
                printf("type error: cannot assign type ");
                type_print(lt);
                printf(" (");
                expr_print(e->right);
                printf(") to type ");
                type_print(rt);
                printf(" (");
                expr_print(e->left);
                printf(").\n");
            }
            result = type_create(lt->kind, 0, 0, 0);
            break;
        case EXPR_AND:
            if (lt->kind != TYPE_BOOLEAN || !type_check(lt, rt)){
                typecheck_error = 1;
                printf("type error: cannot operation and a ");
                type_print(lt);
                printf(" (");
                expr_print(e->left);
                printf(") with a ");
                type_print(rt);
                printf(" (");
                expr_print(e->right);
                printf(").\n");
            }
            result = type_create(TYPE_BOOLEAN,0,0, 0);
            break;
        case EXPR_OR:
            if (lt->kind != TYPE_BOOLEAN || !type_check(lt, rt)){
                typecheck_error = 1;
                printf("type error: cannot operation or a ");
                type_print(lt);
                printf(" (");
                expr_print(e->left);
                printf(") with a ");
                type_print(rt);
                printf(" (");
                expr_print(e->right);
                printf(").\n");
            }
            result = type_create(TYPE_BOOLEAN,0,0, 0);
            break;
        case EXPR_INT:
            result = type_create(TYPE_INTEGER,0,0, 0);
            break;
        case EXPR_FLOAT:
            result = type_create(TYPE_FLOAT,0,0, 0);
            break;
        case EXPR_BOOL:
            result = type_create(TYPE_BOOLEAN,0,0, 0);
            break;
        case EXPR_CHAR:
            result = type_create(TYPE_CHAR, 0,0, 0);
            break;
        case EXPR_STRING:
            // printf("EXPR_STRING");
            result = type_create(TYPE_STRING,0,0, 0);
            break;
        case EXPR_IDENT:
            if (e->symbol){
                result = type_copy(e->symbol->type);
            }
            else{
                result = type_create(TYPE_INTEGER,0,0, 0);
            }
            break;
        case EXPR_ARRAY_ACCESS:
            if (lt->kind != TYPE_ARRAY){
                typecheck_error = 1;
                printf("type error: while dereferencing %s, not of type array.\n", e->left->ident);
                result = type_create(TYPE_INTEGER,0,0, 0);
            }
            else{
                result = array_access_func(lt, e->right);
            }
            break;
        case EXPR_FUNC_CALL:
            if (lt->kind != TYPE_FUNCTION){
                result = type_copy(lt);
            }
            else{
                if (e->left->symbol){
                    result = type_copy(lt->subtype);
                    if (!func_arguments_type_check(e->right, lt->params, e->left->ident)){
                        typecheck_error = 1;
                    }
                }
                else{
                    typecheck_error = 1;
                    printf("type error: function (%s) has not been declared\n", e->left->ident);
                }
            }
            break;
        case EXPR_NESTED_ARRAY_ACCESS:
            if (lt->kind != TYPE_INTEGER){
                typecheck_error = 1;
                printf("type error: ");
                // expr_print(e);
                printf("is not integer\n");
            }
            result = type_create(TYPE_INTEGER, 0, 0, 0);
            break;
        case EXPR_LIST:
            result = type_create(TYPE_INTEGER, 0, 0, 0);
            break;
        case EXPR_NESTED_BRACES:
            result = type_create(TYPE_ARRAY, type_copy(lt), 0, 0);
            break;
        case EXPR_PAREN:
            result = type_copy(lt);
            break;
        case EXPR_POS:
            if (lt->kind!=TYPE_INTEGER && lt->kind!=TYPE_FLOAT){
                typecheck_error = 1;
                printf("type error: cannot apply positive operation to type %s.\n", e->ident);
                type_create(TYPE_INTEGER, 0, 0, 0);
                result =  type_create(TYPE_INTEGER, 0, 0, 0);
            }
            else{
                result =  type_create(lt->kind, 0, 0, 0);
            }
            break;
        case EXPR_ARRAY_BRACES:
            result = type_create(TYPE_ARRAY, lt, 0, 0);
            break;
        case EXPR_INC:
            if (lt->kind != TYPE_INTEGER){
                typecheck_error = 1;
                printf("type error: cannot increment ");
                type_print(lt);
                printf(" (");
                expr_print(e->left);
                printf(")\n");
            }
            result = type_create(TYPE_INTEGER, 0, 0, 0);
            break;
        case EXPR_DEC:
            if (lt->kind != TYPE_INTEGER){
                typecheck_error = 1;
                printf("type error: cannot decrement ");
                type_print(lt);
                printf(" (");
                expr_print(e->left);
                printf(")\n");
            }
            result = type_create(TYPE_INTEGER, 0, 0, 0);
            break;
    }
    if (lt){
        type_delete(lt);
    }
    if (rt){
        type_delete(rt);
    }

    return result;
    }


struct type * expr_typecheck_global( struct expr *e ){
    if(!e) return 0;
    struct type * lt = expr_typecheck_global(e->left);
    extern int typecheck_error;
    struct type *result;

    switch (e->kind) {
        case EXPR_INT:
            result = type_create(TYPE_INTEGER,0,0, 0);
            break;
        case EXPR_FLOAT:
            result = type_create(TYPE_FLOAT,0,0, 0);
            break;
        case EXPR_BOOL:
            result = type_create(TYPE_BOOLEAN,0,0, 0);
            break;
        case EXPR_CHAR:
            result = type_create(TYPE_CHAR, 0,0, 0);
            break;
        case EXPR_STRING:
            result = type_create(TYPE_STRING,0,0, 0);
            break;
        case EXPR_POS:
            if (lt->kind!=TYPE_INTEGER && lt->kind!=TYPE_FLOAT){
                typecheck_error = 1;
                printf("type error: cannot apply positive operation to type %s.\n", e->ident);
                type_create(TYPE_INTEGER, 0, 0, 0);
                result =  type_create(TYPE_INTEGER, 0, 0, 0);
            }
            else{
                result =  type_create(lt->kind, 0, 0, 0);
            }
            break;

        case EXPR_NEG:
            if (lt->kind!=TYPE_INTEGER && lt->kind!=TYPE_FLOAT){
                typecheck_error = 1;
                printf("type error: cannot apply positive operation to type %s.\n", e->ident);
                type_create(TYPE_INTEGER, 0, 0, 0);
                result =  type_create(TYPE_INTEGER, 0, 0, 0);
            }
            else{
                result =  type_create(lt->kind, 0, 0, 0);
            }
            break;

        default:
            typecheck_error = 1;
            printf("type error: only atomic types allowed to be declared globally\n");
            result = type_create(TYPE_CHAR, 0, 0, 0);
    }

    return result;
}


void expr_codegen(struct expr *e, char* function_name){

    if(!e) return;
    int true_label;
    int done_label;
    switch(e->kind) {
// Leaf node: allocate register and load value.
    // m D(RA, RB, C) w
        case EXPR_IDENT:
            e->reg = scratch_alloc();
            fprintf(file, "MOVQ %s, %s\n",
            symbol_codegen(e->symbol),
            scratch_name(e->reg));
            break;
    // Interior node: generate children, then add them.
        case EXPR_ADD:
            expr_codegen(e->left, function_name);
            expr_codegen(e->right, function_name);
            fprintf(file, "ADDQ %s, %s\n",
            scratch_name(e->left->reg),
            scratch_name(e->right->reg));
            e->reg = e->right->reg;
            scratch_free(e->left->reg);
            break;
        case EXPR_ASSIGN:
            if (e->left->kind != EXPR_ARRAY_ACCESS){
                expr_codegen(e->right, function_name);
                fprintf(file, "MOVQ %s, %s\n",
                scratch_name(e->right->reg),
                symbol_codegen(e->left->symbol));
                e->reg = e->right->reg;
            }
            else{
                
                expr_codegen(e->right, function_name);

                e->left->reg = scratch_alloc();
                fprintf(file, "LEAQ %s, %s\n", symbol_codegen(e->left->left->symbol), scratch_name(e->left->reg));

                expr_codegen(e->left->right, function_name);
                fprintf(file, "MOVQ $8, %%rax\n");
                fprintf(file, "IMULQ %s\n", scratch_name(e->left->right->reg));
                fprintf(file, "MOVQ %%rax, %s\n", scratch_name(e->left->right->reg));

                fprintf(file, "ADDQ %s, %s\n", scratch_name(e->left->right->reg), scratch_name(e->left->reg));
                scratch_free(e->left->right->reg);

                fprintf(file, "MOVQ %s, (%s)\n", scratch_name(e->right->reg),scratch_name(e->left->reg));

                e->reg = e->right->reg;
            }

            break;
        case EXPR_SUB:
            expr_codegen(e->left, function_name);
            expr_codegen(e->right, function_name);
            fprintf(file, "SUBQ %s, %s\n",
            scratch_name(e->right->reg),
            scratch_name(e->left->reg));
            e->reg = e->left->reg;
            scratch_free(e->right->reg);
            break;
        case EXPR_MUL:
            expr_codegen(e->left, function_name);
            expr_codegen(e->right, function_name);

            // calculating multiplication
            fprintf(file, "MOVQ %s, %%rax\n", scratch_name(e->right->reg)); 
            fprintf(file, "IMULQ %s\n", scratch_name(e->left->reg));     

            // free right side register
            scratch_free(e->right->reg);
            
            //moving answer to left register
            fprintf(file, "MOVQ %%rax, %s\n", scratch_name(e->left->reg)); 

            // setting current register to left
            e->reg = e->left->reg;
            break;
        case EXPR_MOD:
            expr_codegen(e->left, function_name);
            expr_codegen(e->right, function_name);

            // calculating multiplication
            fprintf(file, "MOVQ %s, %%rax\n", scratch_name(e->left->reg)); 
            fprintf(file, "CQO\n");
            fprintf(file, "IDIVQ %s\n", scratch_name(e->right->reg));     

            // free right side register
            scratch_free(e->right->reg);
            
            //moving answer to left register
            fprintf(file, "MOVQ %%rdx, %s\n", scratch_name(e->left->reg)); 

            // setting current register to left
            e->reg = e->left->reg; 
            break;
        case EXPR_DIV:
            expr_codegen(e->left, function_name);
            expr_codegen(e->right, function_name);

            // calculating multiplication
            fprintf(file, "MOVQ %s, %%rax\n", scratch_name(e->left->reg)); 
            fprintf(file, "CQO\n");
            fprintf(file, "IDIVQ %s\n", scratch_name(e->right->reg));     

            // free right side register
            scratch_free(e->right->reg);
            
            //moving answer to left register
            fprintf(file, "MOVQ %%rax, %s\n", scratch_name(e->left->reg)); 

            // setting current register to left
            e->reg = e->left->reg; 
            break;
        case EXPR_EXP:
            expr_codegen(e->left, function_name);
            expr_codegen(e->right, function_name);
            fprintf(file, "MOVQ %s, %%rdi\n", scratch_name(e->left->reg)); 
            fprintf(file, "MOVQ %s, %%rsi\n", scratch_name(e->right->reg)); 
            fprintf(file, "CALL integer_power\n");
            fprintf(file, "MOVQ %%rax, %s\n", scratch_name(e->left->reg)); 
            scratch_free(e->right->reg);
            e->reg = e->left->reg;
            break;
        case EXPR_NEG:
            expr_codegen(e->left, function_name);

            // calculating multiplication
            fprintf(file, "MOVQ $-1, %%rax\n"); 
            fprintf(file, "IMULQ %s\n", scratch_name(e->left->reg));     
        
            //moving answer to left register
            fprintf(file, "MOVQ %%rax, %s\n", scratch_name(e->left->reg)); 

            // setting current register to left
            e->reg = e->left->reg;
            break;
        case EXPR_LTE:

            expr_codegen(e->left, function_name);
            expr_codegen(e->right, function_name);
            fprintf(file, "CMPQ %s, %s\n", scratch_name(e->right->reg), scratch_name(e->left->reg));

            true_label = label_create();
            done_label = label_create();
            fprintf(file, "JLE %s\n", label_name(true_label));

            fprintf(file, "MOVQ $0, %s\n", scratch_name(e->left->reg));
            fprintf(file, "JMP %s\n", label_name(done_label));

            fprintf(file, "%s:\n", label_name(true_label));

            fprintf(file, "MOVQ $1, %s\n", scratch_name(e->left->reg));
            fprintf(file, "%s:\n", label_name(done_label));

            scratch_free(e->right->reg);
            e->reg = e->left->reg;
            break;
        case EXPR_GTE:
            expr_codegen(e->left, function_name);
            expr_codegen(e->right, function_name);
            fprintf(file, "CMPQ %s, %s\n", scratch_name(e->right->reg), scratch_name(e->left->reg));

            true_label = label_create();
            done_label = label_create();
            fprintf(file, "JGE %s\n", label_name(true_label));

            fprintf(file, "MOVQ $0, %s\n", scratch_name(e->left->reg));
            fprintf(file, "JMP %s\n", label_name(done_label));

            fprintf(file, "%s:\n", label_name(true_label));

            fprintf(file, "MOVQ $1, %s\n", scratch_name(e->left->reg));
            fprintf(file, "%s:\n", label_name(done_label));

            scratch_free(e->right->reg);
            e->reg = e->left->reg;
            break;
        case EXPR_LT:
            expr_codegen(e->left, function_name);
            expr_codegen(e->right, function_name);
            fprintf(file, "CMPQ %s, %s\n", scratch_name(e->right->reg), scratch_name(e->left->reg));

            true_label = label_create();
            done_label = label_create();
            fprintf(file, "JL %s\n", label_name(true_label));

            fprintf(file, "MOVQ $0, %s\n", scratch_name(e->left->reg));
            fprintf(file, "JMP %s\n", label_name(done_label));

            fprintf(file, "%s:\n", label_name(true_label));

            fprintf(file, "MOVQ $1, %s\n", scratch_name(e->left->reg));
            fprintf(file, "%s:\n", label_name(done_label));

            scratch_free(e->right->reg);
            e->reg = e->left->reg;
            break;
        case EXPR_GT:
            expr_codegen(e->left, function_name);
            expr_codegen(e->right, function_name);
            fprintf(file, "CMPQ %s, %s\n", scratch_name(e->right->reg), scratch_name(e->left->reg));

            true_label = label_create();
            done_label = label_create();
            fprintf(file, "JG %s\n", label_name(true_label));

            fprintf(file, "MOVQ $0, %s\n", scratch_name(e->left->reg));
            fprintf(file, "JMP %s\n", label_name(done_label));

            fprintf(file, "%s:\n", label_name(true_label));

            fprintf(file, "MOVQ $1, %s\n", scratch_name(e->left->reg));
            fprintf(file, "%s:\n", label_name(done_label));

            scratch_free(e->right->reg);
            e->reg = e->left->reg;
            break;
        case EXPR_EQ:
            expr_codegen(e->left, function_name);
            expr_codegen(e->right, function_name);
            fprintf(file, "CMPQ %s, %s\n", scratch_name(e->right->reg), scratch_name(e->left->reg));

            true_label = label_create();
            done_label = label_create();
            fprintf(file, "JE %s\n", label_name(true_label));

            fprintf(file, "MOVQ $0, %s\n", scratch_name(e->left->reg));
            fprintf(file, "JMP %s\n", label_name(done_label));

            fprintf(file, "%s:\n", label_name(true_label));

            fprintf(file, "MOVQ $1, %s\n", scratch_name(e->left->reg));
            fprintf(file, "%s:\n", label_name(done_label));

            scratch_free(e->right->reg);
            e->reg = e->left->reg;
            break;
        case EXPR_NOT:
            expr_codegen(e->left, function_name);

            true_label = label_create();
            done_label = label_create();

            fprintf(file, "CMPQ $1, %s\n", scratch_name(e->left->reg));
            fprintf(file, "JE %s\n", label_name(true_label));
            fprintf(file, "MOVQ $1, %s\n", scratch_name(e->left->reg));
            fprintf(file, "JMP %s\n", label_name(done_label));
            fprintf(file, "%s:\n", label_name(true_label));
            fprintf(file, "MOVQ $0, %s\n", scratch_name(e->left->reg));
            fprintf(file, "%s:\n", label_name(done_label));
            e->reg = e->left->reg;
            break;
        case EXPR_NOT_EQ:
            expr_codegen(e->left, function_name);
            expr_codegen(e->right, function_name);
            fprintf(file, "CMPQ %s, %s\n", scratch_name(e->left->reg), scratch_name(e->right->reg));

            true_label = label_create();
            done_label = label_create();
            fprintf(file, "JNE %s\n", label_name(true_label));

            fprintf(file, "MOVQ $0, %s\n", scratch_name(e->left->reg));
            fprintf(file, "JMP %s\n", label_name(done_label));

            fprintf(file, "%s:\n", label_name(true_label));

            fprintf(file, "MOVQ $1, %s\n", scratch_name(e->left->reg));
            fprintf(file, "%s:\n", label_name(done_label));

            scratch_free(e->right->reg);
            e->reg = e->left->reg;
            break;
        case EXPR_PAREN:
            expr_codegen(e->left, function_name);
            e->reg = e->left->reg;
            break;
            break;
        case EXPR_AND:
            expr_codegen(e->left, function_name);
            expr_codegen(e->right, function_name);
            fprintf(file, "ANDQ %s, %s\n", scratch_name(e->left->reg), scratch_name(e->right->reg));

            // free right side register
            scratch_free(e->left->reg);
            e->reg = e->right->reg;
            break;
        case EXPR_OR:
            expr_codegen(e->left, function_name);
            expr_codegen(e->right, function_name);
            fprintf(file, "ORQ %s, %s\n", scratch_name(e->left->reg), scratch_name(e->right->reg));
            // free right side register
            scratch_free(e->left->reg);
            e->reg = e->right->reg;
            break;
        case EXPR_INT:
            e->reg = scratch_alloc();
            fprintf(file, "MOVQ $%d, %s\n", e->int_literal, scratch_name(e->reg));
            break;
        case EXPR_FLOAT:
            printf("cannot handle floats\n");
            break;
        case EXPR_BOOL:
            e->reg = scratch_alloc();
            fprintf(file, "MOVQ $%d, %s\n", e->bool_literal, scratch_name(e->reg));
            break;
        case EXPR_CHAR:
            e->reg = scratch_alloc();
            int temp = char_decode2(e->string_literal);
            fprintf(file, "MOVQ $%d, %s\n", temp, scratch_name(e->reg));
            break;
        case EXPR_STRING:
            string_data_handler(e, function_name);
            break;
        case EXPR_ARRAY_ACCESS:
            expr_codegen(e->right, function_name);
            e->reg = scratch_alloc();
            fprintf(file, "LEAQ %s, %s\n", symbol_codegen(e->left->symbol), scratch_name(e->reg));

            fprintf(file, "MOVQ $8, %%rax\n");
            fprintf(file, "IMULQ %s\n", scratch_name(e->right->reg));
            fprintf(file, "MOVQ %%rax, %s\n", scratch_name(e->right->reg));

            fprintf(file, "ADDQ %s, %s\n", scratch_name(e->right->reg), scratch_name(e->reg));
            
            fprintf(file, "MOVQ (%s), %s\n", scratch_name(e->reg), scratch_name(e->reg));
            scratch_free(e->right->reg);
            break;
        case EXPR_FUNC_CALL:
            expr_codegen(e->right, function_name);
            func_call_args_reg_fixer(e->right, 0);

            fprintf(file, "PUSHQ %%r10\n");
            fprintf(file, "PUSHQ %%r11\n");
            callee_preamble();
            fprintf(file, "CALL %s\n", e->left->ident);
            callee_postamble();
            fprintf(file, "POPQ %%r10\n");
            fprintf(file, "POPQ %%r11\n");
            e->reg = scratch_alloc();
            fprintf(file, "MOVQ %%rax, %s\n", scratch_name(e->reg));
            break;
        case EXPR_NESTED_ARRAY_ACCESS:
            expr_codegen(e->left, function_name);
            e->reg = e->left->reg;
            break;
        case EXPR_LIST:
            break;
        case EXPR_NESTED_BRACES:
            break;
        case EXPR_POS:
            expr_codegen(e->left, function_name);
            e->reg = e->left->reg;
            break;
        case EXPR_INC:
            expr_codegen(e->left, function_name);
            e->reg = e->left->reg;
            fprintf(file, "INCQ %s\n", symbol_codegen(e->left->symbol));
            break;
        case EXPR_DEC:    
            expr_codegen(e->left, function_name);
            e->reg = e->left->reg;
            fprintf(file, "DECQ %s\n", symbol_codegen(e->left->symbol));
            break;
        case EXPR_ARRAY_BRACES:

            break;
        default:
            break;
    }
}

