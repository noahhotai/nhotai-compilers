#include "expr.h"
#include <stdlib.h>


struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right ){
    struct expr *d = malloc(sizeof(struct expr));
    d->kind = kind;
    d->left= left;
    d->right = right;
    return d;
}

struct expr * expr_create_ident( const char *n ){
    struct expr* d = expr_create(EXPR_IDENT, 0, 0);
    d->ident = srtdup(n);
    return d;
}

struct expr * expr_create_integer_literal( int c ){
    struct expr* d = expr_create(EXPR_INT, 0, 0);
    d->int_literal = c;
    return d;
}

struct expr * expr_create_boolean_literal( int c ){
    struct expr* d = expr_create(EXPR_BOOL, 0, 0);
    d->bool_literal = c;
    return d;
}

struct expr * expr_create_char_literal(char c ){
    struct expr* d = expr_create(EXPR_CHAR, 0, 0);
    d->char_literal = c;
    return d;
}

struct expr * expr_create_string_literal( const char *str ){
    struct expr* d = expr_create(EXPR_STRING, 0, 0);
    d->string_literal = strdup(str);
    return d;
}

void expr_print(struct expr *e ){

}
