%{
#include <stdio.h>
%}
// listing all the tokens
%token TOKEN_ERROR
%token TOKEN_EOF
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
%token TOKEN_STR
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
%token TOKEN_EQUAL
%token TOKEN_NOT
%token TOKEN_LESS_THAN
%token TOKEN_GREATER_THAN
%token TOKEN_AND
%token TOKEN_OR
%token TOKEN_TYPE_SET
%token TOKEN_SEMICOLON
%token TOKEN_COMMA
%token TOKEN_PLUS_PLUS
%token TOKEN_MINUS_MINUS
%token TOKEN_COMMENT
%token TOKEN_LESS_THAN_OR_EQUAL
%token TOKEN_GREATER_THAN_OR_EQUAL
%token TOKEN_IDENTIFIER
%token TOKEN_INT_LITERAL
%token TOKEN_FLOAT_LITERAL
%token TOKEN_STRING_LITERAL
%token TOKEN_STRING
%token TOKEN_CHAR_LITERAL

// listing all the rules
%%
program : decl_list TOKEN_EOF
| TOKEN_EOF
;


type: TOKEN_INT | 
TOKEN_FLOAT|
TOKEN_STRING|
TOKEN_BOOLEAN|
TOKEN_CHAR |
TOKEN_ARRAY TOKEN_LEFT_BRACKET TOKEN_INT_LITERAL TOKEN_RIGHT_BRACKET type
;

decl_list: decl_list decl
| decl
;

func_decl: TOKEN_IDENTIFIER TOKEN_COLON TOKEN_FUNCTION function_type TOKEN_LEFT_PARENTHESIS param_list TOKEN_RIGHT_PARENTHESIS TOKEN_ASSIGN stmt
|  TOKEN_IDENTIFIER TOKEN_COLON TOKEN_FUNCTION function_type TOKEN_LEFT_PARENTHESIS param_list TOKEN_RIGHT_PARENTHESIS TOKEN_SEMICOLON
;

var_decl: TOKEN_IDENTIFIER TOKEN_COLON type TOKEN_SEMICOLON
| TOKEN_IDENTIFIER TOKEN_COLON type TOKEN_ASSIGN data_atom TOKEN_SEMICOLON
;

decl: var_decl
| func_decl
;

stmt_block: TOKEN_LEFT_BRACE stmt_list TOKEN_RIGHT_BRACE
| TOKEN_LEFT_BRACE TOKEN_RIGHT_BRACE
;

function_type: type|
TOKEN_VOID
;

param_recursive: TOKEN_COMMA type param_recursive
|
;

param_list: TOKEN_IDENTIFIER TOKEN_COLON type param_recursive
|
;

stmt_list: stmt_list stmt
| stmt
;

stmt: for_loop
| var_decl
| expr_assign
| return_stmt
| print_stmt
| inc_or_dec
| stmt_block
//| if_stmt
;

return_stmt: TOKEN_RETURN expr_val

expr_assign: TOKEN_IDENTIFIER TOKEN_ASSIGN expr_val TOKEN_SEMICOLON
;

inc_or_dec: TOKEN_IDENTIFIER TOKEN_PLUS_PLUS  TOKEN_SEMICOLON
| TOKEN_IDENTIFIER TOKEN_MINUS_MINUS  TOKEN_SEMICOLON

expr_val: expr_val operator data_atom
| data_atom
;

expr: expr_assign
| expr_val
;

for_loop: TOKEN_FOR TOKEN_LEFT_PARENTHESIS for_expr TOKEN_SEMICOLON for_expr TOKEN_SEMICOLON for_expr TOKEN_RIGHT_PARENTHESIS if_for_block

for_expr: expr
|
;


expr_val_list: expr_val expr_val_list_recursive
|
;

expr_val_list_recursive: TOKEN_COMMA expr_val
|
;

if_for_block: stmt
|
;

operator:  TOKEN_GREATER_THAN_OR_EQUAL
| TOKEN_GREATER_THAN
| TOKEN_LESS_THAN
| TOKEN_LESS_THAN_OR_EQUAL
| TOKEN_NOT_EQUAL
| TOKEN_EQUAL
| TOKEN_ADD
|TOKEN_AND
|TOKEN_OR
| TOKEN_SUBTRACT|
TOKEN_MULTIPLY|
TOKEN_MODULO|
TOKEN_EXPONENT
;

boolean_literal: TOKEN_TRUE
| TOKEN_FALSE
;


func_call: TOKEN_IDENTIFIER TOKEN_LEFT_PARENTHESIS expr_val_list TOKEN_RIGHT_PARENTHESIS TOKEN_SEMICOLON
;

data_atom: TOKEN_STRING_LITERAL
| TOKEN_INT_LITERAL
| TOKEN_CHAR_LITERAL
| TOKEN_IDENTIFIER
| boolean_literal
| func_call
| TOKEN_NOT data_atom
| TOKEN_FLOAT_LITERAL
| TOKEN_IDENTIFIER TOKEN_LEFT_BRACKET expr_val TOKEN_RIGHT_BRACKET
| TOKEN_LEFT_PARENTHESIS expr TOKEN_RIGHT_PARENTHESIS
| inc_or_dec
;

print_stmt: TOKEN_PRINT expr_val_list TOKEN_SEMICOLON

%%

// describing error case
int yyerror( char *s ) {
    printf("parse error: %s\n",s);
    return 1;
}