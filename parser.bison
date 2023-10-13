 %{
#include <stdio.h>
extern char *yytext;
extern int yylex();
extern int yyerror( char *str);

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
program : decl_list {return 0; }
| {return 0; }
;

decl_list: decl_list decl
| decl
;


if_dangle: TOKEN_IF TOKEN_LEFT_PARENTHESIS expr TOKEN_RIGHT_PARENTHESIS if_dangle TOKEN_ELSE if_dangle
| var_decl
| for_stmt dangle_end
| func_call TOKEN_SEMICOLON
| return_stmt TOKEN_SEMICOLON
| print_stmt TOKEN_SEMICOLON
| inc_or_dec TOKEN_SEMICOLON
| TOKEN_LEFT_BRACE stmt_list TOKEN_RIGHT_BRACE
| expr_assign TOKEN_SEMICOLON
;


dangle_end: TOKEN_SEMICOLON|
if_dangle
;

reg_end: stmt|
TOKEN_SEMICOLON
;

access: TOKEN_IDENTIFIER
| array_access
;

array_access: TOKEN_IDENTIFIER TOKEN_LEFT_BRACKET expr_val TOKEN_RIGHT_BRACKET array_access_recursive
;

array_access_recursive: TOKEN_LEFT_BRACKET expr_val TOKEN_RIGHT_BRACKET array_access_recursive
|
;

type: TOKEN_INT | 
TOKEN_FLOAT|
TOKEN_STRING|
TOKEN_BOOLEAN|
TOKEN_CHAR |
;



func_decl: TOKEN_IDENTIFIER TOKEN_COLON TOKEN_FUNCTION func_type TOKEN_LEFT_PARENTHESIS param_list TOKEN_RIGHT_PARENTHESIS TOKEN_ASSIGN TOKEN_LEFT_BRACE stmt_list TOKEN_RIGHT_BRACE
|  TOKEN_IDENTIFIER TOKEN_COLON TOKEN_FUNCTION func_type TOKEN_LEFT_PARENTHESIS param_list TOKEN_RIGHT_PARENTHESIS TOKEN_SEMICOLON
;

var_decl: TOKEN_IDENTIFIER TOKEN_COLON type TOKEN_SEMICOLON
| TOKEN_IDENTIFIER TOKEN_COLON type TOKEN_ASSIGN expr_val TOKEN_SEMICOLON
| TOKEN_IDENTIFIER TOKEN_COLON array_type TOKEN_ASSIGN TOKEN_LEFT_BRACE expr_val_list TOKEN_RIGHT_BRACE TOKEN_SEMICOLON
| TOKEN_IDENTIFIER TOKEN_COLON array_type TOKEN_SEMICOLON
;

decl: var_decl
| func_decl
;




stmt_block: TOKEN_LEFT_BRACE stmt_list TOKEN_RIGHT_BRACE
;

func_type: type|
TOKEN_VOID
;

param_recursive: TOKEN_COMMA TOKEN_IDENTIFIER TOKEN_COLON type param_recursive
|
;

every_type: type
| array_type

array_type: TOKEN_ARRAY TOKEN_LEFT_BRACKET array_size TOKEN_RIGHT_BRACKET every_type
;

array_size: expr_val
|
;

param_list: TOKEN_IDENTIFIER TOKEN_COLON type param_recursive
|
;


stmt_list: stmt_list stmt
|
;

stmt: for_stmt reg_end
| TOKEN_IF TOKEN_LEFT_PARENTHESIS expr TOKEN_RIGHT_PARENTHESIS stmt
| TOKEN_IF TOKEN_LEFT_PARENTHESIS expr TOKEN_RIGHT_PARENTHESIS if_dangle TOKEN_ELSE stmt
| expr_assign TOKEN_SEMICOLON
| return_stmt TOKEN_SEMICOLON
| print_stmt TOKEN_SEMICOLON
| inc_or_dec TOKEN_SEMICOLON
| stmt_block
| var_decl
| func_call TOKEN_SEMICOLON
;

return_stmt: TOKEN_RETURN expr |
TOKEN_RETURN 
;

expr_assign: access TOKEN_ASSIGN expr
;

inc_or_dec: TOKEN_IDENTIFIER TOKEN_PLUS_PLUS
| TOKEN_IDENTIFIER TOKEN_MINUS_MINUS

expr_val: expr_val operator data_atom
| data_atom
| inc_or_dec
;

expr: expr_assign
| expr_val
;

for_stmt: TOKEN_FOR for_cond

for_cond: TOKEN_LEFT_PARENTHESIS for_expr TOKEN_SEMICOLON for_expr TOKEN_SEMICOLON for_expr TOKEN_RIGHT_PARENTHESIS

for_expr: expr
|
;


expr_val_list: expr_val expr_val_list_recursive
|
;

expr_val_list_recursive: TOKEN_COMMA expr_val_list
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


func_call: TOKEN_IDENTIFIER TOKEN_LEFT_PARENTHESIS expr_val_list TOKEN_RIGHT_PARENTHESIS
;

data_atom: TOKEN_STRING_LITERAL
| TOKEN_INT_LITERAL
| TOKEN_CHAR_LITERAL
| TOKEN_FLOAT_LITERAL
| boolean_literal
| TOKEN_NOT data_atom
| TOKEN_NEGATIVE data_atom
| func_call
| access
| TOKEN_LEFT_PARENTHESIS expr TOKEN_RIGHT_PARENTHESIS
;

print_stmt: TOKEN_PRINT expr_val_list 
;

%%

// describing error case
int yyerror( char *s ) {
    printf("parse error: %s\n",s);
    return 1;
}