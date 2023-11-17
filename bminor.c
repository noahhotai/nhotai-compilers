#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner_func.c"
#include "string_encode.c"
#include "decl.h"
#include "hash_table.h"
#include "scope.h"


struct decl *parser_result;
extern int yyparse();
int resolve_error;
int typecheck_error;

void indent(int indents){
    for (int i = 0; i < indents; i++){
        printf("    ");
    }
}


int main(int argc, char* argv[]){
    // call scanner
    if (!strcmp(argv[1], "--scan")){
        yyin = fopen(argv[2], "r");
        if (scanner()) {
            printf("ERROR: Failure scanning\n");
            return 1;
        }
    }
    // call encoder
    else if (!strcmp(argv[1], "--encode")){
            FILE* fp = fopen(argv[2], "r");
        if (!fp){
            fprintf(stderr, "ERROR: Unable to open file.\n");
        }

        char buffer[BUFSIZ] = {0};
        if (!fgets(buffer, BUFSIZ, fp)){
            fprintf(stderr, "ERROR: Could not read from file.");
            fclose(fp);
            return 1;
        }
        char decode_string[255] = {0};
        char encode_string[255] = {0};
        if (string_decode((const char*) buffer, decode_string)) return 1;
        string_encode((const char*) decode_string, encode_string);
        fprintf(stdout, "Decoded line: %s\n", decode_string);
        fprintf(stdout, "Encoded line: %s\n", encode_string);
    }
    
    else if (!strcmp(argv[1], "--parse")) {
        if (!(yyin = fopen(argv[2], "r"))) {
            fprintf(stderr, "Could not open %s\n", argv[2]);
            return 1;
        };

        if (yyparse()) {
            return 1;
        } else {
            fprintf(stdout, "Program parsed successfully.\n");
        }
        fclose(yyin);
    }
    else if (!strcmp(argv[1], "--print")) {
        if (!(yyin = fopen(argv[2], "r"))) {
            fprintf(stderr, "Could not open %s\n", argv[2]);
            return 1;
        };
        if (yyparse()) {
            return 1;
        } else {
            // printf("else");
            fprintf(stdout, "Program parsed successfully.\n");
            // printf("else");
        }
        // printf("before111");
        fclose(yyin);
        // printf("before");
        decl_print(parser_result, 0);
    }
    else if (!strcmp(argv[1], "--resolve")) {
        if (!(yyin = fopen(argv[2], "r"))) {
            fprintf(stderr, "Could not open %s\n", argv[2]);
            return 1;
        };
        if (yyparse()) {
            return 1;
        } else {
            fprintf(stdout, "Program parsed successfully.\n");
        }
        fclose(yyin);
        the_stack = scope_stack_creator();
        decl_resolve(parser_result);
        if (!resolve_error){
            fprintf(stdout, "Program resolved successfully.\n");
            return 0;
        }
        else{
            fprintf(stdout, "Program failed to resolve.\n");
            return 1;
        }
    }
    else if (!strcmp(argv[1], "--typecheck")) {
        if (!(yyin = fopen(argv[2], "r"))) {
            fprintf(stderr, "Could not open %s\n", argv[2]);
            return 1;
        };
        if (yyparse()) {
            return 1;
        } else {
            fprintf(stdout, "Program parsed successfully.\n");
        }
        fclose(yyin);
        the_stack = scope_stack_creator();
        decl_resolve(parser_result);
        if (!resolve_error){
            fprintf(stdout, "Program resolved successfully.\n");
        }
        else{
            fprintf(stdout, "Program failed to resolve.\n");
            // return 1;
        }
        // the_stack = scope_stack_creator();
        typecheck_error = 0;
        decl_typecheck(parser_result);
        if (!typecheck_error){
            fprintf(stdout, "Program type checked successfully.\n");
            return 0;
        }
        else{
            fprintf(stdout, "Program failed to typecheck.\n");
            
            return 1;
        }
        
    }
    else{
        return 1;
    }

    return 0;
}

