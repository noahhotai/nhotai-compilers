#include "expr.h"
#include <stdlib.h>
#include <string.h>
#include "type.h"


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

// expr_list_check(e->left){

// }

void expr_print(struct expr *e ){

    // printf("expr print\n");
    // printf("%d\n", e->kind);
    if (!e){
        return;
    }
    // printf("expr_print");
    switch (e->kind) {
        case EXPR_ADD:
            // printf("ecpr_add");
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
    // expr_print(e->next);

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
                printf("%s resolves to global %s\n", symbol_val->name, symbol_val->name);
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
                // type error: cannot add a string ("abc") to an integer (3+5) //      "%s") to an integer (3+5)", );
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
                // type error: cannot add a string ("abc") to an integer (3+5) //      "%s") to an integer (3+5)", );
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
                // type error: cannot add a string ("abc") to an integer (3+5) //      "%s") to an integer (3+5)", );
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
                // type error: cannot add a string ("abc") to an integer (3+5) //      "%s") to an integer (3+5)", );
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
                // type error: cannot add a string ("abc") to an integer (3+5) //      "%s") to an integer (3+5)", );
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
                // type error: cannot add a string ("abc") to an integer (3+5) //      "%s") to an integer (3+5)", );
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
            // printf("herrrreeeeeeee");
            if (!(( lt->kind == TYPE_INTEGER && rt->kind == TYPE_INTEGER) || (lt->kind==TYPE_FLOAT && rt->kind == TYPE_FLOAT))){
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
        case EXPR_GT:
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
            printf("expr-assign");
            if (rt->kind == TYPE_ARRAY){
                typecheck_error = 1;
                printf("type error: cannot assign array type ");
                expr_print(e->right);
                printf(".\n");
                // array_content_check(lt, e->right);
            }
            else if (!type_check(lt, rt)){
                typecheck_error = 1;
                printf("type error: cannot assign type ");
                type_print(rt);
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
                type_print(lt);
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
                type_print(lt);
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
            result = type_create(TYPE_STRING,0,0, 0);
            break;
        case EXPR_IDENT:
            result = type_copy(e->symbol->type);
            break;
        case EXPR_ARRAY_ACCESS:
            if (lt->kind != TYPE_ARRAY){
                typecheck_error = 1;
                printf("type error: while dereferencing %s, not of type array.\n", e->ident);
                result = type_copy(e->symbol->type);
            }
            else{
                // if !(
                result = array_access_func(lt, e->right);
                // result = type_copy(e->symbol->type->);
            }
            break;
        case EXPR_FUNC_CALL:
            if (lt->kind != TYPE_FUNCTION){
                result = type_copy(lt);
            }
            else{
                result = type_copy(lt->subtype);
                func_arguments_type_check(e->right, lt->params, e->left->ident);
                if (!e->left->symbol->has_code){
                    typecheck_error = 1;
                    printf("type error: function (%s) has not been defined\n", e->ident);
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
            // if (type_check(lt, rt)){
            //     printf("array elements are not subtype\n");
            // }
            result = type_copy(lt);
            break;
        case EXPR_NESTED_BRACES:
            // printf("hererere");
            result = type_create(TYPE_ARRAY, lt, 0, 0);
            break;
        case EXPR_PAREN:
            // printf("expr paren\n");
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
            // printf("{");
            // expr_print(e->left);
            // printf("}");
        case EXPR_INC:
            break;
        case EXPR_DEC:
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

