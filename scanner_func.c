#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"


#define MAX_CHAR_LENGTH 255

extern FILE *yyin;
extern int yylex();
extern char *yytext;
extern int yyparse();
extern int yy_error(char *s);

int scanner() {
    while(1) {
        enum yytokentype t = yylex();
        if (t == 0){
            return 0;
        }
        switch (t) {
            case TOKEN_ARRAY:
                printf("ARRAY          %s\n", yytext);
                break;
            case TOKEN_AUTO:
                printf("AUTO           %s\n", yytext);
                break;
            case TOKEN_BOOLEAN:
                printf("BOOL           %s\n", yytext);
                break;
            case TOKEN_CHAR:
                printf("CHAR           %s\n", yytext);
                break;
            case TOKEN_ELSE:
                printf("ELSE           %s\n", yytext);
                break;
            case TOKEN_FALSE:
                printf("FALSE          %s\n", yytext);
                break;
            case TOKEN_FLOAT:
                printf("FLOAT          %s\n", yytext);
                break;
            case TOKEN_FOR:
                printf("FOR            %s\n", yytext);
                break;
            case TOKEN_FUNCTION:
                printf("FUNCTION            %s\n", yytext);
                break;
            case TOKEN_IF:
                printf("IF             %s\n", yytext);
                break;
            case TOKEN_INT:
                printf("INT            %s\n", yytext);
                break;
            case TOKEN_PRINT:
                printf("PRINT          %s\n", yytext);
                break;
            case TOKEN_RETURN:
                printf("RETURN         %s\n", yytext);
                break;
            case TOKEN_STRING:
                printf("STRING         %s\n", yytext);
                break;
            case TOKEN_TRUE:
                printf("TRUE           %s\n", yytext);
                break;
            case TOKEN_SUBTRACT:
                printf("SUBTRACT           %s\n", yytext);
                break;
            case TOKEN_VOID:
                printf("VOID           %s\n", yytext);
                break;
            case TOKEN_WHILE:
                printf("WHILE          %s\n", yytext);
                break;
            case TOKEN_ADD:
                printf("ADD            %s\n", yytext);
                break;
            case TOKEN_NEGATIVE:
                printf("NEGATIVE       %s\n", yytext);
                break;
            case TOKEN_MULTIPLY:
                printf("MULTIPLY       %s\n", yytext);
                break;
            case TOKEN_COLON:
                printf("COLON %s\n", yytext);
                break;
            case TOKEN_DIVISION:
                printf("DIVISION       %s\n", yytext);
                break;
            case TOKEN_MODULO:
                printf("MODULO         %s\n", yytext);
                break;
            case TOKEN_EXPONENT:
                printf("EXPONENT       %s\n", yytext);
                break;
            case TOKEN_LEFT_PARENTHESIS:
                printf("LEFT PARENTHEIS     %s\n", yytext);
                break;
            case TOKEN_RIGHT_PARENTHESIS:
                printf("RIGHT PARENTHESIS    %s\n", yytext);
                break;
            case TOKEN_ASSIGN:
                printf("ASSIGN         %s\n", yytext);
                break;
            case TOKEN_LEFT_BRACE:
                printf("LEFT BRACE     %s\n", yytext);
                break;
            case TOKEN_RIGHT_BRACE:
                printf("RIGHT BRACE    %s\n", yytext);
                break;
            case TOKEN_LEFT_BRACKET:
                printf("LEFT BRACKET   %s\n", yytext);
                break;
            case TOKEN_RIGHT_BRACKET:
                printf("RIGHT BRACKET  %s\n", yytext);
                break;
            case TOKEN_NOT_EQUAL:
                printf("IEQUALITY     %s\n", yytext);
                break;
            case TOKEN_EQUAL:
                printf("EQUALITY       %s\n", yytext);
                break;
            case TOKEN_NOT:
                printf("NOT            %s\n", yytext);
                break;
            case TOKEN_LESS_THAN:
                printf("LESS THAN      %s\n", yytext);
                break;
            case TOKEN_GREATER_THAN:
                printf("GREATER THAN   %s\n", yytext);
                break;
            case TOKEN_AND:
                printf("AND            %s\n", yytext);
                break;
            case TOKEN_OR:
                printf("OR             %s\n", yytext);
                break;
            case TOKEN_TYPE_SET:
                printf("TYPE_SET         %s\n", yytext);
                break;
            case TOKEN_SEMICOLON:
                printf("SEMICOLON      %s\n", yytext);
                break;
            case TOKEN_COMMA:
                printf("COMMA          %s\n", yytext);
                break;
            case TOKEN_PLUS_PLUS:
                printf("INCREMENT      %s\n", yytext);
                break;
            case TOKEN_MINUS_MINUS:
                printf("DECREMENT      %s\n", yytext);
                break;
            case TOKEN_ERROR:
                printf("ERROR          %s\n", yytext);
                return EXIT_FAILURE;
                break;
            case TOKEN_LESS_THAN_OR_EQUAL:
                printf("LESS_THAN_OR_EQUAL            %s\n", yytext);
                break;
            case TOKEN_GREATER_THAN_OR_EQUAL:
                printf("GREATER_THAN_OR_EQUAL            %s\n", yytext);
                break;
            case TOKEN_IDENTIFIER:
                printf("IDENTIFIER     %s\n", yytext);
                break;
            case TOKEN_INT_LITERAL: {
                int64_t read_int;
                if (read_int = atoi(yytext) < 0) {
                    fprintf(stderr, "ERROR: Integer too long\n");
                    return EXIT_FAILURE;
                }
                printf("INT LITERAL    %d\n", read_int);
            } break;
            case TOKEN_FLOAT_LITERAL:{
                float read_float;
                if (read_float = atof(yytext) < 0) {
                    fprintf(stderr, "ERROR: Float error\n");
                    return EXIT_FAILURE;
                }
                printf("FLOAT LITERAL  %lf\n", atof(yytext));
            }
                break;
            
            case TOKEN_STRING_LITERAL: {
                char decoded_string[MAX_CHAR_LENGTH + 1] = {0};
                if (string_decode(yytext, decoded_string)){
                    fprintf(stderr, "ERROR: invalid string literal");
                    return EXIT_FAILURE;
                } 
                printf("STRING LITERAL %s\n", decoded_string);
            } break;
            case TOKEN_CHAR_LITERAL: {
                char read_char;
                if (!(read_char = char_decode(yytext))) {
                    fprintf(stderr, "ERROR: Invalid char literal");
                    return EXIT_FAILURE;
                }
                printf("CHAR LITERAL   %s %c\n", yytext, read_char);
            } break;

            default:
                printf("Scan Error: %d is not a valid character.\n", t);
                return EXIT_FAILURE;
                break;
        }
    }
}