#include "expr.h"
#include <stdlib.h>
#include <string.h>


struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right ){
    struct expr *d = calloc(1, sizeof(struct expr));
    d->kind = kind;
    d->left= left;
    d->right = right;
    return d;
}

struct expr * expr_create_ident( const char *n ){
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

struct expr * expr_create_string_literal( const char *str ){
    struct expr* d = expr_create(EXPR_STRING, 0, 0);
    d->string_literal = strdup(str);
    return d;
}

void expr_print(struct expr *e ){


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
        }
    } 
    else {
        expr_resolve( e->left );
        expr_resolve( e->right );
    }
}


// struct type * expr_typecheck( struct expr *e ){
//     if(!e) return 0;
//     struct type *lt = expr_typecheck(e->left);
//     struct type *rt = expr_typecheck(e->right);
//     struct type *result;

//     switch (e->kind) {
//         case EXPR_ADD:
//             if (lt->kind!= TYPE_INTEGER {

//             }
//             else{
//                 return 
//             }
//                 printf("")
//             expr_print(e->left);
//             printf("+");
//             expr_print(e->right);
//             break;
//         case EXPR_SUB:
//             expr_print(e->left);
//             printf("-");
//             expr_print(e->right);
//             break;
//         case EXPR_MUL:
//             expr_print(e->left);
//             printf("*");
//             expr_print(e->right);
//             break;
//         case EXPR_MOD:
//             expr_print(e->left);
//             printf("%%");
//             expr_print(e->right);
//             break;
//         case EXPR_DIV:
//             expr_print(e->left);
//             printf("/");
//             expr_print(e->right);
//             break;
//         case EXPR_EXP:
//             expr_print(e->left);
//             printf("^");
//             expr_print(e->right);
//             break;
//         case EXPR_NEG:
//             printf("-");
//             expr_print(e->left);
//             break;
//         case EXPR_LTE:
//             expr_print(e->left);
//             printf("<=");
//             expr_print(e->right);
//             break;
//         case EXPR_GTE:
//             expr_print(e->left);
//             printf(">=");
//             expr_print(e->right);
//             break;
//         case EXPR_LT:
//             expr_print(e->left);
//             printf("<");
//             expr_print(e->right);
//             break;
//         case EXPR_GT:
//             expr_print(e->left);
//             printf(">");
//             expr_print(e->right);
//             break;
//         case EXPR_EQ:
//             expr_print(e->left);
//             printf("==");
//             expr_print(e->right);
//             break;
//         case EXPR_NOT:
//             expr_print(e->left);
//             printf("<=");
//             expr_print(e->right);
//             break;
//         case EXPR_NOT_EQ:
//             expr_print(e->left);
//             printf("!=");
//             expr_print(e->right);
//         case EXPR_ASSIGN:
//             expr_print(e->left);
//             printf("=");
//             expr_print(e->right);
//         case EXPR_AND:
//             expr_print(e->left);
//             printf("!=");
//             expr_print(e->right);
//         case EXPR_OR:
//             expr_print(e->left);
//             printf("||");
//             expr_print(e->right);
//             break;
//         case EXPR_INT:
//             result = type_create(TYPE_INTEGER,0,0);
//             break;
//         case EXPR_FLOAT:
//             result = type_create(TYPE_FLOAT,0,0);
//             break;
//         case EXPR_BOOL:
//             printf("Expression: BOOL\n");
//             break;
//         case EXPR_CHAR:
//             printf("'%c'", e->char_literal);
//             break;
//         case EXPR_STRING:
//             printf("%s", e->string_literal);
//             break;
//         case EXPR_IDENT:
//             printf("%s", e->ident);
//             break;
//         case EXPR_ARRAY_ACCESS:
//             expr_print(e->left);
//             printf("[");
//             expr_print(e->right);
//             printf("]");
//             break;
//         case EXPR_FUNC_CALL:
//             expr_print(e->left);
//             printf("(");
//             expr_print(e->right);
//             printf(")");
//             break;
//         case EXPR_NESTED_ARRAY_ACCESS:
//             printf("[");
//             expr_print(e->left);
//             printf("]");
//             expr_print(e->right);
//             break;
//         case EXPR_LIST:
//             expr_print(e->left);
//             printf(",");
//             expr_print(e->right);
//             break;
//         case EXPR_NESTED_BRACES:
//             printf("{");
//             expr_print(e->left);
//             if (e->right){
//                 printf(",");
//                 expr_print(e->right);
//             }
//             break;
//         case EXPR_POS:
//             printf("+");
//             expr_print(e->left);
//             break;
//         default:
//             break;
//     }

//     type_delete(lt);
//     type_delete(rt);
//     return result;
//     result = type_create(TYPE_INTEGER,0,0);
//     break;
//     case EXPR_STRING_LITERAL:
//     result = type_create(TYPE_STRING,0,0);
//     break;
//     /* more cases here */
//     }

