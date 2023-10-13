%{
#include "token.h"
%}

DIGIT    [0-9]
LETTER   [a-zA-Z]
HEX      [0-9a-fA-F]
%%

(" "|\t|\n|\r)+                                       { /* ignore white space */ }

\,                                                    { return TOKEN_COMMA; }
\+\+                                                  { return TOKEN_PLUS_PLUS; }
\-\-                                                  { return TOKEN_MINUS_MINUS; }
\+                                                    { return TOKEN_ADD; }
\:                                                    { return TOKEN_COLON; }
\-                                                    { return TOKEN_SUBTRACT; }
\(                                                    { return TOKEN_LEFT_PARENTHESIS; }
\)                                                    { return TOKEN_RIGHT_PARENTHESIS; }
\{                                                    { return TOKEN_LEFT_BRACE; }
\}                                                    { return TOKEN_RIGHT_BRACE; }
\[                                                    { return TOKEN_LEFT_BRACKET; }
\]                                                    { return TOKEN_RIGHT_BRACKET; }
%                                                     { return TOKEN_MODULO; }
=                                                     { return TOKEN_ASSIGN; }
\^                                                    { return TOKEN_EXPONENT; }
!=                                                    { return TOKEN_NOT_EQUAL; }
==                                                    { return TOKEN_EQUAL; }
!                                                     { return TOKEN_NOT; }
\*                                                    { return TOKEN_MULTIPLY; }
\/                                                    { return TOKEN_DIVISION; }
\<                                                    { return TOKEN_LESS_THAN; }
\>                                                    { return TOKEN_GREATER_THAN; }
\<=                                                   { return TOKEN_LESS_THAN_OR_EQUAL; }
\>=                                                   { return TOKEN_GREATER_THAN_OR_EQUAL; }
&&                                                    { return TOKEN_AND; }
\|\|                                                  { return TOKEN_OR; }
\:                                                    { return TOKEN_COLON; }
\;                                                    { return TOKEN_SEMICOLON; }
array                                                 { return TOKEN_ARRAY; }
auto                                                  { return TOKEN_AUTO; }
boolean                                               { return TOKEN_BOOLEAN; }
char                                                  { return TOKEN_CHAR; }
else                                                  { return TOKEN_ELSE; }
false                                                 { return TOKEN_FALSE; }
float                                                 { return TOKEN_FLOAT; }
for                                                   { return TOKEN_FOR; }
function                                              { return TOKEN_FUNCTION; }
if                                                    { return TOKEN_IF; }
integer                                               { return TOKEN_INT; }
print                                                 { return TOKEN_PRINT; }
return                                                { return TOKEN_RETURN; }
string                                                { return TOKEN_STRING; }
true                                                  { return TOKEN_TRUE; }
void                                                  { return TOKEN_VOID; }
while                                                 { return TOKEN_WHILE; }


({LETTER}|_)({DIGIT}|{LETTER}|_)*                     { 
                                if (strlen(yytext) > 255) {
                                    return TOKEN_ERROR;
                                } 
                                else{
                                    return TOKEN_IDENTIFIER;
                                }
}
\"([^"\\\n]|\\.){0,255}\"                             { return TOKEN_STRING_LITERAL; }
'([^\\]|\\[^']|(\\0x{HEX}{HEX}))'                     { return TOKEN_CHAR_LITERAL; }
{DIGIT}+                                              { return TOKEN_INT_LITERAL; }
({DIGIT}+(\.{DIGIT}*|((\.{DIGIT}+)?[eE][-+]?{DIGIT}+))|\.{DIGIT}+) { return TOKEN_FLOAT_LITERAL; }
(\/\*([^*]|\*[^\/])*\*\*\/)|(\/\*([^*]|\*[^\/])*\*\/)    { return TOKEN_COMMENT; }
.                                                     { return TOKEN_ERROR; }
%%
int yywrap() { return 1; }
