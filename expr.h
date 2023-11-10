
#ifndef EXPR_H
#define EXPR_H
#include <stdbool.h>
#include "symbol.h"
#include "scope.h"

typedef enum {
	EXPR_ADD,
	EXPR_SUB,
	EXPR_MUL,
	EXPR_MOD, 
	EXPR_DIV,
	EXPR_EXP, 
	EXPR_NEG, 
	EXPR_LTE,
	EXPR_GTE,
	EXPR_LT,
	EXPR_GT,
	EXPR_EQ,
	EXPR_NOT,
	EXPR_NOT_EQ,
	EXPR_ASSIGN,
	EXPR_AND,
	EXPR_OR,
	EXPR_INT,
	EXPR_FLOAT,
	EXPR_BOOL,
	EXPR_CHAR,
	EXPR_STRING,
	EXPR_IDENT,
	EXPR_ARRAY_ACCESS,
	EXPR_FUNC_CALL,
	EXPR_NESTED_ARRAY_ACCESS,
	EXPR_LIST,
	EXPR_NESTED_BRACES,
	EXPR_POS,
	EXPR_PAREN,
	EXPR_INC,
	EXPR_DEC
	/* many more kinds of exprs to add here */
} expr_t;

struct expr {
	/* used by all kinds of exprs */
	expr_t kind;
	struct expr *left;
	struct expr *right;

	/* used by various leaf exprs */
	char* ident;
	int int_literal;
	char * string_literal;
	float float_literal;
	bool bool_literal;
	struct symbol *symbol;
} ;

struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right );
struct expr * expr_create_ident( const char *n );
struct expr * expr_create_integer_literal( int c );
struct expr * expr_create_boolean_literal( int c );
struct expr * expr_create_float_literal( float c );
struct expr * expr_create_char_literal( char * c );
struct expr * expr_create_string_literal( const char *str );
void expr_print( struct expr *e );
void expr_resolve( struct expr *e );
// struct type * expr_typecheck( struct expr *e );

#endif
