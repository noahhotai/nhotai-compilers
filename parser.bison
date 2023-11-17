 %{
#include <stdio.h>
#include "decl.h"
#include "expr.h"
#include "type.h"
#include "stmt.h"
extern char *yytext;
extern int yylex();
extern int yyerror( char *str);
extern struct decl *parser_result;

#include "decl.h"
#include <string.h>
#include <stdlib.h>

%}

%type <decl> program decl decl_list var_decl func_decl array_decl                                                                                                                                  
%type <stmt> if_dangle stmt simple_stmt compound_stmt dangle_end reg_end stmt_block stmt_list return_stmt for_stmt for_cond print_stmt
%type <expr> access array_access array_access_recursive array_size array_expr_list nested_array_braces nested_array_braces_recursive expr_assign inc_or_dec expr_val expr for_expr expr_list expr_list_recursive expr2 expr3 expr4 expr5 expr6 expr7 expr8 expr9 boolean_literal func_call data_atom 
%type <type> type func_type every_type array_type  
%type <param_list> param_recursive param_list
%type <name> identifier



%define parse.trace

%union{
	struct decl *decl;
	struct stmt *stmt;
	struct expr *expr;
	char * name;
	struct type *type;
	struct param_list *param_list;
};


// listing all the tokens
%token TOKEN_EOF 0
%token TOKEN_ERROR
%token TOKEN_ARRAY
%token TOKEN_SUBTRACT
%token TOKEN_AUTO
%token TOKEN_BOOLEAN
%token TOKEN_CHAR
%token TOKEN_ELSE
%token TOKEN_FALSE
%token TOKEN_FLOAT
%token TOKEN_FOR
%token TOKEN_FUNCTION
%token TOKEN_COLON
%token TOKEN_IF
%token TOKEN_INT
%token TOKEN_PRINT
%token TOKEN_RETURN
%token TOKEN_STRING
%token TOKEN_TRUE
%token TOKEN_VOID
%token TOKEN_WHILE
%token TOKEN_ADD
%token TOKEN_NEGATIVE
%token TOKEN_MULTIPLY
%token TOKEN_DIVISION
%token TOKEN_MODULO
%token TOKEN_EXPONENT
%token TOKEN_LEFT_PARENTHESIS
%token TOKEN_RIGHT_PARENTHESIS
%token TOKEN_ASSIGN
%token TOKEN_LEFT_BRACE
%token TOKEN_RIGHT_BRACE
%token TOKEN_LEFT_BRACKET
%token TOKEN_RIGHT_BRACKET
%token TOKEN_NOT_EQUAL
%token TOKEN_NOT
%token TOKEN_EQUAL
%token TOKEN_NO
%token TOKEN_LESS_THAN
%token TOKEN_GREATER_THAN
%token TOKEN_AND
%token TOKEN_OR
%token TOKEN_TYPE_SET
%token TOKEN_SEMICOLON
%token TOKEN_COMMA
%token TOKEN_PLUS_PLUS
%token TOKEN_MINUS_MINUS
%token TOKEN_LESS_THAN_OR_EQUAL
%token TOKEN_GREATER_THAN_OR_EQUAL
%token TOKEN_IDENTIFIER
%token TOKEN_INT_LITERAL
%token TOKEN_FLOAT_LITERAL
%token TOKEN_STRING_LITERAL
%token TOKEN_CHAR_LITERAL

// listing all the rules
%%
program : decl_list TOKEN_EOF { parser_result = $1; return 0; }
| TOKEN_EOF { return 0; }
;

decl_list: decl decl_list{$$ = $1; $1->next = $2;}
| decl {$$ = $1;}
;

decl: var_decl  {$$ = $1;}
| func_decl  {$$ = $1;}
;

identifier: TOKEN_IDENTIFIER {$$ = strdup(yytext);}
;

func_decl: identifier TOKEN_COLON TOKEN_FUNCTION func_type TOKEN_LEFT_PARENTHESIS param_list TOKEN_RIGHT_PARENTHESIS TOKEN_ASSIGN stmt_block { $$ = decl_create($1 , type_create(TYPE_FUNCTION, $4, $6, 0), 0, $9, 0);}
|  identifier TOKEN_COLON TOKEN_FUNCTION func_type TOKEN_LEFT_PARENTHESIS param_list TOKEN_RIGHT_PARENTHESIS TOKEN_SEMICOLON  {$$ = decl_create($1, type_create(TYPE_FUNCTION, $4, $6, 0), 0,  0, 0);}
;

var_decl: identifier TOKEN_COLON type TOKEN_SEMICOLON {$$ = decl_create($1, $3, 0, 0, 0 );}
| identifier TOKEN_COLON type TOKEN_ASSIGN expr TOKEN_SEMICOLON { $$ = decl_create($1, $3, $5, 0, 0 );}
| array_decl {$$ = $1;}
;


if_dangle: TOKEN_IF TOKEN_LEFT_PARENTHESIS expr TOKEN_RIGHT_PARENTHESIS if_dangle TOKEN_ELSE if_dangle {$$ = stmt_create(STMT_IF_ELSE, 0, 0, $3, 0, $5, $7, 0);}
| for_stmt dangle_end {$1->body = $2; $$ = $1;} 
| simple_stmt {$$ = $1;}
;

stmt: compound_stmt {$$ = $1;}
| simple_stmt {$$ = $1;}
;

simple_stmt: var_decl {$$ = stmt_create(STMT_DECL, $1, 0, 0, 0, 0, 0, 0);}
| func_call TOKEN_SEMICOLON {$$ = stmt_create(STMT_EXPR, 0, 0, $1, 0, 0, 0, 0);}
| return_stmt TOKEN_SEMICOLON {$$ = $1;}
| print_stmt TOKEN_SEMICOLON {$$ = $1;}
| inc_or_dec TOKEN_SEMICOLON {$$ = stmt_create(STMT_EXPR, 0, 0, $1, 0, 0, 0, 0);}
| stmt_block { $$ = $1;}
| expr_assign TOKEN_SEMICOLON {$$ = stmt_create(STMT_EXPR, 0, 0, $1, 0, 0, 0, 0);}
;

compound_stmt: for_stmt reg_end {$1->body = $2; $$ = $1;}
| TOKEN_IF TOKEN_LEFT_PARENTHESIS expr TOKEN_RIGHT_PARENTHESIS stmt {$$ = stmt_create(STMT_IF_ELSE, 0, 0, $3, 0, $5, 0, 0);}
| TOKEN_IF TOKEN_LEFT_PARENTHESIS expr TOKEN_RIGHT_PARENTHESIS if_dangle TOKEN_ELSE stmt  {$$ = stmt_create(STMT_IF_ELSE, 0, 0, $3, 0, $5, $7, 0);}
;


dangle_end: TOKEN_SEMICOLON {$$ = 0;}
|if_dangle {$$ = $1;}
;

reg_end: stmt {$$ = $1;}
| TOKEN_SEMICOLON {$$ = 0;}
;

access: identifier {$$ = expr_create_ident($1);}
| array_access {$$ = $1;}
;

array_access: identifier TOKEN_LEFT_BRACKET expr TOKEN_RIGHT_BRACKET array_access_recursive { $$ = expr_create(EXPR_ARRAY_ACCESS, expr_create_ident($1), expr_create(EXPR_NESTED_ARRAY_ACCESS,  $3, $5));}
;

array_access_recursive: TOKEN_LEFT_BRACKET expr TOKEN_RIGHT_BRACKET array_access_recursive {$$ = expr_create(EXPR_NESTED_ARRAY_ACCESS, $2, $4);}
| {$$ = 0;}
;

type: TOKEN_INT { $$ = type_create(TYPE_INTEGER, 0, 0, 0);	}
| TOKEN_FLOAT  { $$ = type_create(TYPE_FLOAT, 0, 0, 0);	}
| TOKEN_STRING { $$ = type_create(TYPE_STRING, 0, 0, 0);	}
| TOKEN_BOOLEAN { $$ = type_create(TYPE_BOOLEAN, 0, 0, 0);	}
| TOKEN_CHAR { $$ = type_create(TYPE_CHAR, 0, 0, 0);	}
;

stmt_block: TOKEN_LEFT_BRACE stmt_list TOKEN_RIGHT_BRACE { $$ = stmt_create(STMT_BLOCK, 0, 0, 0, 0, $2, 0, 0);}
;

func_type: type { $$ = $1;	}
| TOKEN_VOID { $$ = type_create(TYPE_VOID, 0, 0, 0);	}
;

param_recursive: TOKEN_COMMA identifier TOKEN_COLON type param_recursive {$$ = param_list_create($2, $4, $5);}
| {$$ = 0;}
;

every_type: type { $$ = $1;	}
| array_type { $$ = $1; } 
;

array_type: TOKEN_ARRAY TOKEN_LEFT_BRACKET array_size TOKEN_RIGHT_BRACKET every_type {$$ = type_create(TYPE_ARRAY, $5, 0, $3);}
;

array_size: expr { $$ = $1; } 
|                { $$ = 0; } 
;

array_expr_list: expr expr_list_recursive { $$ = expr_create(EXPR_LIST, $1, $2); }
| nested_array_braces { $$ = $1; }
;

nested_array_braces: TOKEN_LEFT_BRACE array_expr_list TOKEN_RIGHT_BRACE nested_array_braces_recursive { $$ = expr_create(EXPR_NESTED_BRACES, $2, $4); }
;

nested_array_braces_recursive: TOKEN_COMMA TOKEN_LEFT_BRACE array_expr_list TOKEN_RIGHT_BRACE nested_array_braces_recursive { $$ = expr_create(EXPR_NESTED_BRACES, $3, $5); }
| { $$ = 0; }
;

array_decl: identifier TOKEN_COLON array_type TOKEN_ASSIGN TOKEN_LEFT_BRACE array_expr_list TOKEN_RIGHT_BRACE TOKEN_SEMICOLON {struct expr* temp = expr_create(EXPR_ARRAY_BRACES, $6, 0); $$ = decl_create($1, $3, temp, 0, 0 );}
| identifier TOKEN_COLON array_type TOKEN_SEMICOLON {$$ = decl_create($1, $3, 0, 0, 0);}
;


param_list: identifier TOKEN_COLON every_type param_recursive {$$ = param_list_create($1, $3, $4); }
| {$$ = 0;}
;


stmt_list : stmt stmt_list {$1->next = $2; $$ = $1; }
| {$$ = 0;}
;



return_stmt: TOKEN_RETURN expr  {$$ = stmt_create(STMT_RETURN, 0, 0, $2, 0, 0, 0, 0);}
| TOKEN_RETURN {$$ = stmt_create(STMT_RETURN, 0, 0, 0, 0, 0, 0, 0);}
;

expr_assign: access TOKEN_ASSIGN expr {$$ = expr_create(EXPR_ASSIGN, $1, $3);}
;

inc_or_dec: identifier TOKEN_PLUS_PLUS { $$ = expr_create( EXPR_INC, expr_create_ident($1), 0 ); }
| identifier TOKEN_MINUS_MINUS { $$ = expr_create( EXPR_DEC, expr_create_ident($1), 0 ); }
;

expr_val: expr2 {$$ = $1;}
;

expr: expr_assign { $$ = $1;}
| expr_val { $$ = $1;}
;

for_stmt: TOKEN_FOR for_cond {$$ = $2;}
;

for_cond: TOKEN_LEFT_PARENTHESIS for_expr TOKEN_SEMICOLON for_expr TOKEN_SEMICOLON for_expr TOKEN_RIGHT_PARENTHESIS {$$ = stmt_create(STMT_FOR, 0, $2, $4, $6, 0, 0, 0); }
;

for_expr: expr {$$ = $1;}
| {$$ = 0;}
;

expr_list: expr expr_list_recursive {$$ = expr_create(EXPR_LIST, $1, $2);}
| {$$ = 0;}
;

expr_list_recursive: TOKEN_COMMA expr expr_list_recursive {$$ = expr_create(EXPR_LIST, $2, $3);}
| {$$ = 0;}
;

expr2: expr3 {$$ = $1;}
| expr2 TOKEN_OR expr3 {$$ = expr_create(EXPR_OR, $1, $3);}
;

expr3: expr4 {$$ = $1;}
| expr3 TOKEN_AND expr4 {$$ = expr_create(EXPR_AND, $1, $3);}
;

expr4: expr4 TOKEN_EQUAL expr5 {$$ = expr_create(EXPR_EQ, $1, $3);}
| expr4 TOKEN_NOT_EQUAL expr5 {$$ = expr_create(EXPR_NOT_EQ, $1, $3);}
| expr5 {$$ = $1;}
;

expr5: expr6 {$$ = $1;}
| expr5 TOKEN_LESS_THAN_OR_EQUAL expr6 {$$ = expr_create(EXPR_LTE, $1, $3);}
| expr5 TOKEN_LESS_THAN expr6 {$$ = expr_create(EXPR_LT, $1, $3);}
| expr5 TOKEN_GREATER_THAN expr6 {$$ = expr_create(EXPR_GT, $1, $3);}
| expr5 TOKEN_GREATER_THAN_OR_EQUAL expr6 {$$ = expr_create(EXPR_GTE, $1, $3);}
;

expr6: expr7 {$$ = $1;}
| expr7 TOKEN_ADD expr6 {$$ = expr_create(EXPR_ADD, $1, $3);}
| expr7 TOKEN_SUBTRACT expr6 {$$ = expr_create(EXPR_SUB, $1, $3);}
;

expr7: expr8 {$$ = $1;}
| expr7 TOKEN_MODULO expr8 {$$ = expr_create(EXPR_MOD, $1, $3);}
| expr7 TOKEN_MULTIPLY expr8 {$$ = expr_create(EXPR_MUL, $1, $3);}
| expr7 TOKEN_DIVISION expr8 { $$ = expr_create(EXPR_DIV, $1, $3);}
;

expr8: expr9 {$$ = $1;}
| TOKEN_NOT expr9  {$$ = expr_create(EXPR_NOT, $2, 0);}
| TOKEN_SUBTRACT expr9  {$$ = expr_create(EXPR_NEG, $2, 0);}
| TOKEN_ADD expr9  {$$ = expr_create(EXPR_POS, $2, 0);}
;

expr9: data_atom {$$ = $1;}
| expr9 TOKEN_EXPONENT data_atom {$$ = expr_create(EXPR_EXP, $1, $3);}
;

boolean_literal: TOKEN_TRUE {$$ = expr_create_boolean_literal(1);}
| TOKEN_FALSE {$$ = expr_create_boolean_literal(0);}
;


func_call: identifier TOKEN_LEFT_PARENTHESIS expr_list TOKEN_RIGHT_PARENTHESIS { $$ = expr_create(EXPR_FUNC_CALL, expr_create_ident($1), $3);}
;

data_atom: TOKEN_STRING_LITERAL {$$ = expr_create_string_literal(strdup(yytext));}
| TOKEN_INT_LITERAL {$$ = expr_create_integer_literal(atoi(yytext)); }
| TOKEN_CHAR_LITERAL  {$$ = expr_create_char_literal(yytext);}
| TOKEN_FLOAT_LITERAL  {$$ = expr_create_float_literal(atof(yytext));}
| boolean_literal {$$ = $1;}
| func_call {$$ = $1;}
| access {$$ = $1;}
| inc_or_dec {$$ = $1;} 
| TOKEN_LEFT_PARENTHESIS expr TOKEN_RIGHT_PARENTHESIS {$$ = expr_create(EXPR_PAREN, $2, 0);}
;

print_stmt: TOKEN_PRINT expr_list {$$ = stmt_create(STMT_PRINT, 0, 0, $2, 0, 0, 0, 0);}
;

%%

// describing error case
int yyerror( char *s ) {
    printf("parse error: %s\n",s);
    return 1;
}