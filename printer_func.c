#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"
#include "string_decode.c"


#define MAX_CHAR_LENGTH 255

extern FILE *yyin;
extern int yylex();
extern char *yytext;
extern int yyparse();
extern int yy_error(char *s);

struct stmt {
    stmt_t kind;
    struct decl *decl;
    struct expr *init_expr;
    struct expr *expr;
    struct expr *next_expr;
    struct stmt *body;
    struct stmt *else_body;
    struct stmt *next;
};


struct decl {
    char *name;
    struct type *type;
    struct expr *value;
    struct stmt *code;
    struct decl *next;
};


typedef enum {
    STMT_DECL,
    STMT_EXPR,
    STMT_IF_ELSE,
    STMT_FOR,
    STMT_PRINT,
    STMT_RETURN,
    STMT_BLOCK
} stmt_t;

struct decl * decl_create( char *name, struct type *type, struct expr *value, struct stmt *code, struct decl *next ){

    struct decl *d = malloc(sizeof(*d));
    d->name = name;
    d->type = type;
    d->value = value;
    d->code = code;
    d->next = next;
    return d;
}

struct stmt * stmt_create( stmt_t kind, struct decl *decl, struct expr *init_expr, struct expr *expr, struct expr *next_expr, struct stmt *body, struct stmt *else_body, struct stmt *next){

}


struct decl * decl_create( char *name, struct type *type, struct expr *value, struct stmt *code, struct decl *next ){

    malloc
}



